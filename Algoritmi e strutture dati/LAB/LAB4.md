<h1> Lab4 - 15/04/2025 </h1>

<h1> Indice </h1>


---

## Alberi Binari di Ricerca (Binary Search Trees)

Implementiamo un codice `binTree` che rappresenta un albero binario di ricerca. L'albero è definito come una struttura dati ricorsiva, in cui ogni nodo ha un valore e due figli (sinistro e destro). La proprietà principale di un albero binario di ricerca è che per ogni nodo, il valore del nodo sinistro è minore del valore del nodo padre e il valore del nodo destro è maggiore del valore del nodo padre.

```cpp

struct Node{
    int value;
    Node * left;
    Node * right;

    Node(int val):
        value(val) , left(NULL) , right(NULL) {}
};

class BinTree{
    Node * root_;
public:
    BinTree() { root_ = NULL; }
    Node * getRoot() { return root_; }
}

```

### Funzioni principali

- `insert(int val)`: inserisce un valore nell'albero. Se l'albero è vuoto, crea un nuovo nodo come radice. Altrimenti, chiama una funzione ricorsiva per trovare la posizione corretta in cui inserire il nuovo nodo.

```cpp
void insert(int val){

    // INIZIALIZZAZIONE DEL NODO
    Node *node = new Node(val);
    Node *pre = NULL;
    Node *post = root_;

    // INDIVIDUO LA POSIZIONE
    while(post != NULL){
        pre = post;
        if( val <= post->value )
            post = post->left;
        else
            post = post->right;
    }
    
    /// INSERIMENTO
    if(pre == NULL)
        root_ = node;
    else if( val <= pre -> value)
        pre->left = node;
    else
        pre->right = node;
}

```

- `min/Max()`: restituisce il valore minimo/massimo dell'albero. Queste funzioni percorrono l'albero a sinistra (per il minimo) o a destra (per il massimo) fino a raggiungere una foglia.

```cpp

Node * minValue(){
    Node * temp = root_;
    while( temp->left != NULL )
        temp = temp->left;
    return temp;
}

Node * maxValue(){
    Node * temp = root_;
    while( temp->right != NULL )
        temp = temp->right;
    return temp;
}

```

- Visite:
  - `preOrder()`: visita il nodo corrente, poi il figlio sinistro e infine il figlio destro.
  - `inOrder()`: visita il figlio sinistro, poi il nodo corrente e infine il figlio destro (quella che vedremo).


```cpp
void inOrder(Node * node){

    if(node != NULL){

        inOrder(node->left);

        cout << node->value << "\t";
        
        inOrder(node->right);

    }
}

```
---

#### Esercizio 1

Creare un albero binario di ricerca, inserire nodi con etichette intere, stampare le etichette dei nodi in ordine non descrescente (visita inOrder), cercare e stampare l'etichetta del nodo con valore minimo e con valore massimo.

1. Apriamo il terminale linux e creiamo una cartella per il nostro esercizio:
```bash
mkdir lab4
cd lab4.1
```
2. Creiamo un file `main.cpp` e incolliamo il codice dell'albero binario di ricerca.
3. Aggiungiamo il codice per testare le funzioni di inserimento e visita dell'albero. Ecco un esempio di codice che crea un albero binario di ricerca, inserisce alcuni valori e stampa i nodi in ordine non decrescente:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Struttura per il nodo dell'albero
struct Node{
    int value;
    Node * left;
    Node * right;

    Node(int val):
        value(val) , left(NULL) , right(NULL) {}
};


// Classe per l'albero binario di ricerca
class BinTree{
    Node * root_;
public:
    BinTree() { root_ = NULL; }
    Node * getRoot() { return root_; }
    void insert(int val);
    Node * minValue();
    Node * maxValue();
    void inOrder(Node * node);
};


// 1. Funzione di inserimento
void BinTree::insert(int val){

    // INIZIALIZZAZIONE DEL NODO
    Node *node = new Node(val);
    Node *pre = NULL;
    Node *post = root_;

    // INDIVIDUO LA POSIZIONE
    while(post != NULL){
        pre = post;
        if( val <= post->value )
            post = post->left;
        else
            post = post->right;
    }
    
    /// INSERIMENTO
    if(pre == NULL)
        root_ = node;
    else if( val <= pre -> value)
        pre->left = node;
    else
        pre->right = node;
}


// 2. Funzione per trovare il valore minimo
Node * BinTree::minValue(){
    Node * temp = root_;
    while( temp->left != NULL )
        temp = temp->left;
    return temp;
}


// 3. Funzione per trovare il valore massimo
Node * BinTree::maxValue(){
    Node * temp = root_;
    while( temp->right != NULL )
        temp = temp->right;
    return temp;
}

