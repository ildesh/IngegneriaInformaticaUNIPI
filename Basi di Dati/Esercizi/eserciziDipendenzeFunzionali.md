Perfetto, ti riscrivo l’esercizio in modo ordinato e chiaro, e aggiungo passo per passo la teoria spiegata mentre viene applicata (così il file diventa sia esercizio che ripasso teorico). Ti formatto tutto già pronto in Markdown.

---

# Esercizi sulle Dipendenze Funzionali

---

## Esercizio 1

**Relazione**:
R(ENLCSDMA)

**Dipendenze Funzionali (DF) date**:

* E → NS
* N → MD
* EN → LCD
* C → S
* D → M
* M → D
* ED → A
* NLC → A

---

### Passo 1: Trova la copertura minimale delle DF

#### 📚 Teoria:

La **copertura minimale** si trova:

* **Step 1**: Porta ogni dipendenza a destra singola (se a destra ci sono più attributi, la si spezza).
* **Step 2**: Riduci la parte sinistra (verifica se qualche attributo nella parte sinistra è "estraneo" cioè ridondante).
* **Step 3**: Elimina eventuali DF ridondanti.

#### 🔎 Applichiamo lo Step 1 (spezziamo a destra):

Partiamo dalle DF originali e spezziamo quelle che hanno più attributi a destra:

* E → NS ➔
  E → N /
  E → S

* N → MD ➔
  N → M /
  N → D

* EN → LCD ➔
  EN → L /
  EN → C /
  EN → D

Le altre restano come sono:

* C → S
* D → M
* M → D
* ED → A
* NLC → A

#### Risultato del primo passo (copertura con lato destro singolo):

```
E → N
E → S
N → M
N → D
EN → L
EN → C
EN → D
C → S
D → M
M → D
ED → A
NLC → A
```

---

### Passo 2: Riduci le parti sinistre (Trova attributi estranei)

#### 📚 Teoria:

Un **attributo estraneo** nella parte sinistra di una DF è un attributo che, se rimosso, lascia inalterata la capacità della DF di determinare l’attributo a destra.

#### 🔎 Analizziamo:

##### a) EN → L

Verifico se **N** è estraneo:
Calcolo la chiusura di **E** (E⁺):

* E → N
* E → S
  Quindi **E⁺ = {E, N, S}**
  Ora, se con queste DF posso ottenere **L**, allora N è estraneo.

**No**, perché per ottenere **L** mi serve la DF EN → L. Quindi N non è estraneo.

##### b) EN → C

Stesso ragionamento:

* **E⁺ = {E, N, S}**
* Non ottengo **C** senza N ➔ Quindi N non è estraneo.

##### c) EN → D

Idem:

* **E⁺** non determina **D** da solo ➔ N non è estraneo.

##### d) ED → A

Verifico se **D** è estraneo:

* E⁺ = {E, N, S}
* Per ottenere D da E:

  * E → N
  * N → D
    Quindi E⁺ = {E, N, S, D}

➡️ Quindi posso scrivere **E → D** indirettamente.

Ora con E⁺ vediamo se ottengo A:

* Se ED → A, e io ho **E** e so ottenere **D** da **E**, allora sì.

➡️ Quindi **ED → A** può diventare **E → A** (D è estraneo).

##### e) NLC → A

Qui devo verificare se **N**, **L** o **C** sono estranei.

* **Test 1 (N estraneo?):**
  Calcolo **LC⁺** usando le DF:

  * LC → (?)
  * C → S
  * N → M, D
  * D → M, M → D
  * EN → L, EN → C, EN → D
  * E → N, E → S

  ➔ LC⁺ = {L, C, S}

  Non ottengo **A** ➔ N non è estraneo.

* **Test 2 (L estraneo?):**
  Calcolo **NC⁺**:

  * N → M, D
  * C → S

  ➔ NC⁺ = {N, C, M, D, S} ➔ Non ottengo **A** ➔ L non è estraneo.

* **Test 3 (C estraneo?):**
  Calcolo **NL⁺**:

  * N → M, D
  * L → (nessuna DF diretta)
  * EN → C, L, D
  * E → N, S

  ➔ NL⁺ = {N, L, M, D} ➔ Non ottengo **A** ➔ C non è estraneo.

