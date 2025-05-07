<h1> Lab6 - 06/05/2025 </h1>

<h1> Indice </h1>


---

# Hashing

## Che cos'è una tabella hash:

Una tabella hash è una struttura dati efficiente per implementare dizionari, cio`e insiemi dinamici che supportano le operazioni di inserimento, cancellazione e ricerca.

Le tabelle hash implementano queste tre operazioni con complessit`a media costante _O(1)_.

la ricerca su tabelle hash e piu' efficiente della ricerca su liste (Θ(n)) e di quella su alberi binari di ricerca (Θ(log n)).

---

## Indirizzamento diretto: 
Ogni dato (o chiave) viene memorizzato direttamente nel suo "indirizzo" calcolato dalla funzione hash.
Ad esempio, se la funzione hash restituisce un valore che rappresenta un indice in una tabella, il dato viene memorizzato in quella cella.
L'indirizzamento diretto è semplice e veloce, ma richiede una tabella hash di dimensioni sufficienti a contenere tutti i dati possibili.

---

## Indirizzamento indiretto:
L'indirizzamento indiretto prevede l'utilizzo di un'altra tabella o di un meccanismo per memorizzare l'indirizzo (la posizione in memoria) di un dato, invece del dato stesso. 
In questo caso, l'indirizzo diretto viene utilizzato per trovare l'indirizzo di memoria del dato, non il dato stesso. 
L'indirizzamento indiretto può essere più efficiente in termini di spazio di memoria rispetto all'indirizzamento diretto, soprattutto se il range di chiavi possibili è molto ampio. 
Un esempio di indirizzamento indiretto è la gestione delle password mediante hashing: si memorizza l'hash della password, non la password stessa, per motivi di sicurezza. 

---

### Creazione di una simple hash table:

- Chiave coincide con valore
- Trattiamo interi >0
- La funzione HASH è la funzione modulo
- Come rappresentare le celle vuole?
- Convenzione 0 per vuoto


```cpp
class HashTable{
    int* table_
    int size_;

    public:
        HashTable(int size);

        bool insert(int key);

        void print();

        int hash(int key);


        // Implemetiamo la funzione HashTable() - nostro costruttore:
        HashTable::HashTable(int size){
            table_ = new int[size];
            size_ = size;
            memset(table_,0,size*sizeof(int));
        }

        int HashTable::hash(int key){
            return key % size_; // Gli indici che si possono ottenere andranno da 0 a size - 1 
                                // e la dimensione del vettore DOVRA' essere pari a size_
        }

        bool HashTable::insert( int key ){
            int index = hash(key);
            if( table_[index] != 0 )
            {
            cout << "already occupied" << endl;
            return false;
            }
            table_[index] = key;
            cout << "key stored" << endl;
            return true;
        }
};  
```

---

# Collisioni

## Che cosa sono le collisioni:

Le collisioni si verificano quando due o più dati diversi producono lo stesso valore hash. Questo può essere un problema, soprattutto in applicazioni che richiedono la validazione dell'integrità dei dati o la sicurezza, perché permette di falsificare dei dati. 

- Liste di trabocco
- Indirizzamento aperto

Esempio:

|3|5|6|7 / 12| 4|
|-|-|-|-|-|

Come possiamo notare in questo array, nell'indice 4 sono presenti due numeri:

  - hash(x) = x % size
  - hash(7) = 7 % 5
  - hash(12) = 12 % 5

```cpp
struct Elem
{
    int key;
    Elem * next;
    Elem * prev;
    Elem(): next(NULL) , prev(NULL) {}
};

class HashTable{
    Elem ** table_; // possiamo anche scrivere vector<vector<int>> table_;
    int size_;

    public:
        HashTable( int size );
        int hash( int key );
        void insert( int key );
        void print();
        void printOccupancy();
        bool find(int key);
};
```

### Esercizio

- Scrivere un programma che legga da tastiera: 
  - gli interi M, N, K
  - M interi e li inserisca in una tabella hash
- Si utilizzi la seguente funzione hash:
$$
\text{key} \space \% \space \text{N}
$$
- Si utilizzi l’implementazione con **liste** e si inserisca in testa
- Stampare il numero di valori inseriti in ogni posizione della tabella
- Cercare il valore K, se trovato stampare **“SI”**, altrimenti stampare **“NO”**


