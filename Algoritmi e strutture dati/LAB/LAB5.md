<h1> Lab5 - 29/04/2025 </h1>

<h1> Indice </h1>


---

# 1. Heap

## 1.1. Definizione
Un heap è una struttura dati ad albero binario che soddisfa la proprietà di heap, ovvero:
- In un max heap, per ogni nodo, il valore del nodo è maggiore o uguale ai valori dei suoi figli.
- In un min heap, per ogni nodo, il valore del nodo è minore o uguale ai valori dei suoi figli.

Un heap è un albero completo, il che significa che tutti i livelli dell'albero sono completamente riempiti tranne, eventualmente, l'ultimo livello, che è riempito da sinistra a destra.


## 1.2. Implementazione

```cpp
#include <iostream>
using namespace std;

class Heap {
    vector<int> data_; // Vettore per memorizzare gli elementi dell'heap
    int array_length_; // Lunghezza dell'array
    int heap_size_; // Dimensione dell'heap

    public:
        Heap() : array_length_(0), heap_size_(0) {} // Costruttore

        void fill(int); // Funzione per riempire l'heap con i dati

        void printVector(); // Funzione per stampare gli elementi dell'heap

        bool isFirstChild(int); // Funzione per verificare se un nodo è il primo figlio

        int parent(int); // Funzione per ottenere l'indice del padre di un nodo

        int getLeft(int); // Funzione per ottenere l'indice del figlio sinistro di un nodo

        int getRight(int); // Funzione per ottenere l'indice del figlio destro di un nodo

        void maxHeapify(int); // Funzione per mantenere la proprietà di heap

}

void Heap::fill(int l) {
    array_length_ = l; // Imposta la lunghezza dell'array
    data_.resize(array_length_); // Ridimensiona il vettore per adattarsi alla lunghezza specificata

    for (int i = 0; i < array_length_; i++) {
        cin >> data_[i]; // Legge gli elementi da input e li memorizza nel vettore
    }
}

bool Heap::isFirstChild(int i) {
    if(i != 0 && (i & (i+1) == 0)) { // Controlla se l'indice non è 0 e se è dispari
        return true; // Se è il primo figlio, restituisce true
    }
    return false; // Altrimenti, restituisce false
}

void Heap::printVector() {
    for (int i = 0; i < array_length_; i++) {
        if(isFirstChild(i)){
            cout << endl; // Stampa una nuova riga se l'elemento è il primo figlio
        }
        cout << data_[i] << "\t"; // Stampa gli elementi del vettore
    }
    cout << endl;
}
```

Consideriamo gli indici a partire da 0.

Dato un nodo con indice i:

- Qual'è l'indice del padre?
- Qual'è l'indice dei figli?


```cpp
int Heap::parent(int i) {
    return floor((i - 1) / 2); // Restituisce l'indice del padre di un nodo - 'floor' serve per arrotondare
}
int Heap::getLeft(int i) {
    return (2 * i) + 1; // Restituisce l'indice del figlio sinistro di un nodo
}
int Heap::getRight(int i) {
    return (2 * i) + 2; // Restituisce l'indice del figlio destro di un nodo
}
```

### 1.3 maxHeapify

La funzione maxHeapify è utilizzata per mantenere la proprietà di heap in un max heap. Essa confronta un nodo con i suoi figli e, se necessario, scambia il nodo con il figlio più grande, continuando a farlo ricorsivamente fino a quando la proprietà di heap è ripristinata.

