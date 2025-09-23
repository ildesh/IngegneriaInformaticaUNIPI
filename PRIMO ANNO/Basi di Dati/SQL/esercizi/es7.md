>[!TIP]
> # Esercizio sulla divisione:
>
> Matricola e parcella di tutti i medici che hanno visitato almeno un paziente di ogni città
>
> > La divisione è PRESENTE dalla parola **_"tutti"_**.

Dato un medico M devo dire che non esiste una città di provenienza dei pazienti della quale non esiste un paziente non visitato da M.

Dato un medico M devo dire che non esiste una città per la quale M non ha visitato alcun paziente.

```SQL
SELECT V.Medico, M.Parcella
FROM Visita V
INNER JOIN Medico M ON V.Medico = M.Matricola
INNER JOIN Paziente P ON V.Paziente = P.CodFiscale
GROUP BY V.Medico
HAVING COUNT(DISTINCT P.Citta) = (
    SELECT COUNT DISTINCT P2.Citta
    FROM Paziente P2
)
```

Certo! Ecco una **spiegazione dettagliata passo-passo** della query SQL che risolve l’esercizio:

---

## 🧠 **Obiettivo dell'esercizio**

> Trovare **tutti i medici** (matricola e parcella) che hanno visitato **almeno un paziente per ogni città** presente nel database.

In altre parole, vogliamo:

* Per ogni medico, controllare **quante città diverse** ha coperto con i suoi pazienti.
* E selezionare **solo quei medici** che hanno **coperto tutte le città esistenti** (almeno una visita per ciascuna città).

---

## 🔍 Analisi della Query

```sql
SELECT V.Medico, M.Parcella
FROM Visita V
INNER JOIN Medico M ON V.Medico = M.Matricola
INNER JOIN Paziente P ON V.Paziente = P.CodFiscale
GROUP BY V.Medico
HAVING COUNT(DISTINCT P.Citta) = (
    SELECT COUNT(DISTINCT P2.Citta)
    FROM Paziente P2
)
```

---

## 🔧 **Step-by-step**

### 🔹 `FROM Visita V`

> Prendiamo la tabella `Visita`, che collega **medico** e **paziente**.

---

### 🔹 `INNER JOIN Medico M ON V.Medico = M.Matricola`

> Per ogni visita, colleghiamo le informazioni del **medico**, in particolare per accedere alla sua **parcella**.

---

### 🔹 `INNER JOIN Paziente P ON V.Paziente = P.CodFiscale`

> Colleghiamo anche il **paziente visitato**, per sapere la **città** da cui proviene.

Ora abbiamo:

* il medico che ha fatto la visita,
* la parcella del medico,
* la città del paziente visitato.

---

### 🔹 `GROUP BY V.Medico`

> Raggruppiamo i dati **per medico**, così possiamo contare quante **città diverse** ha coperto ogni medico.

---

### 🔹 `HAVING COUNT(DISTINCT P.Citta) = (...)`

> Selezioniamo solo quei medici per cui il **numero di città diverse** dei pazienti che hanno visitato è **uguale** al **numero totale di città presenti nel database**.

---

### 🔹 Sottoquery:

```sql
SELECT COUNT(DISTINCT P2.Citta)
FROM Paziente P2
```

> Conta quante **città distinte** esistono in tutta la tabella `Paziente`.
> Questo è il numero di città che ogni medico deve "coprire" con almeno un paziente visitato.

---

## 📌 Esempio concreto (semplificato)

Supponiamo di avere 3 città nel database: `Roma`, `Milano`, `Torino`

* Medico A ha visitato pazienti da: `Roma`, `Milano`, `Torino` ✅ → viene selezionato.
* Medico B ha visitato solo: `Roma`, `Milano` ❌ → viene scartato.

---

## 🧠 Dettaglio logico

La logica della divisione (relazionale) è modellata così:

> “Per **ogni città** esiste **almeno un paziente** visitato dal medico **proveniente da quella città**”.

Nel linguaggio SQL, la **divisione relazionale** si implementa con:

* **JOIN** tra le tabelle coinvolte,
* **GROUP BY**,
* **HAVING** con un confronto tra:

  * le **istanze reali coperte** (es. città visitate da un medico)
  * e **l’intero dominio** (es. tutte le città).

---

## ✅ In sintesi

| Parte                     | Significato                                         |
| ------------------------- | --------------------------------------------------- |
| `JOIN`                    | Collegamento tra visita, medico, paziente           |
| `GROUP BY V.Medico`       | Gruppo di visite per medico                         |
| `COUNT(DISTINCT P.Citta)` | Quante città diverse ha coperto il medico           |
| `= (SELECT COUNT...)`     | Quante città totali ci sono nel sistema             |
| →                         | Se sono uguali, il medico ha coperto tutte le città |

---