```cpp
#include <iostream>

struct Elem
{
    int key;
    Elem * next;
    Elem * prev;
    Elem(): next(NULL) , prev(NULL) {}
};

class HashTable{
    Elem ** table_; // possiamo anche scrivere vector<vector<int>> table_;
    int size_;

    public:
        HashTable( int size );
        int hash( int key );
        void insert( int key );
        void print();
        void printOccupancy();
        bool find(int key);

    HashTable(int size) {
        size_ = size;
        table_ = new Elem*[size_];
        for (int i = 0; i < size_; i++)
            table_[i] = NULL;
    }

    int hash(int key) {
        return key % size_;
    }

    void insert(int key) {
        int pos = hash(key);
        Elem* nuovo = new Elem(key);
        nuovo->next = table_[pos];
        if (table_[pos] != NULL)
            table_[pos]->prev = nuovo;
        table_[pos] = nuovo;
    }

    // Funzione in cui vengono contati quanti elementi sono 
    // presenti in una sola posizione della lista
    void printOccupancy() {
        for (int i = 0; i < size_; i++) {
            int count = 0;
            Elem* p = table_[i];
            while (p != NULL) {
                count++;
                p = p->next;
            }
            cout << "Posizione " << i << ": " << count << " elementi" << endl;
        }
    }

    // Funzione che ci permette di trovare 
    bool find(int key) {
        int pos = hash(key);
        Elem* p = table_[pos];
        while (p != NULL) {
            if (p->key == key)
                return true;
            p = p->next;
        }
        return false;
    }

};

int main(){
    int M,N,K;
    cin >> M >> N >> K;

    HashTable table(N);
    
    for (int i = 0; i < M; i++){
        int val;
        cin >> val;
        table.insert(val);
    }

    if(table.find(K)){
        cout << "SI" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}
```

---

# Hashing stringhe
## Come avviene l'hashing sulle stringhe?

L'hashing sulle stringhe permette di convertire una stringa di input di lunghezza arbitraria in una stringa di lunghezza fissa, chiamata "valore hash". Questo valore hash rappresenta la stringa originale e viene utilizzato per scopi come il confronto di stringhe, l'identificazione univoca di elementi, o la memorizzazione efficiente di dati. 

Per questo tipo di hash possiamo usare questa funzione:

```cpp
// Somma di caratteri

int hash(string key)
{
    int index = 0;
    for( int i = 0 ; i < key.length() ; ++i ){
        index += ( index + key[i] );
    }
    return index % size_;
}

// Prima lettera

int hash(string key)
{
    int index = key[0] % size_;
}
```

>[!WARNING]
> Nella seconda funzione (Prima lettera) potrebbero sorgere dei problemi riguardo al fatto in cui potrebberò essere riempite con parecchi, pochissimi o anche zero caratteri, le caselle della tabella hash.
> 
> Questa funzione usa solo la prima lettera della stringa per calcolare la posizione nella tabella hash. Quindi:
>
> - Se tante parole iniziano con la stessa lettera (esempio: molte parole che iniziano con 'a' o 's'), andranno tutte nella stessa posizione nella tabella → creano collisioni.
>
> - Altre lettere magari non vengono mai usate come iniziale, quindi certe posizioni nella tabella hash restano sempre vuote.

### Esercizio:

- Scrivere un programma che legga da tastiera:
    - gli interi N, size e H. H è il tipo di funzione hash da utilizzare
    - N stringhe e le inserisca in una tabella hash
- Si implementino le funzioni hash delle slides precedenti:
    - Prima lettera (tipo 0)
    - Somma caratteri (tipo 1)
- Si utilizzi l’implementazione con VECTOR
- Stampare il numero massimo collisioni nella tabella per la  funzione hash H.

```cpp
class HashTable{
    vector<vector<string>> table_;
    int size_;

public:
    HashTable(int);
    int hash1(string);
    int hash2(string);
    void insert(string key, int H);
    int maxCollision();
};

HashTable::HashTable(int size){
        size_ = size;
        table_.resize(size_);
}

int HastTable::hash1(string key)
{
    int index = 0;
    for( int i = 0 ; i < key.length() ; ++i ){
        index += ( index + key[i] );
    }
    return index % size_;
}

// Prima lettera

int HastTable::hash2(string key)
{
    int index = key[0] % size_;
}

void insert(string key, int H) {
        int pos;
        if (H == 0)
            pos = hash2(key);
        else
            pos = hash1(key);
        table_[pos].push_back(key);
}

int maxCollision(){
    int max = 0;
    for(int i = 0; i < size_; i++){
        int count = table_[i].size();
        if(count > max){
            max = count;
        }
        return max;
    }
}

int main(){
    int N,size;

    HashTable H(size);

    for(int i = 0; i < size; i++){
        string elemento;
        cin >> elemento
        H.insert(elemento, H);
    }

    int max = maxCollision();
    cout << "Il massimo di collisioni e' pari a " << max << endl;

    return 0;
}
```

---

# Good HASH