```cpp
void Heap::Heap::maxHeapify(int i){

    int left = getLeft(i); // Ottiene l'indice del figlio sinistro
    int right = getRight(i); // Ottiene l'indice del figlio destro

    int largest; // Inizializza la variabile largest
    if(left < array_length_ && data_[left] > data_[i]){ // Se il figlio sinistro è maggiore del nodo corrente
        largest = left; // Aggiorna largest con l'indice del figlio sinistro
    }
    else{
        largest = i; // Altrimenti, aggiorna largest con l'indice del nodo corrente
    }

    if(right < array_length_ && data_[right] > data_[largest]){ // Se il figlio destro è maggiore del nodo corrente
        largest = right; // Aggiorna largest con l'indice del figlio destro
    }

    if(largest != i){ // Se largest non è uguale al nodo corrente
        swap(data_[i], data_[largest]); // Scambia i valori dei nodi
        maxHeapify(largest); // Chiama ricorsivamente maxHeapify sul nodo largest
    }
}
```

### 1.4 Esercizio

- Aggiungere nodi
- Stampare Heap (print, isFirstChild)
- Implementare getLeft, getRight, maxHeapify
- Utilizzare stampe di debug per verificare funzionamento maxHeapify

1. Creare una cartella 'LAB5' e all'interno creare un file 'heap.cpp'.
```bash
mkdir LAB5
cd LAB5
touch heap.cpp
```
2. Copiare il codice sopra in 'heap.cpp'.
```bash
nano heap.cpp

# ------------ #

```

```cpp

#include <iostream>
using namespace std;
#include <vector>
#include <cmath> // Per la funzione floor
#include <algorithm> // Per la funzione swap


class Heap {
    vector<int> data_; // Vettore per memorizzare gli elementi dell'heap
    int array_length_; // Lunghezza dell'array
    int heap_size_; // Dimensione dell'heap

    public:
        Heap() : array_length_(0), heap_size_(0) {} // Costruttore

        void fill(int); // Funzione per riempire l'heap con i dati

        void printVector(); // Funzione per stampare gli elementi dell'heap

        bool isFirstChild(int); // Funzione per verificare se un nodo è il primo figlio

        int parent(int); // Funzione per ottenere l'indice del padre di un nodo

        int getLeft(int); // Funzione per ottenere l'indice del figlio sinistro di un nodo

        int getRight(int); // Funzione per ottenere l'indice del figlio destro di un nodo

        void maxHeapify(int); // Funzione per mantenere la proprietà di heap
};

void Heap::fill(int l) {
    array_length_ = l; // Imposta la lunghezza dell'array
    data_.resize(array_length_); // Ridimensiona il vettore per adattarsi alla lunghezza specificata

    for (int i = 0; i < array_length_; i++) {
        cin >> data_[i]; // Legge gli elementi da input e li memorizza nel vettore
    }
}

bool Heap::isFirstChild(int i) {
    if(i != 0 && (i & (i+1) == 0)) { // Controlla se l'indice non è 0 e se è dispari
        return true; // Se è il primo figlio, restituisce true
    }
    return false; // Altrimenti, restituisce false
}

void Heap::printVector() {
    for (int i = 0; i < array_length_; i++) {
        if(isFirstChild(i)){
            cout << endl; // Stampa una nuova riga se l'elemento è il primo figlio
        }
        cout << data_[i] << "\t"; // Stampa gli elementi del vettore
    }
    cout << endl;
}

int Heap::parent(int i) {
    return floor((i - 1) / 2); // Restituisce l'indice del padre di un nodo - 'floor' serve per arrotondare
}

int Heap::getLeft(int i) {
    return (2 * i) + 1; // Restituisce l'indice del figlio sinistro di un nodo
}

int Heap::getRight(int i) {
    return (2 * i) + 2; // Restituisce l'indice del figlio destro di un nodo
}

void Heap::maxHeapify(int i){

    int left = getLeft(i); // Ottiene l'indice del figlio sinistro
    int right = getRight(i); // Ottiene l'indice del figlio destro

    int largest; // Inizializza la variabile largest
    if(left < array_length_ && data_[left] > data_[i]){ // Se il figlio sinistro è maggiore del nodo corrente
        largest = left; // Aggiorna largest con l'indice del figlio sinistro
    }
    else{
        largest = i; // Altrimenti, aggiorna largest con l'indice del nodo corrente
    }

    if(right < array_length_ && data_[right] > data_[largest]){ // Se il figlio destro è maggiore del nodo corrente
        largest = right; // Aggiorna largest con l'indice del figlio destro
    }

    if(largest != i){ // Se largest non è uguale al nodo corrente
        swap(data_[i], data_[largest]); // Scambia i valori dei nodi
        maxHeapify(largest); // Chiama ricorsivamente maxHeapify sul nodo largest
    }
}

int main(){
    Heap h; // Crea un oggetto Heap
    int l; // Variabile per la lunghezza dell'array

    cout << "Inserisci la lunghezza dell'array: ";
    cin >> l; // Legge la lunghezza dell'array da input

    h.fill(l); // Riempi l'heap con i dati
    h.printVector(); // Stampa gli elementi dell'heap

    cout << "Inserisci l'indice del nodo da heapificare: ";
    int index;
    cin >> index; // Legge l'indice del nodo da heapificare da input

    h.maxHeapify(index); // Chiama la funzione maxHeapify sul nodo specificato
    h.printVector(); // Stampa gli elementi dell'heap dopo l'heapificazione

    return 0; // Restituisce 0 per indicare che il programma è terminato con successo
}

```
3. Compilare il file con il comando:
```bash
g++ heap.cpp -o heap 
```

