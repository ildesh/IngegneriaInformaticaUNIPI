# MANUALE COMPLETO E DEFINITIVO: ALGORITMI E STRUTTURE DATI

## CAPITOLO 1: ANALISI MATEMATICA DELLA COMPLESSITÀ

### 1.1 Definizioni Formali e Limiti Asintotici

L'analisi asintotica serve a descrivere l'andamento del tempo di esecuzione di un algoritmo al crescere della dimensione dell'input $n$, ignorando costanti moltiplicative e termini di ordine inferiore.

- **Limite Superiore (Notazione** $O$**) - Caso Peggiore:** $f(n) \in O(g(n))$ se $\exists c > 0, \exists n_0 \ge 0$ tali che $\forall n \ge n_0, f(n) \le c \cdot g(n)$. _Significato:_ $f(n)$ cresce al massimo con la stessa velocità di $g(n)$.
- **Limite Inferiore (Notazione** $\Omega$**) - Caso Ottimo/Intrinseco:** $f(n) \in \Omega(g(n))$ se $\exists c > 0, \exists n_0 \ge 0$ tali che $\forall n \ge n_0, f(n) \ge c \cdot g(n)$. _Significato:_ $f(n)$ cresce almeno con la stessa velocità di $g(n)$.
- **Limite Stretto (Notazione** $\Theta$**):** $f(n) \in \Theta(g(n))$ se $f(n) \in O(g(n))$ e $f(n) \in \Omega(g(n))$. _Significato:_ $f(n)$ cresce esattamente con la stessa velocità di $g(n)$ a meno di costanti.
    

**Il Metodo del Limite (Fondamentale per l'esame teorico):** Per confrontare due funzioni $f(n)$ e $g(n)$, si calcola $\lim_{n \to \infty} \frac{f(n)}{g(n)} = L$.

- Se $L = 0$: $f(n)$ è $o(g(n))$ (cresce strettamente più lentamente).
- Se $L = \infty$: $f(n)$ è $\omega(g(n))$ (cresce strettamente più velocemente).
- Se $0 < L < \infty$: $f(n)$ è $\Theta(g(n))$.

### 1.2 Regole Algebriche e Classi di Complessità

Ordine di grandezza crescente (dal più veloce al più lento): $O(1) \subset O(\log n) \subset O(n) \subset O(n \log n) \subset O(n^2) \subset O(n^3) \subset O(2^n) \subset O(n!)$

**Teorema dei Polinomi:** Dato un polinomio $P(n) = a_k n^k + a_{k-1} n^{k-1} + \dots + a_0$ con $a_k > 0$, $P(n) = \Theta(n^k)$. **Regola dell'Esponenziale:** Qualsiasi esponenziale $a^n$ con $a > 1$ domina qualsiasi polinomio $n^k$. Limite matematico: $\lim_{n \to \infty} \frac{n^k}{a^n} = 0$.

### 1.3 Analisi Iterativa: Tipi di Cicli

Per analizzare il codice, dobbiamo tradurre i cicli in Sommatorie Matematiche.

**Modello 1: Incremento Lineare (Costo O(n))**

```
int a = 0;
for (int i = 0; i < n; i += c) { // dove c è una costante > 0
    a++; // O(1)
}
```

_Matematica:_ $\sum_{i=0}^{n/c} 1 = \frac{n}{c} = \Theta(n)$.

**Modello 2: Incremento Moltiplicativo (Costo O(log n))**

```cpp
int a = 0;
for (int i = 1; i < n; i = i * 2) { 
    a++;
}
```

_Matematica:_ Ad ogni passo $k$, $i$ vale $2^k$. Il ciclo termina quando $2^k \ge n \implies k = \log_2 n$. Costo totale = $\Theta(\log n)$.

**Modello 3: Cicli Annidati Dipendenti (Costo O(n^2))**

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
        // O(1)
    }
}
```

_Matematica:_ $\sum_{i=0}^{n-1} \sum_{j=0}^{i} 1 = \sum_{i=0}^{n-1} (i + 1) = \frac{n(n+1)}{2} = \Theta(n^2)$.

### 1.4 La Trappola d'Esame: Funzioni nel Test del Ciclo

Spessissimo all'esame capita un ciclo `while` che invoca una funzione all'interno della condizione di terminazione.

```cpp
int f(int x) { // Somma i numeri da 1 a x. Costo temporale: O(x). Ritorno: O(x^2)
    int s = 0;
    for(int i = 1; i <= x; i++) s += x;
    return s;
}

