## Lezione 3 - 03/10/2023

### Complessità dei programmi ricorsivi
#### Programmi ricorsivi : definizioni iterative e induttive
Fattoriale di un numero naturale : n! --> n! = n * (n-1)!
- 0!=1
- n! = 1 x 2 x … n per n > 0 --> Definizione iterativa

- 0!=1
- n! = n * (n-1)! per n > 0 --> Definizione ricorsiva (o induttiva)

#### Implementazione iterativa del fattoriale
```cpp
int fact(int n) {
    if (n == 0) return 1;
    int a=1;
    for (int i=1; i<=n; i++) a=a*i;
    return a;
}
```

#### Implementazione ricorsiva del fattoriale
```cpp
int fact(int x) {
    if (x == 0) return 1;
    else return x*fact(x-1);
}
```

#### Implementazione ricorsiva della moltiplicazione di due numeri naturali (x,y) : x*y = x + x*(y-1)
```cpp
int mult(int x, int y) {
    if (x == 0) return 0;
    return y + mult(x-1,y);
}
```

#### Implementazione ricorsiva di pari e massimo comun divisore

```cpp
int pari(int x) {
    if (x == 0) return 1;
    if (x == 1) return 0;
    return pari(x-2);
}
```

```cpp
// Algoritmo di Euclide
int MCD (int x, int y) {
    if (x == y) return x;
    if (x < y) return MCD (x, y-x);
    return MCD (x-y, y);
}
```


### Regole da rispettare
1. Individuare i casi base in cui la funzione è definita immediatamente
2. Effettuare le chiamate ricorsive su un insieme più "piccolo" di dati
3. Fare in modo che alla fine di ogni sequenza di chiamate ricorsive, si ricada in uno dei casi base

#### Esempi di errori ricorsivi

```cpp
int pari_errata(int x) {
    if (x == 0) return 1;
    return pari_errata(x-2); 
    // infranta la regola 3 perché non 
    // si torna mai al caso base (x-2 non è mai 0)
} 
```

```cpp
int MCD _errata(int x, int y) {
    if (x == y) return x;
    if (x < y) return MCD _errata(x, y-x);
    return MCD _errata(x, y);
}
    // infranta la regola 2 perché non si riduce mai il problema 
    // (y-x non è sempre più piccolo di y)
```

---

## | Programmi ricorsivi su liste
### Definizione di lista:
Una lista è una struttura dati che contiene una sequenza di elementi, dove ogni elemento è un nodo che contiene un valore e un riferimento al nodo successivo nella sequenza. La lista può essere singolarmente collegata o doppiamente collegata.
- NULL (sequenza vuota) è una lista
- Un elemento seguito da una lista è una lista
- Struttura
  - ```cpp
    typedef ("tipo di elemento") InfoType;
    struct Elem {
    InfoType inf;
    Elem* next;
    };
    ```
#### Esempi:
```cpp
int length(Elem* p) {
    if (p == NULL) return 0; // (! p)
    return 1+length(p->next);
}
```
```cpp
int howMany(Elem* p, int x) {
    if (p == NULL) return 0;
    return (p->inf == x)+howMany(p->next, x);
}
```
```cpp
int belongs(Elem *l, int x) {
    if (l == NULL) return 0;
    if (l->inf == x) return 1;
    return belongs(l->next, x);
}
```
```cpp
void tailDelete(Elem * & l) {
    if (l == NULL) return;
    if (l->next == NULL) {
        delete l;
        l=NULL;
    }
    else tailDelete(l->next);
}
```
```cpp
void tailInsert(Elem* & l, int x) {
    if (l == NULL) {
        l=new Elem;
        l->inf=x;
        l->next=NULL;
    }
    else tailInsert(l->next,x);
}
```
```cpp
void append(Elem* & l1, Elem* l2) {
    if (l1 == NULL) l1=l2;
    else append(l1->next, l2);
}
```
```cpp
Elem* append(Elem* l1, Elem* l2) {
    if (l1 == NULL) return l2;
    l1->next= append( l1->next, l2 );
    return l1;
}
```
---
## | Induzione naturale:

Sia \( P(n) \) una proprietà sui numeri naturali. Se si verifica:
1. \( P(0) \) (cioè la proprietà vale per \( n = 0 \)),
2. \( P(n) \Rightarrow P(n+1) \) per ogni \( n \) (cioè, se la proprietà è vera per un dato \( n \), allora è vera anche per \( n+1 \)),

allora \( P(n) \) è vera per ogni \( n \in \mathbb{N} \).