// 4. Funzione di visita in ordine
void BinTree::inOrder(Node * node){

    if(node != NULL){

        inOrder(node->left);

        cout << node->value << "\t";
        
        inOrder(node->right);

    }
}

int main(){
    BinTree tree;
    vector<int> values;
    int n;

    cout << "Quanti valori vuoi inserire nell'albero? ";
    cin >> n;

    cout << "Inserisci " << n << " valori interi:" << endl;
    for(int i = 0; i < n; ++i){
        int val;
        cin >> val;
        values.push_back(val);
        tree.insert(val);
    }

    cout << "Funzione inOrder: ";
    tree.inOrder(tree.getRoot());
    cout << endl;

    Node * minNode = tree.minValue();
    Node * maxNode = tree.maxValue();

    if(minNode && maxNode){
        cout << "Min Value: " << minNode->value << endl;
        cout << "Max Value: " << maxNode->value << endl;
    }

    return 0;
}

```

4. Compiliamo il codice con il comando `g++ main.cpp -o lab4` e poi eseguiamo il programma con `./lab4`. Dovremmo vedere l'output della visita in ordine e i valori minimo e massimo dell'albero.

```bash
g++ main.cpp -o lab4.1
./lab4
``` 

5. L'output dovrebbe essere simile a questo:

```bash
Funzione inOrder: 1	 3	4  5  7  8	9
Min Value: 1
Max Value: 9
```

>[!NOTE]
> Il costo dell'inOrder è O(n) in quanto dobbiamo visitare ogni nodo dell'albero. Il costo di ricerca del valore minimo e massimo è O(h), dove h è l'altezza dell'albero. In un albero bilanciato, h è logaritmico rispetto al numero di nodi, mentre in un albero sbilanciato può essere lineare. Il costo di inserimento è O(n<sup>2</sup>) nel caso peggiore (quando l'albero è **_TOTALMENTE SBILANCIATO_**).
> 
> - Albero Alto: log(n) (bilanciato) <--> n (sbilanciato)
> - Inserimento: n*log(n) (bilanciato) <--> n<sup>2</sup> (sbilanciato)
> - Visite: n (bilanciato)
>
> Tutte queste insieme fanno **O(n log(n))** perché l'altezza dell'albero è log(n) e dobbiamo visitare ogni nodo (nella parte bilanciata).
> 
> Tutte queste insieme fanno **O(n<sup>2</sup>)** perché l'altezza dell'albero è n e dobbiamo visitare ogni nodo (nella parte sbilanciata).
---

Andiamo a implementare la funzione `search` che ci permette di cercare un valore nell'albero binario di ricerca. La funzione `search` prende un valore come input e restituisce un puntatore al nodo che contiene quel valore, oppure NULL se il valore non è presente nell'albero.

```cpp
bool * search(Node* tree, int val){
    if(tree == NULL)
        return NULL;

    bool found;

    if(tree->value == val)
        return tree;
    else if(val < tree->value)
        found = search(tree->left, val);
    else
        found = search(tree->right, val);

    return found;
}
```

Ora andiamo a modificare la funzione `search` in modo che restituisca il numero di nodi visitati durante la ricerca del valore. La funzione restituirà 0 se il valore non è presente nell'albero.

```cpp
int search(Node* tree, int val){

    int conta = 0;

    if(tree->value == val) // se il valore è uguale al nodo corrente
    return tree;
    else if(val < tree->value) // se il valore è minore del nodo corrente
        conta = search(tree->left, val);
    else
        conta = search(tree->right, val);

    if(conta != 0) // se il nodo è stato trovato
        return conta + 1; // conta il numero di nodi visitati
    else return 0; // non trovato
}
```

#### Esercizio 2

Riprendendo l'esercizio e quindi il codice di prima adesso implementiamo la funzione `search` e testiamola. Ecco il codice completo:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Struttura per il nodo dell'albero
struct Node{
    int value;
    Node * left;
    Node * right;

    Node(int val):
        value(val) , left(NULL) , right(NULL) {}
};


// Classe per l'albero binario di ricerca
class BinTree{
    Node * root_;
public:
    BinTree() { root_ = NULL; }
    Node * getRoot() { return root_; }
    void insert(int val);
    Node * minValue();
    Node * maxValue();
    void inOrder(Node * node);
};


// 1. Funzione di inserimento
void BinTree::insert(int val){

    // INIZIALIZZAZIONE DEL NODO
    Node *node = new Node(val);
    Node *pre = NULL;
    Node *post = root_;

    // INDIVIDUO LA POSIZIONE
    while(post != NULL){
        pre = post;
        if( val <= post->value )
            post = post->left;
        else
            post = post->right;
    }
    
    /// INSERIMENTO
    if(pre == NULL)
        root_ = node;
    else if( val <= pre -> value)
        pre->left = node;
    else
        pre->right = node;
}


// 2. Funzione per trovare il valore minimo
Node * BinTree::minValue(){
    Node * temp = root_;
    while( temp->left != NULL )
        temp = temp->left;
    return temp;
}


// 3. Funzione per trovare il valore massimo
Node * BinTree::maxValue(){
    Node * temp = root_;
    while( temp->right != NULL )
        temp = temp->right;
    return temp;
}

// 4. Funzione di visita in ordine
void BinTree::inOrder(Node * node){

    if(node != NULL){

        inOrder(node->left);

        cout << node->value << "\t";
        
        inOrder(node->right);

    }
}

// 5. Funzione di ricerca
int search(Node* tree, int val){

    int conta = 0;

    if(tree->value == val) // se il valore è uguale al nodo corrente
        return conta;
    else if(val < tree->value) // se il valore è minore del nodo corrente
        conta = search(tree->left, val);
    else
        conta = search(tree->right, val);

    if(conta != 0) // se il nodo è stato trovato
        return conta + 1; // conta il numero di nodi visitati
    else return 0; // non trovato
}

int main(){
    BinTree tree;
    vector<int> values;
    int n;

    cout << "Quanti valori vuoi inserire nell'albero? ";
    cin >> n;

    /* -------...... - Le altre funzioni nella parte precedente -1 .........------- */

    cout << "Inserisci il valore da cercare: ";
    int searchValue;
    cin >> "Qual'è il valore che vuoi trovare: " searchValue;
    int result = search(tree.getRoot(), searchValue);

    if(result != 0)
        cout << "Il valore " << searchValue << " è stato trovato dopo aver visitato " << result << " nodi." << endl;
    else
        cout << "Il valore " << searchValue << " non è stato trovato nell'albero." << endl;

    return 0;
}

```