4. Eseguire il file con il comando:
```bash
./heap
```

5. Proviamo a inserire dei dati:
```bash
./heap
```
```bash
"Inserisci la lunghezza dell'array:" 10 # Inseriamo 10 elementi nell'array

10 
20 
30 
40 
50 
60 
70 
80 
90 
100

# Stampa l'array
10	20	30	40	50  60	70	80	90	100 

# Inseriamo l'indice del nodo da heapificare
"Inserisci l'indice del nodo da heapificare:" 2

# Stampa l'array dopo l'heapificazione (scambiando l'elemento di indice 2 con l'elemento di indice 6 per la proprietà di max heap)
10	20	70  40	50	60  30	80	90	100
```

## 1.5 BuildHeap

La funzione BuildHeap è utilizzata per costruire un max heap a partire da un array non ordinato. Essa chiama la funzione maxHeapify su ogni nodo a partire dall'ultimo nodo non foglia fino alla radice dell'albero.

```cpp
void Heap::BuildHeap() {
    for (int i = array_length_ / 2 - 1; i >= 0; --i) { // Inizia dall'ultimo nodo non foglia
        maxHeapify(i); // Chiama maxHeapify per mantenere la proprietà di heap
        print(); // Stampa l'array dopo ogni chiamata a maxHeapify
    }
}
```

### 1.6 Esempio BuildHeap

Supponiamo di avere un array di grandezza 7. Eseguendo la funzione BuildHeap, otteniamo:

```cpp
// Elementi del vettore - 12 16 10 8 3 10 17 2
i = floor(7/2) - 1 = 2
// Chiama maxHeapify(2)
maxHeapify(2)
// Stampa l'array dopo la chiamata a maxHeapify(2) scambiando dunque l'elemento con indice 2 con quello con indice 5 per la 
// proprietà dell'maxHeapify - 12 16 17 8 3 10 10 2
// Facciamo il maxHeapify(5) - non fa nulla in quanto è una foglia e non ha figli

/* ---------------------------------------------- */

// Passiamo al padre (indice 1)
i = 1
// Chiama maxHeapify(1)
// Stampa l'array dopo la chiamata a maxHeapify(1) scambiando dunque l'elemento con indice 1 con quello con indice 3 per la 
// proprietà dell'maxHeapify - 12 16 8 17 3 10 10 2
// Facciamo il maxHeapify(3) - non fa nulla in quanto è una foglia e non ha figli

/* ---------------------------------------------- */
// Passiamo all'altro figlio della radice (indice 1)
i = 1
// Chiama maxHeapify(1)
maxHeapify(1)
// Stampa l'array dopo la chiamata a maxHeapify(1) scambiando dunque l'elemento con indice 1 con quello con indice 3 per la
// proprietà dell'maxHeapify - 12 16 17 8 3 10 10 2
// Facciamo il maxHeapify(3) - non fa nulla in quanto è una foglia e non ha figli

/* ---------------------------------------------- */

// Passiamo alla radice (indice 0)
i = 0
// Chiama maxHeapify(0)
// Stampa l'array dopo la chiamata a maxHeapify(0) scambiando dunque l'elemento con indice 0 con quello con indice 1 per la
// proprietà dell'maxHeapify - 17 16 12 8 3 10 10 2
// Fine perché siamo arrivati alla radice
```

