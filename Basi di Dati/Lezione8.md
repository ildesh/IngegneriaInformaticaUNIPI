## Dipendenze Funzionali e Normalizzazione

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
---
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
---
### 3. Linee Guida per la Progettazione

- Semplicità: ogni relazione rappresenta un solo concetto.
- Nessuna anomalia: usare FD per attestare correttamente l'assenza di incongruenze.
- Null rari: evitare attributi con valori null frequentemente.

**Approfondimento**
- Balance tra forme normali e performance: normalizzazione spinta può frammentare eccessivamente lo schema.
- Design pragmatico: a volte accettare 3NF invece di BCNF per preservazione dipendenze.
---
### 4. Definizione Formale di Dipendenza Funzionale

- Dato R(T) e FD X → Y, consideriamo l'insieme di tutte le istanze possibili.
- Espressione logica: per ogni coppia di tuple t1 e t2 di R, se t1[X] = t2[X] allora t1[Y] = t2[Y].
- Superchiavi e chiavi:
  - Calcolo di chiusura degli attributi X+.
  - Chiave: X+ = T e nessun sottoinsieme proprio di X ha chiusura pari a T.
---
### 5. Forme Normali e Normalizzazione

- 1NF: atomicità degli attributi.
- 2NF: ogni attributo non-primo dipende dalla chiave intera.
- 3NF: ogni FD non banale X → A soddisfa: X è superchiave o A è attributo primo.
- BCNF: rafforza la 3NF richiedendo sempre che X sia superchiave.

**Vantaggi e svantaggi**
- 3NF conserva dipendenze, BCNF evita ogni ridondanza residua.
- BCNF può rompere la preservazione dipendenze.
---
### 6. Regole di Inferenza di Armstrong

1. **_Riflessività_**: se Y è contenuto in X allora X → Y.
2. **_Additività_**: da X → Y ottengo XZ → YZ.
3. **_Transitività_**: da X → Y e Y → Z ottengo X → Z.

**Regole derivate comuni**
1. **_Unione_**: {X → Y, X → Z} ⊢ X → YZ
2. **_Decomposizione_**: {X → YZ} ⊢ X → Y
3. **_Indebolimento_**: {X → Y} ⊢ XZ → Y
4. **_Identità_**: {} ⊢ X → X 
---
### 7. Chiusura di Attributi e Insiemi di Dipendenze

**Definizione:** 

La **chiusura di un insieme di attributi** `X`, indicata come `X⁺`, è l'insieme di tutti gli attributi che possono essere determinati *funzionalmente* partendo da `X`, usando le dipendenze funzionali note (`F`).

#### **Perché serve?**
- Serve a verificare se `X` può determinare tutti gli attributi della relazione → quindi a capire se `X` è una *chiave candidata*.
- Serve a derivare nuove dipendenze implicate da `F`.

#### **Algoritmo per calcolare X⁺**
È un algoritmo iterativo, semplice da ricordare:

1. **Inizia** con `X⁺ = X` (parti dagli attributi di X).
2. **Per ogni** dipendenza funzionale `Y → Z` in `F`:
   - Se `Y` ⊆ `X⁺`, allora aggiungi `Z` a `X⁺`.
3. **Ripeti** il passo 2 finché `X⁺` non cambia più (cioè rimane stabile).

##### **Esempio**
Supponiamo di avere:
- Attributi: `A`, `B`, `C`, `D`
- Dipendenze funzionali:
  - `A → B`
  - `B → C`
  - `C → D`

Se vogliamo calcolare `A⁺`:
- Inizio: `A⁺ = {A}`
- `A → B`: aggiungo `B` → `A⁺ = {A, B}`
- `B → C`: `B` è in `A⁺`, aggiungo `C` → `A⁺ = {A, B, C}`
- `C → D`: `C` è in `A⁺`, aggiungo `D` → `A⁺ = {A, B, C, D}`

Fine: `A⁺ = {A, B, C, D}` → Quindi `A` è chiave, perché determina tutto!

---

### **Chiusura di un Insieme di FD (F⁺)**