1. Compiliamo il codice adesso con la nuova funzione `search` e testiamola. Ecco il comando per compilare il codice:

```bash
g++ main.cpp -o lab4.1.1
./lab4
```
2. L'output dovrebbe essere simile a questo:

```bash
Funzione inOrder: 1	 3	4  5  7  8	9
Min Value: 1
Max Value: 9
#Inseriamo il valore 5 in input
Il valore 5 è stato trovato dopo aver visitato 3 nodi.
```

---

### Esercizio 3

Implementare una struttura dati che supporti un albero binario di ricerca e etichette multi valore. La struttura dati deve supportare le seguenti operazioni:
- insert su albero binario;
- search nodi a livello H;
- sort su stringa.

La struct che dovremmo usare sarà la seguente:

```cpp
struct Node{
    int key;
    string str;
    Node * left;
    Node * right;
}
```

1. Apriamo il terminale linux e creiamo una cartella per il nostro esercizio:
```bash
mkdir lab4
cd lab4.2
```

2. Creiamo un file `main.cpp` e incolliamo il codice dell'albero binario di ricerca.
```bash
touch main.cpp
```
3. Aggiungiamo il codice per testare le funzioni di inserimento e visita dell'albero. Ecco un esempio di codice che crea un albero binario di ricerca, inserisce alcuni valori e stampa i nodi in ordine non decrescente:

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int key;
    string str;
    Node* left;
    Node* right;

    Node(int k, string s) : key(k), str(s), left(NULL), right(NULL) {}
};

class BinTree {
    Node* root_;
public:
    BinTree() { root_ = NULL; }
    void insert(int k, string s);
    void preOrder(Node* node);
    void search(Node* node, int level, int currentLevel);
    void sortString(Node* node);
    Node* getRoot() { return root_; }
};

// Funzione di inserimento
void BinTree::insert(int k, string s) {
    // INIZIALIZZAZIONE DEL NODO
    Node* node = new Node(k, s);
    Node* pre = NULL;
    Node* post = root_;

    // INDIVIDUO LA POSIZIONE
    while (post != NULL) {
        pre = post;
        if (k <= post->key)
            post = post->left;
        else
            post = post->right;
    }

    // INSERIMENTO
    if (pre == NULL)
        root_ = node;
    else if (k <= pre->key)
        pre->left = node;
    else
        pre->right = node;
}

// Funzione di visita pre ordine
void BinTree::preOrder(Node* node) {
    if (node != NULL) {
        cout << node->key << "\t" << node->str << endl;
        preOrder(node->left);
        preOrder(node->right);
    }
}

// Funzione di ricerca nodi a livello H
void BinTree::search(Node* node, int level, int currentLevel) {
    if (node != NULL) {
        if (currentLevel == level)
            cout << node->key << "\t" << node->str << endl;

        search(node->left, level, currentLevel + 1);
        search(node->right, level, currentLevel + 1);
    }
}

// Funzione di ordinamento stringa
void BinTree::sortString(Node* node) {
    if (node != NULL) {
        sortString(node->left);  // Ordina prima a sinistra
        cout << node->key << "\t" << node->str << endl;  // Stampa il nodo
        sortString(node->right); // Poi a destra
    }
}