# 2. HeapSort

## 2.1 Definizione

HeapSort è un algoritmo di ordinamento che utilizza la struttura dati heap per ordinare gli elementi. L'algoritmo funziona in due fasi:
1. Costruisce un max heap a partire dall'array non ordinato.
2. Estrae gli elementi dall'heap uno alla volta, riducendo la dimensione dell'heap e mantenendo la proprietà di heap fino a quando l'array è ordinato in ordine crescente.
3. La funzione HeapSort è implementata come segue:

```cpp
void Heap::HeapSort() {
    for (int i = array_length_ - 1; i > 0; --i) { // Estrae gli elementi dall'heap
        swap(data_[0], data_[i]); // Scambia il primo elemento con l'ultimo
        --array_length_; // Riduce la dimensione dell'heap
        maxHeapify(0); // Mantiene la proprietà di heap
    }
}
```


### 2.2 Esercizio 

1. Aggiungere nella cartella 'LAB5' un file 'heapsort.cpp'.
```bash
cd LAB5
touch heapsort.cpp
```

2. Copiare il codice sopra in 'heapsort.cpp'.
```bash
nano heapsort.cpp
```

```cpp

#include <iostream>
using namespace std;
#include <vector>
#include <cmath> // Per la funzione floor
#include <algorithm> // Per la funzione swap


class Heap {
    vector<int> data_; // Vettore per memorizzare gli elementi dell'heap
    int array_length_; // Lunghezza dell'array
    int heap_size_; // Dimensione dell'heap

    public:
        Heap() : array_length_(0), heap_size_(0) {} // Costruttore

        void fill(int); // Funzione per riempire l'heap con i dati

        void printVector(); // Funzione per stampare gli elementi dell'heap

        bool isFirstChild(int); // Funzione per verificare se un nodo è il primo figlio

        int parent(int); // Funzione per ottenere l'indice del padre di un nodo

        int getLeft(int); // Funzione per ottenere l'indice del figlio sinistro di un nodo

        int getRight(int); // Funzione per ottenere l'indice del figlio destro di un nodo

        void maxHeapify(int); // Funzione per mantenere la proprietà di heap

        void BuildHeap(); // Funzione per costruire l'heap a partire dall'array non ordinato

        void HeapSort(); // Funzione per ordinare l'array utilizzando HeapSort
};

void Heap::fill(int l) {
    array_length_ = heap_size_ = l; // Imposta la lunghezza dell'array
    data_.resize(array_length_); // Ridimensiona il vettore per adattarsi alla lunghezza specificata

    for (int i = 0; i < array_length_; i++) {
        cin >> data_[i]; // Legge gli elementi da input e li memorizza nel vettore
    }
}

bool Heap::isFirstChild(int i) {
    if(i != 0 && ((i & (i+1)) == 0)) { // Controlla se l'indice non è 0 e se è dispari
        return true; // Se è il primo figlio, restituisce true
    }
    return false; // Altrimenti, restituisce false
}

void Heap::printVector() {
    for (int i = 0; i < array_length_; i++) {
        if(isFirstChild(i)){
            cout << endl; // Stampa una nuova riga se l'elemento è il primo figlio
        }
        cout << data_[i] << "\t"; // Stampa gli elementi del vettore
    }
    cout << endl;
}

int Heap::parent(int i) {
    return (i - 1) / 2; // Restituisce l'indice del padre di un nodo - 'floor' serve per arrotondare
}

int Heap::getLeft(int i) {
    return (2 * i) + 1; // Restituisce l'indice del figlio sinistro di un nodo
}

int Heap::getRight(int i) {
    return (2 * i) + 2; // Restituisce l'indice del figlio destro di un nodo
}

void Heap::maxHeapify(int i){

    int left = getLeft(i); // Ottiene l'indice del figlio sinistro
    int right = getRight(i); // Ottiene l'indice del figlio destro

    int largest; // Inizializza la variabile largest
    if(left < heap_size_ && data_[left] > data_[i]){ // Se il figlio sinistro è maggiore del nodo corrente
        largest = left; // Aggiorna largest con l'indice del figlio sinistro
    }
    else{
        largest = i; // Altrimenti, aggiorna largest con l'indice del nodo corrente
    }

    if(right < heap_size_ && data_[right] > data_[largest]){ // Se il figlio destro è maggiore del nodo corrente
        largest = right; // Aggiorna largest con l'indice del figlio destro
    }

    if(largest != i){ // Se largest non è uguale al nodo corrente
        swap(data_[i], data_[largest]); // Scambia i valori dei nodi
        maxHeapify(largest); // Chiama ricorsivamente maxHeapify sul nodo largest
    }
}

void Heap::BuildHeap() {
    for (int i = array_length_ / 2 - 1; i >= 0; --i) { // Inizia dall'ultimo nodo non foglia
        maxHeapify(i); // Chiama maxHeapify per mantenere la proprietà di heap
        printVector(); // Stampa l'array dopo ogni chiamata a maxHeapify - per debug
    }
}

void Heap::HeapSort() {
    for (int i = array_length_ - 1; i > 0; --i) { // Estrae gli elementi dall'heap
        swap(data_[0], data_[i]); // Scambia il primo elemento con l'ultimo
        --heap_size_; // Riduce la dimensione dell'heap
        maxHeapify(0); // Mantiene la proprietà di heap
    }
}



int main(){
    Heap h; // Crea un oggetto Heap
    int l; // Variabile per la lunghezza dell'array

    cout << "Inserisci la lunghezza dell'array: ";
    cin >> l; // Legge la lunghezza dell'array da input

    h.fill(l); // Riempi l'heap con i dati
    h.printVector(); // Stampa gli elementi dell'heap

    cout << "Inserisci l'indice del nodo da heapificare: ";
    int index;
    cin >> index; // Legge l'indice del nodo da heapificare da input

    cout << "Uso di Heapify:" << endl;
    h.maxHeapify(index); // Chiama la funzione maxHeapify sul nodo specificato
    h.printVector(); // Stampa gli elementi dell'heap dopo l'heapificazione

    cout << "---" << endl;
    cout << "Uso di BuildHeap:" << endl;
    h.BuildHeap(); // Costruisce l'heap a partire dall'array non ordinato
    h.printVector(); // Stampa l'array dopo la costruzione dell'heap

    cout << "---" << endl;
    cout << "Uso di HeapSort:" << endl;
    h.HeapSort(); // Ordina l'array utilizzando HeapSort
    h.printVector(); // Stampa l'array ordinato

    return 0; // Restituisce 0 per indicare che il programma è terminato con successo
}
```