void main_esame(int n) {
    int i = 1;
    while (i <= f(n)) { 
        i++;
    }
}
```

_Analisi riga per riga:_

1. La funzione `f(n)` restituisce $n \times n = n^2$. Il suo tempo di esecuzione è però $\Theta(n)$.
2. Il ciclo `while` esegue l'incremento di `i` partendo da 1 fino al valore restituito da `f(n)`. Quindi esegue $n^2$ iterazioni.
3. **TRAPPOLA:** La condizione `i <= f(n)` viene ricalcolata a _ogni singola iterazione_.
4. Costo totale = $\sum_{iter=1}^{n^2} (\text{costo test} + \text{costo corpo}) = \sum_{iter=1}^{n^2} (\Theta(n) + \Theta(1)) = n^2 \times \Theta(n) = \Theta(n^3)$.

## CAPITOLO 2: RELAZIONI DI RICORRENZA E TEOREMA DEL MAESTRO

### 2.1 Srotolamento dell'Equazione (Metodo Iterativo)

Consideriamo $T(n) = 3T(n/3) + n$. (Complessità del MergeSort a 3 vie).

- Livello 0: $n$
- Livello 1: Sostituiamo $T(n/3)$ $\implies$ $3[3T(n/9) + n/3] + n = 9T(n/9) + 2n$
- Livello $k$: $3^k T(n/3^k) + k \cdot n$
- Condizione di terminazione: $n/3^k = 1 \implies 3^k = n \implies k = \log_3 n$
- Sostituiamo $k$: $n \cdot T(1) + n \log_3 n = \Theta(n \log n)$.

### 2.2 Il Teorema del Maestro

Applichiamo la "ricetta" a $T(n) = aT(n/b) + \Theta(n^k)$. Confrontiamo $a$ (numero di nodi figli creati) con $b^k$ (fattore di bilanciamento del costo dei nodi interni).

- **Caso 1 (Costo dominato dalle foglie / radice dell'albero domina in basso):** $a > b^k \implies T(n) = \Theta(n^{\log_b a})$ _Esempio:_ $T(n) = 4T(n/2) + n$. Qui $a=4, b=2, k=1$. Dato che $4 > 2^1$, la complessità è $n^{\log_2 4} = \Theta(n^2)$.
- **Caso 2 (Equilibrio perfetto / Ogni livello dell'albero costa uguale):** $a = b^k \implies T(n) = \Theta(n^k \log n)$ _Esempio:_ MergeSort $T(n) = 2T(n/2) + n$. $a=2, b=2, k=1$. Dato che $2 = 2^1$, la complessità è $\Theta(n \log n)$.
- **Caso 3 (Costo dominato dal nodo radice iniziale):** $a < b^k \implies T(n) = \Theta(n^k)$ _Esempio:_ $T(n) = 2T(n/2) + n^3$. $a=2, b=2, k=3$. Dato che $2 < 2^3$, il costo della divisione iniziale annulla tutto: $\Theta(n^3)$.

### 2.3 Ricorrenze Lineari e Sottoproblemi (Attenzione ai Fibonacci!)

$T(n) = a \cdot T(n-c) + \Theta(1)$ Se $a = 1$ (una sola chiamata ricorsiva, come nella Ricerca Lineare Ricorsiva): Il tempo è $\Theta(n)$. L'altezza dell'albero è $n$ e la larghezza è 1. Se $a > 1$ (più chiamate, es. $T(n) = 2T(n-1) + 1$ come le Torri di Hanoi o Fibonacci ingenuo): Il tempo diventa catastrofico, un albero binario completo di altezza $n$. Complessità $\Theta(2^n)$.

## CAPITOLO 3: STRUTTURE DATI LINEARI (C++)

In un esame pratico, l'allocazione dinamica e l'uso corretto dei puntatori salvano il voto. Ecco una Lista Concatenata Semplice con Inserimento, Ricerca e Distruzione sicura.

```cpp
#include <iostream>
using namespace std;