✅ Quindi NLC → A resta com'è.

---

### Passo 3: Riscrivo la copertura minimale finale

```
E → N
E → S
E → A  // da ED → A semplificato
N → M
N → D
EN → L
EN → C
EN → D
C → S
D → M
M → D
NLC → A
```

---


## Esercizio 2

**Relazione:**  
R(ABCDEF)

**Insiemi di dipendenze funzionali:**

- **G** = { AB → C, B → A, AD → E, BD → F }  
- **H** = { AB → C, B → A, AD → EF }

### 1. Copertura minimale per **G**

#### Step 1: Rendere il lato destro singolo attributo (forma canonica)
- AB → C ✅ già singolo
- B → A ✅ già singolo
- AD → E ✅ già singolo
- BD → F ✅ già singolo

#### Step 2: Eliminare attributi estranei dal lato sinistro

- **AB → C**  
  - Proviamo a togliere **A**:  
    - Se **B⁺** = {B, A} (grazie a B → A), allora **B⁺** → C?  
      - **B⁺** = {B, A} → **AB → C** ci dà anche C ⇒ **B** da solo può determinare C  
    - Quindi possiamo semplificare: **B → C**
  
- **B → A**  
  - Già minimale, nessun attributo da togliere.
  
- **AD → E**  
  - Proviamo a togliere **A**:
    - **D⁺** = {D} (nessuna FD parte da D) ⇒ non determina E  
  - Proviamo a togliere **D**:
    - **A⁺** = {A} ⇒ non determina E  
  - Quindi **AD → E** è minimale.
  
- **BD → F**  
  - Proviamo a togliere **B**:
    - **D⁺** = {D} ⇒ non determina F  
  - Proviamo a togliere **D**:
    - **B⁺** = {B, A, C} ⇒ non determina F  
  - Quindi **BD → F** è minimale.

#### Step 3: Risultato copertura minimale di **G**
$$
\text{Gmin} = \{ B \to C, B \to A, AD \to E, BD \to F \}
$$

---

### 2. Copertura minimale per **H**

#### Step 1: Rendere il lato destro singolo attributo
- **AB → C** ✅ già singolo
- **B → A** ✅ già singolo
- **AD → EF**  
  - Si spezza in:  
    - **AD → E**  
    - **AD → F**

#### Step 2: Eliminare attributi estranei dal lato sinistro

- **AB → C**  
  - Come prima: **B⁺** = {B, A} → **AB → C** ⇒ **B** da solo determina **C**  
  - Quindi diventa **B → C**

- **B → A**  
  - Già minimale.

- **AD → E**
  - Provare a togliere **A**:
    - **D⁺** = {D} ⇒ non determina E  
  - Provare a togliere **D**:
    - **A⁺** = {A} ⇒ non determina E  
  - Quindi è minimale.

- **AD → F**
  - Provare a togliere **A**:
    - **D⁺** = {D} ⇒ non determina F  
  - Provare a togliere **D**:
    - **A⁺** = {A} ⇒ non determina F  
  - Quindi è minimale.

#### Step 3: Risultato copertura minimale di **H**
$$
\text{Hmin} = \{ B \to C, B \to A, AD \to E, AD \to F \}
$$

---

### 3. Verifica se le due coperture sono uguali

#### Confronto:
- **Gmin**: { B → C, B → A, AD → E, BD → F }
- **Hmin**: { B → C, B → A, AD → E, AD → F }

✅ Le prime tre sono uguali.  
❓ La differenza sta in:  
- **G** ha **BD → F**  
- **H** ha **AD → F**

#### Controllo se sono equivalenti:
- **In G**:  
  - **B → A**, quindi **BD → F** implica:  
    - **A (da B)** + D → F  
    - Quindi **AD → F** (che è presente in H)

- **In H**:  
  - **AD → F** e **B → A** ⇒ **BD → F**  
    - Infatti, B (che dà A) + D → F  

Quindi, sì: **Gmin** e **Hmin** sono equivalenti, rappresentano la stessa chiusura.


