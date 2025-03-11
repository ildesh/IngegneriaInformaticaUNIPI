# Lezione 2 - 11/03/2025

## | Classificazione di alcune relazioni di ricorrenza

### Metodo divide et impera:

```cpp
void dividetimpera( S ){
    if ( |S|<= m )
        // risolvi direttamente il problema;
    else {
        // dividi S in b sottoinsiemi S1.. Sb;
        dividetimpera(S i1 );
        ...
        dividetimpera(S ia );
        // combina i risultati ottenuti;
    }
}
```

>[!TIP] Ma che cosa fanno le relazioni di ricorrenza?
>Le relazioni di ricorrenza permettono di analizzare la complessità computazionale degli algoritmi e prevederne le prestazioni.

>[!TIP] Che cos'è il teorema Divide et impera ?
>Il metodo Divide et Impera è una tecnica algoritmica che suddivide un problema in sottoproblemi più piccoli e li risolve ricorsivamente. Alla fine, combina le soluzioni dei sottoproblemi per ottenere il risultato finale.

Riguardo i costi, analizziamo come si deve l'algoritmo. Possiamo dire che il costo di un algoritmo _divide ete impera_ dipende da **tre fattori**:

1. **_Costo della divisione_**: quanto tempo serve per suddividere il problema in sottoproblemi;
2. **_Costo della risoluzione dei sottoproblemi_**: dipende da quanti sottoprolemi vengono creati e dalla loro dimensione;
3. **_Costo della combinazione_**: tempo neessario per unire i risultati dei sottoproblemi.

La formula quindi per calcolare la complessità T(n) è:


T(n) = aT(n/b) + f(n)


Dove:
- a = numero di sottoproblemi in cui il problema viene suddiviso.
- b = fattore con cui la dimensione del problema viene ridotta a ogni passo. 
- f(n) = costo della divisione e della combinazione.

Il modo migliore per capire la crescita di 𝑇(𝑛) è costruire **l'albero della ricorsione**.

#### L'albero di ricorsione:

Ogni volta che applichiamo la ricorsione, la dimensione del problema diminuisce di un fattore 𝑏, quindi il numero di livelli dell'albero ricorsivo è circa:

h=log<sub>b</sub>n

perché la ricorsione si arresta quando il problema raggiunge una dimensione costante (n=1).

#### Qual è il costo per livello?

Il costo per ogni livello ( j ) dell'albero ricorsivo può essere rappresentato come:

$$
a^j f\left(\frac{n}{b^j}\right)
$$

Dove:
- ( a^j ): è il numero di sottoproblemi al livello ( j ),
- f(n / b^j): è il costo di risolvere ciascun sottoproblema, con la dimensione di ogni sottoproblema ridotta di un fattore ( b^j ).

Se supponiamo che il costo di divisione e combinazione sia di tipo ( f(n) = O(n^k)), allora il costo per livello ( j ) diventa:

$$
a^j O\left(\left(\frac{n}{b^j}\right)^k\right) = O\left(a^j n^k b^{-jk}\right)
$$

### Riscrittura dell'espressione

Questa espressione può essere semplificata come segue:

$$
O\left(n^k \cdot \left(\frac{a}{b^k}\right)^j\right)
$$

### Interpretazione

- ( a^j ): rappresenta il numero di sottoproblemi al livello ( j ),
- ((n / b^j)^k): è il costo per risolvere ciascun sottoproblema, dove ogni sottoproblema ha dimensione ridotta di un fattore ( b^j ),
- ((a / b^k)^j): esprime come il costo totale di ogni livello cambia in funzione del numero di sottoproblemi e della dimensione di ciascuno.


Valutiamolo in 3 casi:
1. a = b<sup>k</sup> --> n<sup>k</sup>log<sub>b</sub>n;
   - In questo caso, il numero di sottoproblemi è pari alla potenza della dimensione del problema.  
   - Il costo di divisione e combinazione cresce come ( O(n<sup>k</sup>log n) ), in quanto la somma dei costi sui vari livelli dell'albero risulta essere dominata dal termine (log<sub>b</sub>n).
