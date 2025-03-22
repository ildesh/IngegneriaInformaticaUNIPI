<h1> Lezione 4 - 12-03-2025 - 13-03-2025 </h1>

---

<h1> 📚 Indice </h1>

- [Calcolo relazionale](#calcolo-relazionale)
  - [Che cos'è il calcolo relazionale?](#che-cosè-il-calcolo-relazionale)
- [Calcolo sui domini](#calcolo-sui-domini)
  - [Formule Atomiche](#formule-atomiche)
    - [Convenzioni:](#convenzioni)
  - [Il valore di verità di una formula](#il-valore-di-verità-di-una-formula)
  - [Espressioni del calcolo sui domini](#espressioni-del-calcolo-sui-domini)
    - [Esempio 1 - Selezione di studenti con voto maggiore di 27:](#esempio-1---selezione-di-studenti-con-voto-maggiore-di-27)
    - [Esempio 2 - Attraverso due relazioni...](#esempio-2---attraverso-due-relazioni)
  - [Dipendenza dal dominio](#dipendenza-dal-dominio)
  - [Indipendenza dal dominio](#indipendenza-dal-dominio)
- [Calcolo sulle tuple](#calcolo-sulle-tuple)
  - [Target list](#target-list)
  - [Range List](#range-list)
  - [Formule](#formule)
- [Calcolo sulle n-uple: Caratteristiche e Limitazioni](#calcolo-sulle-n-uple-caratteristiche-e-limitazioni)
  - [Vantaggi](#vantaggi)
  - [Limitazioni significative](#limitazioni-significative)
  - [Confronto tra Calcolo Relazionale e Algebra Relazionale](#confronto-tra-calcolo-relazionale-e-algebra-relazionale)
    - [Equivalenza fondamentale](#equivalenza-fondamentale)
    - [Limiti comuni a entrambi i formalismi](#limiti-comuni-a-entrambi-i-formalismi)

---


## Calcolo relazionale

### Che cos'è il calcolo relazionale?

>[!TIP]
>Il calcolo relazionale è una famiglia di **linguaggi dichiarativi** basati sul calcolo dei predicati del primo ordine.
Esistono diverse versioni:
1. **_Calcolo relazionale sui domini_**
  - Calcolo sui domini, in breve
2. **_Calcolo su n-uple con dichiarazione di range_**
  - Calcolo sulle tuple, in breve
  - base per il linguaggio SQL

- I **_simboli di predicato_** corrispondono alle relazioni presenti nella base di dati.
  - Non compaiono simboli di funzione.
- Nel calcolo relazionale vengono utilizzate prevalentemente **_formule aperte_**, cioè formule con variabili libere, il cui valore di verità dipende dai valori assegnati alle variabili libere.
    - Il risultato di un’interrogazione (formula aperta) è costituito dalle tuple di valori che, sostituiti alle variabili libere, la rendono vera.
- In coerenza con quanto fatto in algebra relazionale (attributi con nome), utilizzeremo una **_notazione non posizionale_**.

---

## Calcolo sui domini

- **_Sintassi_**: le **espressioni** hanno la forma:
$$
{A_1 : x_1, …, A_k : x_k |f}
$$

- dove:
  -  A<sub>1</sub>,…, A<sub>k</sub> sono attributi distinti (possono anche non comparire nello schema della base di dati).
  -  x<sub>1</sub>,…, x<sub>k</sub> sono variabili (che assumiamo essere distinte, nonostante non sia strettamente necessario).
  -  A<sub>1</sub> : x<sub>1</sub>,…, A<sub>k</sub> : x<sub>k</sub> è chiamata target list (lista degli obiettivi), e descrive il risultato.
  - f è una **formula** costruita a partire da formule atomiche utilizzando eventualmente i connettivi Booleani e quantificatori ∃x e ∀x, con x variabile.

### Formule Atomiche

- $R(A_1 : x_1, \ldots, A_p : x_p)$, dove $R(A_1, \ldots, A_p)$ è uno **schema di relazione** e $x_1, \ldots, x_p$ sono variabili
- Interpretabile come $[x_1, \ldots, x_p] \in R$
- $x_i$ OP $x_j$
- dove $x_i$ e $x_j$ sono variabili e OP è un **operatore di confronto** $<, >, =, \leq, \geq, \neq$
- $x_i$ OP $c$ oppure $c$ OP $x_i$
- dove $c$ è una costante (nel dominio $A_i$ di $x_i$)

Le formule atomiche sono formule:

- Se *f* è una formula, allora anche ¬*f* lo è.
- Se *f₁* e *f₂* sono formule, allora anche (*f₁ ∧ f₂*) lo è.
- Se *f₁* e *f₂* sono formule, allora anche (*f₁ ∨ f₂*) lo è.
- Se *f* è una formula e *x* è una variabile, allora anche  
- ∃*x(f)* e ∀*x(f)* sono formule, dove ∃ e ∀ sono quantificatori.

#### Convenzioni:

- Per convenienza, useremo le parentesi laddove necessario.
- Raggrupperemo le variabili usate nei quantificatori con la medesima formula;  
  per esempio:  
  ∃*x(∃y(f))* ≡ ∃*x, y(f)*

### Il valore di verità di una formula

- Il **valore di verità di una formula** è definito nel modo seguente (assumiamo per semplicità che tutti gli attributi abbiano lo stesso dominio):

  - una formula atomica $R(A_1 : x_1, \ldots, A_p : x_p)$ è vera sui valori di $x_1, \ldots, x_p$ che costituiscono una $n$-upla di $R$
  
  - una formula atomica $x\theta y$ ($x\theta c$) è vera sui valori $x$ e $y$ che rendono vera la condizione $\theta$
  
  - il valore di verità di $\land$, $\lor$ e $\neg$ è definito nel modo usuale
  
  - una formula della forma $\exists x(f)$ (rispettivamente, $\forall x(f)$) è vera se esiste almeno un elemento del dominio che (rispettivamente, ogni elemento del dominio), sostituito ad $x$, rende vera $f$

### Espressioni del calcolo sui domini

- Un'espressione del calcolo sui domini:
  
  $$
  A_1 : x_1, \dots, A_k : x_k \mid f
  $$

- può essere "interpretata" come una **formula logica** del tipo
  
  $$
  \{x_1, \ldots, x_k | f(x_1, \ldots, x_k)\}
  $$

- dove:
  - $x_1, \ldots, x_k$ sono **variabili o costanti**
  - $f(x_1, \ldots, x_k)$ è un **predicato** che può essere _VERO o FALSO_

- **Semantica**: il risultato di un'espressione del calcolo sui domini è una relazione su $A_1, \ldots, A_k$ che contiene $n$-uple di tutti i possibili valori per $x_1, \ldots, x_k$ che rendono vero il predicato $f(x_1, \ldots, x_k)$ rispetto a un'istanza di base di dati a cui l'espressione è applicata

#### Esempio 1 - Selezione di studenti con voto maggiore di 27:

Supponiamo di avere una relazione Studenti con il seguente schema: $\text{Studenti(Nome, Matricola, Voto)}$

>[!TIP] 
>### Cosa vogliamo trovare?
> Vogliamo trovare i nomi e le matricole degli studenti che hanno preso un voto maggiore di 27.

Espressione del calcolo sui domini:

$$
\{ Nome: x, Matricola: y \ | \ \exists v (Studenti(Nome: x, Matricola: y, Voto: v) \land v > 27) \}
$$

Avendo questa espressione possiamo dire che:
1. x è il **_nome del corso_**
2. y è la **_matricola dello studente_**
3. v è il **_voto dello studente_**
4. La condizione v > 27 assicura che selezioniamo gli **_studenti con voto superiore a 27._**

#### Esempio 2 - Attraverso due relazioni...

>[!TIP] 
> ### Sapendo che abbiamo due relazioni...
>- Impiegato(Matr, Nome, Età, Stipendio)
>- Supervisione(Matr, Capo)


L'esercizio chiede di:
>[!IMPORTANT] 
> #### Selezionare i nomi degli impiegati con stipendio superiore a 3000

Scrivi un'espressione in calcolo relazionale per ottenere i nomi degli impiegati che guadagnano più di 3000 euro.
Per risolverlo possiamo:
1. utilizzare la relazione Impiegato: 
$
Impiegato(\text{Matr}, \text{Nome}, \text{Età}, \text{Stipendio})
$
- Matr = Matricola dell'impiegato
- Nome = Nome dell'impiegato
- Età = Età dell'impiegato
- Stipendio = Stipendio dell'impiegato

1. utilizzare il vincolo sullo stipendio:
    - Poiché vogliamo selezionare i nomi degli impiegati con stipendio superiore a 3000, dobbiamo estrarre solo le informazioni pertinenti da questa relazione.

2. Definiamo le variabili:
Ogni attributo della relazione verrà associato a una variabile:
- **_m_** → variabile per Matr
- **_x_** → variabile per Nome
- **_e_** → variabile per Età
- **_s_** → variabile per Stipendio

1. Scrivere la formula logica:
Ora possiamo scrivere la formula logica che descrive il problema:

$$ 
Nome:x ∣ ∃m,e,s(Impiegato(Matr:m,Nome:x,Etaˋ:e,Stipendio:s)∧s>3000) 
$$

5. Spiegando la formula in maniera frasale possiamo dire che:
>[!TIP] 
> ### Soluzione
>Esistono delle variabili _(∃m, e, s)_ che rappresentano i valori di _**Matr (m)**_, _**Età (e)**_ e _**Stipendio (s)**_ per un impiegato, tale che **l'impiegato abbia Matr (m), Nome (x), Età (e) e Stipendio (s)**, ossia _Impiegato(Matr: m, Nome: x, Età: e, Stipendio: s)_, con la **_condizione che s > 3000_**.

### Dipendenza dal dominio

>[!IMPORTANT] 
> ### Che cos'è la dipendenza del dominio, o meglio, come si verifica?
>La dipendenza dal dominio si verifica quando il risultato di un'espressione del calcolo relazionale dipende non solo dalle tuple presenti nelle relazioni della base di dati, ma anche dall'insieme completo di valori possibili (dominio) degli attributi coinvolti nell'espressione.

1. Mostriamo il primo esempio:

    ${A : x, B : y \space| \space R(A : x) ∧ y = y}$

   - In questa espressione, nel risultato compaiono tuple per qualsiasi valore del dominio di B
   - Se il dominio di B è infinito, il risultato sarà infinito
   - Se il dominio di B cambia, il risultato cambia (questo è esplicitamente indicato come "dipendenza dal dominio")

2. Mostriamo il secondo esempio:

    ${A : x \space|\space ¬R(A : x)}$
    
    - In questo caso, nel risultato **compaiono tuple per qualsiasi valore del dominio di A che non compaiono in R**
    - Questo è in contrasto con l'algebra relazionale, dove, _"tutte le espressioni hanno un senso"_, ovvero c'è "**_indipendenza dal dominio_**". In algebra relazionale, i risultati dipendono solo dai dati effettivamente presenti nelle relazioni, non dai possibili valori dei domini.

  
<p align="center" style="font-size: 24px"><strong>La dipendenza dal dominio può essere problematica perché:</strong></p>

<ul align="center">
    <li>Rende <strong><i>i risultati delle query potenzialmente infiniti</strong></i>
    <li>Fa sì che i risultati cambino se cambia la definizione del dominio, anche se i dati nelle relazioni rimangono gli stessi
    Introduce verbosità e complessità nelle espressioni, come indicato nei <strong><i>"Difetti"</i></strong> menzionati nell'immagine
</ul>

### Indipendenza dal dominio

- **Un’espressione** di un linguaggio di interrogazione si dice
**_indipendente dal dominio_** se il suo risultato, su ciascuna istanza della base di dati, non varia al variare del dominio rispetto al quale l’espressione viene valutata (purché ogni dominio contenga almeno i valori presenti nell’istanza e nell’espressione);
- **_Un linguaggio_** si dice **_indipendente dal dominio_** se tali sono tutte
le sue espressioni;
- Il **_calcolo sui domini_** non è indipendente dal dominio;
- **_L’algebra relazionale_** è indipendente dal dominio:
  - Costruisce i risultati a partire dalle relazioni presenti nella base didati, senza far mai riferimento ai domini degli attributi: i valori che compaiono nei risultati sono tutti presenti nell’istanza cui l’espressione viene applicata.

---

## Calcolo sulle tuple

Il **calcolo su tuple** è un modello formale per esprimere interrogazioni sui database relazionali. Deriva dal **calcolo su domini**, ma semplifica la scrittura delle formule trattando **_INTERE TUPLE_** invece di **_SINGOLI VALORI_**.

Il calcolo su domini presenta lo svantaggio di richiedere **numerose variabili**, spesso una per ciascun attributo di ciascuna relazione coinvolta (lo stesso con i quantificatori)

Nel calcolo su domini, ogni valore di un attributo deve essere trattato separatamente con una variabile. Questo comporta:
- ✔ Un numero elevato di variabili, rendendo le query lunghe e difficili da leggere.
- ✔ La necessità di gestire esplicitamente i quantificatori esistenziali e universali per ciascun valore.

Le espressioni hanno la forma:

$$
\{\text{T} | \text{L} | \text{f}\}
$$

dove: 
- **T** è una **_Target List_** (obiettivo dell'interrogazione);
- **L** è una **_Range List_** (lista di variabili di range):
- **f** è una **_Formula_** (formula che specifica la condizione).

### Target list

La **Target List** rappresenta il risultato della query ed è ottenuta tramite **proiezione** di alcuni attributi della relazione.  
Questa proiezione può essere formalizzata con le seguenti notazioni:  

1. **\( Y : x . Z \)** → Definisce Y come l'insieme degli attributi \( Z \) della tupla \( x \).  
   - Esprime la selezione di un sottoinsieme di attributi da una tupla.  

2. **\( x . Z \equiv Z : x . Z \)** → Indica che la proiezione può essere espressa in entrambi i modi.  
   - Mostra che la notazione può essere scritta sia indicando la variabile prima che dopo.  

3. **\( x . * \equiv X : x . X \)** → Seleziona **tutti gli attributi della tupla \( x \)**.  
   - Significa che prendere tutti gli attributi equivale a fare una proiezione sull'intero insieme degli attributi della relazione.  

### Range List

- L è una lista che contiene, senza ripetizioni, tutte le
variabili della target list, con la relazione associata da
cui sono prelevati i valori assunti dalla variabile.

  - in altre parole, nella relazione...

    $$ L \equiv x_1(R_1), \dots, x_k(R_k) $$

    - **_x<sub>i</sub>_** è una variabile;
    - **_R<sub>i</sub>_** è una relazione.

- L è una dichiarazione di range: specifica l’insieme dei
valori che possono essere assegnati alle variabili:
  - Non occorrono più condizioni atomiche che vincolano una tupla ad appartenere ad una relazione. 

### Formule 

Rappresentiamo le formule tramite le seguenti notazioni:
- **_x<sub>i</sub>_** indica una variabile, **_c_** indica una costante.
- **_A<sub>i</sub>_** indica un attributo, **_R_** indica una relazione.

>[!WARNING]
> La formule atomiche sono formule!!

Detto ciò possiamo rappresentare le formule atomiche nel seguente modo:

- **_x<sub>i</sub>_** . **_A<sub>i</sub>_** OP **_x<sub>j</sub>_** . **_A<sub>j</sub>_**
- **_x<sub>i</sub>_** . **_A<sub>i</sub>_** OP **_c_**
- **_c_** OP **_x<sub>i</sub>_** . **_A<sub>i</sub>_**

Rappresentiamo delle regole che possono essere applicate alle **_funzioni_**

- Se f è una formula, allora anche ¬f lo è;
- Se f<sub>1</sub> e f<sub>2</sub> sono formule, allora anche f<sub>1</sub> ∧ f<sub>2</sub> lo è;
- Se f<sub>1</sub> e f<sub>2</sub> sono formule, allora anche f<sub>1</sub> ∨ f<sub>2</sub> lo è;
- Se f è una formula e x una variabile che indica una n-upla su R, allora anche ∃x(R)(f) e ∀x(R)(f) sono formule, dove ∃ e ∀ sono **quantificatori**;
  - Notare che anche i **quantificatori** contengono ora delle
**dichiarazioni di range**; 
  - ∃x(R)(f) significa “esiste nella relazione R una n-upla x che
soddisfa la formula f”.

---

## Calcolo sulle n-uple: Caratteristiche e Limitazioni

Il calcolo relazionale sulle n-uple è un formalismo per interrogare database relazionali dove le variabili rappresentano tuple complete invece di singoli valori.

### Vantaggi
- **Minore verbosità**: Poiché le variabili rappresentano tuple intere, le espressioni risultano più compatte rispetto ad altri formalismi.

### Limitazioni significative
- **Problemi con l'unione**: Non è possibile esprimere direttamente le unioni tra relazioni.
  - Questo accade perché ogni variabile nel risultato può avere un solo range di definizione, mentre nell'unione vorremmo includere tuple provenienti da relazioni diverse (`R₁(AB) ∪ R₂(AB)`).
  - In altri termini, non possiamo dichiarare che una variabile rappresenti contemporaneamente tuple di due relazioni diverse.

- **Altre operazioni insiemistiche**:
  - L'intersezione e la differenza sono invece esprimibili nel calcolo relazionale sulle n-uple.
  
- **Impatto su SQL**:
  - SQL, essendo basato sul calcolo relazionale su tuple, include un operatore esplicito di unione (`UNION`).
  - Non tutte le implementazioni di SQL supportano nativamente intersezione (`INTERSECT`) e differenza (`EXCEPT`).


### Confronto tra Calcolo Relazionale e Algebra Relazionale

#### Equivalenza fondamentale
 - Per ogni espressione del calcolo relazionale indipendente dal dominio esiste un'espressione equivalente nell'algebra relazionale.
 - Per ogni espressione dell'algebra relazionale esiste un'espressione equivalente nel calcolo relazionale (che sarà quindi indipendente dal dominio).

#### Limiti comuni a entrambi i formalismi
 Nonostante la loro equivalenza, ci sono interrogazioni importanti che non possono essere espresse né nel calcolo né nell'algebra relazionale:

1. **Calcolo di valori derivati**:
 - Entrambi i formalismi permettono solo di estrarre valori esistenti, non di calcolarne di nuovi.
 - Questo vale sia a livello di:
   - Tuple o singoli valori (conversioni, somme, differenze, ecc.)
   - Insiemi di tuple (somme aggregate, medie, ecc.)

2. **Interrogazioni ricorsive**:
 - Non è possibile esprimere interrogazioni inerentemente ricorsive, come la chiusura transitiva di una relazione.
 - Esempio tipico: trovare tutti i percorsi possibili in un grafo partendo da un nodo, che richiede l'applicazione ripetuta di un'operazione fino al raggiungimento di un punto fisso.
