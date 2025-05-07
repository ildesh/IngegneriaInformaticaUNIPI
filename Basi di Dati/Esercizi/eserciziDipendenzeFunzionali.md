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

✅ Quindi, sì: **Gmin** e **Hmin** sono equivalenti, rappresentano la stessa chiusura.

---

## Risposta Finale

- **Copertura minimale di G**: { B → C, B → A, AD → E, BD → F }  
- **Copertura minimale di H**: { B → C, B → A, AD → E, AD → F }  
- ✅ **Sono equivalenti**.

---
