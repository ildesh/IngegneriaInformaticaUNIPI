# Lezione 1 - 27/03/2025

## Gestione delle date

>[!IMPORTANT]
> ### Cos'è una data in MySQL
>
>Una data è il tempo che intercorre tra due eventi. In MySQL, una data è rappresentata come un valore di tipo DATE, che può essere utilizzato per memorizzare informazioni relative a date e orari. 

Le date in SQL posso essere rappresentate in due modi:

- Dateformat: YYYY-MM-DD (es. 2025-03-27)
- Timestamp: YYYY-MM-DD HH:MM:SS (es. 2025-03-27 14:30:00)

>[!NOTE]
>In MySQL, è possibile "manipolare" una data mediante la funzione DATE_FORMAT (utile per usare alcune funzioni di utlità, o per effettuare parsing di stringhe in date).

### Alcuni formati utili:

| Formato | Descrizione |
|---------|-------------|
| %Y      | Anno a 4 cifre |
| %y      | Anno a 2 cifre |
| %M     | Nome del mese (es. Gennaio) |
| %m      | Mese a 2 cifre (01-12) |
| %d      | Giorno del mese (01-31) |
| %W     | Nome del giorno della settimana (es. Lunedì) |
| %w      | Giorno della settimana (0-6, 0 = Domenica) |
| %T      | Orario (HH:MM:SS) |

#### Esempio di utilizzo di DATE_FORMAT:

>[!TIP]
>Indicare matricola e data di laurea (nel formato 'dd|mm|yyyy, nome_giorno') degli studenti iscritti prima del 2005:

```sql
SELECT Matricola, DATE_FORMAT(DataLaurea, '%d/%m/%Y, %W')
FROM Studente
WHERE DataIscrizione < '2005-01-01';
```

In questo esempio, la funzione DATE_FORMAT viene utilizzata per formattare la data di laurea in un formato più leggibile (giorno/mese/anno, giorno della settimana).

| <u>Matricola</u> | DATE_FORMAT(DataLaurea, '%d/%m/%Y, %W')|
|-----------|----------------------------------------|
| 123456    | 27/03/2025, Giovedì                    |
| 654321    | 15/05/2025, Sabato                     |
| 789012    | 01/01/2025, Lunedì                     |
| 345678    | 10/10/2025, Martedì                    |
| 234567    | 20/12/2025, Mercoledì                   |



#### Un altro esempio...

>[!TIP]
>Indichiamo la matricola degli srudenti che si sono laureati di mercoledì:

```sql
SELECT Matricola
FROM Studente
WHERE DATE_FORMAT(DataLaurea, '%w') = 3;
```
In questo esempio, la funzione DATE_FORMAT viene utilizzata per estrarre il giorno della settimana dalla data di laurea e confrontarlo con il valore 3 (mercoledì).

| <u>Matricola</u> |
|-----------|
|234567|

---

### Condizioni con le date: confronti

>[!TIP]
>Si possono usare gli operatori di confronto per confrontare le date. Ad esempio:

```sql
SELECT Matricola, DataLaurea
FROM Studente
WHERE DataLaurea > '2022-01-01' AND DataLaurea < '2025-12-31';
```

---

### Estrazione di giorno, mese e anno da una data

>[!IMPORTANT]
>Le funzioni DAY, MONTH e YEAR prendono come argomento una data e ne restituiscono, rispettivamente, giorno, mese e anno (<i>espressi come numeri interi</i>).

```sql
SELECT Matricola, YEAR(DataLaurea) AS Anno, MONTH(DataLaurea) AS Mese, DAY(DataLaurea) AS Giorno
FROM Studente
WHERE DataLaurea > '2022-01-01' AND DataLaurea < '2025-12-31';
```

In questo esempio, le funzioni YEAR, MONTH e DAY vengono utilizzate per estrarre rispettivamente l'anno, il mese e il giorno dalla data di laurea.

| <u>Matricola</u> | Anno | Mese | Giorno |
|-----------|------|------|--------|
| 123456    | 2025 | 03   | 27     |
| 654321    | 2025 | 05   | 15     |
| 789012    | 2025 | 01   | 01     |
| 345678    | 2025 | 10   | 10     |
| 234567    | 2025 | 12   | 20     |

#### Esempio:

>[!TIP]
>Indicare matricola e mese di laurea degli studenti immatricolati dopo il 2000:

```sql
SELECT Matricola, MONTH(DataLaurea)
FROM Studente
WHERE DataLaurea IS NOT NULL 
    AND YEAR(DataIscrizione) > 2000;
```

In questo esempio, la funzione MONTH viene utilizzata per estrarre il mese dalla data di laurea. La condizione YEAR(DataIscrizione) > 2000 filtra gli studenti immatricolati dopo il 2000.

|<u>Matricola</u>|MONTH(DataLaurea)|
|----------|----------------|
|  1282    |       04       |

#### Esempio:

>[!TIP]
>Indicare il cognome degli sudenti che si sono laureati cinque anni fa

>[!WARNING]
> ### Attenzione: 
>La query deve esprimere
la condizione «cinque anni fa»,
indipendentemente da quando viene eseguita.

Faccio una sorta di _balzo nel passato_ e mi chiedo:

<div align="center">
<p><i>Quale data era cinque anni fa? Di quanto dobbiamo tornare indietro?</i></p>
</div>

```sql
SELECT DISTINCT Cognome
FROM Studente
WHERE DataLaurea IS NOT NULL 
    AND YEAR(DataLaurea) = YEAR(CURRENT_DATE) - 5;
```

>[!NOTE]
> _CURRENT_DATE_ è una variabile di sistema che restituisce la data odierna. 

---

### Lasso di tempo

>[!WARNING]
> ### Attenzione:
> Le date in MySQL non possono essere sottratte tramite l’operatore classico ‘ - ’, ma occorre usare **_DATEDIFF()_** (numeri di giorni che intercorrono tra due date).

#### Lassi di tempo in giorni: esempio

>[!TIP]
>Indicare matricola e **_da quanti giorni risultavano iscritti gli studenti_**,
ad oggi laureati, che non si erano ancora laureati il 15 Luglio 2005

```sql
SELECT Matricola, DATEDIFF('2005-07-15', DataIscrizione)
FROM Studente
WHERE DataIscrizione < '2005-07-15'
    AND DataLaurea > '2005-07-15';
```

In questo esempio, **_la funzione DATEDIFF calcola il numero di giorni tra la data1 '2005-07-15' e la data di iscrizione degli studenti (data2)_** e la condizione **_WHERE_** filtra gli studenti che si sono iscritti prima del 15 luglio 2005 e si sono laureati dopo quella data.

>[!NOTE]
> #### Nel caso in cui DataLaurea fosse NULL?
> In questo caso, la condizione **_DataLaurea > '2005-07-15'_** non verrebbe soddisfatta e quindi non verrebbe restituito alcun risultato.

>[!WARNING]
>### Attenzione:
> ```yaml
>NULL == NULL  →  FALSE
>NULL != NULL  →  FALSE
> ```
> Questo perché NULL non è un valore, ma un indicatore di assenza di valore > e quindi non possiamo confrontare il nulla con il nulla.

---

### Sommare/sottrarre intervalli di tempo

Le funzioni **_DATE_ADD_** e **_DATE_SUB_** _(che da come risultato una nuova data)_ permettono di sommare o sottrarre intervalli di tempo _(espressi con la keyword INTERVALL)_ a una data.

```sql
INTERVAL 'Numero Intero' [ YEAR | MONTH | DAY ]
```

#### Esempio:

>[!TIP]
>Indicare la matricola e il mese di iscrizione degli studenti che si sono laureati dopo cinque anni esatti dal giorno dell’iscrizione

```sql
SELECT Matricola, MONTH(DataIscrizione)
FROM Studente
WHERE DataLaurea = DATE_ADD(DataIscrizione, INTERVAL 5 YEAR);
```

>[!NOTE]
> Non importa aggiungere anche DataLaurea IS NOT NULL, perché la condizione di uguaglianza tra DataLaurea e DataIscrizione + 5 anni implica che DataLaurea non sia NULL e quindi gli ultimi record con DataLaurea = NULL vengono già scartati.

Se volessimo mettere IS NOT NULL...

```sql
SELECT Matricola, MONTH(DataIscrizione)
FROM Studente
WHERE DataLaurea IS NOT NULL 
    AND DataLaurea = DataIscrizione + INTERVAL 5 YEAR;
```

>[!WARNING]
>### Attenzione:
>**_La somma e la sottrazione si fanno sempre con una data e un INTERVAL_**, mai fra due date

#### Altre funzioni di utilità sulle date:

| Funzione | Descrizione |
|----------|-------------|
| **_dayname()_** | Restituisce il nome del giorno della settimana per una data specificata |
|**_monthname()_** | Restituisce il nome del mese per una data specificata |
|**_dayofweek()_** | Restituisce il numero del giorno della settimana (1 = Domenica, 7 = Sabato) per una data specificata |
| **_weekday()_** | Restituisce il numero del giorno della settimana (0 = Lunedì, 6 = Domenica) per una data specificata |
| **_last_day()_** | Restituisce l'ultimo giorno del mese per una data specificata |
|**_dayofyear()_** | Restituisce il numero del giorno dell'anno (1-366) per una data specificata |
|**_weekofyear()_** | Restituisce il numero della settimana dell'anno (1-53) per una data specificata |
|**_yearweek()_** | Restituisce il numero dell'anno e della settimana (YYYYWW) per una data specificata |

---

### Operatori di aggregazione

>[!IMPORTANT]
> ### Cos'è un operatore di aggregazione?
> Un operatore di aggregazione è una funzione che opera su un insieme di valori e restituisce un singolo valore. Gli operatori di aggregazione più comuni in SQL sono:

In breve... Permettono di eseguire calcoli _(conteggio, somma, minimo/massimo, media)_ i cui operandi sono i valori assunti da un attributo, in un insieme di record _(collassa in un solo record formato da un solo attributo numerico)_

#### Conteggio: esempio

>[!TIP]
> Indicare il numero di visite effettuate in data 1° Marzo 2013

```sql
SELECT COUNT(*) AS VisitePrimoMarzo
FROM Visita
WHERE DataVisita = '2013-03-01';
```
In questo esempio, **la funzione COUNT conta il numero di righe nella tabella _Visita_ in cui la data della visita è il 1° marzo 2013**. 

L'asterisco (*) indica che vogliamo contare tutte le righe che soddisfano la condizione. La condizione **_WHERE_** filtra le righe in base alla data specificata.

Il risultato **_viene restituito con l'alias_** "VisitePrimoMarzo" (_Ridenominazione parlando di calcolo relazionale_).

| Medico  | Paziente | Data      |
|---------|---------|------------|
| 413563  | GBLDRDS | 2013-03-01 |
| 298741  | MKLJHGF | 2013-03-11 |
| 562314  | QWERTYU | 2013-06-01 |
| 874125  | ASDFGHJ | 2013-06-21 |
| 659874  | ZXCVBNM | 2013-02-10 |

|VisitePrimoMarzo|
|----------------|
|       2        |


### Conteggio su un attributo

Permette di contare i valori diversi assunti da un attributo (o più attributi) in un insieme di record

>[!TIP]
Indicare il numero di pazienti visitati nel mese di Marzo 2013

```sql
SELECT COUNT(DISTINCT Paziente) AS PazientiMarzo
FROM Visita
WHERE MONTH(Data) = '03'
    AND YEAR(Data) = '2013';
```

| Medico | Paziente | Data       |
|--------|----------|------------|
| 35512  | GTTFBL   | 2013-03-01 |
| 18339  | CPRLND   | 2013-03-01 |
| 35512  | LPRNTA   | 2013-03-01 |
| 35512  | CPRLND   | 2013-03-01 |


| PazientiMarzo |
|----------------|
|       3        |

>[!NOTE]
> #### DISTINCT
> In questo esempio, possiamo notare che uno stesso paziente è stato visitato più volte nel mese di marzo 2013.
> 
> Per evitare di contare più volte lo stesso paziente (evitando quindi di avere 4 visite sulla tabella _**PazientiMarzo**_), utilizziamo la parola chiave DISTINCT per contare solo i pazienti unici visitati nel mese di marzo 2013.
> 
> La parola chiave DISTINCT viene utilizzata per restituire solo i valori unici (diversi) per l'attributo specificato. In questo caso, stiamo contando solo i pazienti unici visitati nel mese di marzo 2013.

---

### Somma e Media

>[!IMPORTANT]
> ### Cos'è la somma e la media?
> La somma è l'operazione di addizione di un insieme di valori, mentre la media è il risultato della somma diviso il numero totale di valori.
> 
>  In SQL, possiamo utilizzare le funzioni **_SUM_** e **_AVG_** per calcolare rispettivamente la somma e la media di un attributo numerico.

#### Somma: esempio

>[!TIP]
>Supponendo che Umberto Manzi sia il marito di Antonella Lepre, calcolare il reddito totale della famiglia Manzi.

Ecco dei dati della tabella **_PAZIENTE_** per l'esempio:

| CodFiscale | Cognome | Nome     | DataNascita | Reddito |
|------------|---------|----------|-------------|---------|
| LPRNTA     | Lepre   | Antonella| 1958-05-03  | 1200    |
| GTTFBL     | Gatto   | Fabiola | 1983-10-30  | 1400    |
| MNZMBT     | Manzi   | Umberto | 1949-07-12  | 1350    |
| CPRLND     | Capra   | Leonardo | 1967-09-20  | 1600    |

```sql
SELECT SUM(Reddito) AS RedditoTotale
FROM PAZIENTE
WHERE (Cognome = 'Lepre'
    AND Nome = 'Antonella')
    OR 
    (Cognome = 'Manzi' 
    AND Nome = 'Umberto');
```

| RedditoTotale  |
|----------------|
|       2550     |

#### Media: esempio

>[!TIP]
>Calcolare il reddito medio dei pazienti nati dopo il 1950

```sql
SELECT AVG(Reddito) AS RedditoMedio
FROM PAZIENTE
WHERE DataNascita > '1950-12-31';
```

| RedditoMedio |
|--------------|
|     1400     |

---

### Minimo e Massimo

>[!IMPORTANT]
> ### Cos'è il minimo e il massimo?
> Il minimo è il valore più basso in un insieme di valori, mentre il massimo è il valore più alto. 
> 
> In SQL, possiamo utilizzare le funzioni **_MIN_** e **_MAX_** per calcolare rispettivamente il minimo e il massimo di un attributo numerico in un insieme di record.

#### Esempio di minimo e massimo:

>[!TIP]
> Ricavare il reddito massimo/minimo fra quelli di tutti i pazienti

```sql
SELECT MIN(Reddito) AS RedditoMinimo
FROM PAZIENTE;
```

```sql
SELECT MAX(Reddito) AS RedditoMassimo
FROM PAZIENTE;
```

<div style="border: 4px solid #fff; border-radius: 10px; padding: 10px; margin: 30px; display: flex; gap: 50px; align-items: center; justify-content: space-evenly;">
  <table style="color: white; padding: 10px; border-collapse: collapse;">
    <tr>
      <th>RedditoMinimo</th>
    </tr>
    <tr>
      <td>1200</td>
    </tr>
  </table>
  
  <table style="color: white; padding: 10px; border-collapse: collapse;">
    <tr>
      <th>RedditoMassimo</th>
    </tr>
    <tr>
      <td>1600</td>
    </tr>
  </table>
</div>


>[!WARNING]
>### Attenzione:
> Se ci chiedono, ad esempio:
> 
> Indicare qual è il reddito massimo, e il nome e cognome di chi lo detiene
>
> Scrivere:
>
>```sql
>SELECT MAX(Reddito), Nome, Cognome
>FROM Paziente;
>```
> E' sbagliato, perché:
> 1. Uso di MAX(Reddito) in una selezione con altre colonne:
>       1. La funzione MAX() è una funzione di aggregazione che restituisce un singolo valore: il massimo del reddito. Tuttavia, quando si usa una funzione di aggregazione (come MAX(), SUM(), etc.), tutte le altre colonne devono essere aggregate o essere raggruppate usando GROUP BY se vogliamo restituire più di un valore.
>       2. Nel caso della query errata, abbiamo MAX(Reddito) ma anche Nome e Cognome, che sono colonne che contengono valori diversi per ogni riga. SQL non sa come aggregare questi valori con MAX(Reddito) e quindi restituirà un errore o, a seconda del sistema di gestione del database (DBMS), potrebbe restituire un risultato inatteso o errato.
> 2. Eliminazione dei dati:
>       1. Se il DBMS non restituirà un errore, ciò che accadrà è che la query cercherà di restituire il massimo del reddito e per ogni massimo restituito, un nome e cognome casuale da tutta la tabella, senza alcuna connessione con il massimo reddito. Questo non ha alcun senso logico e non soddisfa la richiesta di identificare la persona con il reddito massimo.
>
> 3. La query corretta:
> ```sql
> SELECT Nome, Cognome, Reddito
>FROM Paziente
>WHERE Reddito = (SELECT MAX(Reddito) FROM Paziente);
> ```
>
>Questa query restituirà il nome, il cognome e il reddito della persona o delle persone che hanno il reddito massimo. In caso di più persone con lo stesso reddito massimo, verranno restituite tutte le righe corrispondenti.