// Struttura base del nodo
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {} // Costruttore
};

class LinkedList {
private:
    ListNode* head;
    ListNode* tail; // Mantenere la coda rende l'inserimento in fondo O(1) invece di O(n)

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Distruttore per evitare Memory Leak all'esame
    ~LinkedList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Inserimento in Coda - O(1) grazie al puntatore tail
    void push_back(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Ricerca Lineare Ricorsiva - O(n)
    bool search_recursive(ListNode* node, int target) {
        if (node == nullptr) return false;
        if (node->val == target) return true;
        return search_recursive(node->next, target);
    }
    
    // Wrapper per la ricerca
    bool contains(int target) {
        return search_recursive(head, target);
    }
};
```

## CAPITOLO 4: ALBERI BINARI E VISITE (DFS)

### 4.1 Rappresentazione Memoria

Un albero generico con grado $K$ non limitato si rappresenta sempre in memoria come un **Albero Binario Isomorfo** (First-Child, Next-Sibling).

- `left`: punta al primo figlio del nodo.
- `right`: punta al primo fratello (stesso livello) del nodo. Una visita IN-ORDER dell'albero isomorfo riproduce magicamente la visita POST-ORDER dell'albero generico originale.

### 4.2 Visite Ricorsive (DFS)

Si differenziano unicamente per il momento in cui si "elabora" (stampa) la radice corrente rispetto alle chiamate ricorsive.

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. PRE-ORDER: Elaboro me stesso, poi i discendenti. Utile per serializzare l'albero o copiarlo.
void preOrder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " "; // ELABORAZIONE ANTICIPATA
    preOrder(root->left);
    preOrder(root->right);
}

// 2. IN-ORDER: Sx, Radice, Dx. Fondamentale nei BST per ottenere i dati ordinati in modo crescente!
void inOrder(TreeNode* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->val << " "; // ELABORAZIONE SIMMETRICA
    inOrder(root->right);
}

// 3. POST-ORDER: Sx, Dx, Radice. Utile per deallocare memoria bottom-up (distruttore di un albero).
void postOrder(TreeNode* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " "; // ELABORAZIONE POSTICIPATA
}
```

### 4.3 Esercizi Tipici sugli Alberi Generici

Due classici che vi chiederanno di implementare al volo.

```cpp
// 1. Contare i nodi dell'albero
int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 2. Calcolare l'Altezza (profondità massima)
#include <algorithm>
int height(TreeNode* root) {
    if (root == nullptr) return -1; // L'altezza di un albero vuoto è convenzionalmente -1 (o 0 a seconda del testo)
    return 1 + std::max(height(root->left), height(root->right));
}
```

## CAPITOLO 5: ALBERI BINARI DI RICERCA (BST)

Nei BST vale l'invariante: Per ogni nodo $N$, le chiavi nel sottoalbero sinistro sono minori di $N$, le chiavi nel destro sono maggiori (o uguali, ma generalmente si evita la duplicazione). _Complessità nel caso peggiore (Albero Degenere a Lista):_ $O(n)$ _Complessità nel caso medio/bilanciato:_ $O(\log n)$

### 5.1 Codice C++: Implementazione Completa del BST

Il trucco per le manipolazioni (inserimento/cancellazione) in C++ è passare il puntatore alla radice **per Riferimento** (`TreeNode*&`). Modificando il puntatore ricorsivamente, stiamo agganciando il nuovo nodo direttamente al campo `left` o `right` del padre nello stack della memoria, senza impazzire con doppi puntatori.

```cpp
class BST {
private:
    TreeNode* root;

    // Inserimento - Nota il TreeNode*&
    void insertNode(TreeNode*& node, int val) {
        if (node == nullptr) {
            node = new TreeNode(val); // Modifica direttamente il puntatore del padre!
        } else if (val < node->val) {
            insertNode(node->left, val);
        } else if (val > node->val) {
            insertNode(node->right, val);
        }
    }

    // Ricerca del minimo (fondamentale per la rimozione)
    TreeNode* findMin(TreeNode* node) {
        if (node == nullptr) return nullptr;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Cancellazione Nodo (I 3 Casi D'esame)
    void removeNode(TreeNode*& node, int val) {
        if (node == nullptr) return; // Non trovato
        
        if (val < node->val) {
            removeNode(node->left, val);
        } else if (val > node->val) {
            removeNode(node->right, val);
        } else {
            // NODO TROVATO
            // Caso 1 e 2: Il nodo ha ZERO o UN figlio
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                node = temp; // Ricollega il figlio al nonno
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                node = temp;
            } 
            // Caso 3: Il nodo ha DUE figli. 
            // Bisogna trovare il Successore (il minimo del sottoalbero destro)
            else {
                TreeNode* temp = findMin(node->right);
                node->val = temp->val; // Sovrascrivo il valore con quello del successore
                removeNode(node->right, temp->val); // Vado a cancellare il successore (che ricadrà nel Caso 1 o 2)
            }
        }
    }

public:
    BST() : root(nullptr) {}
    void insert(int val) { insertNode(root, val); }
    void remove(int val) { removeNode(root, val); }
};
```

## CAPITOLO 6: HEAP, CODE DI PRIORITÀ E HEAPSORT

Un Max-Heap è un albero binario quasi completo, in cui il valore di ogni padre è $\ge$ ai valori dei suoi figli. Viene implementato tramite un **Array** (o `std::vector`), senza usare puntatori. Formule matematiche (con Radice in `A[0]`):

- Figlio Sinistro: $2i + 1$
- Figlio Destro: $2i + 2$
- Padre: $\lfloor (i - 1) / 2 \rfloor$

### 6.1 Setacciamento e Operazioni

- **siftUp (Propagazione verso l'alto):** Usato quando si inserisce un elemento in fondo (ultima cella dell'array). Se l'elemento è più grande del padre, lo scambio. Costo: $O(\log n)$.
- **siftDown (Setacciamento verso il basso):** Usato quando si estrae la radice e la si rimpiazza con l'ultima foglia dell'albero. Confronto il nodo con il più grande dei due figli e lo faccio "scendere". Costo: $O(\log n)$.

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void siftUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void siftDown(int i, int n) {
        int maxIndex = i;
        int l = left(i);
        int r = right(i);

        if (l < n && heap[l] > heap[maxIndex]) maxIndex = l;
        if (r < n && heap[r] > heap[maxIndex]) maxIndex = r;

        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            siftDown(maxIndex, n);
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        siftUp(heap.size() - 1); // Costo O(log n)
    }

