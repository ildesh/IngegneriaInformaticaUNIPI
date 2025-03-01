## Lezione 2 - Esercizi

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

### Esempio 3:

>[!IMPORTANT] Definire uno schema di basi di dati che organizzi i dati necessari a generare la pagina dei programmi radiofonici di un quotidiano, con stazionim ore e titoli dei programmi; per ogni stazione sono memorizzati, oltre al nome, anche la frequenza di trasmissione e la sede.

> [!NOTE] Schema della base di dati
> 
> **Relazione Programma Radiofonico**  
> - **Attributi**: `NomeStazione`, `Ore`, `TitoliProgrammi`  
> 
> **Relazione Stazione**  
> - **Attributi**: `Nome`, `Frequenza`, `Sede`

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