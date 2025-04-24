## Espansione dettagliata su Dipendenze Funzionali e Normalizzazione

### 1. Introduzione alle Dipendenze Funzionali
**Contesto storico e motivazione**
- Le dipendenze funzionali (FD) sono state formalizzate negli anni '70 da Edgar F. Codd per risolvere problemi di ridondanza e anomalie nelle basi di dati relazionali.
- Intuizione: una FD descrive un vincolo semantico, derivato dalla realtà del dominio, che non può essere scoperto automaticamente dal database ma richiede conoscenza dell'applicazione.

**Definizione estesa**
- Una FD X → Y su uno schema R significa: ogni coppia di tuple di R che concordano sui valori di X concorda anche su quelli di Y.
- Interpretazione semantica: se conosciamo il valore di X, possiamo dedurre quello di Y senza accedere ad altre informazioni.
- Tipi particolari:
  - Banale se Y è un sottoinsieme di X.
  - Completa o minima se nessun sottoinsieme proprio di X determina Y.
  - Superchiave: X determina tutti gli attributi di R.
  - Chiave: superchiave minimale.

**Esempi reali**
1. In un archivio studenti, Matricola determina Nome, Cognome, DataNascita.
2. In un sistema di fatturazione, CodProdotto determina Descrizione, PrezzoUnitario, Categoria.

### 2. Obiettivi della Progettazione Logica

1. Conservazione dell’informazione
   - Garantire che tutte le regole di vincolo concettuali siano esprimibili nello schema logico.
   - Mantenere integrità semantica di entità e associazioni.
2. Minimizzazione della ridondanza
   - Ridurre duplicazioni di valori per abbassare spazio di memorizzazione e costo di manutenzione.
3. Assenza di anomalie
   - Inserimento: poter aggiungere nuova informazione senza dati fittizi.
   - Cancellazione: eliminare tuple senza perdere informazioni inconsapevolmente.
   - Aggiornamento: modificare un attributo in un unico punto.

**Approccio top-down vs bottom-up**
- Top-down: partenza da modello E-R, traduzione guidata da FD.
- Bottom-up: riflessione su schemi già esistenti e decomposizione.

### 3. Linee Guida per la Progettazione

- Semplicità: ogni relazione rappresenta un solo concetto.
- Nessuna anomalia: usare FD per attestare correttamente l'assenza di incongruenze.
- Null rari: evitare attributi con valori null frequentemente.

**Approfondimento**
- Balance tra forme normali e performance: normalizzazione spinta può frammentare eccessivamente lo schema.
- Design pragmatico: a volte accettare 3NF invece di BCNF per preservazione dipendenze.

### 4. Definizione Formale di Dipendenza Funzionale

- Dato R(T) e FD X → Y, consideriamo l'insieme di tutte le istanze possibili.
- Espressione logica: per ogni coppia di tuple t1 e t2 di R, se t1[X] = t2[X] allora t1[Y] = t2[Y].
- Superchiavi e chiavi:
  - Calcolo di chiusura degli attributi X+.
  - Chiave: X+ = T e nessun sottoinsieme proprio di X ha chiusura pari a T.

### 5. Forme Normali e Normalizzazione

- 1NF: atomicità degli attributi.
- 2NF: ogni attributo non-primo dipende dalla chiave intera.
- 3NF: ogni FD non banale X → A soddisfa: X è superchiave o A è attributo primo.
- BCNF: rafforza la 3NF richiedendo sempre che X sia superchiave.

**Vantaggi e svantaggi**
- 3NF conserva dipendenze, BCNF evita ogni ridondanza residua.
- BCNF può rompere la preservazione dipendenze.

### 6. Regole di Inferenza di Armstrong

1. Riflessività: se Y è contenuto in X allora X → Y.
2. Additività: da X → Y ottengo XZ → YZ.
3. Transitività: da X → Y e Y → Z ottengo X → Z.

**Regole derivate**
- Unione, decomposizione, pseudoprimitività.

### 7. Chiusura di Attributi e Insiemi di Dipendenze

- Chiusura di attributi X+: algoritmo iterativo per determinare tutti gli attributi determinati da X.
- Chiusura di un insieme di FD F+: insieme di tutte le FD implicate.

**Applicazioni**
- Verifica di chiusura per controllo chiave.
- Derivazione di FD implicate senza enumerare tutte le istanze.

### 8. Equivalenza tra Insiemi di Dipendenze

- F è equivalente a G se e solo se F+ = G+.
- Tecniche di minimalizzazione: coperture minime, rimozione di ridondanze.
- Copertura minimale: decomporre ogni FD in FD elementari, eliminare attributi estranei e dipendenze ridondanti.