3. Compilare il file con il comando:
```bash
g++ heapsort.cpp -o heapsort 
```
4. Eseguire il file con il comando:
```bash
./heapsort
```
5. Proviamo a inserire dei dati:
```bash
"Inserisci la lunghezza dell'array:" 7
1
2
3
4
5
6
7
1	
2	3	
4	5	6	7	

"Inserisci l'indice del nodo da heapificare:" 2
"Uso di Heapify:"
1	
2	3	
4	5	6	7	

---

"Uso di BuildHeap:"
1	
2	7	
4	5	6	3	
1	
5	7	
4	2	6	3	
7	
5	6	
4	2	1	3	
7	
5	6	
4	2	1	3	

---

"Uso di HeapSort:"
1	
2	3	
4	5	6	7	

```

# 3 Heap STL 

## 3.1 Definizione

La Standard Template Library (STL) di C++ fornisce una classe heap che implementa le operazioni di heap in modo efficiente. La STL utilizza un vettore per memorizzare gli elementi dell'heap e fornisce funzioni per costruire, modificare e ordinare l'heap.

## 3.2 Implementazione

```cpp
#include <iostream>
#include <algorithm> // Per le funzioni di heap
#include <vector>
using namespace std;

make_heap( inizio , fine ) // Dato un vettore, riordina i suoi elementi per formare uno heap
pop_heap( inizio , fine ) // Dato un vettore, sposta l’elemento maggiore (in testa) in fondo al vettore. Ripristina lo Heap.
pop_back() // Elimina l'ultimo elemento del vettore

int main(){
    vector<int> vect;
    for( int i = 0 ; i<quanti ; ++i ){
        cin >> val;
        vect.push_back(val);
    }
    make_heap(vect.begin(),vect.end());
    while(!vect.empty()){
        cout << "top " << *vect.begin() << endl;
        pop_heap(vect.begin(),vect.end());
        vect.pop_back();
    }
    return 0;
}
```