---


## Esercizio 3

**Insieme di dipendenze funzionali (F):**

```
F = { ABC → DEG, BD → ACE, C → BH, H → BDE }
```

---

### Passo 1: Riduzione degli attributi estranei

#### 📚 Teoria:

Un attributo è **estraneo** nella parte sinistra di una dipendenza funzionale se, rimuovendolo, la dipendenza continua a essere valida (cioè la chiusura degli attributi rimanenti determina ancora il lato destro).

---

#### 🔎 Analisi delle dipendenze:

1. **ABC → DEG**

  - Verifichiamo se **A** è estraneo:
    - Calcoliamo **BC⁺** (chiusura di BC):
     - BC → DEG (da ABC → DEG, rimuovendo A)
     - C → BH
     - H → BDE
     - **BC⁺ = {B, C, D, E, G, H, A}**
    - **BC⁺** include **DEG**, quindi **A** è estraneo.

  - Riscriviamo la dipendenza come: **BC → DEG**

  - Verifichiamo se **B** è estraneo:
    - Calcoliamo **C⁺** (chiusura di C):
     - C → BH
     - H → BDE
     - **C⁺ = {C, B, H, D, E}**
    - **C⁺** include **DEG**, quindi **B** è estraneo.

  - Riscriviamo la dipendenza come: **C → DEG**

2. **BD → ACE**

  - Verifichiamo se **B** è estraneo:
    - Calcoliamo **D⁺** (chiusura di D):
     - Nessuna dipendenza parte da D direttamente.
     - **D⁺ = {D}**
    - **D⁺** non include **ACE**, quindi **B** non è estraneo.

  - Verifichiamo se **D** è estraneo:
    - Calcoliamo **B⁺** (chiusura di B):
     - Nessuna dipendenza parte da B direttamente.
     - **B⁺ = {B}**
    - **B⁺** non include **ACE**, quindi **D** non è estraneo.

  - La dipendenza rimane: **BD → ACE**

3. **C → BH**

  - Verifichiamo se **C** è minimale:
    - **C** è già singolo, quindi non ci sono attributi da verificare.

  - La dipendenza rimane: **C → BH**

4. **H → BDE**

  - Verifichiamo se **H** è minimale:
    - **H** è già singolo, quindi non ci sono attributi da verificare.

  - La dipendenza rimane: **H → BDE**

---

### Passo 2: Eliminazione delle dipendenze ridondanti

#### 📚 Teoria:

Una dipendenza funzionale è **ridondante** se può essere derivata dalle altre dipendenze nell'insieme. Per verificare, rimuoviamo temporaneamente la dipendenza e calcoliamo la chiusura degli attributi per vedere se il lato destro della dipendenza può essere determinato.

---

#### 🔎 Analisi delle ridondanze:

1. **C → DEG**
  - Rimuoviamo temporaneamente **C → DEG** e calcoliamo **C⁺** usando le altre dipendenze:
    - C → BH
    - H → BDE
    - **C⁺ = {C, B, H, D, E, G}**
  - **C⁺** include **DEG**, quindi **C → DEG** è ridondante.

2. **BD → ACE**
  - Rimuoviamo temporaneamente **BD → ACE** e calcoliamo **BD⁺** usando le altre dipendenze:
    - Nessuna dipendenza determina **A**, **C**, o **E** partendo da **BD**.
    - **BD⁺ = {B, D}**
  - **BD⁺** non include **ACE**, quindi **BD → ACE** non è ridondante.

3. **C → BH**
  - Rimuoviamo temporaneamente **C → BH** e calcoliamo **C⁺** usando le altre dipendenze:
    - Nessuna dipendenza determina **B** o **H** partendo da **C**.
    - **C⁺ = {C}**
  - **C⁺** non include **BH**, quindi **C → BH** non è ridondante.

4. **H → BDE**
  - Rimuoviamo temporaneamente **H → BDE** e calcoliamo **H⁺** usando le altre dipendenze:
    - Nessuna dipendenza determina **B**, **D**, o **E** partendo da **H**.
    - **H⁺ = {H}**
  - **H⁺** non include **BDE**, quindi **H → BDE** non è ridondante.

