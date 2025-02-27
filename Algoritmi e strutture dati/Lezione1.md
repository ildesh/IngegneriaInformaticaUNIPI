# Lezione 1 - Algoritmi e strutture dati
## | Nozione di Algoritmo

Un algoritmo è una sequenza finita di passaggi ben definiti che, dati alcuni input, produce un output desiderato. Gli algoritmi sono fondamentali in informatica per risolvere problemi e automatizzare processi.

Prime caratterizzazioni di algoritmo e computer:
- Alan Turing (1936) - Macchina di Turing;
- Alonzo Church (1936) - Lambda calcolo;
- John von Neumann (1945) - Architettura di von Neumann;
- John Backus (1957) - Linguaggio Fortran;
- John McCarthy (1958) - Linguaggio Lisp;
- etc.. etc.. etc..

---

### | Caratteristiche di un algoritmo:

1. **Insieme finito** di passaggi ben definiti: Ogni passo deve essere chiaro e non ambiguo.
2. **Input**: Dati di ingresso su cui l'algoritmo opera.
3. **Output**: Risultato prodotto dall'algoritmo.
4. Ogni istruzione deve essere eseguibile in un **tempo finito**.
5. L'algoritmo deve essere **deterministico**: per gli stessi input, l'algoritmo deve produrre gli stessi output.
   
#### Primi esempi di algoritmi nella storia:

- **Algoritmo di Euclide** per il calcolo del massimo comune divisore (MCD) di due numeri (300 a.c.).
- **Setaccio di Eratostene** per trovare tutti i numeri primi minori di un certo numero (I secolo d.c.).

L'algoritmo può essere visto come l'essenza computazionale di un programma, nel senso che fornisce il procedimento per giungere alla soluzione di un dato problema di calcolo.
L'algoritmo è DIVERSO dal programma perché:
- Programma è la codifica di un algoritmo in un linguaggio di programmazione.
- Un algoritmo può essere visto come un programma distillato da dettegli riguardanti il linguaggio di programmazione, ambiente di sviluppo, sistema operativo.
- L'algoritmo è indipendente dal linguaggio di programmazione ed è un concetto autonomo da quello di programma.

---

### | Perché studiare gli algoritmi?

Ricordando Donald Knuth, profeossere emerito di informatica all'Università di Stanford, dice: 

#### Importanza teorica:

<blockquote>

"Se è vero che un problema non si capisce a fondo finch+ non lo si deve insegnare a qualcuno altro, a maggior ragione nulla è compreso in modo più approfondito di ciò che si deve insegnare ad una macchina, ovvero di ciò che va espresso tramite un algoritmo."

</blockquote>

#### Importanza pratica:

<blockquote>

"Se vuoi diventare un programmatore di classe mondiale, hai due scelte:

1. programma ogni giorno per 10 anni
2. oppure programma ogni giorno per 2 anni ...

</blockquote>

#### Esempio: PROBLEMA DEL MASSIMO COMUN DIVISORE FRA DUE NUMERI INTERI NON NEGATIVI - uso di un algoritmo di Euclide

MCD(30,21) = 3

Il MCD fra due numeri è uguale al MCD fra il più piccolo dei due e la loro differenza.

```cpp
int MCD(int x, y){
    while(x != y){
        if(x < y) y = y-x; 
        else x = x-y;
    }
    return x;
}
```

Risoluzione con calcoli (differenza tra numeri):

Passaggio  |Operazione  |x	|y
|-----------|----------|-----------|-----------|
|Iniziale	|MCD(30, 21)	|30	|21
|1° iterazione	|30 > 21, x = x - y	|9	|21
|2° iterazione	|21 > 9, y = y - x	|9	|12
|3° iterazione	|12 > 9, y = y - x	|9	|3
|4° iterazione	|9 > 3, x = x - y	|6	|3
|5° iterazione	|6 > 3, x = x - y	|3	|3
|Fine	|x == y, MCD = 3	|3	|3


```cpp
int MCD(int x, y){
    while (y != 0){
        int k = x;
        x = y;
        y = k % y;
    }
    return x;
}
```

Risoluzione con calcoli (Algoritmo di Euclide):


|Passaggio  |Operazione| Risultato |
|-----------|----------|-----------|
|MCD(30, 21)|  30 % 21 |	 9     |
|MCD(21, 9)	|  21 % 9  |	 3     |
|MCD(9, 3)  |   9 % 3  |	 0     |
|MCD(3, 0)  |	 -	   |     3     |