## 3.3 Priority Queue

Le priority queue sono strutture dati che servono per mantenere dati ordinati secondo una certa politica (max per default).

Le operazioni principali sono:
- `Inserimento`: inserisce un elemento nella coda con priorità.
- `findMin` / `findMax`: restituisce l'elemento con priorità massima o minima.
- `deleteMin` / `deleteMax`: rimuove l'elemento con priorità massima o minima.


>[!NOTE]
>Le code di priorità possono essere realizzate tramite Heap binario.
>
>Funzione maxHeapify va adattata alla politica adottata.

### 3.4 Esercizio

Si consideri un sistema per la gestione delle richieste.
- Si leggano N richieste e si inseriscano in una priority queue, implementata tramite Heap.
- Politica di ordinamento nella coda: Priorità decrescente. A parità di priorità, ID decrescente.
- La prima riga dell’input contiene l’intero N.
- Le successive righe contengono una richiesta per riga, con ID e priorità separati da spazio.
- Si stampi l’ID della richiesta con più alta priorità.
- Si elimini l’elemento in testa. Si stampi l’ID della richiesta con più alta priorità.

1. Aggiungere nella cartella 'LAB5' un file 'priority_queue.cpp'.
```bash
cd LAB5
touch priority_queue.cpp
```

2. Prendere spunto dal codice sopra e implementare la priority queue.
```bash
nano priority_queue.cpp
```