---

### Passo 3: Risultato finale

Dopo aver eliminato gli attributi estranei e le dipendenze ridondanti, l'insieme minimale delle dipendenze funzionali è:

```
Fmin = {
  BD → ACE,
  C → BH,
  H → BDE
}
```

--- 

## Esercizio 4:

```
F = {AB --> CDE, CE --> AB, A --> G, G --> B}
```

- AB --> C
- AB --> D
- AB --> E
- CE --> A 
- CE --> B
- A --> G
- G --> B
- G --> D

1. A<sup>+</sup> = AGBD ==> B è estraneo
2. C<sup>+</sup> = C ==> C non è estraneo

Ora troviamo le dipendenze ridondanti:

Noi ora abbiamo:

- A --> C
- A --> D
- A --> E
- CE --> A 
- CE --> B
- A --> G
- G --> B
- G --> D


(DA FINIRE)


---

## Esercizio 5

G = {A --> B, C --> AD, AF --> EC}

- F<sup>+</sup> = F
- AF<sup>+</sup> = AFBCED ==> CHIAVE
- CF<sup>+</sup> = CFADEB ==> CHIAVE

- A --> B
- C --> AD
- AF --> E
- AF --> C

1. A<sup>+</sup> = AB ==> non è estraneo
2. F<sup>+</sup> = F == non è estraneo

---

## Esercizio 5:

F = {E --> D, C --> B, CE --> G, B --> A}

- CE<sup>+</sup> = CEDBGA ==> chiave

1. R1 = (ED)
2. R2 = (CB)
3. R3 = (CEG)
4. R4 = (AB)

---

## Esercizio 6:

F = {AB --> CDE, AC --> BDE, B --> C, C --> BD, B --> E}

1. A fa parte della chiave perché non è presente in nessuna della parte destra
2. B fa la stessa cosa

Controlliamo: 

1. AB<sup>+</sup> = ABCDE ==> chiave
2. AC<sup>+</sup> = ACBDE ==> chiave

Facciamo un check se sono tutte in terza forma normale (3FN)

1. AB e AC sono entrambi chiavi quindi va bene così
2. B --> C
   1. B non è superchiave però C fa parte di una delle chiavi
3. C --> B
   1. C non è superchiave però B fa parte di una delle chiavi
4. C --> D
   1. C non è superchiave e D non fa parte delle chiavi (NO 3FN)
5. B --> E
   1. B non è una superchiave e E non fa parte delle chiavi (NO 3FN)

Quindi NON E' IN TERZA FORMA NORMALE!

Calcoliamo dunque la copertura minimale:

1. Troviamo gli attributi estranei:
   1. AB --> C
      1. controlliamo se A è estraneo
         1. B<sup>+</sup> = BCDAE --> A è estraneo
      2. controlliamo se B è estraneo
         1. A<sup>+</sup> = A --> B non è estraneo
   2. AB --> D
      1. non serve
   3. AB --> E
      1. non serve
2. Controlliamo le ridondanze
    1. Controllo **B → C**:
       1. È dato direttamente ⇒ NON ridondante
    2. Controllo **B → D**:
       1. Verifica se **B → D** è derivabile da altre:
          1. B → C e **C → D**
          2. Quindi: B → C → D
             1.  Quindi **B → D è ridondante** (posso eliminarla!)
    3. Controllo **B → E**:
        1. È dato direttamente ⇒ NON ridondante
    4. Controllo **C → B**:
       1.  È dato direttamente ⇒ NON ridondante
    5. Controllo **C → D**:
       1. È dato direttamente ⇒ NON ridondante

    La nostra copertura minimale finale è:
    - B → C
    - B → E
    - C → B
    - C → D

    O magari meglio:
    - B → CE
    - C → BD

3. Visto che non abbiamo ancora la 3FN allora creiamo delle relazioni (decomposizione):
   1. R1 = (BCE)
   2. R2 = (CBD)
   3. R3 = (AB) --> devo mettere una relazione con una chiave perché appunto nelle altre non compare una chiave
4. Adesso è in 3FN!


---