int main() {
    BinTree tree;
    vector<int> values;
    int n;

    cout << "Quanti valori vuoi inserire nell'albero? ";
    cin >> n;

    cout << "Inserisci " << n << " valori interi e stringhe:" << endl;
    for (int i = 0; i < n; ++i) {
        int k;
        string s;
        cin >> k >> s;
        tree.insert(k, s);
    }

    // Funzione preOrder
    cout << "Funzione preOrder: " << endl;
    tree.preOrder(tree.getRoot());
    cout << endl;

    int level;
    cout << "Inserisci il livello da cercare: ";
    cin >> level;
    cout << "Nodi a livello " << level << ":" << endl;
    tree.search(tree.getRoot(), level, 0);
    cout << endl;

    cout << "Stringa ordinata: " << endl;
    tree.sortString(tree.getRoot());

    return 0;
}
```

4. Compiliamo il codice con il comando `g++ main.cpp -o lab4.2` e poi eseguiamo il programma con `./lab4.2`. Dovremmo vedere l'output della visita in ordine e i valori minimo e massimo dell'albero.

```bash
g++ main.cpp -o lab4.2
./lab4.2
```

5. Ci farà inserire degli input:
```bash
Quanti valori vuoi inserire nell'albero? 5
Inserisci 5 valori interi e stringhe:
1 a
4 b
2 c
8 d
5 e
```
6. L'output dovrebbe essere simile a questo:

```bash
Funzione preOrder:
1	a
4	b
2	c
8   d
5	e
```

7. Adesso andiamo a cercare i nodi a livello 2:
```bash
Inserisci il livello da cercare: 2
Nodi a livello 2:
1	c
4	e
```
8. Infine andiamo a ordinare le stringhe:
```bash
Stringa ordinata:
1    a
2    c
4    b
5    e
8    d
```

---

### Esercizio 4

Implementare una struttura dati che supporti un albero binario di ricerca e con etichette intere. La struttura dati deve supportare le seguenti operazioni:
- insert su albero binario;
- Calcola F(u) e I(u) (usando preOrder + calcolo (informazioni da figli))
- Stampa i nodi validi (inOrder)

La struttura a cui ci facciamo affidamento è la seguente:
```cpp
struct Node
{
    int key;
    int F, I;
    Node* right;
    Node* left;
};
```

1. Apriamo il terminale linux e creiamo una cartella per il nostro esercizio:
```bash
mkdir lab4
cd lab4.3
```
2. Creiamo un file `main.cpp` e incolliamo il codice dell'albero binario di ricerca.
```bash
touch main.cpp
```
3. Aggiungiamo il codice per testare le funzioni di inserimento e visita dell'albero. Ecco un esempio di codice che crea un albero binario di ricerca, inserisce alcuni valori e stampa i nodi in ordine non decrescente:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Node
{
    int key;
    int F, I;
    Node* right;
    Node* left;

    Node(int k) : key(k), F(0), I(0), right(NULL), left(NULL) {}
};

class BinTree
{
    Node* root_;
public:
    BinTree() { root_ = NULL; }
    void insert(int k);
    void preOrder(Node* node);
    void calcolo(Node* node);
    void inOrder(Node* node);
};

// Funzione di inserimento
void BinTree::insert(int k)
{
    // INIZIALIZZAZIONE DEL NODO
    Node* node = new Node(k);
    Node* pre = NULL;
    Node* post = root_;

    // INDIVIDUO LA POSIZIONE
    while (post != NULL) {
        pre = post;
        if (k <= post->key)
            post = post->left;
        else
            post = post->right;
    }

    // INSERIMENTO
    if (pre == NULL)
        root_ = node;
    else if (k <= pre->key)
        pre->left = node;
    else
        pre->right = node;
}

// Funzione di visita pre ordine
void BinTree::preOrder(Node* node)
{
    if (node != NULL) {
        cout << node->key << "\t" << node->F << "\t" << node->I << endl;
        preOrder(node->left);
        preOrder(node->right);
    }
}

// Funzione di calcolo F(u) e I(u)
void BinTree::calcolo(Node* node, int &i, int &f)
{
    if (node == NULL) return;

    // Inizializza F e I
    node->F = 0;
    node->I = 0;

    // Calcola I(u) e F(u) per i figli
    calcolo(node->left, node->left->i, node->right->f);
    calcolo(node->right, node->left->i, node->right->f);

    // se sono una foglia incremento F


}

// Funzione di visita in ordine
void BinTree::inOrder(Node* node)
{
    if (node != NULL) {
        inOrder(node->left);
        cout << node->key << "\t" << node->F << "\t" << node->I << endl;
        inOrder(node->right);
    }
}
