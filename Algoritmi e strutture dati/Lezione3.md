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
Sia P una proprietà sui naturali. Se vale P(0) e vale P(n) ⇒ P(n+1) per ogni n, allora P(n) vale per ogni n.
- **Somma dei primi n numeri naturali**: Sia P(n) la proprietà "1+2+...+n=n(n+1)/2". Valgono P(0) e P(n) ⇒ P(n+1). Quindi P(n) vale per ogni n.

---

## | Induzione completa:

Sia P una proprietà sui naturali. Se vale P(0) e vale P(n) ⇒ P(n+1) e P(n) ⇒ P(n-1) per ogni n, allora P(n) vale per ogni n.

- **Somma dei primi n numeri naturali**: Sia P(n) la proprietà "1+2+...+n=n(n+1)/2". Valgono P(0) e P(n) ⇒ P(n+1) e P(n) ⇒ P(n-1). Quindi P(n) vale per ogni n.