<h1> Lezione 8 </h1> 
<h2>📚 Indice</h2>

- [Dipendenze Funzionali e Normalizzazione](#dipendenze-funzionali-e-normalizzazione)
    - [1. Introduzione alle Dipendenze Funzionali](#1-introduzione-alle-dipendenze-funzionali)
    - [2. Obiettivi della Progettazione Logica](#2-obiettivi-della-progettazione-logica)
    - [3. Linee Guida per la Progettazione](#3-linee-guida-per-la-progettazione)
    - [4. Definizione Formale di Dipendenza Funzionale](#4-definizione-formale-di-dipendenza-funzionale)
    - [5. Forme Normali e Normalizzazione](#5-forme-normali-e-normalizzazione)
    - [6. Regole di Inferenza di Armstrong](#6-regole-di-inferenza-di-armstrong)
    - [7. Chiusura di Attributi e Insiemi di Dipendenze](#7-chiusura-di-attributi-e-insiemi-di-dipendenze)
      - [**Perché serve?**](#perché-serve)
      - [**Algoritmo per calcolare X⁺**](#algoritmo-per-calcolare-x)
        - [**Esempio**](#esempio)
    - [**Chiusura di un Insieme di FD (F⁺)**](#chiusura-di-un-insieme-di-fd-f)
      - [**Perché serve?**](#perché-serve-1)
    - [**Applicazioni pratiche**](#applicazioni-pratiche)
    - [**Teorema di chiusura degli attributi**](#teorema-di-chiusura-degli-attributi)
    - [**Teorema di Correttezza e Completezza**](#teorema-di-correttezza-e-completezza)
      - [**Correttezza**](#correttezza)
      - [**Completezza**](#completezza)
      - [**Tradotto in parole semplici:**](#tradotto-in-parole-semplici)
        - [**Schema mentale per ricordare**](#schema-mentale-per-ricordare)
    - [8. Equivalenza tra Insiemi di Dipendenze](#8-equivalenza-tra-insiemi-di-dipendenze)
    - [9. Decomposizione](#9-decomposizione)
    - [10. Algoritmo per decomposizione in BCNF](#10-algoritmo-per-decomposizione-in-bcnf)
    - [11. Algoritmo per decomposizione in 3NF](#11-algoritmo-per-decomposizione-in-3nf)
    - [12. Verifica di BCNF / 3NF](#12-verifica-di-bcnf--3nf)
    - [13. Applicazioni alla Progettazione Concettuale](#13-applicazioni-alla-progettazione-concettuale)
    - [14. Esempi di decomposizione errata](#14-esempi-di-decomposizione-errata)
    - [15. Diagrammi Decisionali](#15-diagrammi-decisionali)

---


# Dipendenze Funzionali e Normalizzazione

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

**Esempio di equivalenza:**
Consideriamo due insiemi FD:
- F = {A → B, B → C}
- G = {A → B, A → C, B → C}

**Verifica F ≡ G:**
1. Calcoliamo F⁺:
   - A+ = {A,B,C}
   - B+ = {B,C}
   - C+ = {C}

2. Verifichiamo se G ⊆ F⁺:
   - A → C ∈ F⁺? Sì, perché A determina C tramite transitività.

3. Verifichiamo se F ⊆ G⁺:
   - A → B ∈ G⁺? Sì (direttamente in G).
   - B → C ∈ G⁺? Sì (direttamente in G).

**Conclusione:** F ≡ G. La copertura minima è {A → B, B → C}.

---

### 9. Decomposizione

**Definizione:** {R1(T1), ..., Rk(Tk)} è decomposizione di R se T1 ∪ ... ∪ Tk = T

**Proprietà desiderate:**

* Preservazione dei dati:

  * Teorema: r = πT1(r) ⋈ ... ⋈ πTk(r)
  * Basta che T1 ∩ T2 → T1 ∈ F+ o T2

* Preservazione delle dipendenze:

  * ∪i πTi(F) ≈ F

**Proiezione di FD su Ti:**

* πTi(F) = {X → Y ∈ F+ | X, Y ⊆ Ti}

**Esempio di decomposizione con perdita di dati:**
Schema R(A,B,C) con FD {A → B}
- Decomposizione in R1(A,B) e R2(A,C)

**Tabella originale:**
| A | B | C |
|---|---|---|
| 1 | X | 10 |
| 2 | Y | 20 |

**Proiezioni:**
R1:
| A | B |
|---|---|
| 1 | X |
| 2 | Y |

R2:
| A | C |
|---|---|
| 1 | 10 |
| 2 | 20 |

**Join naturale:** Ricostruisce correttamente i dati originali → decomposizione senza perdita.

**Caso problematico (senza FD A → B):**
Se decomponiamo in R1(B,C) e R2(A,C), il join può creare tuple spurie.

---

### 10. Algoritmo per decomposizione in BCNF

**Caso complesso:** 
R(Studente, Corso, Professore) con FD:
1. Studente, Corso → Professore
2. Professore → Corso

**Passaggi:**
1. Chiavi candidate: {Studente, Corso} e {Studente, Professore}
2. FD problematica: Professore → Corso (LHS non è superchiave)
3. Decomposizione:
   - R1(Professore, Corso)
   - R2(Studente, Professore)

**Verifica:**
- R1 soddisfa BCNF (Professore è chiave)
- R2 non ha FD non banali → BCNF

**Perdita dipendenze:** FD originale Studente,Corso→Professore non è preservata.



1. Finché esiste una FD X → A che viola BCNF:
2. Dividi in:

   * R1 = (X ∪ A)
   * R2 = (T \ A)
3. Ripeti ricorsivamente su R1, R2

* Garantisce: dati preservati
* Non garantisce: dipendenze preservate

**Esempio dettagliato:**

Supponiamo lo schema R(A, B, C, D) con F = {A → B, B → C, C → D}

1. Calcoliamo le chiavi:

   * A+ = {A, B, C, D} ⇒ A è chiave

2. Verifichiamo BCNF:

   * A → B: A è chiave ⇒ OK
   * B → C: B non è chiave ⇒ viola BCNF
   * C → D: C non è chiave ⇒ viola BCNF

3. Decomposizione su B → C:

   * R1 = (B, C)
   * R2 = (A, B, D) (con FD proiettate: A → B, C → D non resta in R2 perché C manca)

4. Verifica in R2:

   * A → B: A è chiave ⇒ OK
   * D non ha dipendenze ⇒ OK

5. Verifica R1:

   * B → C: B non è chiave ⇒ viola BCNF

6. Decomposizione di R1 su B → C:

   * R1a = (B, C)
   * R1b = (C) — da eliminare, già incluso in R1a

7. Schema finale:

   * R1a(B, C)
   * R2(A, B, D)

Nota: la FD C → D è persa nella decomposizione, quindi non tutte le dipendenze sono preservate. Tuttavia, lo schema risultante è in BCNF e preserva i dati (nessuna perdita informativa con join naturali).

---

### 11. Algoritmo per decomposizione in 3NF

1. Trova copertura minima G di F
2. Per ogni FD X → Y in G crea relazione XY
3. Se nessuna relazione contiene una chiave di R, aggiungila

* Garantisce: dati e dipendenze preservate
* Tutte le relazioni in 3NF

**Esempio pratico:**

Schema: R(A, B, C, D) con F = {A → B, B → C, C → D, A → D}

1. Troviamo una copertura minima:

   * Scomponiamo RHS:

     * F1 = {A → B, B → C, C → D, A → D}
   * Nessun attributo estraneo
   * Verifica ridondanza:

     * A → D è implicata? A+ = {A, B} → B → C → C → D ⇒ A+ = {A, B, C, D} ⇒ A → D è implicata → possiamo rimuoverla.
     * Risultato: G = {A → B, B → C, C → D}

2. Creiamo una relazione per ogni FD:

   * R1(A, B)
   * R2(B, C)
   * R3(C, D)

3. Controlliamo se abbiamo una relazione che contiene una chiave:

   * A+ con G = {A → B, B → C, C → D} ⇒ A+ = {A, B, C, D} ⇒ A è chiave
   * Nessuna delle R1–R3 contiene tutti questi attributi, quindi aggiungiamo:
   * R4(A, C, D) oppure R4(A, B, C, D)

4. Schema finale:

   * R1(A, B)
   * R2(B, C)
   * R3(C, D)
   * R4(A, B, C, D)

Tutte le relazioni sono in 3NF, e sia le FD che i dati sono preservati. copertura minima G di F
2\. Per ogni FD X → Y in G crea relazione XY
3\. Se nessuna relazione contiene una chiave di R, aggiungila

**Scenario ospedaliero:**
R(Paziente, Medico, Reparto, Specializzazione) con FD:
1. Medico → Reparto
2. Reparto → Specializzazione
3. Paziente, Medico → Reparto

**Copertura minima:**
- Decomponi RHS: già elementari
- Rimuovi attributi estranei: nessuno
- Elimina FD ridondanti: Paziente,Medico→Reparto è implicata da Medico→Reparto? No.

**Decomposizione:**
1. R1(Medico, Reparto)
2. R2(Reparto, Specializzazione)
3. R3(Paziente, Medico)
4. Aggiungi chiave originale (Paziente, Medico) se necessario

---

### 12. Verifica di BCNF / 3NF

**BCNF:** Per ogni FD non banale X → A, X è superchiave
**3NF:** X è superchiave oppure A è attributo primo

* 3NF ∈ BCNF ma più permissiva

**Tabella Non Normalizzata (1NF):**
| OrdineID | Prodotti (Lista) |
|----------|------------------|
| 1001     | Penna, Matita   |

**Dopo 1NF:**
| OrdineID | Prodotto |
|----------|----------|
| 1001     | Penna    |
| 1001     | Matita   |

**Violazione 2NF:**
| OrdineID | Prodotto | Prezzo |
|----------|----------|--------|
| 1001     | Penna    | 1.50   |
| 1001     | Matita   | 0.80   |

FD: OrdineID → Prezzo (dipendenza parziale dalla chiave composta)


---

### 13. Applicazioni alla Progettazione Concettuale

**Verifica su entità**

* PartitaIVA → Nome, Indirizzo: viola 3NF se PartitaIVA non è chiave

**Verifica su relationship**

* Studente → Corso, Professore: se Professore → Dipartimento, e Professore non è chiave, → violazione 3NF

- **Modello E-R per biblioteca:**

   [Utente]--->Prestito<---[Libro]

   **Traduzione in relazione:**
   Prestito(CF_Utente, CodiceLibro, DataPrestito, TitoloLibro, Genere)

   **FD problematiche:**
   - CodiceLibro → TitoloLibro, Genere (viola 3NF)

   **Decomposizione corretta:**
   1. Prestiti(CF_Utente, CodiceLibro, DataPrestito)
   2. Libri(CodiceLibro, TitoloLibro, Genere)


---

### 14. Esempi di decomposizione errata

**Perdita di dati:**

* Join su proiezioni produce tuple spurie

**Perdita di dipendenze:**

* Se X → Y ma X e Y in relazioni separate, non preservata

**Caso 1 - Anomalia di Inserimento:**
Tabella non normalizzata ClientiOrdini:
| ClienteID | OrdineID | DettagliCliente |
|-----------|----------|------------------|
| C001      | O1001    | Via Roma 5       |
| C001      | O1002    | Via Roma 5       |

**Problema:** Per inserire un nuovo cliente senza ordini, devo inserire un ordine fittizio.

**Caso 2 - Anomalia di Cancellazione:**
Se elimino l'ultimo ordine di C001, perdo l'indirizzo del cliente.

---

### 15. Diagrammi Decisionali
```plantuml
start
if (FD X→Y) then (X superchiave?)
  :BCNF OK;
else
  :Decomponi in R1(XY)\nR2(T-Y);
endif

if (A è attributo primo?) then (yes)
  :3NF OK;
else (no)
  :Decomponi;
endif
stop
```

---