**Esempio:**
- **Somma dei primi \( n \) numeri naturali**: Sia \( P(n) \) la proprietà che afferma che la somma dei primi \( n \) numeri naturali è \( 1 + 2 + \cdots + n = \frac{n(n+1)}{2} \). 
  - Verifica \( P(0) \): \( 1 + 2 + \cdots + 0 = 0 \), che è congruente con \( \frac{0(0+1)}{2} = 0 \). 
  - Verifica la condizione di induzione: se la proprietà vale per \( n \), cioè \( 1 + 2 + \cdots + n = \frac{n(n+1)}{2} \), allora vale anche per \( n+1 \), cioè \( 1 + 2 + \cdots + (n+1) = \frac{(n+1)(n+2)}{2} \).

Poiché entrambe le condizioni sono verificate, la proprietà è vera per ogni \( n \in \mathbb{N} \).

---

## | Induzione completa (o bidirezionale):

Sia \( P(n) \) una proprietà sui numeri naturali. Se si verifica:
1. \( P(0) \) (cioè la proprietà vale per \( n = 0 \)),
2. \( P(n) \Rightarrow P(n+1) \) per ogni \( n \),
3. \( P(n) \Rightarrow P(n-1) \) per ogni \( n \) (cioè, se la proprietà è vera per un dato \( n \), allora è vera anche per \( n-1 \)),

allora \( P(n) \) è vera per ogni \( n \in \mathbb{N} \).

**Esempio:**
- **Somma dei primi \( n \) numeri naturali**: Sia \( P(n) \) la proprietà che afferma che la somma dei primi \( n \) numeri naturali è \( 1 + 2 + \cdots + n = \frac{n(n+1)}{2} \). 
  - Verifica \( P(0) \): \( 1 + 2 + \cdots + 0 = 0 \), che è congruente con \( \frac{0(0+1)}{2} = 0 \). 
  - Verifica la condizione di induzione: se la proprietà vale per \( n \), cioè \( 1 + 2 + \cdots + n = \frac{n(n+1)}{2} \), allora vale anche per \( n+1 \), cioè \( 1 + 2 + \cdots + (n+1) = \frac{(n+1)(n+2)}{2} \).
  - Inoltre, se vale per \( n \), vale anche per \( n-1 \), completando la condizione di induzione completa.

Poiché tutte le condizioni sono soddisfatte, la proprietà è vera per ogni \( n \in \mathbb{N} \).

---

## | Induzione ben fondata:

L'induzione ben fondata è un principio che si applica a una struttura di ordine ben fondato (ad esempio, i numeri naturali, ma anche set di oggetti strutturati con un ordine parziale che non possiede cicli). La definizione di induzione ben fondata è:

Sia \( P \) una proprietà definita su un insieme \( S \) dotato di un ordine ben fondato. Se si verifica:
1. \( P(x) \) è vera per ogni elemento \( x \in S \) che non ha predecessori rispetto all'ordine (per esempio, il caso base),
2. Se \( P(y) \) è vera per ogni \( y \) precedentemente a \( x \), allora \( P(x) \) è vera,

allora \( P(x) \) è vera per ogni elemento \( x \in S \).

**Esempio:**
- **Proprietà su un insieme di numeri**: Se si ha un insieme ordinato di numeri con un ordine ben fondato, l'induzione ben fondata consente di estendere la proprietà da un numero a tutti i numeri successivi, eliminando la possibilità di cicli nell'ordine e garantendo che la proprietà si mantenga vera.

---

### Complessità dei programmi ricorsivi - esempio:

```cpp
int fact(int x) {
    if (x == 0) return 1;    // O(1)
    else return x*fact(x-1); // Richiamando la funzione in maniera ricorsiva 
                             // con complessità O(n-1) si arriva a una 
                             // conclusione ovvero O(n)
}
```

>[!NOTE] Relazione di ricorrenza
> - T ( 0 ) = a **_(CASO BASE)_**
> - T ( n ) = b + T(n-1) **_(CASO RICORSIVO)_**
>
> dove T rappresenta la complessità nel tempo di esecuzione della funzione.

#### Soluzione con passaggi
>[!IMPORTANT] 
> - T ( 0 ) = a
> - T ( n ) = b + T(n-1)
> 

1. T ( 0 ) = a
2. T ( 1 ) = b + a
3. T ( 2 ) = b + b+ a = 2 b + a
4. T ( 3 ) = b+2 b + a =3 b + a
5. .
6. .
7. T ( n ) = n b + a

Quindi la complessità di T(n) è O(n).

---

### Selection Sort Ricorsiva

