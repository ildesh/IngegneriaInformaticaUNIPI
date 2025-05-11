 <h1> Lezione 1 - 27/03/2025 </h1>

---

<h1> Indice  </h1>

* [Cos’è un database relazionale](#cosè-un-database-relazionale)
  * [Chiavi primarie e chiavi esterne](#chiavi-primarie-e-chiavi-esterne)
  * [RDBMS e proprietà ACID](#rdbms-e-proprietà-acid)
* [Introduzione a SQL](#introduzione-a-sql)
  * [Esempio di query SQL](#esempio-di-query-sql)
  * [Best practice di base](#best-practice-di-base)
* [Clausole e operatori in SQL](#clausole-e-operatori-in-sql)
  * [Flusso logico di una query SQL](#flusso-logico-di-una-query-sql)
  * [Errori comuni da evitare](#errori-comuni-da-evitare)
* [Gestione delle date in SQL](#gestione-delle-date-in-sql)
  * [Best practice con le date](#best-practice-con-le-date)
* [Operatori di aggregazione](#operatori-di-aggregazione)
  * [Funzioni aggregate principali](#funzioni-aggregate-principali)
  * [Best practice e avvertenze](#best-practice-e-avvertenze)
* [JOIN e relazioni](#join-e-relazioni)
  * [Tipi di JOIN](#tipi-di-join)
  * [Errori comuni sui JOIN](#errori-comuni-sui-join)
* [Valori NULL](#valori-null)
  * [Regole e comportamento dei NULL](#regole-e-comportamento-dei-null)
  * [Best practice sui NULL](#best-practice-sui-null)
* [Sottoquery](#sottoquery)
  * [Esempio di sottoquery semplice](#esempio-di-sottoquery-semplice)
  * [Sottoquery scalari vs set-oriented](#sottoquery-scalari-vs-set-oriented)
  * [Sottoquery correlate](#sottoquery-correlate)
  * [Suggerimenti e avvertenze](#suggerimenti-e-avvertenze)
  * [Esempio riassuntivo](#esempio-riassuntivo)
* [Collegamenti tra concetti SQL](#collegamenti-tra-concetti-sql)

---

## Cos’è un database relazionale

Un **database** è una raccolta organizzata di dati strutturati per consentire il recupero, l’aggiornamento e la gestione efficiente dell’informazione. Nei database relazionali i dati sono memorizzati in **tabelle** formate da righe e colonne; ogni riga rappresenta un record e ogni colonna un attributo (campo) del dato. Le **tabelle** possono essere correlate tra loro tramite chiavi, permettendo di modellare relazioni complesse: per esempio una tabella *Clienti* (con colonne *ID\_cliente*, *Nome*, *Settore*, …) può essere unita a una tabella *Transazioni* (con colonne *ID\_transazione*, *ID\_cliente*, *Data*, *Importo*, …) attraverso il campo comune *ID\_cliente*. In questo modo una query SQL può combinare dati provenienti da più tabelle (ad esempio, generare report di vendite per cliente o settore).

I database relazionali sono gestiti da un **RDBMS** (Relational Database Management System) come MySQL, PostgreSQL, Oracle o SQL Server, che forniscono i servizi di memorizzazione, indicizzazione, controllo concorrente e transazionale. Una caratteristica fondamentale è il supporto alle **transazioni ACID**, che garantiscono che insiemi di operazioni sui dati vengano eseguiti tutti insieme o per nulla, preservando l’integrità del database. Le proprietà ACID sono:

* **Atomicità**: tutte le modifiche richieste da una transazione avvengono come un’unica operazione indivisibile (tutte riescono o nessuna viene applicata).
* **Coerenza**: il database passa sempre da uno stato valido a un altro stato valido, applicando regole di integrità (vincoli, tipi di dato, chiavi).
* **Isolamento**: l’esecuzione contemporanea di più transazioni non causa interferenze; ogni transazione vede i dati come se fosse unica e serializzata.
* **Durabilità**: una volta che una transazione è confermata, le sue modifiche persistono nel tempo anche in caso di malfunzionamenti.

Alcuni termini chiave: 
- una **chiave primaria** è un attributo (o insieme di attributi) di una tabella con valori univoci che identificano univocamente ogni riga. Una 
- **chiave esterna** è un attributo in una tabella che riferisce la chiave primaria di un’altra, definendo così una relazione uno-a-molti o molti-a-uno fra le tabelle. 
    - Ad esempio, *ID\_cliente* nella tabella *Transazioni* può essere chiave esterna che fa riferimento al *ID\_cliente* primario nella tabella *Clienti*. È buona pratica **indicizzare** le colonne di chiave esterna per migliorare le prestazioni dei join e delle query che le coinvolgono. Infine, un sistema RDBMS differisce da un generico DBMS nel fatto che memorizza dati in tabelle relazionate (mentre un DBMS generico potrebbe usare file non strutturati).

## Introduzione a SQL

**SQL** (Structured Query Language) è il linguaggio standard per interagire con i database relazionali. Con SQL si possono definire le strutture dati (linguaggio DDL: `CREATE TABLE`, `ALTER TABLE`, `DROP TABLE`), manipolare i dati (linguaggio DML: `INSERT`, `UPDATE`, `DELETE`) e interrogarli (linguaggio DQL: `SELECT`). Ad esempio, la seguente query SQL recupera il nome del cliente e il totale degli importi delle sue transazioni nell’anno 2022:

```sql
SELECT c.Nome, SUM(t.Importo) AS Totale2022
FROM Transazioni t
LEFT JOIN Clienti c ON t.ID_cliente = c.ID_cliente
WHERE YEAR(t.Data) = 2022
GROUP BY c.Nome;
```

Questa query utilizza **`SELECT`** per scegliere le colonne di output, **`FROM`** per specificare le tabelle, **`JOIN`** per unire le tabelle mediante la chiave comune, **`WHERE`** per filtrare sulle righe di interesse (ad esempio l’anno), e **`GROUP BY`** per raggruppare i risultati per cliente. In pochi comandi SQL è quindi possibile costruire report complessi. Le istruzioni SQL sono dichiarative, il che significa che si specificano “cosa” ottenere, mentre l’ottimizzazione interna del database decide “come” eseguire al meglio la query. In ambito SQL esistono variazioni di sintassi minime fra i dialetti (es. `TOP 10` in SQL Server vs `LIMIT 10` in MySQL) e differenze nella gestione dei tipi di dato, ma la logica di base rimane comune a tutti i sistemi relazionali.

**Best practice di base:**

* Usare alias chiari per tabelle e colonne (`AS`) quando si fanno query su più tabelle.
* Evitare `SELECT *` nelle query di produzione; specificare invece solo le colonne necessarie per ridurre I/O.
* Impostare vincoli e tipi di dato corretti (ad esempio `NOT NULL` dove possibile) durante la creazione delle tabelle.
* Usare transazioni (`BEGIN/COMMIT/ROLLBACK`) quando si effettuano operazioni DML (INSERT/UPDATE/DELETE) in blocco per garantire coerenza.

## Clausole e operatori in SQL

Le query SQL usano diverse **clausole** e **operatori** per filtrare e ordinare i dati:

* **SELECT** – elenca le colonne da restituire (con possibili calcoli e alias). Si possono usare `DISTINCT` per rimuovere duplicati.

* **FROM** – elenca le tabelle coinvolte. Può includere anche subquery o tabelle derivate.

* **JOIN/ON/USING** – specifica come unire le tabelle (INNER JOIN, LEFT JOIN, RIGHT JOIN, CROSS JOIN, ecc.) tramite condizioni sulle chiavi comuni.

* **WHERE** – filtra le righe prima di raggruppamenti; accetta condizioni booleane con operatori di confronto (`=, <>, <, >, <=, >=`), operatori logici (`AND, OR, NOT`), e operatori speciali (`LIKE`, `IN`, `BETWEEN`, `IS NULL`, ecc.). Ad esempio `WHERE Nome LIKE 'A%' AND Età >= 18`.

* **GROUP BY** – raggruppa le righe in base ai valori di una o più colonne, preparandole per calcoli aggregati (es. `GROUP BY Reparto`).

* **HAVING** – filtra i gruppi dopo il raggruppamento, basandosi su condizioni su funzioni di aggregazione (ad esempio `HAVING SUM(Importo) > 1000`).

* **ORDER BY** – ordina i risultati finali (es. `ORDER BY Data DESC, Nome ASC`).

* **LIMIT/OFFSET** – limita il numero di righe restituite e imposta un offset (es. paginazione), oppure `TOP N` nei DB che lo supportano.

Alcuni operatori utili e considerazioni:

* **LIKE** e wildcard `%` o `_` per confronti su stringhe (es. `WHERE Cognome LIKE 'Rossi%'` trova tutti i Cognomi che iniziano con “Rossi”).
* **BETWEEN** per valori in intervalli (es. `BETWEEN '2022-01-01' AND '2022-12-31'`).
* **IN** e **NOT IN** per confronti con un insieme di valori
* **CASE WHEN…THEN…ELSE…END** per logica condizionale nel SELECT.

**Flusso logico di una query:** nell’esecuzione, le clausole seguono un ordine logico: si parte da `FROM` e `JOIN` (per costruire il dataset di partenza), poi `WHERE` filtra le righe, quindi `GROUP BY` divide in gruppi, `HAVING` filtra i gruppi, quindi `SELECT` proietta le colonne finali, e infine `ORDER BY` ordina i risultati. Per esempio, condizioni con aggregate non possono stare in `WHERE` ma devono stare in `HAVING`: la clausola `WHERE` agisce sui dati grezzi, mentre `HAVING` agisce sui risultati aggregati.

**Errori comuni:** confondere WHERE e HAVING, dimenticare l’alias di tabella nel JOIN, applicare funzioni su colonne non menzionate in GROUP BY, oppure sovraccaricare la clausola WHERE con subquery complesse anziché usare join o CTE più leggibili. Un altro errore frequente è dimenticare di indicizzare le colonne usate in JOIN o in WHERE, provocando rallentamenti.

## Gestione delle date in SQL

Il supporto per date e orari varia tra i DBMS, ma concetti generali sono simili. SQL prevede tipi di dato speciali per gestire date e timestamp. Ad esempio, **MySQL** offre `DATE` (formato `YYYY-MM-DD`), `DATETIME`/`TIMESTAMP` (data + ora `YYYY-MM-DD HH:MM:SS`), `TIME` (ora del giorno o intervallo) e `YEAR` (solo anno). In **Oracle**, invece, il tipo `DATE` include automaticamente data e ora (fino ai secondi), mentre esistono tipi `TIMESTAMP` anche con fuso orario. È importante usare sempre formati internazionalizzati per le date (come ISO `YYYY-MM-DD`), poiché formati locali o stringhe diverse possono causare errori di conversione.

**Esempio di manipolazione date:** si possono usare funzioni quali `CURRENT_DATE` (data odierna), `CURRENT_TIMESTAMP` (data e ora attuali), oppure calcoli come `DATEDIFF` (differenza tra date) o `DATE_ADD`/`DATE_SUB` per aggiungere giorni. In MySQL, ad esempio, `SELECT * FROM Ordini WHERE OrderDate='2022-11-11'` restituisce tutte le righe con **OrderDate** uguale al giorno indicato. Tuttavia attenzione: se `OrderDate` è di tipo `DATETIME` e contiene anche componenti orarie, la stessa query (che cerca esattamente `'2022-11-11 00:00:00'`) **non troverà** nulla. In pratica, il confronto con stringa data confronta anche l’ora. Un suggerimento è quello di filtrare con range temporali (ad es. `BETWEEN '2022-11-11 00:00:00' AND '2022-11-11 23:59:59'`) o utilizzare funzioni di estrazione anno/mese (`YEAR(OrderDate) = 2022`) per non escludere date valide.

**Best practice:** memorizzare sempre le date in colonne dedicate anziché come stringhe, per sfruttare ordinamenti e confronti nativi. Impostare il fuso orario del database correttamente se si utilizzano timestamp con zone. Quando si effettuano operazioni su date, usare le funzioni del DB specifico (ad es. `TO_DATE` in Oracle o `STR_TO_DATE` in MySQL) per convertire stringhe in date. Evitare calcoli ripetuti su colonne date nelle clausole WHERE (ad esempio, non usare `WHERE YEAR(data)=2022` se è possibile filtrare con range, poiché può impedire l’uso di indici).

## Operatori di aggregazione

Gli **operatori di aggregazione** (o funzioni aggregate) eseguono calcoli su gruppi di righe e restituiscono un singolo valore scalare per gruppo. Le funzioni più comuni sono `COUNT()`, `SUM()`, `AVG()`, `MIN()` e `MAX()`. Ad esempio, `SUM(Importo)` restituisce la somma di tutti gli importi di un gruppo di righe; `COUNT(*)` conta il numero totale di righe del gruppo (inclusi eventuali valori NULL). Alcune note importanti:

* **`COUNT(*)`** conta tutte le righe (inclusi i campi NULL); mentre **`COUNT(colonna)`** conta solo le righe in cui *colonna* è non-NULL.
* Le opzioni **DISTINCT** e **ALL** possono modificare l’aggregazione: e.g. `COUNT(DISTINCT col)` conta i valori distinti. Di default (ALL) si includono i duplicati.
* I valori NULL vengono *ignorati* nelle funzioni SUM, AVG, MIN, MAX. Se un gruppo è vuoto (o contiene solo NULL), SUM/AVG/MIN/MAX restituiscono NULL, mentre `COUNT(*)` restituisce 0.
* Le funzioni MAX e MIN possono essere applicate anche a stringhe o date, restituendo il valore “massimo” o “minimo” lessicografico/temporale corrispondente.

Per usare le funzioni aggregate bisogna solitamente combinare con **`GROUP BY`**, come nel seguente esempio: per calcolare il numero di ordini per ogni cliente si scrive

```sql
SELECT ID_cliente, COUNT(*) AS NumeroOrdini
FROM Ordini
GROUP BY ID_cliente;
```

Se si include una funzione aggregata, tutte le altre colonne nel `SELECT` devono essere o incluse in `GROUP BY` o esse stesse usate in una funzione aggregata. Dopo il raggruppamento, la clausola **HAVING** può filtrare i gruppi in base al risultato aggregato (ad es. `HAVING COUNT(*) > 5` restituirà solo i clienti con più di 5 ordini).

**Variazioni sintattiche:** diversi DB hanno estensioni dell’aggregazione. Ad esempio, SQL standard supporta `GROUP BY ROLLUP` o `CUBE` per generare subtotali, oppure funzioni condizionali come `SUM(CASE WHEN ... THEN valore ELSE 0 END)` per aggregazioni condizionali. In alcuni sistemi (es. MySQL) si possono anche usare funzioni di finestra (*window functions*) per calcoli aggregati senza raggruppare, ma questo è un argomento avanzato.

**Best practice e avvertenze:**

* Usare `COUNT(*)` con consapevolezza: conta tutte le righe, quindi può restituire 0 anche se il gruppo contiene solo NULL in una colonna.
* In grandi tabelle, una `GROUP BY` sui campi giusti (preferibilmente indicizzati) è essenziale per le prestazioni.
* Non inserire in `HAVING` condizioni che non dipendono da aggregati; quelle vanno in `WHERE`.
* Attenzione alle colonne “aperte” nella SELECT senza aggregazione: molti DB richiedono che ogni colonna non aggregata sia elencata in GROUP BY (in MySQL standard può essere tollerante, ma è comunque buona prassi elencarle tutte).

## JOIN e relazioni

I **JOIN** servono a combinare i dati di più tabelle sfruttando le relazioni (chiavi) fra esse. Si deve sempre specificare la condizione di join (`ON` o `USING`) per indicare come le righe di una tabella corrispondono a quelle dell’altra, di solito comparando chiavi esterne con chiavi primarie. Le tipologie di join principali sono:

* **INNER JOIN**: restituisce solo le righe in cui le chiavi combaciano tra le tabelle. In pratica prende l’intersezione dei dati basandosi sulle chiavi.
* **LEFT (OUTER) JOIN**: restituisce tutte le righe della tabella “sinistra” e le corrispondenze nella tabella “destra”. Per le righe sinistre senza match, le colonne della tabella destra verranno come NULL.
  &#x20;*Nell’immagine sopra (Left Outer Join), è evidenziata in blu l’area di *Table A* (sinistra) che viene mantenuta interamente nell’output; la parte comune (intersezione) è anch’essa blu, mentre i valori senza corrispondenza producono campi NULL.*
* **RIGHT (OUTER) JOIN**: analogo al LEFT JOIN ma include tutte le righe della tabella destra (utile quando si vuole conservare ogni record della tabella destra a prescindere dalla corrispondenza).
* **FULL (OUTER) JOIN**: restituisce tutte le righe di entrambe le tabelle, mettendo NULL nelle colonne dove manca la corrispondenza.
  &#x20;*L’immagine sopra illustra un Full Outer Join: entrambe le tabelle sono interamente blu, e l’intersezione è evidenziata a colori mischiati. Vengono restituite tutte le righe da entrambe le tabelle.*
* **CROSS JOIN**: produce il prodotto cartesiano delle tabelle (ogni riga di A combinata con ogni riga di B); raramente usato intenzionalmente, genera molte righe e di norma è disastroso sulle performance a meno di tabelle molto piccole.
* **SELF JOIN**: una tabella si unisce con sé stessa (usando alias diversi), utile per confronti o gerarchie nella stessa tabella (ad es. in una tabella *Impiegati*, un self-join può mettere a confronto i manager con i subordinati).

Quando si specifica un JOIN con `ON`, è importante usare indici sulle colonne di join (specialmente chiavi esterne) per evitare scansioni complete. Come raccomanda IBM, ogni chiave esterna dovrebbe avere un indice dedicato. Senza indice, un join può diventare molto lento su tabelle grandi. Inoltre, bisogna prestare attenzione a non dimenticare la clausola `ON`: un `FROM TabA JOIN TabB` senza `ON` crea un cross join implicito (prodotto cartesiano).

**Errori comuni:** confondere le condizioni di join con quelle di filtro, o usarle nel posto sbagliato. Ad esempio, porre la condizione di join nella clausola `WHERE` anziché in `ON` in un LEFT JOIN può trasformarla in un INNER JOIN mascherato. Oppure dimenticare l’alias e non specificare a quale tabella appartiene una colonna nei join multipli. Un altro rischio è unire su colonne che non sono chiavi: ciò può produrre duplicati o risultati non intenzionali. Utilizzare sempre nomi di colonne qualificati (e.g. `A.id = B.a_id`) per evitare ambiguità.

## Valori NULL

In SQL, **`NULL`** rappresenta l’assenza di valore (dato sconosciuto o non applicabile) e non è equivalente a zero o stringa vuota. Per esempio, in una colonna `DataDiRinnovo` che può non essere ancora nota, `NULL` indica che il rinnovo non è stato inserito. È importante tenere presente che qualsiasi operazione aritmetica o confronto con `NULL` restituisce `NULL` (concetto di logica a tre valori: *TRUE, FALSE, UNKNOWN*). In pratica:

* Non si può usare `=` per confrontare con NULL: l’espressione `campo = NULL` non restituisce mai TRUE. Bisogna usare gli operatori **`IS NULL`** o **`IS NOT NULL`**. Ad esempio, `WHERE DataDiRinnovo IS NULL` trova tutte le righe dove il rinnovo manca.
* In un’espressione booleana, `NULL` si comporta come “UNKNOWN”: ad es. `5 > NULL` restituisce NULL (quindi considerato falso in filtro), come anche `NULL = NULL` restituisce NULL (non vero!). Questo può sorprendere: due NULL non sono considerati “uguali” in una condizione `=`.
* Le funzioni booleane standard interpretano NULL come **UNKNOWN**: per es. `FALSE AND NULL` è FALSE, `TRUE OR NULL` è TRUE, ma `NULL OR NULL` è NULL.
* Quando si ordinano valori, spesso i NULL sono trattati come maggiori di qualsiasi valore (posizionandosi in fondo con `ORDER BY ASC`, a seconda del DB).

Nei calcoli aggregati, i NULL vengono ignorati (tranne in `COUNT(*)` come detto sopra). Se una colonna contiene solo valori NULL, `SUM, AVG, MIN, MAX` daranno `NULL`. Se invece si vuole trattare i NULL come 0 o altro, si può ricorrere a `COALESCE` (o a specifiche funzioni come `NVL` in Oracle) per sostituirli. Ad esempio, `SELECT COALESCE(MediaVoti, 0) FROM Studenti;` restituirà 0 se **MediaVoti** era NULL.

**Attenzione:** la gestione dei NULL è una fonte comune di errori logici. Ad esempio, un INNER JOIN ignorerà le righe con chiave esterna NULL (non troverebbero match nella tabella madre). Inoltre, ricordare che `COUNT(col)` **non conta** i NULL, mentre `COUNT(*)` li conta come righe. Infine, non confondere un campo **vuoto** (empty string) con NULL; alcuni DB permettono stringhe vuote, ma esse sono valori significativi non equivalenti a NULL.

## Sottoquery

Una **sottoquery** (o subquery) è una query annidata all’interno di un’altra query. In pratica è una “query dentro una query”. Le sottoquery possono essere utilizzate in molti contesti: nelle clausole `SELECT` (per generare colonne calcolate), `WHERE`, `FROM` (come tabelle derivate) o `HAVING`. Ad esempio:

```sql
SELECT Nome
FROM Studenti
WHERE Voto > (SELECT AVG(Voto) FROM Studenti);
```

Qui la sottoquery `SELECT AVG(Voto) FROM Studenti` viene eseguita per prima e restituisce un valore scalare (la media dei voti). Poi la query esterna confronta il voto di ogni studente con questo valore. Se una sottoquery restituisce una sola riga/colonna si dice **scalare**; in questo caso si possono usare operatori di confronto come `=, <, >`. Se invece la subquery può restituire più righe, bisogna usare operatori set-oriented come **`IN`**, **`EXISTS`**, `ANY`, `ALL`. Ad esempio:

```sql
SELECT Nome
FROM Studenti
WHERE ID_Classe IN (
    SELECT ID_Classe
    FROM Classi
    WHERE Anno = 2023
);
```

In questo caso la subquery non è scalare: elenca più ID di classi; per questo si usa `IN`. In alternativa si sarebbe potuto scrivere una JOIN.

È importante distinguere le **subquery correlate** da quelle indipendenti. Una subquery indipendente (o non correlata) non dipende dalle righe della query esterna: viene eseguita una sola volta. Una subquery correlata invece si riferisce a colonne della query esterna e viene rieseguita per ogni riga (o gruppo) dell’esterno. Ad esempio, per trovare i reparti il cui stipendio medio supera la media dell’area di afferenza, si può usare:

```sql
SELECT WORKDEPT, AVG(SALARY) AS MediaDipartimento
FROM EMPLOYEE X
GROUP BY WORKDEPT
HAVING AVG(SALARY) > (
    SELECT AVG(SALARY)
    FROM EMPLOYEE
    WHERE SUBSTR(X.WORKDEPT,1,1) = SUBSTR(WORKDEPT,1,1)
);
```

Qui la sottoquery `SELECT AVG(SALARY) ... WHERE SUBSTR(X.WORKDEPT,1,1)=...` è correlata: utilizza `X.WORKDEPT` dalla query esterna per calcolare la media del settore corrispondente. La sottoquery viene quindi eseguita una volta per ogni dipartimento esterno, sostituendo il valore `X.WORKDEPT` corrente; in pratica per ogni gruppo il DB calcola la media “dell’area” di quel gruppo. Le subquery correlate possono essere potenti ma anche molto costose in termini di performance (vengono eseguite ripetutamente); quando possibile si valuta l’uso di join o di Common Table Expression (`WITH`) come alternative più efficienti.

**Suggerimenti e avvertenze:**

* Operatori come `IN`, `EXISTS`, `> ALL`, `= ANY` sono molto utili con subquery: per es., `EXISTS (subquery)` verifica semplicemente la presenza di almeno una riga nel risultato secondario.
* Se una subquery restituisce più colonne o righe quando l’operatore richiede solo un valore, la query fallirà. Ad esempio, usare `=` con una subquery che ritorna due righe genera un errore.
* Evitare subquery non necessarie: spesso un join ben fatto può sostituire una subquery in `WHERE` e migliorare le prestazioni.
* L’uso di sottoquery nel blocco `FROM` (come tabelle derivate) può rendere il codice più leggibile quando è necessario filtrare o aggregare prima di unire i risultati.

**Esempio riassuntivo:**

```sql
SELECT CustomerID, CompanyName 
FROM Customers
WHERE CustomerID IN (
    SELECT DISTINCT CustomerID
    FROM Orders
    WHERE OrderDate BETWEEN '2023-01-01' AND '2023-03-31'
);
```

In questa query estraiamo tutti i clienti che hanno ordini nel primo trimestre 2023. La subquery interna ottiene la lista di `CustomerID` dagli ordini in quel periodo, e `IN` filtra i clienti corrispondenti.

**Collegamenti tra i concetti:** notiamo che molti concetti SQL interagiscono: ad esempio, un `JOIN` si basa sulle chiavi (PK e FK) del database relazionale, e può restituire risultati che poi vengono aggregati con `GROUP BY`. Le sottoquery possono sfruttare le funzioni di aggregazione (ad es. per confrontare con una media) o addirittura includere altri join al loro interno. Comprendere bene la relazione fra chiavi (PK/FK), join e filtri è fondamentale: i join con chiavi esterne ottimizzati da indici sono spesso più veloci di subquery ripetute.

**Fonti:** principi teorici e spiegazioni da manualistica e tutorial (Oracle, IBM, tutorial LearnSQL).
