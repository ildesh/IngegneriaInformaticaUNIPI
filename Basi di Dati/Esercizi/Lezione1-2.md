## Lezione 1-2 - Esercizi

### Esercizio 1:

> [!IMPORTANT] Rappresentare per mezzo di una o più relazioni le informazioni contenute nell'orario delle partenze di una stazione ferroviaria: numero, orario, destinazione finale, categoria, fermate intermedie, di tutti i treni in partenza.

>[!NOTE] Sostantivi: `numero`,`orario`,`destinazione`,`categoria`

>[!WARNING]
>Ci possono essere dei treni in cui non esistono fermate intermedie. 
>
>Quindi le **fermate intermedie** non possono essere un attributo della relazione **treno** ma devono essere rappresentate in una relazione a parte. Le fermate intermedie sono valori variabili e possono essere più di uno. 

>[!NOTE] Possibile schema:
>**Relazione TRENO**
>- **Attributi**: `Numero`,`Orario`,`Destinazione`,`Categoria`
>
>**Relazione FERMATE**
>- **Attributi**: `Numero`,`Stazione`,`Orario`




>[!NOTE]
> La relazione "PARTENZE" contiene le informazioni relative ai treni in partenza dalla stazione.
> 
> La relazione "FERMATE" contiene le informazioni relative alle fermate intermedie di ciascun treno. 
> 
> La chiave primaria della relazione "PARTENZE" è il numero del treno, mentre la chiave primaria della relazione "FERMATE" è composta dal numero del treno e dalla stazione di fermata. La chiave esterna della relazione "FERMATE" è il numero del treno, che fa riferimento alla chiave primaria della relazione "PARTENZE".

---
### Esercizio 2:
>[!IMPORTANT] Definire uno schema di base di dati per organizzare le informazioni di un'azienda che ha impiegati (ognuno con codice fiscale, cognome, nome e data di nascita) e filiali (con codice, sede e direttore, che è un impiegato).  Indicare le chiavi e i vincoli di integrità referenziale dello schema.

>[!TIP]
> - Ogni impiegato lavora presso una filiale.


>[!NOTE] Schema della base di dati:
> **Relazione Impiegato:**
> - **Attributi**: `CF`, `Cognome`, `Nome`, `DataNascita`, `CodFiliale`
> 
> **Relazione Filiale:**
> - **Attributi**: `Codice`, `Sede`, `CFDirettore`



> [!NOTE] Chiavi primarie:
> - Impiegato: CF 
> - Filiale: Codice

> [!NOTE] Chiavi esterne:
> - Impiegato: CodFiliale (riferisce a Filiale.Codice)
> - Filiale: CFDirettore (riferisce a Impiegato.CF)

> [!NOTE] Vincoli di integrità referenziale:
> - Ogni impiegato deve lavorare presso una filiale esistente. `Impiegato.CodFiliale` --> `Filiale.Codice`
> - Ogni filiale deve avere un direttore che è un impiegato esistente. `Filiale.CFDirettore` --> `Impiegato.CF`
---
### Esempio 3:

>[!IMPORTANT] Definire uno schema di basi di dati che organizzi i dati necessari a generare la pagina dei programmi radiofonici di un quotidiano, con stazionim ore e titoli dei programmi; per ogni stazione sono memorizzati, oltre al nome, anche la frequenza di trasmissione e la sede.

> [!NOTE] Schema della base di dati
> 
> **Relazione Programma Radiofonico**  
> - **Attributi**: `NomeStazione`, `Ore`, `TitoliProgrammi`  
> 
> **Relazione Stazione**  
> - **Attributi**: `Nome`, `Frequenza`, `Sede`
---
### Esercizio 4:

> [!IMPORTANT] Progettare uno schema di base di dati per gestire le informazioni di una biblioteca. La biblioteca possiede libri, ciascuno identificato da un codice univoco, un titolo e un autore. Ogni libro può essere preso in prestito da un utente, che è identificato da un codice univoco, un nome e un cognome. Ogni prestito è caratterizzato dalla data di inizio e dalla data di scadenza.

> [!NOTE] Schema della base di dati:
> 
> Relazione Libro:
> - Attributi: CodiceLibro, Titolo, Autore
> 
> Relazione Utente:
> - Attributi: CodiceUtente, Nome, Cognome
> 
> Relazione Prestito:
> - Attributi: CodiceLibro, CodiceUtente, DataInizio, DataScadenza
> 

>[!NOTE] Chiavi primarie:
> 
> **Libro**: CodiceLibro
> **Utente**: CodiceUtente
> **Prestito**: CodiceLibro, CodiceUtente (combinata)

> [!NOTE] Chiavi esterne:
> 
> **Prestito.CodiceLibro** → **Libro.CodiceLibro**
>
> **Prestito.CodiceUtente** → **Utente.CodiceUtente**
 