```cpp
#include <iostream>
#include <algorithm> // Per le funzioni di heap
#include <vector>
using namespace std;

struct Richiesta{
    int id; // ID della richiesta
    int priorita; // Priorità della richiesta

    Richiesta(int i, int p) : id(i), priorita(p) {} // Costruttore per inizializzare ID e priorità
};

class Heap{

    vector<Richiesta> data_; // Vettore per memorizzare le richieste
    int array_length_; // Lunghezza dell'array
    int heap_size_; // Dimensione dell'heap

    public:
        Heap();// Costruttore

        void fill(int); // Funzione per riempire l'heap con le richieste

        bool confrontaRichieste(Richiesta, Richiesta)// Funzione per verificare le condizioni delle richieste

        void printVector(); // Funzione per stampare le richieste nell'heap

        void maxHeapify(int); // Funzione per mantenere la proprietà di heap

        int getLeft(int); // Funzione per ottenere l'indice del figlio sinistro di un nodo

        int getRight(int); // Funzione per ottenere l'indice del figlio destro di un nodo

        void eliminaTestaHeap(); // Funzione per eliminare l'elemento in testa all'heap

};

void Heap::fill(int l) {
    array_length_ = heap_size_ = l; // Imposta la lunghezza dell'array
    data_.resize(array_length_); // Ridimensiona il vettore per adattarsi alla lunghezza specificata

    for (int i = 0; i < array_length_; i++) {
        cin >> data_[i]; // Legge gli elementi da input e li memorizza nel vettore
    }
}


void Heap::printVector() {
    for (int i = 0; i < array_length_; i++) {
        if(confrontaRichieste(i)){
            cout << endl; // Stampa una nuova riga se l'elemento è la prima richiesta
        }
        cout << data_[i] << "\t"; // Stampa gli elementi del vettore
    }
    cout << endl;
}


int Heap::getLeft(int i) {
    return (2 * i) + 1; // Restituisce l'indice del figlio sinistro di un nodo
}

int Heap::getRight(int i) {
    return (2 * i) + 2; // Restituisce l'indice del figlio destro di un nodo
}

bool Heap::confrontaRichieste(Richiesta a, Richiesta b){
    if(a.priorita > b.priorita){ // Se la priorità della richiesta a è maggiore di quella della richiesta b
        return true; // Restituisce true
    }
    else if(a.priorita == b.priorita && a.id > b.id){ // Se le priorità sono uguali e l'ID della richiesta a è maggiore di quello della richiesta b
        return true; // Restituisce true
    }
    return false; // Altrimenti, restituisce false
}

void Heap::maxHeapify(int i){

    int left = getLeft(i); // Ottiene l'indice del figlio sinistro
    int right = getRight(i); // Ottiene l'indice del figlio destro

    int largest; // Inizializza la variabile largest
    if(left < heap_size_ && confrontaRichieste(data_[left], data_[i])){ // Se il figlio sinistro è maggiore del nodo corrente
        largest = left; // Aggiorna largest con l'indice del figlio sinistro
    }
    else{
        largest = i; // Altrimenti, aggiorna largest con l'indice del nodo corrente
    }

    if(right < heap_size_ && confrontaRichieste(data_[left], data_[largest])){ // Se il figlio destro è maggiore del nodo corrente
        largest = right; // Aggiorna largest con l'indice del figlio destro
    }

    if(largest != i){ // Se largest non è uguale al nodo corrente
        swap(data_[i], data_[largest]); // Scambia i valori dei nodi
        maxHeapify(largest); // Chiama ricorsivamente maxHeapify sul nodo largest
    }
}

void Heap::BuildHeap() {
    for (int i = array_length_ / 2 - 1; i >= 0; --i) { // Inizia dall'ultimo nodo non foglia
        maxHeapify(i); // Chiama maxHeapify per mantenere la proprietà di heap
        // printVector(); Stampa l'array dopo ogni chiamata a maxHeapify - per debug
    }
}

void Heap::HeapSort() {
    for (int i = array_length_ - 1; i > 0; --i) { // Estrae gli elementi dall'heap
        swap(data_[0], data_[i]); // Scambia il primo elemento con l'ultimo
        --heap_size_; // Riduce la dimensione dell'heap
        maxHeapify(0); // Mantiene la proprietà di heap
    }
}

void Heap::eliminaTestaHeap() {
    data_[0] = data_[heap_size_ - 1]; // Sposta l'ultimo elemento in testa
    data_.pop_back(); // Rimuove l'ultimo elemento
    --heap_size_; // Riduce la dimensione dell'heap
    maxHeapify(0); // Mantiene la proprietà di heap
}

int main(){
    Heap h; // Crea un oggetto Heap
    int l; // Variabile per la lunghezza dell'array

    cout << "Inserisci la lunghezza dell'array: ";
    cin >> l; // Legge la lunghezza dell'array da input

    h.fill(l); // Riempi l'heap con i dati
    h.printVector(); // Stampa gli elementi dell'heap


    return 0;
}

// DA SISTEMARE