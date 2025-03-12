<h1> Lezione 4 - 12-03-2025 </h1>

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

### Calcolo sui domini

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

>[!TIP] Cosa vogliamo trovare?
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

>[!TIP] Sapendo che abbiamo due relazioni...
>- Impiegato(Matr, Nome, Età, Stipendio)
>- Supervisione(Matr, Capo)


L'esercizio chiede di:
>[!IMPORTANT] Selezionare i nomi degli impiegati con stipendio superiore a 3000

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
>[!TIP] Soluzione
>Esistono delle variabili _(∃m, e, s)_ che rappresentano i valori di _**Matr (m)**_, _**Età (e)**_ e _**Stipendio (s)**_ per un impiegato, tale che **l'impiegato abbia Matr (m), Nome (x), Età (e) e Stipendio (s)**, ossia _Impiegato(Matr: m, Nome: x, Età: e, Stipendio: s)_, con la **_condizione che s > 3000_**.

### Dipendenza dal dominio

>[!IMPORTANT] Che cos'è la dipendenza del dominio, o meglio, come si verifica?
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