2. a > b<sup>k</sup> --> a<sup>j</sup> = a<sup>log<sub>b</sub>a</sup> = n<sup>log<sub>b</sub>a</sup>
    - Qui, il numero di sottoproblemi cresce più rapidamente rispetto alla riduzione della dimensione del problema.  
    - Il costo totale è dominato dal termine dell'ultimo livello dell'albero, che cresce esponenzialmente, e la complessità finale è \( O(n<sup>log<sub>b</sub> a) \).  
     - In altre parole, la complessità cresce come la potenza della base a, ridotta dal fattore b.
3. a < b<sup>k</sup> --> n<sup>k</sup>
   - In questo caso, il numero di sottoproblemi cresce più lentamente rispetto alla riduzione della dimensione del problema.  
   - Il costo è dominato dal primo livello dell'albero, dove si verifica la divisione e la combinazione.  
   - Il costo totale è quindi \( O(n<sup>k</sup>) \), poiché i livelli successivi non contribuiscono significativamente al costo complessivo.

---

## Algoritmi di teoria dei numeri

La complessità è calcolata prendendo come misura il
numero di cifre che compongono il numero
Ad esempio:
- L’addizione ha complessità O(n)
- la moltiplicazione che studiamo alle
elementari ha complessità O(n<sup>2</sup>)

>[!TIP] Che cos'è la moltiplicazione veloce?
> La moltiplicazione veloce è una serie di metodi che migliorano l'efficienza dell'operazione di moltiplicazione rispetto al metodo classico. La moltiplicazione classica tra due numeri di n e m cifre richiede un numero di operazioni proporzionale a O(n * m), che può diventare inefficiente per numeri molto grandi. La moltiplicazione veloce cerca di ridurre questo numero di operazioni, cercando di moltiplicare i numeri con un costo computazionale inferiore.

> [!IMPORTANT]
> Molti algoritmi di moltiplicazione veloce si basano sulla tecnica divide et impera, cioè dividono il problema di moltiplicare due numeri in sottoproblemi più piccoli e poi combinano i risultati per ottenere il prodotto finale. Questa tecnica riduce significativamente il numero di moltiplicazioni dirette necessarie.

Un esempio è la **_Moltiplicazione di Karatsuba_**:

Karatsuba è uno degli algoritmi più famosi per la moltiplicazione veloce, sviluppato da Anatolii Alexeevitch Karatsuba nel 1960. L'algoritmo sfrutta il principio del divide et impera, riducendo il numero di moltiplicazioni necessarie.

- Passaggio 1: Divide i numeri A e B in due parti uguali (o quasi) in modo che:

    $$
    A = 10^m \cdot A_1 + A_0
    $$

    $$
    B = 10^m \cdot B_1 + B_0
    $$

- Passaggio 2: Moltiplica i due numeri utilizzando solo 3 moltiplicazioni invece di 4:

    $$
    P_1 = A_1 \cdot B_1
    $$

    $$
    P_2 = A_0 \cdot B_0
    $$

    $$
    P_3 = (A_1 + A_0) \cdot (B_1 + B_0)
    $$

- Passaggio 3: Calcola il prodotto finale come:

    $$
    A \cdot B = 10^{2m} \cdot P_1 + 10^m \cdot (P_3 - P_1 - P_2) + P_2
    $$

In questo modo, Karatsuba riduce la complessità della moltiplicazione da \( O(n^2) \) (dove n è la lunghezza dei numeri) a \( O(n^{\log_2 3}) (approssimato) O(n^{1.585})).

---

## Relazioni lineari
>[!TIP]
>Le relazioni lineari sono un tipo di relazione ricorsiva in cui una funzione T(n) viene definita in termini di valori precedenti di n, solitamente in modo lineare.
>$$
>T(n) = a_1 T(n-1) + a_2 T(n-2) + \dots + a_r T(n-r) + f(n)
>$$


Affinché una relazione lineare abbia una soluzione polinomiale, devono essere soddisfatte determinate condizioni, ovvero:

- Esiste al più un solo:
  - 𝑎<sub>𝑖</sub> =1, e
  - Gli altri coefficienti devono essere pari a 0 (cioè, ci deve essere una sola chiamata ricorsiva).