**Definizione:**  
La **chiusura di un insieme di dipendenze funzionali** `F`, indicata come `F⁺`, è l'insieme di *tutte* le dipendenze funzionali che sono *implicate logicamente* da `F`.
>
>$$
>F^+ = \{ X \rightarrow Y \mid F \models X \rightarrow Y \}
>$$
>
>e si legge:  
>*"La chiusura di F è l'insieme di tutte le dipendenze X determina Y tali >che F implica X determina Y."*


#### **Perché serve?**
- Serve a sapere *tutte* le FD che valgono per quella relazione, anche quelle che non sono scritte direttamente ma derivano da `F`.
- Consente di verificare se una dipendenza `X → Y` è valida: basta vedere se è in `F⁺`.

---

### **Applicazioni pratiche**

1. **Controllo chiave**
   - Se la chiusura `X⁺` di un insieme `X` contiene *tutti* gli attributi della relazione, allora `X` è una *superchiave*.
   - Se nessun sottoinsieme proprio di `X` è una superchiave, allora `X` è una *chiave candidata*.

2. **Derivazione di FD implicate**
   - Se voglio sapere se `X → Z` è valida, posso calcolare `X⁺`:
     - Se `Z` ⊆ `X⁺`, allora `X → Z` è implicata da `F`.
   - Quindi non serve enumerare tutte le istanze della relazione → lo faccio *matematicamente*.

---

### **Teorema di chiusura degli attributi**

- Se `X` è un insieme di attributi e `F` è un insieme di dipendenze funzionali, allora `X⁺` è l'insieme di tutti gli attributi che possono essere determinati da `X` usando le dipendenze in `F`.
- **_Superchiave_**: X⁺ ⊇ tutti gli attributi
- **_Chiave candidata_**: X⁺ = tutti gli attributi e X è minimale.

---

### **Teorema di Correttezza e Completezza**

Questo teorema riguarda il sistema di **Armstrong** per le dipendenze funzionali (che sono le 3 regole base: riflessività, estensione e transitività).

Ci permette di scambiare ⊧ con ⊢ ovunque. In particolare nella definizione di chiusura degli attributi, cioè:
>
>$$
>X^+ = \{ A \in T \mid F \models X \rightarrow A \}
>$$
>
>e si legge così:  
>*"La chiusura di X è l'insieme degli attributi A appartenenti a T tali che F implica X che determina A."*

#### **Correttezza**
Tutte le dipendenze funzionali che possiamo derivare usando le regole di Armstrong sono *corrette*, cioè sono davvero valide in ogni relazione che soddisfa `F`.

#### **Completezza**
Tutte le dipendenze che sono *implicate* da `F` possono essere *derivate* usando solo le regole di Armstrong.

#### **Tradotto in parole semplici:**
Le regole di Armstrong sono:
- **giuste** (non derivano mai una dipendenza falsa),
- **sufficienti** (possono derivare tutte le dipendenze vere implicate da `F`).
- Si può dimostrare che le regole di inferenza di Armstrong
sono **minimali**, cioè **ignorando** anche una sola di esse,
l’insieme di regole che rimangono **non è più completo**.
- Le regole di inferenza di Armstrong non sono l’unico
insieme di regole corretto e completo!

---

##### **Schema mentale per ricordare**
- **X⁺** = chiusura di attributi = serve a trovare chiavi e derivare FD.
- **F⁺** = chiusura di FD = tutte le FD vere implicate da quelle date.
- **Teorema**: le regole di Armstrong ci danno *tutto* (completo) e *giusto* (corretto).

---

### 8. Equivalenza tra Insiemi di Dipendenze

- F è equivalente a G se e solo se F<sup>+</sup> = G<sup>+</sup>.
- Tecniche di minimalizzazione: coperture minime, rimozione di ridondanze.
- Copertura minimale: decomporre ogni FD in FD elementari, eliminare attributi estranei e dipendenze ridondanti.

- Se F ≡ G allora F è una copertura di G e viceversa
- Per verificare l’equivalenza è sufficiente che:
  - F ⊆ G<sup>+</sup> e G ⊆ F<sup>+</sup>