- Dipende fortemenete dal tipo di applicazione
- Per applicazione di indexing è fondamentale l'uniformità
- Per applicazioni di sicurezza è fondamentale la non invertibilità e la resistenza alle collisioni
- Per il load balancing è fondamentale la coerenza
- Lavorano sulla rappresentazione binaria, operano a livello di bit 
  - Prima viene applicata la conversione e poi operazioni bit a bit
    - Utilizzato molto per i database come per esempio: MurmurHash,
CityHash, FarmHash

## `stl::map`

```cpp
std::map < key_T, obj_t > table;
```
Osserviamo e capiamo 
- key_T = rappresenta il tipo di chiave;
- obj_t = rappresenta il tipo di dati;

```cpp
table[ 'uno' ] = "valore uno";
table.find('uno');
```

### Open Addressing

- **_Scansione lineare_**: cerco il mio elemento x partendo dall’indice h(x) e
scorrendo verso destra. Mi fermo quando lo trovo o quando trovo una
posizione vuota.

    (ℎ 𝑥 + 𝑖) % 𝑠𝑖𝑧𝑒, 0 ≤ 𝑖 ≤ 𝑠𝑖𝑧𝑒

- Le collisioni aumentano il tempo di ricerca.
- Il numero di valori che si può inserire è limitato.
  - Quando una posizione è vuota?
  - Come gestire le cancellazioni?
  
### Open Addressing - Inserimento 

||||3|33|48|63|**_-1_**|||||||
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|

- -1 identifica una posizione vuota
  - Se sto cercando 18, quando trovo -1 capisco che il valore non c'è;
  - Se voglio inserire 18, quando trovo -1 lo inserisco.
 
### Open Addressing - Cancellazione

||||3|33|**_-2_**|63|-1|||||||
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|

- -2 identifica una posizione con valore cancellato
  - Durante una ricerca, se trovo -2 proseguo;
  - Se voglio un valore, quando trovo -2 lo cancello

---

# Lista di trabocco
Per ogni cella della tabella di hash si fa corrispondere invece di un elemento, una lista (solitamente una lista concatenata). In questo modo un elemento che collide viene aggiunto alla lista corrispondente all'indice ottenuto.

### Esercizio: tabella hash con ABR (albero binario)

- Si costruisca una tabella hash per salvare il numero di studenti per ogni
docente. Ogni elemento della tabella hash è un ABR
- Ogni docente è caratterizzato da
        
        <matricola (int), cognome (string), totale_iscritti (int)>

- Ogni docente è inserito in un ABR utilizzando la matricola come etichetta
- Funzione Hash: 
  
        h(x) = {matricola}%(N/2)

- Si consideri l’indice della tabella hash con più collisioni. A parità di collisioni,
selezionare l’indice minore. Dato un valore intero K e gli elementi a quell’indice,
stampare il cognome dei docenti in ordine di matricola non decrescente, con
almeno K iscritti.

```cpp
struct Node{
    int matricola;
    string cognome;
    int totale_iscritti;
    Node *left;
    Node *right;
};

class HashTable{
    vectore<Node*> docente;
    int size_;
    public:
        HashTable(int N){
            size_ = N;
            table.resize(size_, nullptr)
        }
        int hash(int matricola){
            return matricola % (size_/2);
        }

        void insertDocente(int matricola, string cognome, int iscritti) {
            int index = hash(matricola);
            Node* newDoc = new Node(matricola, cognome, iscritti);
            insertInTree(table_[index], newDoc);
        }

        void insertInTree(Node*& root, Node* newDoc) {
            if (root == nullptr) {
                root = newDoc;
                return;
            }
            if (newDoc->matricola < root->matricola)
                insertInTree(root->left, newDoc);
            else
                insertInTree(root->right, newDoc);
        }

        int countNodes(Node* root) {
            if (root == nullptr) return 0;
            return 1 + countNodes(root->left) + countNodes(root->right);
        }

        int indiceMassimeCollisioni() {
            int max = -1, indice = -1;
            for (int i = 0; i < size_; i++) {
                int count = countNodes(table_[i]);
                if (count > max || (count == max && i < indice)) {
                    max = count;
                    indice = i;
                }
            }
            return indice;
        }

        void stampaDocenti(Node* root, int K) {
            if (root == nullptr) return;
            stampaDocenti(root->left, K);
            if (root->totale_iscritti >= K)
                cout << root->cognome << endl;
            stampaDocenti(root->right, K);
        }

        void stampaDocentiConAlmenoK(int K) {
            int indice = indiceMassimeCollisioni();
            stampaDocenti(table_[indice], K);
        }
};

int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        int matricola, iscritti;
        string cognome;
        cin >> matricola >> iscritti >> cognome;
        t.insertDocente(matricola,iscritti,cognome);
    }

    int K;
    cin >> K;

    t.stampaDocentiConAlmenoK(K);

    return 0;
}
```