Queste condizioni implicano che l'algoritmo ricorsivo non deve fare troppe chiamate ricorsive, ma solo una per volta. In altre parole, l'algoritmo deve essere tale che il suo tempo di esecuzione cresce in modo polinomiale, quindi la sua complessità è di tipo 
𝑂(𝑛<sup>𝑘</sup>), dove 𝑘 è il grado del polinomio.

### Relazioni lineare con più chiamate ricorsive:

Se ci sono più di una chiamata ricorsiva (cioè quando ci sono più 𝑎<sub>𝑖</sub> diversi da 0), la relazione tende ad avere una **complessità esponenziale**, non polinomiale. In questi casi, l'algoritmo potrebbe eseguire una grande quantità di chiamate ricorsive, esplorando molte possibili soluzioni in parallelo.

La relazione di ricorrenza si può scrivere nel seguente modo:
$$
T(n) = a_1 T(n-1) + a_2 T(n-2) + \dots + a_r T(n-r) + f(n)
$$

con r >= 2 e più coefficienti non nulli.

### Serie di Fibonacci e Sezione Aurea

#### Serie di Fibonacci come relazione ricorsiva

La **serie di Fibonacci** è definita da una relazione ricorsiva lineare molto semplice:

$$
F(n) = F(n-1) + F(n-2)
$$

Con i casi base:

$$
F(0) = 0, \quad F(1) = 1
$$

Questa è una **relazione ricorsiva lineare** in cui ogni termine è la somma dei due precedenti. È un esempio tipico di una relazione ricorsiva che ha una struttura **polinomiale**, poiché può essere risolta in termini di un'analisi della soluzione del polinomio caratteristico associato.

#### Sezione aurea e serie di Fibonacci

La **sezione aurea**, rappresentata dal numero $\phi$ (phi), è legata alla serie di Fibonacci in un modo molto interessante. La sezione aurea è un numero irrazionale approssimativamente pari a:

$$
\phi = \frac{1 + \sqrt{5}}{2} \approx 1.6180339887...
$$

Con la **sezione aurea** che appare naturalmente in vari contesti matematici, geometria e arte. La connessione con la serie di Fibonacci si verifica quando osserviamo come i **rapporti successivi** di numeri consecutivi nella serie di Fibonacci si avvicinano a $\phi$ man mano che n aumenta.

#### Relazione tra Fibonacci e la sezione aurea

Uno dei risultati più noti riguarda il limite del rapporto tra numeri successivi della serie di Fibonacci:

$$
\lim_{n \to \infty} \frac{F(n)}{F(n-1)} = \phi
$$

Questa formula mostra come i numeri di Fibonacci "convergono" al numero aureo $\phi$ quando si considerano i termini successivi nella sequenza.

#### Approccio ricorsivo alla sezione aurea

Per comprendere come la sezione aurea emerge dalle relazioni ricorsive, possiamo anche risolvere la relazione ricorsiva di Fibonacci utilizzando il metodo delle **soluzioni dell'equazione caratteristica**.

L'equazione caratteristica della relazione ricorsiva di Fibonacci è:

$$
x^2 = x + 1
$$

Le radici di questa equazione sono:

$$
x = \frac{1 \pm \sqrt{5}}{2}
$$

Queste due radici sono la sezione aurea $\phi$ e la sua coniugata $1 - \phi$. La soluzione generale della relazione ricorsiva di Fibonacci è quindi una combinazione lineare di queste due radici:

$$
F(n) = A \cdot \phi^n + B \cdot (1 - \phi)^n
$$

Dove \(A\) e \(B\) sono costanti determinate dai valori iniziali di Fibonacci, ossia $F(0)$ e $F(1)$.

Quando $n$ cresce, il termine che coinvolge $(1 - \phi)^n$ diminuisce rapidamente, poiché $1 - \phi$ è minore di 1, mentre il termine che coinvolge $\phi^n$ cresce esponenzialmente. Questo comporta che, per valori di $n$ grandi, il numero di Fibonacci $F(n)$ cresce approssimativamente come potenza della sezione aurea $\phi^n$.

---

## MergeSort

```cpp
void mergeSort( sequenza S ) {
    if ( |S|<= 1 )
    return;
    else {
    // dividi S in 2 sottosequenze S1 e S2 di uguale lunghezza >;
    mergeSort( S1 );
    mergeSort( S2 );
   // fondi S1 e S2 >;
    }
} 
```