#### Esempio: Trovare tutti i numeri primi fino a un dato numero \( n \) - uso del Crivello di Eratostene

Esistono diversi approcci per trovare tutti i numeri primi fino a un numero \( n \):

1. **Metodo ingenuo (molto inefficiente):**  
   - Per ogni numero da \( 2 \) a \( n \), controllare se è primo dividendo per tutti i numeri precedenti.  
   - Complessità: **O(n²)**.

2. **Metodo leggermente migliorato:**  
   - Per ogni numero da \( 2 \) a \( n \), controllare se è primo dividendo solo per i numeri primi già trovati minori o uguali alla sua radice quadrata.  
   - Complessità: **O(n \sqrt{n})**.

3. **Crivello di Eratostene (efficiente):**  
   - Creare un array di booleani di dimensione \( n+1 \) inizializzato a `true`.  
   - Segnare come `false` i multipli di ogni numero primo trovato, eliminandoli dal conteggio.  
   - Complessità: **O(n log log n)**, molto più veloce rispetto agli approcci precedenti.

Esempio di implementazione del Crivello di Eratostene in C++:

```cpp
#include <iostream>
using namespace std;

void crivelloEratostene(int n) {
    bool primo[n + 1];  
    fill(primo, primo + n + 1, true);  

    for (int p = 2; p * p <= n; p++) {  
        if (primo[p]) {  
            for (int i = p * p; i <= n; i += p)  
                primo[i] = false;  
        }  
    }

    cout << "Numeri primi fino a " << n << ": ";
    for (int p = 2; p <= n; p++) {
        if (primo[p]) cout << p << " ";
    }
    cout << endl;
}

int main() {
    int n = 50;  
    crivelloEratostene(n);
    return 0;
}
```

Eseguendo il codice con 
𝑛 = 50, otterremo:
```output
"Numeri primi fino a 50: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47"
```

---

### | CONCETTI CHIAVE APPLICATI AL NOSTRO CASO:

1. **Complessità temporale dell'algoritmo:**  
   - Indica il numero di operazioni eseguite dall'algoritmo per trovare tutti i numeri primi fino a un certo valore \( n \).  
   - Per il **Crivello di Eratostene**, la complessità è **O(n log log n)**, che è molto efficiente rispetto ad altri approcci.

2. **Complessità temporale nel caso peggiore:**  
   - Rappresenta il massimo numero di operazioni eseguite dall'algoritmo su un'istanza di dimensione \( n \).  
   - Nel caso del Crivello di Eratostene, il caso peggiore rimane **O(n log log n)**, poiché ogni numero viene visitato al massimo un numero limitato di volte.

3. **Efficienza dell'algoritmo:**  
   - L'efficienza dipende dal rapporto tra la complessità e le prestazioni pratiche.  
   - Il Crivello di Eratostene è molto più efficiente rispetto al controllo ingenuo di primalità (O(n²)) o alla verifica fino alla radice quadrata di ogni numero (O(n√n)).  
   - Questo lo rende uno degli algoritmi più usati per generare numeri primi fino a grandi valori di \( n \).

In sintesi, il Crivello di Eratostene è uno degli algoritmi più veloci per la generazione di numeri primi in un intervallo dato e viene spesso utilizzato in problemi di teoria dei numeri e in competizioni di programmazione.

Complessità di un algoritmo: funzione (sempre positiva) che associa alla dimensione del problema il costo della sua risoluzione

- Costo della risoluzione: tempo di esecuzione o spazio utilizzato
- Dimensione del problema: numero di elementi di input o valore massimo di input

---

### | Complessità vs Profiling

**_Profiling_**: tecnica utilizzata per misurare le prestazioni di un programma in esecuzione, fornendo informazioni dettagliate su tempo di esecuzione, utilizzo della memoria e altre metriche rilevanti.
Questa misura dipende da fattori specifici dell'ambiente di esecuzione e dall'instanza considerata.
**_Complessità_**: analisi teorica che descrive come il costo di un algoritmo cresce con la dimensione del problema, indipendentemente dall'ambiente di esecuzione e dall'istanza specifica. E'necessario trovare un metodo di clacolo della complessità

#### caso peggiore, migliore e medio:

Misureremo il tempo di esecuzione di un algoritmo in funzione della dimensione n delle istanze.
Istanze diverse, a parità di dimensione, possono comportare tempi di esecuzione diversi. Per questo motivo, si distinguono tre tipi di complessità:
Distinzione tra caso peggiore, migliore e medio:
- **Caso peggiore**: il tempo massimo necessario per risolvere un problema di dimensione n.
- **Caso migliore**: il tempo minimo necessario per risolvere un problema di dimensione n.
- **Caso medio**: il tempo medio necessario per risolvere un problema di dimensione n, calcolato su tutte le possibili istanze di dimensione n.

##### Esempio: 

$$
T_{p}(n) = \text{complessità del tempo di esecuzione del programma P al variare di n}
$$

```cpp

int max(int a[], int n){
    int m = a[0]; // 1 
    for(int i = 1; i < n; i++){ // - ciclo eseguito n-1 volte
       if(a[i] > m) m = a[i];   // 1 per confronto e 3 per l'assegnazione
    }
    return m; // 1
}

```
L’efficienza deve essere misurata indipendentemente anche da specifiche dimensioni dei dati:
> la funzione della complessità deve essere analizzata nel suo comportamento asintotico

Ma quanto costerà questo algoritmo???

#### | Analisi del Tempo di Esecuzione

Per determinare il tempo di esecuzione, consideriamo le seguenti operazioni:

1. **Inizializzazione di `m`:**
   - L'operazione `int m = a[0];` costa **1 unità di tempo**.
   
   **Tempo**: 1 operazione.

