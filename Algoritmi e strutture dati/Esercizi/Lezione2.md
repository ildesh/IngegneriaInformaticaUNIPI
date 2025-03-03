## Esercizio 1:

>[!TIP]Calcolare la complessità in funzione di n > 0 del seguente frammento di programma con la seguente definizione di f:
>
>```cpp
>for (int j=1 ; j<=f(n) ; j++) a+=n // codice principale
>```
>
>```cpp
>int f (int n){ // funzione f(n)
>    int a=0;
>    for (int j=1; j<=n ; j++) a+=n;
>    return a;
>} 
>```

Per calcolare la complessità in funzione di 
𝑛
n, analizziamo separatamente la funzione f(n) e il ciclo che la utilizza.
1. **Analisi di f(n):**
   - La funzione f(n) contiene un ciclo for che esegue n iterazioni. In ogni iterazione, viene eseguita l'operazione `a += n`, che ha complessità O(1).
   - Quindi, la complessità di f(n) è `O(n)`.
2. **Analisi del ciclo principale:** 
   - Il ciclo principale esegue f(n) iterazioni. Poiché f(n) è O(n), il ciclo principale esegue n iterazioni. In ogni iterazione, viene eseguita l'operazione `a += n`, che ha complessità O(1).
   - Quindi, la complessità del ciclo principale è `O(n * n)` = `O(n^2)`. 

<strong>Combinando le due analisi, la complessità totale dell'algoritmo è `O(n^2)`.</strong>

## Esercizio 2

>[!TIP] Dire, per ogni coppia di funzioni fra quelle definite sotto, se una è O dell’altra oppure no.
>
>$$
>f(n) = 
>\begin{cases} 
>3n^3 + 3n & \text{se } n \text{ è primo} \\ 
>n & \text{altrimenti} 
>\end{cases}
>$$
>
>$$
>g(n) = 
>\begin{cases} 
>4n^3 & \text{se l'ultima cifra di } n \text{ è 0 o 5} \\ 
>n^3 & \text{altrimenti} 
>\end{cases}
>$$
>
>$$
>h(n) = 
>\begin{cases} 
>4n^2 & \text{se } n \text{ è divisore di 50} \\ 
>n^3 & \text{altrimenti} 
>\end{cases}
>$$

Studiamo la complessità di ciascuna funzione e vediamo se una è O dell’altra.
1. f(n):
   - Se n è primo, f(n) = 3n^3 + 3n, che è O(n^3)
   -  Se n non è primo, f(n) = n, che è O(n).- Quindi, f(n) è O(n^3) nel caso peggiore.
2. g(n):
    - Se l'ultima cifra di n è 0 o 5, g(n) = 4n^3, che è O(n^3)
    - Se l'ultima cifra di n non è 0 o 5, g(n) = n^3, che è O(n^3).- Quindi, g(n) è O(n^3) in entrambi i casi.
3. h(n):
   - Se n è divisore di 50, h(n) = 4n^2, che è O(n^2)
   - Se n non è divisore di 50, h(n) = n^3, che è O(n^3).- Quindi, h(n) è O(n^3) nel caso peggiore. 

Adesso confrontiamo le funzioni:


## Esercizio 3

>[!TIP] Calcolare la complessità in funzione di n>=0 della seguente funzione: 
> ```cpp
>int g (int n) {
>   int a=n;
>   if (n<=500){
>       for (int i=1 ; i<=n; i++)
>           for (int j=1 ; j<=n ;j++)
>               a+=n;
>   }
>   else
>       for (int i=1 ; i<=n ; i++) a+=n;
>   return a;
>}
>```

Analizziamo la funzione g(n):

- Se n <= 500, il ciclo esterno esegue n iterazioni e il ciclo interno esegue n iterazioni per ogni iterazione del ciclo esterno. Quindi, la complessità è O(n^2).
- Se n > 500, il ciclo esegue n iterazioni. Quindi, la complessità è O(n).
- La complessità totale è O(n) nel caso peggiore perché quando n > 500 dobbiamo immaginare una retta che va fino all'infinito e invece per n <= 500 la retta è limitata a 500 _(questo per il limite asintotico della funzione)_.

## Esercizio 4

>[!TIP] Dato il seguente frammento di programma e calcolare la complessità in funzione di n>0 nei casi:  
>```cpp
> i = n;
> while (i>=1){
>   for (int j=1 ; j<=n ; j++)
>       a++;
>   i=E;
> }
>```
>a) E = i-1
>
>b) E = i-n
>
>c) E = i/2