    int pop() {
        if (heap.empty()) return -1;
        int result = heap[0];
        heap[0] = heap.back(); // Metto l'ultimo in radice
        heap.pop_back();       // Rimuovo fisicamente l'ultima cella
        siftDown(0, heap.size()); // Ripristino, Costo O(log n)
        return result;
    }
};
```

### 6.2 L'Eleganza del BuildHeap (Perché costa O(n) e non O(n log n))

Per trasformare un array disordinato in uno Heap, non faccio $n$ inserimenti (che costerebbe $O(n \log n)$). Faccio un `buildHeap`. Parto dall'indice $n/2 - 1$ (l'ultimo nodo che ha almeno un figlio, poiché tutti i successivi sono foglie) e vado a ritroso fino all'indice 0, chiamando `siftDown`. **Dimostrazione Matematica:** Le foglie (metà dei nodi) sono a quota 0 e non scendono. Un quarto dei nodi può scendere al massimo di 1 livello. Un ottavo scende di 2, ecc. La serie $\sum_{h=0}^{\log n} \frac{h}{2^h}$ converge a una costante. Moltiplicata per $n$, dà una complessità temporale rigorosamente $O(n)$. È il fulcro magico dell'algoritmo Heapsort.

## CAPITOLO 7: TABELLE HASH

Le mappe Hash mappano chiavi in indici di un array tramite una funzione di hashing, raggiungendo tempi medi di ricerca in $O(1)$. Il **Fattore di Carico (**$\alpha$**)** si definisce come $\alpha = \frac{n}{m}$ (numero di chiavi inserite diviso dimensione dell'array).

### 7.1 La Funzione di Hash Universale

Per l'esame pratico, si usa spesso la formula a congruenza lineare: $h(k) = ((a \cdot k + b) \pmod p) \pmod m$ **Criticità C++:** $(a \cdot k)$ andrà in Integer Overflow per numeri elevati. È obbligatorio usare `(long long)`.

### 7.2 Gestione Collisioni: Separate Chaining (Concatenazione)

Ogni cella dell'array contiene il puntatore iniziale a una Lista Concatenata. In caso di collisione, si aggiunge la chiave alla lista di quel bucket. La ricerca costa asintoticamente $O(1 + \alpha)$. Ottimo se non si ha idea di quanti dati arriveranno.

### 7.3 Gestione Collisioni: Open Addressing (Scansione Lineare)

I dati stanno tutti all'interno dell'array originario, senza liste extra. Se $h(k)$ è occupata, controllo $h(k)+1$, poi $h(k)+2$, ecc.

- **Problema della Cancellazione (Tombstone):** Se cancello l'elemento $x$ e marco la cella come "Vuota", una successiva ricerca di $y$ (che era colliso con $x$ ed era stato spostato in avanti) si arresterà prematuramente incontrando il vuoto.
- _Soluzione:_ Uso il valore `DELETED` (es. -2). Durante l'inserimento, tratto -2 come cella vuota dove poter sovrascrivere. Durante la ricerca, se incontro -2 _salto oltre_ e continuo a cercare finché non trovo la cella veramente "Vuota" (-1).

## CAPITOLO 8: SIMULAZIONE COMPLETA PROVE PRATICHE DI LABORATORIO

Ecco un esercizio ibrido complesso tipico da 30 e lode, che richiede unione tra BST, hashing e code di priorità. Risolviamo l'Esercizio della Categoria di Frequenza Massima.

**Testo Problema MOCK:** In ingresso vengono fornite le categorie testuali di $N$ esami universitari superati. Un utente vuole trovare la categoria in cui è stata registrata la frequenza massima. In caso di parità, restituire la categoria alfanumericamente inferiore. Utilizzare un BST per memorizzare le categorie ed effettuare i calcoli di frequenza.

**Soluzione C++ Analizzata:**

```cpp
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string categoria;
    int frequenza;
    Node* left;
    Node* right;
    
    Node(string c) : categoria(c), frequenza(1), left(nullptr), right(nullptr) {}
};