2. **Ciclo `for`:**
   - Ogni iterazione esegue un **confronto** (`a[i] > m`), che costa **1 unità di tempo**.
   - Se il confronto è vero, esegue un'**assegnazione** (`m = a[i]`), che costa **3 unità di tempo**.
   - In totale, per ogni iterazione, il costo è di **4 unità di tempo** (1 per il confronto e 3 per l'assegnazione).
   - Il ciclo si ripete per **(n-1)** iterazioni.
   
   **Tempo**: 4(n-1) operazioni.

3. **Operazione di ritorno:**
   - Il ritorno del valore di `m` (`return m;`) costa **1 unità di tempo**.

4. **Totale:**
   Sommiamo tutte le operazioni per ottenere il tempo totale di esecuzione:
   
   $$
   T_{\text{totale}}(n) = 1 + 1 + 4(n-1) + 1 + 1 = 4n
   $$

Quindi, la complessità temporale dell'algoritmo è **O(n)**.

---

### | Limite asintotico superiore: Notazione O grande:

Una funzione f(n) è di ordine O(g(n)) se esistono una costante c > 0 e un valore di n0 tale che, per ogni n > n0, si verifica:
$$
f(n) ≤ c * g(n)
$$

Questa definizione formale ci dice che, a partire da un certo punto (n₀), la funzione f(n) non crescerà mai più velocemente di g(n), a meno di una costante moltiplicativa (c).
In altre parole, g(n) è un limite superiore per la crescita di f(n) quando n diventa molto grande.

---

### | **Complessità computazionale:**

La complessità computazionale di un algoritmo è una misura della quantità di risorse (come tempo e spazio) necessarie per eseguire l'algoritmo in funzione della dimensione dell'input. La notazione O-grande è utilizzata per descrivere il limite asintotico superiore della complessità temporale di un algoritmo.

**Ricordando che...**

| Funzione | Definizione |
|---|---|
| T<sub>p</sub>(n) | 2n<sup>2</sup> |
| T<sub>q</sub>(n) | 100n |
| T<sub>r</sub>(n) | 5n |

**Analisi della complessità:**

| Affermazione | Risultato | Dettagli |
|---|---|---|
| T<sub>0</sub>(n) è O(T<sub>p</sub>(n)) | **Vero** | [n<sub>0</sub> = 50, c = 1] oppure [n<sub>0</sub> = 1, c = 50] |
| T<sub>R</sub>(n) è O(T<sub>p</sub>(n)) | **Vero** | [n<sub>0</sub> = 3, c = 1] |
| T<sub>R</sub>(n) è O(T<sub>0</sub>(n)) | **Vero** | [n<sub>0</sub> = 1, c = 20] |
| T<sub>0</sub>(n) è O(T<sub>R</sub>(n)) | **FALSO** | |
| T<sub>p</sub>(n) non è O(T<sub>R</sub>(n)) | **Vero** | |
| T<sub>p</sub>(n) non è O(T<sub>0</sub>(n)) | **Vero** | |


**In conclusione,** la complessità computazionale descrive come cresce il tempo di esecuzione di un algoritmo all'aumentare della dimensione dell'input (n). La notazione O-grande è utilizzata per esprimere il limite asintotico superiore della complessità temporale di un algoritmo, fornendo una stima superiore del tempo di esecuzione in funzione di n.

---

### | Regole:

1. Regola dei fattori costanti
    - Se un algoritmo ha una complessità di O(cf(n)), dove 'c' è una costante, allora la complessità può essere semplificata in O(f(n)). In altre parole, le costanti moltiplicative non influenzano la notazione O-grande.
2. Regola della somma
   - Se un algoritmo esegue due blocchi di codice consecutivi con complessità O(f(n)) e O(g(n)), allora la complessità totale dell'algoritmo è O(max(f(n), g(n))). In altre parole, la complessità è determinata dal blocco di codice con il tasso di crescita più elevato.
3. Regola del prodotto
   - Se un algoritmo esegue un blocco di codice con complessità O(f(n)) all'interno di un altro blocco di codice con complessità O(g(n)), allora la complessità totale dell'algoritmo è O(f(n) * g(n)).
4. Regola di transitività
   - Se f(n) è O(g(n)) e g(n) è O(h(n)), allora f(n) è O(h(n)).
5. Per ogni costante k, k è O(1);
6. Per m <= p, n<sup>m</sup> è O(n<sup>p</sup>);
7. Un polinomio di grando m è O(n<sup>m</sup>);


#### Esempi:


1. **Regola dei fattori costanti:**

   - Consideriamo un algoritmo con complessità O(3n). Secondo la regola dei fattori costanti, possiamo semplificare questa complessità in O(n). In altre parole, la costante moltiplicativa 3 non influisce sulla notazione O-grande.
  
2. **Regola della somma:**
   - Supponiamo di avere un algoritmo che esegue due operazioni: una con complessità O(n) e l'altra con complessità O(n^2). Secondo la regola della somma, la complessità totale dell'algoritmo sarà O(max(n, n^2)) = O(n^2).


3. **Regola del prodotto:**
    - Consideriamo un algoritmo che esegue un blocco di codice con complessità O(n) all'interno di un altro blocco di codice con complessità O(n^2). Secondo la regola del prodotto, la complessità totale dell'algoritmo sarà O(n * n^2) = O(n^3).

4. **Regola di transitività:**
    - Se abbiamo f(n) = O(g(n)) e g(n) = O(h(n)), allora f(n) = O(h(n)). 
    - Per esempio, se f(n) = O(n^2) e g(n) = O(n^3), allora f(n) = O(n^3).


5. **Per ogni costante k, k è O(1):**
    - Una costante k è sempre O(1), perché non dipende dalla dimensione dell'input n. Questo significa che qualsiasi operazione che richiede un tempo costante è O(1).
    - Per esempio, l'assegnamento di una variabile a una costante è O(1), perché richiede un tempo costante indipendentemente dalla dimensione dell'input.

6. **Per m <= p, n<sup>m</sup> è O(n<sup>p</sup>):**
    - Per esempio, n<sup>2</sup> è O(n<sup>3</sup>), perché n<sup>2</sup> cresce più lentamente di n<sup>3</sup>.

7. **Per ogni k > 0, n<sup>k</sup> è O(n<sup>k+1</sup>):**
    - Per esempio, n<sup>2</sup> è O(n<sup>3</sup>), perché n<sup>2</sup> cresce più lentamente di n<sup>3</sup>.

--- 

### | Classi di complessità:

1. **O(1) - Costante:**
2. **O(log n) - Logaritmica:**
3. **O(n) - Lineare:**
4. **O(n log n) - Lineare logaritmica:**
5. **O(n^2) - Quadratica:**
6. **O(n^3) - Cubica:**
7. **O(2<sup>n</sup>) - Esponenziale:**
8. **O(n!) - Fattoriale:**
9. **O(√n) - Radice quadrata:**

Queste classi di complessità sono utilizzate per descrivere come il tempo di esecuzione di un algoritmo cresce in relazione alla dimensione dell'input.