La variabile i parte da n e si aggiorna ad ogni iterazione della while in base al valore di E. All'interno del ciclo while, c'è un ciclo for che viene eseguito n volte.

- #### Caso a) E = i-1
In questo caso, ad ogni iterazione della while, i viene decrementato di 1. Quindi, il ciclo while viene eseguito n volte. La complessità totale è O(n^2) perché per ogni iterazione della while, il ciclo for viene eseguito n volte.

- #### Caso b) E = i-n
In questo caso, ad ogni iterazione della while, i viene decrementato di n. Quindi, il ciclo while viene eseguito 1 volta. La complessità totale è O(n) perché il ciclo for viene eseguito n volte.

- #### Caso c) E = i/2
In questo caso, ad ogni iterazione della while, i viene dimezzato. Quindi, il ciclo while viene eseguito log(n) volte. La complessità totale è O(n log n) perché per ogni iterazione della while, il ciclo for viene eseguito n volte.

## Esercizio 5

> [!TIP] Date le seguenti dichiarazioni di funzione, calcolare la complessità in funzione di n>0 della chiamata P(F(n),y).
> ```cpp
> int f(int n){
>    int b;
>    int a=0;
>    for (int i=1 ; i<=n ; i++)
>        for (int j=1 ; j<=n ; j++)
>            a++;
>    b= a/n;
>    return 2*b;
>}
>```
>```cpp
>void P (int m, int &x) {
>    for (int i=1 ; i<=m*m ; i++) x+=3;
>}
>```

Per risolvere questo esercizio, dobbiamo prima calcolare la complessità della funzione F(n) e poi utilizzare il risultato per calcolare la complessità della chiamata P(F(n),y).

- ####  Calcolo della complessità di F(n)

La funzione F(n) è definita come segue:
> ```cpp
> int f(int n){
>    int b;
>    int a=0;
>    for (int i=1 ; i<=n ; i++)
>        for (int j=1 ; j<=n ; j++)
>            a++;
>    b= a/n;
>    return 2*b;
>}
>```

Per calcolare la complessità di F(n), dobbiamo contare il numero di operazioni elementari eseguite dalla funzione. La funzione contiene due cicli annidati, ciascuno che viene eseguito n volte. Quindi, il numero totale di operazioni elementari è O(n^2). Il risultato di questa funzione è 2b, dove b = a/n. Poiché a è incrementato n^2 volte, b sarà n. Quindi, il risultato della funzione è 2n. 

- #### Calcolo della complessità di P(F(n),y)

Ora, dobbiamo calcolare la complessità della funzione P(F(n),y). La funzione P(m,x) è definita come segue: 

>```cpp
>void P (int m, int &x) {
>    for (int i=1 ; i<=m*m ; i++) x+=3;
>}
>```


La funzione P(m,x) contiene un ciclo che viene eseguito m^2 volte. Quindi, la complessità della funzione P(m,x) è O(m^2).

- #### Combinazione delle funzioni
In conclusione...:
1. La complessità di f(int n) è `𝑂(𝑛^2)`.
2. La complessità di P(F(n), y) è 𝑂((𝑛^2)^2)=`𝑂(𝑛^4)`

La complessità della chiamata P(F(n), y) è: `𝑂(𝑛^4)`.