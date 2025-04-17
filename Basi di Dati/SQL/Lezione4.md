<h1> Lezione 4 SQL - 16/04/2025 </h1>

<h1> Indice </h1>


---

## SubQuery

Le subquery sono un'alternativa al JOIN, ma senza usare il JOIN, per query su più tabelle (a volte sono più semplici da capire e da scrivere). Sono query che possono essere incapsulate in un’altra query.

Struttura: Query ESTERNA + Query INTERNA = query con Subquery

### Non-correlated subquery: 

>[!IMPORTANT]
> #### Che cosa sono?
> Una non-correlated subquery è una sottoquery che può essere eseguita indipendentemente dalla query esterna. 
>
> > In breve... I record ottenuti dalla subquery non dipendono dalla outer query.

Il risultato della Noncorrelated subquery possiamo definirlo così:

Un record fa parte del risultato (quello che vede l'utente - risultato outer query) se i valori che assume su un sottoinsieme di attributi si torva anche in (almeno) un record del result set della subquery.

#### Esempio:

>[!TIP]
> Indicare nome, cognome e parcella degli ortopedici che hanno effettuato almeno una visista nell'anno 2013

```sql
-- Outer Query
SELECT M.nome, M.cognome, M.parcella
FROM Medico M
WHERE M.Specializzazione = 'Ortopedia'
    AND M.Matricola IN ( -- L'IN permette di controllare la presenza matricola 
                         -- della all'interno del risultato della subquery
        -- Subquery
        SELECT V.Medico
        FROM Visita V
        WHERE YEAR(V.Data) = 2013
    );
```

### Negazione della subquery
>[!IMPORTANT]
> #### Che cos'è?
> Usando NOT IN un record della outer query va nel risultato
solo se non è presente nel result set della subquery.

>[!WARNING]
> IN controlla che il record sia anche nel risultato
della subquery, mentre NOT IN che non ci sia

#### Esempio 2:

>[!TIP]
> Indicare i cognomi dei pazienti che non appartengono anche a un medico

```sql
SELECT DISTINCT P.cognome
FROM Paziente P
WHERE P.Matricola NOT IN (
                         SELECT M.Cognome
                         FROM Medico M
                         );
```

#### Esempio 3:

>[!TIP]
> Indicare nome, cognome e specializzazione dei medici che hanno effettuato visite eccetto che il giorno 1° Marzo 2013

```sql
SELECT M.nome, M.cognome, M.specializzazione
FROM Medico M
WHERE M.Matricola NOT IN (
                         SELECT V.Medico
                         FROM Visita V
                         WHERE V.Data = '2013-03-01' -- ERRORE - se un medico non ha effetuato alcuna visita va nel risultato!
                         );
```

```sql
-- Soluzione corretta

SELECT M.nome, M.cognome, M.specializzazione
FROM Medico M
WHERE M.Matricola IN (
                      SELECT V.Medico
                      FROM Visita V                     
                     )
            AND M.Matricola NOT IN (
                                    SELECT V.Medico
                                    FROM Visita V
                                    WHERE V.Data = '2013-03-01'
                                   );
-- Se un medico nnon ha effettuato alcuna visita non va nel risultato
```

---

## Versione Join-equivalente

>[!IMPORTANT]
> #### Che cos'è?
> Data una query con subquery è SEMPRE possibile passare alla versione basata su join, e viceversa. 
>
> Il query optimizer sfrutta questa equivalenza per riscrivere le query il cui codice avrebbe bassa performance.

#### Esempio:

>[!TIP]
Indicare nome, cognome e specializzazione dei medici che hanno 
effettuato visite eccetto che il giorno 1° Marzo 2013

<div style="display: flex; justify-content: space-between; gap: 2%;">

<div style="width: 48%;">

### Query con Subquery

```sql
-- Con Subquery
SELECT M.nome, M.cognome, M.specializzazione
FROM Medico M
WHERE M.Matricola IN (
    SELECT V.Medico
    FROM Visita V
)
AND M.Matricola NOT IN (
    SELECT V.Medico
    FROM Visita V
    WHERE V.Data = '2013-03-01'
);

```

</div> <div style="width: 48%;">

### Query con Join

```sql
-- Con Join-equivalente
SELECT M.nome, M.cognome, M.specializzazione
FROM Visita V
INNER JOIN Medico M ON V.Medico = M.Matricola
LEFT OUTER JOIN (
    SELECT *
    FROM Visita
    WHERE Data = '2013-03-01'
) AS D ON V.Medico = D.Medico
WHERE D.Medico IS NULL;
```
</div>
</div>

>[!WARNING]
> ## Ma quando devo usare il join al posto delle subquery?
> Il join va usato al posto delle subquery perché i join sono più efficenti e leggibili dai codificatori.

| | Join | Subquery |
|---|---|---|
| **Vantaggi** | Efficiente, leggibile per esperti | Può essere più semplice da scrivere e capire per chi non ha esperienza |
| **Svantaggi** | Non sempre possibile in alcuni casi | Può essere difficile da leggere e avere presatazioni non ottimali

---

## Annidamento multiplo

>[!IMPORTANT]
> #### Che cos'è?
> Non c'è limite (teoricamente) al numero che si possono annidare l'una nell'altra.

#### Esempio:

>[!TIP]
> Indicare il numero di pazienti di Siena, mai visitati da ortopedici

```sql
SELECT COUNT(*)
FROM Paziente P
WHERE P.Comune = 'Siena'
    AND P.Matricola NOT IN (
        SELECT V.Paziente
        FROM Visita V
        WHERE V.Medico IN (
            SELECT M.Matricola
            FROM Medico M
            WHERE M.Specializzazione = 'Ortopedia'
        )
    );
```

### Visibilità:

In una subquery si possono riferire tutti gli attrivuti delle query esterne, a qualsiasi liveloo di annidamento esterno essi si trovino (SI ESCE MA NON SI ENTRA).

---

## Subquery vs Subquery scalari

- **_SUBQUERY_**: produce un insieme di
record, si lega alla
query esterna mediante
IN o NOT IN.
Se produce un solo
record si usa = o <>.

- **_SUBQUERY SCALARE_**: produce un unico record
con un unico attributo.
Se è numerico, si usano
<, <=, =, >=, >, <>
per il confronto con i
record della query esterna.

#### Esempio:

>[!TIP]
> Indicare il numero degli otorini aventi parcella più alta della media delle parcelle dei medici della loro specializzazione.

```sql
SELECT COUNT(*)
FROM Medico M1
WHERE M1.Specializzazione = 'Otorinolaringoiatria'
    AND M1.Parcella > (
        SELECT AVG(M2.Parcella)
        FROM Medico M2
        WHERE M2.Specializzazione = 'Otorinolaringoiatria'
    );
-- La query restituisce un numero!
```

---

#### Esempio:

>[!TIP]
> Indicare qual è il reddito massimo, e il nome e cognome di chi lo detiene

>[!WARNING]
>### ERRORI BLU:
>
> ```sql
> SELECT MAX(Reddito), Nome, Cognome
>FROM Paziente;
>-- errore grave nello scrivere in MAX(reddito)
>```
>
>```sql
>SELECT, Nome, Cognome
>FROM Paziente
>WHERE Reddito = 
>    MAX(Reddito);
>
>-- errore grave nello scrivere in MAX(reddito) - MAX deve essere preceduto da un SELECT.
>```

>[!NOTE]
> ### Soluzione:
> ```sql
> SELECT Reddito, Nome, Cognome
> FROM Paziente
> WHERE Reddito = (
>     SELECT MAX(Reddito)
>     FROM Paziente
> );
> ```
>
> è l'unico modo corretto di risolvere il problema del record correlato al valore massimo su un attributo

---

## Correlated subquery

>[!IMPORTANT]
> #### Che cos'è?
> Una correlated subquery è una sottoquery che dipende dalla query esterna.
> > In breve... Il loro risultato dipende da ciascuna tupla della query esterna
>
> simile al concetto simile a una chiamata di funzione

#### Esempio:

>[!TIP]
> Indicare la matricola dei medici che hanno visitato per la prima volta almeno un paziente nel mese di Ottobre 2013

```sql
-- Query esterna (visite di Ottobre 2013)
SELECT DISTINCT V1. Medico
FROM Visita V1
WHERE YEAR(V1.Data) = 2013
    AND MONTH(V1.Data) = 10
    AND V1.Paziente NOT IN (SELECT V2.Paziente -- correlated subquery (eseguita per ogni tupla selezionata dalla query esterna)
                            FROM Visita V2
                            WHERE V1.Medico = V2.Medico
                                AND V2.Data < V1.Data);
```

>[!NOTE]
> Una correlated subquery è eseguita PER OGNI record della query esterna e il suo risultato ne dipende.

---

## Costrutto EXIST - NOT EXISTS

>[!IMPORTANT]
> ### Che cos'è?
> Il costrutto EXISTS è un operatore logico che restituisce TRUE se la subquery produce almeno un record, FALSE altrimenti.
> > In breve... Se la subquery produce almeno un record, il costrutto EXISTS è TRUE, altrimenti è FALSE.

#### Esempio:

>[!TIP]
> Una visita di controllo è una visita in cui un medico visita un paziente già visitato precedentemente almeno una volta. Indicare medico, paziente e data delle visite di controllo del mese di Gennaio 2016.

```sql
SELECT V1.Medico, V1.Paziente, V1.Data
FROM Visita V1
WHERE MONTH(V1.Data) = 1
    AND YEAR(V1.Data) = 2016
    AND EXISTS (SELECT *
                FROM Visita V2
                WHERE V2.Medico = V1.Medico
                    AND V2.Paziente = V1.Paziente
                    AND V2.Data < V1.Data);
```

>[!NOTE]
> ∃ i record del risultato hanno almeno un record nel result set della subquery

#### Esempio 2:

>[!TIP]
> Indicare la matricola dei medici che hanno visitato per la prima volta almeno un paziente nel mese di Ottobre 2013

```sql
SELECT DISTINCT V1.Medico
FROM Visita V1
WHERE YEAR(V1.Data) = 2013
    AND MONTH(V1.Data) = 10
    AND NOT EXISTS (SELECT *
                    FROM Visita V2
                    WHERE V2.Medico = V1.Medico
                        AND V2.Paziente = V1.Paziente
                        AND V2.Data < V1.Data);
```

>[!NOTE]
> ¬∃ i record del risultato hanno il result set della subquery vuoto

---


## Divisione

>[!IMPORTANT]
> ### Che cos'è?
> La divisione è un'operazione che permette di ottenere i record di una tabella che sono associati a **_tutti i record_** di un'altra tabella.
>
> In dettaglio... la divisione è un operatore insiemistico derivato utile per interrogazioni che contengono condizioni esaustive espresse mediante l’avverbio **_tutti_**.

#### Esempio:

>[!TIP]
> Indicare i pazienti visitati da tutti i medici

```sql
SELECT P.CodFiscale
FROM Paziente P
WHERE NOT EXISTS
(
    SELECT *
    FROM Visita V
    WHERE V.Medico = M.Matricola
        AND V.Paziente = P.CodFiscale
)

>[!NOTE]
> Prendi ogni paziente P per il quale non trovi nemmeno un medico M che non abbia visitato P (cioè nemmeno un medico qui).