```cpp
void r_selectionSort (int* A, int m, int i=0) {
    if (i == m-1) return; // O(1)
    int min = i; // O(1)
    for (int j=i+1; j <m; j++) // O(n)
        if (A[j] < A[min]) min=j;
    exchange(A[i],A[min]);
    r_selectionSort (A, m, i+1) // O(n-1)
}
```
>[!NOTE]
> - T ( 1 ) = a
> - T ( n) = bn + T(n-1)

La complessità totale della funzione r_selectionSort sarà O(n<sup>2</sup>).

---

### Quicksort

Il Quicksort è un algoritmo di ordinamento molto popolare, sviluppato da Tony Hoare nel 1960. È un algoritmo **_divide et impera_**, che significa che **divide il problema in sotto-problemi più piccoli**, **li risolve separatamente e poi combina le soluzioni per ottenere il risultato finale**.

La nostra funzione sarà rappresentata nel seguente modo:
```cpp
void quicksort(array A ,inf, sup)
```

Il ragionamento alla base dell'algoritmo Quicksort si basa su:

1. Scegli un perno
   - Si sceglie un elemento dell'array come "perno" (o "pivot"). La scelta del perno è cruciale per l'efficienza dell'algoritmo (potremmo scegliere qualsiasi elemento, inizio metà, fine, etc...).
2. Dividi l'array in due parti (**_PARTIZIONAMENTO_**)
   - Si ordina l'array in modo che:
      - Nella prima parte vengano messi tutti gli elementi minori o uguali al perno.
      - Nella seconda parte vengano messi tutti gli elementi maggiori o uguali al perno. 
3. Chiama QuickSort sulla prima parte
   - Dopo aver effettuato il partizionamento, possiamo chiamare ricorsivamente l'algoritmo QuickSort sulla prima parte (quella che contiene gli elementi minori o uguali al perno), ma solo se contiene almeno 2 elementi. Se la parte ha 1 o 0 elementi, è già ordinata.
4.  Chiama QuickSort sulla seconda parte
    -  Lo stesso vale per la seconda parte (quella che contiene gli elementi maggiori o uguali al perno): 
        - se contiene almeno 2 elementi, viene chiamato ricorsivamente QuickSort
        -  altrimenti è già ordinata.


>[!NOTE] Codice QuickSort
>```cpp
>void quickSort(int A[], int inf=0, int sup=n-1) {
>    int perno = A[(inf + sup) / 2], s = inf, d = sup;
>    while (s <= d) {
>        while (A[s] < perno) s++;
>        while ( A[d] > perno) d--;
>        if (s > d) break;
>        exchange(A[s], A[d]);
>        s++;
>        d--;
>};
>
>if (inf < d)
>    quickSort(A, inf, d);
>if (s < sup)
>    quickSort(A, s, sup);
>```

#### Soluzione con passaggi ricorsivi:

- T ( 1 ) = a
- T ( n ) = bn + 2T( n/2 )

La complessità nel caso medio è uguale a quella nel caso
migliore: `O(nlogn)` (ma con una costante nascosta
maggiore). Questo se tutti i possibili contenuti dell’array in
input (tutte le permutazioni degli elementi) sono
equiprobabili.
Per ottenere questo risultato indipendentemente dal
particolare input, ci sono versioni **_“randomizzate”_** di
quicksort in cui il perno ad ogni chiamata è scelto in modo
casuale.

--- 

## Torre di Hanoi

La Torre di Hanoi è un celebre problema ricorsivo e un rompicapo matematico che aiuta a comprendere i concetti fondamentali della ricorsione.
Immagina di avere:
1. **Tre pali**: solitamente chiamati origine, ausiliario e destinazione.
2. **Dischi di diverse dimensioni**: inizialmente impilati su uno dei pali (di solito l'origine) in ordine decrescente di dimensioni, con il disco più piccolo in cima.

Bisogna seguire le seguenti regole:

1. **_Muovere un solo disco alla volta_**: Si può spostare solo il disco che si trova in cima a un qualsiasi palo.
2. **_Non posizionare un disco più grande su uno più piccolo_**: In ogni mossa, se il palo di destinazione contiene già dei dischi, il disco che si sta spostando deve essere più piccolo di quello che si trova in cima.

>[!NOTE] Codice Hanoi
>```cpp
>void hanoi(int n, pal A, pal B, pal C){
>   if (n == 1)
>       sposta(A, C);
>else {
>   hanoi(n - 1, A, C, B);
>   sposta(A, C);
>   hanoi(n - 1, B, A, C);
>   }
>}
>```

#### Soluzione con passaggi ricorsivi:

- T ( 1 ) = a
- T ( n ) = bn + 2T( n-1 )