> [!NOTE] Vincoli di integrità referenziale:
> Un libro in prestito deve esistere nella biblioteca.
>
> Un prestito deve essere associato a un utente registrato.
>
> Un libro può essere in prestito a un solo utente alla volta.

---

### Esercizio 5: 

>[!IMPORTANT] Si supponda di volere rappresentare in una base di dati relazionale le informazioni relative al calendario d'esami di una facoltà universitaria, che vengono pubblicate con avvici con la struttura mostrata in fugura. Mostrare gli sche i delle relazioni da utilizzare (con attributi e vincoli di chiave e di integrità referenziale).
>
> <strong>Calendario Esami</strong>
>
> | Codice | Titolo | Prof | Appello | Data |
> |--------|--------|------|---------|------|
> |   1    | Fisica | Neri | 1<br>2<br>3<br>4|01/06/2006<br>05/07/2006<br>04/09/2006<br>30/09/2006|
> |   2    | Chimica| Rossi| 1 <br> 2| 06/06/2006<br>05/07/2006|
> |   3    | Algebra| Bruni|         | da definire|

Relazione compito/esame
- Codice (_chiave primaria_)
- Titolo
- Professore

Relazione appello
- codiceEsame (_chiave esterna_)
- numAppello
- DataAppello

>[!TIP] Possiamo notare che non esistono elementi con valore duplicato e quindi potevamo scegliere qualsiasi elemento come chiave primaria 

Esiste un vincolo di integrità referenziale fra **_codiceAppello_** nella relazione **_appello_** e (**_codic_**) la relazione **_appello_**

---
### Esercizio 6:

>[!IMPORTNT] Supponendo di voler erappresentare una base di dati relazionale contenente le informazioni relative agli autori di una serie di libri raccolte secondo la struttura della figura, nostrare li schemi delle relazioni da utilizzare (con attributi, vincoli di chiave e vincoli di integrità referenziale) e l'istanza corrispondente ai dati mostrati


Relazione libro
- Codice (_chiave primaria_)
- titolo
- DataPubblicazione

Relazione info:
- codicelibro (_chiave esterna_)
- autore (_chiave_)
- telefono (_chiave_)

Esiste un vincolo di integrità referenziale fra 

---

### Esercizio 7:
**_Domande e risposte_** sulle prime due lezioni:

1. ogni relazione ha almeno una chiave <strong>V</strong>:
    -  In ogni relazione deve esistere almeno una chiave, ovvero un insieme di attributi che identifica univocamente ogni tupla. Anche una chiave minima soddisfa questo requisito.
2. ogni relazione ha esattamente una chiave <strong>F</strong>:
    -  Una relazione può avere più chiavi (chiavi candidate). Ad esempio, in una relazione "Studente" potresti avere sia il codice fiscale che il numero di matricola come chiavi potenziali.
3. ogni attributo appartiene al massimo ad una chiave: <strong>F</strong>
    -  Un attributo può appartenere a più chiavi. Ad esempio, in una relazione "Prodotto", un attributo come "Categoria" potrebbe far parte di più chiavi candidate.
4. possono esistere attrivuti che non appartengono a nessuna chiave: <strong>V</strong>
    - Alcuni attributi possono essere descrittivi e non far parte di alcuna chiave. Ad esempio, in una relazione "Dipendente", l'attributo "Colore degli occhi" potrebbe non essere parte di nessuna chiave.
5. Una chiave può essere sottoinsieme di un'altra chiave: <strong>F</strong>
    - Una chiave non può essere un sottoinsieme di un'altra chiave. Le chiavi devono essere minimali, il che significa che nessun suo sottoinsieme può essere una chiave.
6. Può esistere una chiave che coinvolge tutti gli attributi: <strong>V</strong>
    - In alcuni casi, tutti gli attributi di una relazione possono formare una chiave, sebbene questo sia piuttosto raro.
7. Possono esistere più chiavi e una di esse coinvolge tutti gli attributi: <strong>F</strong>
    - Se una chiave coinvolge tutti gli attributi, questa è l'unica chiave possibile. Non possono esistere altre chiavi in questo scenario.
8. Ogni relazione ha almeno una superchiave: <strong>V</strong>
    - Una superchiave è un insieme di attributi che identifica univocamente una tupla. Ogni relazione ha almeno una superchiave, che può coincidere con l'intera lista degli attributi.
9. Ogni relazione ha esattamente una superchiave: <strong>F</strong>
    - Una relazione può avere multiple superchiavi. Ad esempio, in una relazione "Studente", sia "Codice Fiscale" che "Numero di Matricola + Nome" possono essere superchiavi.
10. Possono esistere più superchiavi e una di esse coinvolge tutti gli attributi: <strong>V</strong>
    - È possibile avere multiple superchiavi, e una di queste può coinvolgere tutti gli attributi della relazione.