void inserisciBST(Node*& radice, const string& cat) {
    if (radice == nullptr) {
        radice = new Node(cat);
    } else if (cat < radice->categoria) {
        inserisciBST(radice->left, cat);
    } else if (cat > radice->categoria) {
        inserisciBST(radice->right, cat);
    } else {
        radice->frequenza++;
    }
}

void trovaMassimoInOrder(Node* radice, string& bestCat, int& maxFreq) {
    if (radice == nullptr) return;
    
    trovaMassimoInOrder(radice->left, bestCat, maxFreq);
    
    if (radice->frequenza > maxFreq) {
        maxFreq = radice->frequenza;
        bestCat = radice->categoria;
    } else if (radice->frequenza == maxFreq) {
        if (radice->categoria < bestCat) {
            bestCat = radice->categoria;
        }
    }
    
    trovaMassimoInOrder(radice->right, bestCat, maxFreq);
}

void distruggiAlbero(Node* radice) {
    if (radice == nullptr) return;
    distruggiAlbero(radice->left);
    distruggiAlbero(radice->right);
    delete radice;
}

int main() {
    int N;
    if (!(cin >> N)) return 0;
    
    Node* radice = nullptr;
    
    for (int i = 0; i < N; i++) {
        string cat;
        cin >> cat;
        inserisciBST(radice, cat);
    }
    
    string migliorCategoria = "";
    int massimaFrequenza = -1;
    
    trovaMassimoInOrder(radice, migliorCategoria, massimaFrequenza);
    cout << migliorCategoria << " " << massimaFrequenza << endl;
         
    distruggiAlbero(radice);
    return 0;
}
```

## CAPITOLO 9: ALGORITMI DI ORDINAMENTO E LIMITI INFERIORI

### 9.1 Ordinamenti Basati su Confronti

Esiste un limite matematico insormontabile per algoritmi che ordinano dati unicamente confrontandoli tra loro: il **Limite Inferiore** $\Omega(n \log n)$. L'albero decisionale delle permutazioni ha infatti $n!$ foglie, e la sua altezza minima è $\log_2(n!) \approx n \log n$.

**1. Merge Sort** Divide l'array in due metà, le ordina ricorsivamente e le fonde (`merge`).

- **Complessità:** Essendo in perfetto bilanciamento, $T(n) = 2T(n/2) + \Theta(n)$. Tempo sempre $\Theta(n \log n)$.
- **Svantaggio:** Non è _in-place_. Richiede uno spazio di memoria ausiliario $\Theta(n)$ per l'array di appoggio durante la fusione.

**2. Quick Sort** Sceglie un elemento come _Pivot_, e tramite la funzione `Partition` sposta tutti i minori a sinistra e i maggiori a destra. Poi opera ricorsivamente sui due sotto-array. È _in-place_.

- **Caso Medio/Ottimo:** Il pivot divide a metà. $T(n) = 2T(n/2) + \Theta(n) \implies O(n \log n)$.
- **Caso Peggiore:** Il pivot è sempre il massimo o il minimo (es. array già ordinato in un quicksort non randomizzato). $T(n) = T(n-1) + \Theta(n)$. L'altezza dell'albero diventa $n$, e la complessità crolla a disastrosi $O(n^2)$.

### 9.2 Ordinamenti Lineari (Non basati su confronti)

Eludono il limite $\Omega(n \log n)$ facendo assunzioni strette sui dati di input.

**1. Counting Sort** Conta le occorrenze di ogni elemento usando i valori stessi come indici di un array ausiliario.

- **Condizione:** I dati devono essere interi in un range ristretto $[0, k]$.
- **Complessità:** $O(n + k)$. Ottimo se $k \le n$, pessimo se c'è un elemento enormemente più grande degli altri.

**2. Radix Sort** Ordina in sequenza i numeri basandosi su una cifra alla volta (dalla meno significativa alla più significativa), usando un algoritmo di ordinamento _stabile_ (come il Counting Sort) per le singole cifre.

- **Complessità:** $O(d(n + k))$, dove $d$ è il numero massimo di cifre. Estremamente veloce per chiavi come Stringhe fisse, CAP, o numeri interi limitati.

## CAPITOLO 10: TECNICHE ALGORITMICHE AVANZATE

### 10.1 Approccio Greedy (Ingordo)

Negli algoritmi Greedy, si fa una "scelta localmente ottima" ad ogni passo, sperando che questa porti alla "soluzione globale ottima". Una volta fatta una mossa, non si torna mai indietro (niente backtracking).

- **Codifica di Huffman:** Crea codici prefissi a lunghezza variabile ottimi. I caratteri più frequenti hanno codici più corti. Costruisce l'albero bottom-up, accoppiando ricorsivamente i due nodi con la frequenza _minima_ (usando una coda a priorità Min-Heap). Complessità per $n$ caratteri: $O(n \log n)$.

### 10.2 Programmazione Dinamica (Dynamic Programming)

Usata per problemi di ottimizzazione in cui l'approccio divide-et-impera "ingenuo" fallirebbe calcolando milioni di volte gli stessi sottoproblemi (es. Fibonacci ricorsivo degenere). Requisiti:

1. **Sottostruttura ottima:** La soluzione globale contiene le soluzioni dei sottoproblemi ottimi.
2. **Sottoproblemi sovrapposti:** Lo spazio dei sottoproblemi è "piccolo", quindi conviene memorizzare i risultati (Memoization/Tabulation) piuttosto che ricalcolarli.

**Problema PLSC (Più Lunga Sottosequenza Comune - Slide 12):** Date due sequenze di caratteri `A` e `B` di lunghezze $m$ e $n$, qual è la più lunga sottosequenza che appare in entrambe? L'algoritmo riempie una matrice bidimensionale $L(i,j)$ tramite questa _Relazione di Ricorrenza_:

- **Caso base:** $L(i, 0) = 0$ e $L(0, j) = 0$.
- **Se l'ultimo carattere coincide** ($A_i == B_j$): La lunghezza cresce. $L(i,j) = 1 + L(i-1, j-1)$.
- **Se non coincide** ($A_i \neq B_j$): Eredito il massimo raggiunto escludendo uno dei due caratteri. $L(i,j) = \max(L(i, j-1), L(i-1, j))$. La matrice $m \times n$ garantisce una complessità polinomiale rigorosa $O(m \cdot n)$.

## CAPITOLO 11: TEORIA DELLA COMPLESSITÀ E NP-COMPLETEZZA

All'esame finale, la distinzione tra calcolabilità matematica e trattabilità è cruciale (Slide 16).

### 11.1 Problemi di Decisione

Si studiano solitamente problemi decisionali (la cui risposta è strettamente "SI" o "NO") perché ogni problema di Ottimizzazione ("Trova il cammino più breve") può essere ridotto a un problema Decisionale ("Esiste un cammino di lunghezza $\le K$?") e viceversa in tempo polinomiale.

### 11.2 Le Classi P ed NP

- **La Classe P (Polinomiale Determinista):** Contiene tutti i problemi per cui **esiste** un algoritmo che fornisce la risposta corretta nel caso peggiore in tempo limitato superiormente da un polinomio $O(n^k)$. (Es. Ricerca su grafo, MST, Ordinamento). Si considerano problemi "trattabili".
- **La Classe NP (Polinomiale Non-Determinista):** Contiene problemi in cui, se la risposta è SI, esiste un "certificato" (una prova) che può essere **VERIFICATO in tempo polinomiale**. Esempio principe: la Fattorizzazione. Trovare due fattori primi da un numero gigante costa tempo enorme (spesso esponenziale se misurato sul numero di bit), ma se _ti fornisco io_ i due fattori A e B, tu ci metti un millisecondo per fare $A \times B$ e _verificare_ che formano quel numero (tempo $O(n^2)$). NP racchiude problemi potenzialmente difficilissimi da _risolvere_ (come TSP - Commesso Viaggiatore, SAT, Sudoku generico), ma facilissimi da _controllare_ a posteriori se viene fornita una soluzione candidata. Ovviamente, siccome ciò che è in P è anche verificabile velocemente, abbiamo che $P \subseteq NP$.

### 11.3 La Classe NP-Completi

Costituiscono il nucleo dei "problemi più difficili della classe NP". Un problema $L$ è NP-Completo se:

1. Appartiene alla classe NP.
2. È **NP-Hard**: Ogni singolo problema della classe NP può essere ridotto al problema $L$ in tempo polinomiale. L'enigma del Millennio $P \overset{?}{=} NP$ nasce qui: se si trovasse un algoritmo polinomiale per risolvere anche **un solo** problema NP-Completo, allora per la regola della riduzione cadrebbero a cascata tutti gli altri, dimostrando che P = NP. Finché non accade, li consideriamo intrattabili.