# Lezione 3 - 09/04/2025

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

- Partiamo dalla prima query:

    ```sql
    SELECT Specializzazione, AVG(Parcella)
    FROM Medico
    GROUP BY Specializzazione;
    ```
- Poi calcoliamo la massima parcella media:

    ```sql