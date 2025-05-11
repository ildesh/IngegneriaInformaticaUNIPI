<h1> Indice Lezione 3 - Raggruppamento </h1>

---

- [Raggruppamento](#raggruppamento)
  - [Esempio di raggruppamento](#esempio-di-raggruppamento)
- [Raggruppamento e aggregazione](#raggruppamento-e-aggregazione)
- [Raggruppamento e proiezione](#raggruppamento-e-proiezione)
  - [STIAMO ATTENTI...](#stiamo-attenti)
- [Condizioni sui gruppi](#condizioni-sui-gruppi)
  - [Esempio:](#esempio)
    - [Come possiamo agire?](#come-possiamo-agire)
      - [Step 1: Calcolare la media per ogni specializzazione](#step-1-calcolare-la-media-per-ogni-specializzazione)
      - [Step 2: Calcolare la massima parcella media](#step-2-calcolare-la-massima-parcella-media)
      - [Step 3: Restituire le specializzazioni con la media massima](#step-3-restituire-le-specializzazioni-con-la-media-massima)
- [Condizioni sui gruppi vs. condizioni sui record](#condizioni-sui-gruppi-vs-condizioni-sui-record)
  - [Esempio: Specializzazioni con più di 2 medici di Pisa](#esempio-specializzazioni-con-più-di-2-medici-di-pisa)
- [Ordine di esecuzione di una query SQL](#ordine-di-esecuzione-di-una-query-sql)
- [Common Table Expression (CTE)](#common-table-expression-cte)
  - [Sintassi generale](#sintassi-generale)
  - [Esempio: Pazienti di Siena mai visitati da ortopedici](#esempio-pazienti-di-siena-mai-visitati-da-ortopedici)
    - [Step 1: Creo una CTE con i pazienti visitati da ortopedici](#step-1-creo-una-cte-con-i-pazienti-visitati-da-ortopedici)
  - [Esempio avanzato: Uso di **2 CTE**](#esempio-avanzato-uso-di-2-cte)
- [✅ Riepilogo Lezione 3](#-riepilogo-lezione-3)

---


## Raggruppamento 

Il raggruppamento è una funzionalità di SQL che consente di aggregare i dati in base a uno o più criteri. Questo è utile quando si desidera ottenere statistiche o riepiloghi sui dati.

Formalmente... 

>[!IMPORTANT]
> **Raggruppamento**: Permette di suddividere un insieme di record in gruppi di record (la tabella target viene frammentata); in ogni gruppo, il valore di un attributo (anche più attributi) è costante in tutti i record.

### Esempio di raggruppamento

Consideriamo la seguente tabella STUDENTE:
- STUDENTE( Matricola, Nome, Cognome, Età, Sesso, ColoreCapelli)

<div align = "center"><p style="font-size: 24px;"><b>Svolgiamo e risolviamo le seguenti query: </b></p></div>

>[!TIP]
> **Query 1**: Indicare il numero di studenti biondi:
>```sql
>SELECT COUNT(*) AS NumeroStudentiBiondi
>FROM STUDENTE
>WHERE ColoreCapelli = 'Biondo';
>```

>[!NOTE]
> **Nota**: La query precedente non utilizza il raggruppamento, ma è un esempio di query semplice. Il risultato sarà un singolo valore che rappresenta il numero di studenti biondi.
---
>[!TIP]
> **Query 2**: Indicare il numero di studenti per ogni colore di capelli:
>```sql
>SELECT ColoreCapelli, COUNT(*) AS NumeroStudenti
>FROM STUDENTE
>GROUP BY ColoreCapelli;
>```

>[!NOTE]
> **Nota**: La query precedente utilizza il raggruppamento per contare il numero di studenti per ciascun colore di capelli. Il risultato sarà una tabella con due colonne: ColoreCapelli e NumeroStudenti.
---
>[!TIP]
> **Query 3**: Indicare il numero di studenti castani di ciascun sesso
>```sql
>SELECT Sesso, COUNT(*) AS NumeroStudentiCastani
>FROM STUDENTE
>WHERE ColoreCapelli = 'Castano'
>GROUP BY Sesso;
>```

>[!NOTE]
> **Nota**: La query precedente utilizza il raggruppamento per contare il numero di studenti castani per ciascun sesso. Il risultato sarà una tabella con due colonne: Sesso e NumeroStudentiCastani.
---
>[!TIP]
> **Query 4**: Indicare il numero di studenti per ciascun sesso e colore di capelli:
>```sql
>SELECT Sesso, ColoreCapelli, COUNT(*) AS NumeroStudenti
>FROM STUDENTE
>GROUP BY Sesso, ColoreCapelli;
>```

>[!NOTE]
> **Nota**: La query precedente utilizza il raggruppamento per contare il numero di studenti per ciascun sesso e colore di capelli. Il risultato sarà una tabella con tre colonne: Sesso, ColoreCapelli e NumeroStudenti.

>[!WARNING]
> **Attenzione**: Nel caso in cui, uno dei gruppi (per esempio: Bionde F) non esista un elemento appartenente a quel gruppo, il risultato della query non restituirà l'attributo Bionde F.
>
> In SQL, i **_GROUP BY_** non creano righe "vuote" per combinazioni mancanti — _**mostrano solo i gruppi esistenti nei dati**_.
---

## Raggruppamento e aggregazione

Consideriamo la seguente tabella MEDICO:

Medico (Matricola, Nome, Cognome, Specializzazione, Parcella)

>[!TIP]
> **Query 1**: Data ogni specializzazione, indicarne il nome e la parcella media dei medici:
>
> ```sql
>SELECT Specializzazione, Nome, Cognome, AVG(Parcella) AS ParcellaMedia
>FROM MEDICO
>GROUP BY Specializzazione, Nome, Cognome;
> ```

>[!NOTE]
> **Nota**: La query precedente utilizza il raggruppamento per calcolare la parcella media dei medici per ciascuna specializzazione. Il risultato sarà una tabella con tre colonne: Specializzazione, Nome, Cognome e ParcellaMedia.

>[!TIP] 
> **Query 2**: Indicare la parcella media dei medici di ciascuna specializzazione:
>
> ```sql
>SELECT Specializzazione, AVG(Parcella) AS ParcellaMedia
>FROM MEDICO
>GROUP BY Specializzazione;
> ```

>[!NOTE]
> **Nota**: La query precedente utilizza il raggruppamento per calcolare la parcella media dei medici per ciascuna specializzazione. Il risultato sarà una tabella con due colonne: Specializzazione e ParcellaMedia.
>
> L'operatore **_AVG_** calcola la media dei valori di una colonna numerica ed è applicato gruppo per gruppo
(calcola un valore riepilogativo per il gruppo!).
>
> La clausola **_“group by”_** permette di frammentare la tabella e su quello applicato "Specializzazione" assume lo stesso valore in un gruppo.

---

<div align = "center">

>[!IMPORTANT]
> ### Regola FONDAMENTALE per il raggruppamento:
> Quando si usa il raggruppamento OGNI gruppo genera UN SOLO record nel result set

</div>

---

## Raggruppamento e proiezione

>[!TIP]
> **Query 3**: Per ogni specializzazione, calcolare la parcella media dei suoi medici:
> ```sql
>SELECT Specializzazione, AVG(Parcella) AS ParcellaMedia
>FROM MEDICO
>GROUP BY Specializzazione;
> ```

>[!NOTE]
> **Nota**: La query precedente utilizza il raggruppamento per calcolare la parcella media dei medici per ciascuna specializzazione. Il risultato sarà una tabella con due colonne: Specializzazione e ParcellaMedia.

---


<div align="center"> 
    <h2> DOMANDA: </h2>
    <h5 style = "font-size: 20px;"> Si può non proiettare l’attributo di raggruppamento? </h5> 
</div>

No, in SQL standard non si può omettere l’attributo o gli attributi di raggruppamento nella clausola SELECT, a meno che non vengano usati in una funzione di aggregazione.

Quando si usa GROUP BY, tutti gli attributi che non sono usati in una funzione di aggregazione devono necessariamente essere presenti anche nel GROUP BY. Questo serve a garantire che i dati siano coerenti e che ogni riga rappresenti un gruppo ben definito.

>[!WARNING]
> ❌ Quella errata:
>```sql
>SELECT AVG(Parcella) AS ParcellaMedia
>FROM MEDICO
>GROUP BY Specializzazione;
>```
> - Perché manca Specializzazione nel SELECT, e quindi non sapresti a quale specializzazione corrisponde la media.

<br>

>[!TIP]
>✔️ Quella corretta:
>```sql
>SELECT Specializzazione, AVG(Parcella) AS ParcellaMedia
>FROM MEDICO
>GROUP BY Specializzazione;
>```
> - Perché include Specializzazione nel SELECT, quindi sai a quale specializzazione corrisponde la media.

---

### STIAMO ATTENTI...

Per ogni specializzazione medica, indicarne il nome, la parcella minima **_e il cognome del medico a cui appartiene_**

>[!WARNING]
>❌ Quella errata:
>```sql
>SELECT Specializzazione, MIN(Parcella) AS ParcellaMinima, Cognome
>FROM MEDICO
>GROUP BY Specializzazione;
>```
> - Perché Cognome non è aggregato (non connesso al medico) e non è presente nel GROUP BY, quindi SQL non sa a quale cognome si riferisce (in più non è **_NEMMENO COSTANTE_**).

>[!NOTE]
> #### COSA SIGNFICIA "NON COSTANTE"?
> - Significa che il cognome può variare all'interno dello stesso gruppo di specializzazione, quindi non è possibile determinare a quale cognome si riferisce la parcella minima.
> - In altre parole, non puoi semplicemente "prendere" il cognome da un gruppo senza specificare come vuoi che venga selezionato (ad esempio, il primo, l'ultimo, ecc.).

Vediamo sotto forma di tabella il risultato della query errata:

| Matricola | Nome | Cognome | Specializzazione | Parcella |
|-----------|------|---------|------------------|----------|
| 1         | Mario | Rossi   | Cardiologia      | 100      |
| 2         | Luca  | Bianchi | Cardiologia      | 150      |
| 3         | Anna  | Verdi   | Cardiologia      | 120      |
| 4         | Marco | Neri    | Ortopedia        | 200      |
| 5         | Sara  | Gialli  | Ortopedia        | 180      |

| Specializzazione | ParcellaMinima |
|------------------|----------------|
| Cardiologia      | 100            |
| Ortopedia        | 180            |

<h3> E COGNOME DOVE SI TROVA? </h3>

--- 

<div align = "center"> 

>[!IMPORTANT]
> #### La proiezione può contenere solo attributi presenti nel predicato di raggruppamento (perché sono i soli ad assumere un valore costante in ogni gruppo). Gli altri attributi proiettati devono essere argomento di funzioni di aggregazione!!!

</div>

RISOLVIAMO DUNQUE LA QUERY:

>[!TIP]
> ✔️ Quella corretta:
>```sql
>SELECT M.Specializzazione,
>       D.ParcellaMinima,
>       M.Cognome
>FROM Medico M
>    NATURAL JOIN
>    (
>        SELECT Specializzazione, MIN(Parcella) AS ParcellaMinima
>        FROM Medico
>        GROUP BY Specializzazione
>    ) AS D
>WHERE M.Parcella = D.ParcellaMinima;
>```
>- In questo caso, abbiamo creato una sottoquery (D) che calcola la parcella minima per ogni specializzazione e poi abbiamo unito questa sottoquery alla tabella MEDICO per ottenere il cognome del medico corrispondente alla parcella minima.

---

## Condizioni sui gruppi

>[!IMPORTANT]
> ### Definzione:
> Le condizioni sui gruppi sono espresse esclusivamente tramite operatori di aggregazione e permettono di scartare gruppi, qualora non siano soddisfatte.
>
> Vengono usati gli **_operatori di aggregazione_** perché esprimono una caratteristica di un gruppo, cioè globale, sommaria, riepilogativa degli attributi variabili (non di raggruppamento) dei record che lo compongono.

> [!WARNING]
> Le condizioni sui gruppi sono controllate gruppo per gruppo, non record per record.
> Quindi, se un gruppo non soddisfa la condizione, viene scartato interamente dal risultato finale.

### Esempio:

>[!TIP]
> **Query 1**: Indicare le specializzazioni della clinica con più di due medici:
>
> ```sql
>SELECT Specializzazione, COUNT(*) AS NumeroMedici
>FROM MEDICO
>GROUP BY Specializzazione
>HAVING COUNT(*) > 2;
> ```
> - In questo caso, la condizione HAVING filtra i gruppi in base al numero di medici per ciascuna specializzazione. Solo le specializzazioni con più di due medici saranno incluse nel risultato finale.

>[!WARNING]
> ### Ma il distinct serve?
> Non è necessario utilizzare **`DISTINCT`** in una query con **`GROUP BY`**, poiché l'attributo di raggruppamento (_**SPECIALIZZAZIONE**_) garantisce già che i risultati siano unici per ciascun gruppo e non ha senso parlare di duplicati.

---

>[!TIP]
> **Query 2**: Indicare le specializzazioni con la più alta parcella media:

>[!WARNING]
> ### ❌ ERRORE DA MATITA BLU:
> 
> ```sql
>SELECT Specializzazione
>FROM MEDICO
>GROUP BY Specializzazione
>HAVING MAX(AVG(Parcella)); -- ERRORE GRAVISSIMO
>```
> - Gli operatori di aggregazione non si annodano MAII! 
> - La clausola `HAVING` contiene sempre 2 parti connesse da un operatore di confronto (es. =, <, >, <=, >=, <>).

#### Come possiamo agire?

1. Media delle parcelle per ogni specializzazione
2. Calcolo della massima parcella media 
3. Specializzazioni con media parcelle uguale alla massima parcella media 

##### Step 1: Calcolare la media per ogni specializzazione

```sql
SELECT Specializzazione, AVG(Parcella) AS MediaParcelle
FROM Medico
GROUP BY Specializzazione;
```

##### Step 2: Calcolare la massima parcella media

```sql
SELECT MAX(D.MediaParcelle)
FROM (
    SELECT Specializzazione, AVG(Parcella) AS MediaParcelle
    FROM Medico
    GROUP BY Specializzazione
) AS D;
```

##### Step 3: Restituire le specializzazioni con la media massima

```sql
SELECT M.Specializzazione
FROM Medico M
GROUP BY M.Specializzazione
HAVING AVG(M.Parcella) = (
    SELECT MAX(D.MediaParcelle)
    FROM (
        SELECT M2.Specializzazione, AVG(M2.Parcella) AS MediaParcelle
        FROM Medico M2
        GROUP BY M2.Specializzazione
    ) AS D
);
```

> [!NOTE]
> ✔️ Questa query proietta **tutte le specializzazioni a pari merito** che hanno la massima parcella media!

---

## Condizioni sui gruppi vs. condizioni sui record

> [!TIP]
> 🔎 **Regola d’oro**:
>
> * Le **condizioni sui record** vanno in `WHERE`
> * Le **condizioni sui gruppi** (usano funzioni aggregate) vanno in `HAVING`

| Dove va la condizione? | Tipo                         | Quando si usa?           |
| ---------------------- | ---------------------------- | ------------------------ |
| `WHERE`                | Su singoli record            | Prima del raggruppamento |
| `HAVING`               | Su gruppi (usa aggregazioni) | Dopo il raggruppamento   |

---

### Esempio: Specializzazioni con più di 2 medici di Pisa

```sql
SELECT Specializzazione
FROM Medico
WHERE Citta = 'Pisa'
GROUP BY Specializzazione
HAVING COUNT(*) > 2;
```

* ✅ `WHERE Citta = 'Pisa'` ➔ scarta subito i medici non di Pisa (record)
* ✅ `HAVING COUNT(*) > 2` ➔ mantiene solo i gruppi con più di 2 medici (gruppi)

---

## Ordine di esecuzione di una query SQL

1. **FROM**
2. **WHERE**
3. **GROUP BY**
4. **HAVING**
5. **SELECT**

> [!NOTE]
> ✔️ Prima si selezionano i record (`WHERE`), poi si formano i gruppi (`GROUP BY`), poi si filtrano i gruppi (`HAVING`), e infine si proietta (`SELECT`).

---

## Common Table Expression (CTE)

* Una **CTE** crea un risultato temporaneo **con nome** usando `WITH`
* Utile per costruire passaggi intermedi
* Puoi creare anche più CTE contemporaneamente!

### Sintassi generale

```sql
WITH nome1 AS (query1),
     nome2 AS (query2),
     ...
SELECT ...
FROM nome1, nome2, ...;
```

---

### Esempio: Pazienti di Siena mai visitati da ortopedici

#### Step 1: Creo una CTE con i pazienti visitati da ortopedici

```sql
WITH pazienti_visitati_ortopedici AS (
    SELECT V.Paziente AS CodFiscale
    FROM Visita V
        INNER JOIN Medico M ON V.Medico = M.Matricola
    WHERE M.Specializzazione = 'Ortopedia'
)
SELECT COUNT(*)
FROM Paziente P
    NATURAL RIGHT OUTER JOIN pazienti_visitati_ortopedici PVO
WHERE PVO.CodFiscale IS NULL;
```

---

### Esempio avanzato: Uso di **2 CTE**

```sql
WITH ortopedici AS (
    SELECT M.Matricola AS Medico
    FROM Medico M
    WHERE M.Specializzazione = 'Ortopedia'
),
paz_visitati_ortopedici AS (
    SELECT V.Paziente AS CodFiscale
    FROM Visita V NATURAL JOIN ortopedici O
)
SELECT COUNT(*)
FROM Paziente P
    NATURAL LEFT OUTER JOIN paz_visitati_ortopedici PVO
WHERE P.Citta = 'Siena'
  AND PVO.CodFiscale IS NULL;
```

> [!NOTE]
> ✔️ Qui la seconda CTE (`paz_visitati_ortopedici`) **usa** la prima (`ortopedici`).
> La query finale conta i pazienti di Siena **mai visitati** da ortopedici.

---

## ✅ Riepilogo Lezione 3

| Concetto                          | Clausola SQL                         | Note                                  |
| --------------------------------- | ------------------------------------ | ------------------------------------- |
| Condizioni sui **record**         | `WHERE`                              | Prima del raggruppamento              |
| Condizioni sui **gruppi**         | `HAVING`                             | Dopo il raggruppamento, con aggregati |
| Calcolo media per gruppi          | `AVG()` + `GROUP BY`                 |                                       |
| Filtrare gruppi                   | `HAVING COUNT(*) > n`                |                                       |
| Proiezione valida                 | Solo attributi di gruppo + aggregati |                                       |
| **CTE (Common Table Expression)** | `WITH`                               | Definisce tabelle temporanee nominate |

---