<h1> Lezione 7 SQL - 15/05/2025 </h1>

<h1> Indice </h1>

- [Data Analytics](#data-analytics)
  - [Window Functions (aka Analytic Functions)](#window-functions-aka-analytic-functions)
    - [Che cosa sono?](#che-cosa-sono)
    - [Esempio:](#esempio)
  - [Clausola OVER](#clausola-over)
    - [Risolviamo l'esempio di prima grazie a OVER:](#risolviamo-lesempio-di-prima-grazie-a-over)
  - [Partition](#partition)
    - [Che cos'è:](#che-cosè)
    - [Esempio:](#esempio-1)
  - [Window functions non-aggregate](#window-functions-non-aggregate)
    - [Che cosa sono?](#che-cosa-sono-1)
    - [1. Funzione ROW\_NUMBER](#1-funzione-row_number)
    - [2. Funzione RANK](#2-funzione-rank)
      - [Esempio:](#esempio-2)
    - [3. Funzione DENSE\_RANK](#3-funzione-dense_rank)
      - [Esempio:](#esempio-3)
    - [4. Rank multipli](#4-rank-multipli)
      - [Esempio:](#esempio-4)
    - [5. Funzioni LEAD e LAG](#5-funzioni-lead-e-lag)
      - [5.1 Funzione LAG](#51-funzione-lag)
        - [Esempio:](#esempio-5)
      - [5.2 Funzione LEAD](#52-funzione-lead)
        - [Esempio:](#esempio-6)


---

# Data Analytics
- **Data Analytics**: è l'analisi dei dati per scoprire informazioni utili, informare le conclusioni e supportare la decisione.

## Window Functions (aka Analytic Functions)
### Che cosa sono?
Queste Analytic Functions affiancano a ogni record r un valore ottenuto da un'operazione (conteggio,media,rank...) eseguita su un insieme di record logicamente connessi a r.

### Esempio:

>[!TIP]
> Scrivere una query che indichi, per ogni cardiologo, la matricola, parcella e la parcella media della sua specializzazione.

>[!IMPORTANT]
> Ogni record del result set è un record della tabella Medico, tutti i record relativi ai cardiologi devono essere mantenuti, tuttavia, occorre anche applicare un operatore di aggragazione.

>[!WARNING]
> Non possiamo usare la clausola GROUP BY, in quanto non possiamo raggruppare i record della tabella Medico, ma dobbiamo mantenere tutti i record. Se la usassimo, perderemmo i record della tabella Medico.
>
>```sql
>SELECT AVG(M.Parcella)
>FROM Medico M
>WHERE M.Specializzazione = >'Cardiologo'
>```
>
> fa squash ed elimina i record originari e per calcolare la parcella media, si perdono i record della tabella Medico!

---

## Clausola OVER
La clausola OVER permette di definire una finestra di righe su cui eseguire l'operazione di aggregazione. La sintassi è la seguente:

```sql
SELECT <funzione_aggregazione>(<colonna>) OVER (<finestra>)
FROM <tabella>;
```

### Risolviamo l'esempio di prima grazie a OVER:

```sql
SELECT M.Matricola, 
       M.Parcella, 
       AVG(M.Parcella) OVER () AS Parcella_Media
FROM Medico M
WHERE M.Specializzazione = 'Cardiologo';
```

>[!IMPORTANT]
> **_OVER()_**: se over non ha contenuto,la partition è sempre la stessa per ogni record, e coincide con il result set della query senza la parte `AVG(M.Parcella) OVER () AS Parcella_Media`.

---

## Partition
### Che cos'è:

La partition è l’insieme di record a cui si applica una funzione aggregate/nonaggregate e **dipende dal record processato**

- Può essere definita anche su attributi non proiettati.

### Esempio:

>[!TIP]
>Scrivere una query che indichi, per ogni medico, la matricola, la specializzazione, la parcella, e la parcella media della sua specializzazione
> - non solo la cardiologia, ma tutte le specializzazioni

```sql
SELECT
         M.Matricola, 
         M.Specializzazione, 
         M.Parcella, 
         AVG(M.Parcella) OVER (
                                PARTITION BY M.Specializzazione
                                ) AS Parcella_Media
FROM Medico M;
```

> [!NOTE]
> **Esempio di tabella `Medico`:**
>
>| Matricola | Cognome | Specializzazione | Parcella |
>| --------- | ------- | ---------------- | -------- |
>| 101       | Rossi   | Cardiologia      | 200      |
>| 102       | Bianchi | Cardiologia      | 220      |
>| 103       | Verdi   | Ortopedia        | 180      |
>| 104       | Neri    | Ortopedia        | 170      |
>| 105       | Gialli  | Neurologia       | 210      |
>
>**Risultato della query:**
>
>| Matricola | Specializzazione | Parcella | Parcella\_Media |
>| --------- | ---------------- | -------- | --------------- |
>| 101       | Cardiologia      | 200      | 210.0           |
>| 102       | Cardiologia      | 220      | 210.0           |
>| 103       | Ortopedia        | 180      | 175.0           |
>| 104       | Ortopedia        | 170      | 175.0           |
>| 105       | Neurologia       | 210      | 210.0           |
>
> **Spiegazione:**
>
> * La query restituisce, per ogni medico, la sua **matricola**, la **specializzazione**, la sua **parcella**, e la **parcella media** dei medici con la stessa specializzazione.
> * La funzione **`AVG(M.Parcella) OVER (PARTITION BY M.Specializzazione)`** è una funzione finestra (`window function`) che calcola la **media delle parcelle** all'interno di ciascun gruppo di medici con la stessa specializzazione.
> * La clausola **`PARTITION BY`** suddivide il risultato in gruppi (partizioni) basati sulla colonna `Specializzazione`. All’interno di ogni gruppo, la funzione `AVG` calcola la media delle parcelle.
> * Questo approccio **mantiene tutte le righe** della tabella originale, affiancando a ciascuna riga il valore medio relativo alla specializzazione di riferimento.

---

## Window functions non-aggregate
### Che cosa sono?

Associano a ciascun record di un result set un valore ottenuto dalla partition senza fonderne i record in un’informazione riepilogativa
- come invece fanno le funzioni aggregate (count, sum, avg...)

### 1. Funzione ROW_NUMBER
- Restituisce il numero di riga di un record all’interno della sua partizione

### 2. Funzione RANK
- Restituisce il numero di riga di un record all’interno della sua partizione, ma se ci sono righe con lo stesso valore, assegna lo stesso numero di riga a tutte le righe con lo stesso valore e salta i numeri successivi.
- Serve per stilare una classifica dipendentemente da un criterio

#### Esempio:

>[!TIP]
> Classificare i medici in base alla loro convenienza. Restituire matricola, cognome, specializzazione, parcella e posizione in classifica.
> > parcelle basse hanno maggior convenienza, quindi rank migliori

```sql
SELECT
    M.Matricola,
    M.Cognome,
    M.Specializzazione,
    M.Parcella,
    RANK() OVER(
        ORDER BY M.Parcella
    )
FROM
    Medico M;
```

>[!WARNING]
> Non usiamo il PARTITION BY, perché vogliamo una classifica generale, non per specializzazione.

> [!NOTE]
> **Esempio di tabella `Medico`:**
> 
> | Matricola | Cognome | Specializzazione | Parcella |
> | --------- | ------- | ---------------- | -------- |
> | 201       | Bruni   | Cardiologia      | 250      |
> | 202       | Neri    | Ortopedia        | 180      |
> | 203       | Verdi   | Neurologia       | 210      |
> | 204       | Bianchi | Cardiologia      | 180      |
> | 205       | Rossi   | Ortopedia        | 300      |
> 
> **Risultato della query:**
> 
> | Matricola | Cognome | Specializzazione | Parcella | RANK |
> | --------- | ------- | ---------------- | -------- | ---- |
> | 202       | Neri    | Ortopedia        | 180      | 1    |
> | 204       | Bianchi | Cardiologia      | 180      | 1    |
> | 203       | Verdi   | Neurologia       | 210      | 3    |
> | 201       | Bruni   | Cardiologia      | 250      | 4    |
> | 205       | Rossi   | Ortopedia        | 300      | 5    |
>
> Possiamo notare che ci sono due persone che sono a pari merito (1° posto), quindi hanno lo stesso rank, e il rank successivo è 3, non 2 (RANK = H + K).
> - La funzione RANK() salta un numero di posizione della classifica pari al numero di ex aequo trovati.

### 3. Funzione DENSE_RANK
- Classifica i record come la funzione rank, ma in caso di ex aequo, la row che segue i record a pari merito assume rank immediatamente successivo
- In breve, se è presente un ex aequo, il prossimo rank non salta numeri, ma continua la numerazione.
- il dense rank è anche detto “rank senza gap”.

#### Esempio:

> [!TIP]
> Effettuare una classifica **senza gap** dei medici **per specializzazione**, ordinati in base alla **parcella decrescente** (dalla più alta alla più bassa).
> Restituire matricola, cognome, specializzazione, parcella e posizione nella classifica.
>
> Parcelle più alte corrispondono a rank migliori (più in alto).

```sql
SELECT
    M.Matricola,
    M.Cognome,
    M.Specializzazione,
    M.Parcella,
    DENSE_RANK() OVER (
        PARTITION BY M.Specializzazione
        ORDER BY M.Parcella DESC
    ) AS RANK
FROM
    Medico M;
```

> [!NOTE]
> **Esempio di tabella `Medico`:**
>
>| Matricola | Cognome | Specializzazione | Parcella |
>| --------- | ------- | ---------------- | -------- |
>| 201       | Bruni   | Cardiologia      | 250      |
>| 202       | Neri    | Ortopedia        | 180      |
>| 203       | Verdi   | Neurologia       | 210      |
>| 204       | Bianchi | Cardiologia      | 180      |
>| 205       | Rossi   | Ortopedia        | 300      |
>
> **Risultato della query:**
>
>| Matricola | Cognome | Specializzazione | Parcella | RANK |
>| --------- | ------- | ---------------- | -------- | ---- |
>| 201       | Bruni   | Cardiologia      | 250      | 1    |
>| 204       | Bianchi | Cardiologia      | 180      | 2    |
>| 205       | Rossi   | Ortopedia        | 300      | 1    |
>| 202       | Neri    | Ortopedia        | 180      | 2    |
>| 203       | Verdi   | Neurologia       | 210      | 1    |

### 4. Rank multipli
- Stilare una classifica dei medici in base al numero di visite effettuate.
Restituire cognome, specializzazione, numero di viste effettuate, posizione
nella classifica generale (ogni medico è confrontato con tutti gli altri), e posizione nella classifica per specializzazione (ogni medico è confrontato con quelli della sua specializzazione).

#### Esempio:
>[!TIP]
> Prendiamo il testo di prima:
```SQL
WITH visite AS (
    SELECT V.Medico, M.Cognome. M.Specializzazione, COUNT(*) AS Visite
    FROM Visita V
    INNER JOIN Medico M on V.Medico = M.Matricola
    GROUP BY V.Medico
)

SELECT VV.Cognome,
       VV.Specializzazione,
       VV.Visite,
       RANK() OVER (ORDER BY VV.Visite DESC) AS Rank_Generale,
       RANK() OVER (PARTITION BY VV.Specializzazione ORDER BY VV.Visite DESC) AS Rank_Specializzazione
FROM visite VV;
```

### 5. Funzioni LEAD e LAG
- Ricavano il valore (a sua volta può anche essere argomento di altre function) di un attributo di una row posta k posizioni prima (lag) o dopo (lead) la current row
  - Si presuppone un ordinamento sensato nella partition afiichè il "balzo" in avanti o indietro abbia un significato
#### 5.1 Funzione LAG
>[!IMPORTANT]
> ## Che cosa fa:
> Il LAG permette di affiancare a ogni record 'i' il valore di un record 'j' posizionato k posizioni prima del record i all'interno della partition associata a i.
> > Fa un balzo indietro nella partition di k rowsm dove il valore di k deve esere passato come secondo argomento della funzione, mentre il primo argomento è il nome dell'attributo del record j da restituire in uscita.

##### Esempio:
>[!TIP]
> Considerare le visite otorinolaringoiatriche dal 2010 al 2019, restituire, per ciascuna, matricola del medico, codice fiscale del paziente, data, e data della visita precedente del paziente con un medico della stessa specializzazione.

```sql
SELECT 
    V.Medico,
    V.Paziente,
    V.'Data',
    LAG(V.'Data',1) OVER(
        PARTITION BY V.Paziente
        ORDER BY V.'Data'
    )
FROM Visita V INNER JOIN Medico M ON V.Medico = M.Matricola
WHERE M.Specializzazzione = 'Otorinolaringoiatria'
AND YEAR(V.'Data') BETWEEN 2010 AND 2019;
```
>[!WARNING]
> Nella riga `LAG(V.'Data',1)` significa che k = 1, quindi si va indietro di una sola row e si affianca alla current row (i) la data della visita j posta nella posizione (i-k). 

#### 5.2 Funzione LEAD
>[!IMPORTANT]
> ## Che cosa fa:
> Permette di affiancare a ogni record i il valore di un record j posizionato k posizioni dopo il record i all’interno della partition associata a i
> > Fa un balzo in avanti nella partition di k rows, dove il valore di k deve essere passato come secondo argomento della funzione, mentre il primo argomento è il nome dell'attributo del record j da restituire in uscita.

##### Esempio:
>[!TIP]
>Considerare le visite otorinolaringoiatriche dal 2010 al 2019, restituire, per ciascuna, matricola del medico, codice fiscale del paziente, data, e data della visita successiva del paziente con un medico della stessa specializzazione

```sql
SELECT 
    V.Medico,
    V.Paziente,
    V.'Data',
    LEAD(V.'Data',1) OVER(
        PARTITION BY V.Paziente
        ORDER BY V.'Data'
    )
FROM Visita V INNER JOIN Medico M ON V.Medico = M.Matricola
WHERE M.Specializzazzione = 'Otorinolaringoiatria'
AND YEAR(V.'Data') BETWEEN 2010 AND 2019;
```

---