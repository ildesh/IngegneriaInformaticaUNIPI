<h1> Lezione 5 - 12-03-2025 18-03-2025 </h1>

---

<h1> 📚 Indice </h1>


---


# Heap
>[!IMPORTANT] 
>## Definizione
>Un heap è una struttura dati ad albero binario quasi bilanciato (tutti i livelli sono pieni tranne al minimo l'ultimo) che soddisfa la proprietà di heap, che può essere definita in due modi:
>- **Max-Heap**: per ogni nodo `n`, il valore di `n` è maggiore o uguale ai valori dei suoi figli.
>- **Min-Heap**: per ogni nodo `n`, il valore di `n` è minore o uguale ai valori dei suoi figli.

>[!NOTE]
>## Proprietà
>1. I nodi dell'ultimo livello sono addossati a sinistra
>2. In ogni sottoalbero l'etichetta della radice è maggiore o uguale a quella dei figli (max-heap).

![memorizzazzione in Array](../Algoritmi%20e%20strutture%20dati/image/memorizzazioneArray.png)

>[!NOTE]
>## Operazioni
> 1. Inserimento di un nodo
> 2. Estrazione del nodo massimo (radice)   

### Class Heap

```cpp
class Heap {
    int * heap; // array che contiene gli elementi dell'heap
    int last;
    void up(int);
    void down(int);
    void exchange(int i, int j);
    {
        int k = heap[i]; heap[i] = heap[j]; heap[j] = k; // scambia i due nodi
    }
    public:
        Heap(int); // costruttore
        ~Heap() { delete[] heap; } // distruttore
        void insert(int); // inserisce un elemento nell'heap
        int extract(); // estrae l'elemento massimo (radice) dall'heap
        void print(); // stampa l'heap
}
```

>[!NOTE]
> ### Costruttore e distruttore:
> ```cpp
> Heap::Heap(int n){ 
>   heap = new int[n]; last = -1; // inizializza l'array e il contatore
> } 
>
> Heap::~Heap(){
>   delete[] heap; // dealloca l'array
> }
> ```
>
> ### Funzione di inserimento:
> - memorizza l'elemento nella prima posizione libera dell'array (last+1)
> - fai risalire l'elemento tramite scambi figlio-padre per mantenere la proprietà di heap
> ```cpp
> void Heap::insert(int x){
>   heap[++last] = x; // inserisce l'elemento nell'array
>   up(last); // fa risalire l'elemento per mantenere la proprietà di heap
> }
> ```
>
> ### Funzione di risalita:
> - confronta il nodo corrente con il suo padre
> ```cpp
> void Heap::up(int i){
>   int p = (i-1)/2; // calcola l'indice del padre
>   if(i > 0){ // se il nodo corrente è la radice, esci
>       if(heap[i] > h(p)){ // finché il nodo corrente è maggiore del padre
>           exchange(i, p); // scambia il nodo corrente con il padre
>           up(p) // chiama up sulla nuova posizione del nodo corrente
>       }
>    }
> }
> ```
>
> ### Funzione di estrazione:
> - restituisce il primo elemento dell'array
> - metti l'ultimo elemento al posto della radice e decrementa il contatore
> - fai scendere l'elemento tramite scambi padre-figlio per mantenere la proprietà di heap
> ```cpp
> int Heap::extract(){
>   int x = heap[0]; // memorizza il primo elemento
>   heap[0] = heap[last--]; // sposta l'ultimo elemento alla radice
>   down(0); // fa scendere l'elemento per mantenere la proprietà di heap
>   return x; // restituisce l'elemento estratto
> }
> ```
>
> ### Funzione di discesa:
> - confronta il nodo corrente con i suoi figli
> - se il nodo corrente è minore di uno dei figli, scambia il nodo corrente con il figlio maggiore e chiama down sul figlio scambiato
> ```cpp
> void Heap::down(int i){
>   int son = 2*i+1; // calcola l'indice del figlio sinistro (se esiste)
>   if(son == last){ // se i ha un solo figlio (è l'ultimo nodo)
>       if(heap[i] < heap[son]){ // se il nodo corrente è minore del figlio
>           exchange(i, son); // scambia il nodo corrente con il figlio
>       }
>   }
>   else if(son < last){ // se i ha due figli
>      if(heap[i] < heap[son+1]){ // se il nodo corrente è minore del figlio sinistro
>          son++; // incrementa l'indice del figlio sinistro
>      }
>      if(heap[i] < heap[son]){ // se il nodo corrente è minore del figlio maggiore
>          exchange(i, son); // scambia il nodo corrente con il figlio maggiore
>          down(son); // chiama down sul figlio scambiato
>      }
>   }
> }
> ```

### Quando si usa l'heap?

- L'heap si usa particolarmente per implementare il tipo di dato astratto coda con priorità.

  - Si tratta di una coda in cui gli elementi contengono, oltre all'informazione, un intero che rappresenta la priorità dell'elemento stesso.

  - In caso di estrazione, viene estratto l'elemento con priorità maggiore.

# HeapSort
>[!IMPORTANT]
>## Definizione
>HeapSort è un algoritmo di ordinamento che utilizza la struttura dati heap per ordinare gli elementi di un array. L'algoritmo ha una complessità temporale di O(n log n) e una complessità spaziale di O(1).
>
>### Algoritmo
>- trasforma l'array in un heap (costruzione dell'heap - buildHeap)
>- esegui n volte l'estrazione scambiando ogni volta il primo elemento dell'array con quello puntato da last
y è ordinato quando last è uguale a 0
>```cpp
>void heapsort(int *a, int n){
>   buildHeap(a,n); // crea un heap di dimensione n - O(n)
>   int i = n-1; // inizializza l'indice dell'ultimo elemento
>   while(i > 0){ // finché ci sono elementi da ordinare - O(n log n)
>       extract(a, i); // estrae l'elemento massimo e lo scambia con l'ultimo elemento
>   }
>}


>[!NOTE]
> ### Funzione di costruzione dell'heap:
> - esegui la funzione down sulla prima metà degli elementi dell'array (gli elementi della seconda metà sono foglie)
> - esegui down partendo dall'elemento centrale e tornando indietro fino alla radice
>
>```cpp
>void buildHeap(int *a, int n){
>   for(int i = n/2-1; i >= 0; i--){ // inizia dalla metà dell'array e scende fino alla radice - O(n)
>       down(a, i, n); // chiama down per ogni nodo - O(nlog n)
>   }
>}
>```

>[!WARNING]
> #### Extract modificata:
> - la funzione extract è modificata per accettare l'array e la dimensione dell'heap come parametri
> - l'estrazione dell'elemento massimo viene eseguita in modo simile alla funzione di estrazione dell'heap, ma senza la necessità di mantenere la struttura dell'heap dopo ogni estrazione
> ```cpp
> void extract(int *h, int &last){
>   exchange(h, 0, last--); // scambia il primo elemento con l'ultimo
>   down(h, 0, last); // chiama down per mantenere la proprietà di heap
> }
> ```
>
> - I parametri sono l'array e l'ultimo elemento dello heap. L'ultimo elemento viene scambiato con il primo e non si restituisce nulla.
>
>### Down modificata:
> - la funzione down è modificata per accettare l'array e la dimensione dell'heap come parametri
> - la funzione down scende nell'heap e mantiene la proprietà di heap
> ```cpp
> void down(int *h, int i, int last){
>   int son = 2*i+1; // calcola l'indice del figlio sinistro (se esiste)
>   if(son == last){ // se i ha un solo figlio (è l'ultimo nodo)
>       if(h[i] < h[son]){ // se il nodo corrente è minore del figlio
>           exchange(h, i, son); // scambia il nodo corrente con il figlio
>       }
>   }
>   else if(son < last){ // se i ha due figli
>      if(h[i] < h[son+1]){ // se il nodo corrente è minore del figlio sinistro
>          son++; // incrementa l'indice del figlio sinistro
>      }
>      if(h[i] < h[son]){ // se il nodo corrente è minore del figlio maggiore
>          exchange(h, i, son); // scambia il nodo corrente con il figlio maggiore
>          down(h, son, last); // chiama down sul figlio scambiato
>      }
>   }
> }
> ```
>
> - I parametri quindi sono l'array, l'indice dell'elemento da far scendere e l'ultimo elemento dell'array (last).