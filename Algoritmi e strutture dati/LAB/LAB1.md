# LAB 1 - 04-03-2025
## | Comandi base Unix
- Navigare tra cartelle

| Comando                 | Descrizione |
|-------------------------|------------|
| `ls`                   | Elenca i file e le directory nella cartella corrente. |
| `ls -l`                | Mostra i dettagli di ogni file (permessi, dimensione, data di modifica, ecc.). |
| `ls -a`                | Mostra anche i file nascosti (quelli che iniziano con `.`). |
| `pwd`                  | Mostra il percorso assoluto della directory corrente. |
| `cd nome_cartella`     | Entra nella directory `nome_cartella`. |
| `cd ..`               | Torna indietro di una directory. |
| `cd /percorso/assoluto` | Si sposta direttamente alla directory specificata. |
| `cd ~`                | Torna alla home dell’utente. |

- Creare/spostare/copiare/cancellare fle e cartelle

| Comando                 | Descrizione |
|-------------------------|------------|
| `mkdir nome_cartella`  | Crea una nuova cartella. |
| `touch nome_file`      | Crea un file vuoto. |
| `cp file1 file2`       | Copia `file1` e crea un duplicato chiamato `file2`. |
| `cp -r dir1 dir2`      | Copia una directory (`dir1`) e il suo contenuto in `dir2`. |
| `mv file cartella/`    | Sposta il file nella cartella indicata. |
| `mv vecchio_nome nuovo_nome` | Rinomina un file o una cartella. |
| `rm file`             | Cancella un file. |
| `rm -r cartella`      | Cancella una cartella e il suo contenuto. |
| `rm -rf cartella`     | Cancella forzatamente una cartella, senza chiedere conferma. |

- Comandi per compilare ed eseguire file

| Comando                 | Descrizione |
|-------------------------|------------|
| `g++ file.cpp -o output` | Compila un file C++ e genera un eseguibile chiamato `output`. |
| `./output`              | Esegue il programma compilato. |
| `g++ -Wall file.cpp -o output` | Compila mostrando eventuali **warning** (consigliato per il debug). |
| `g++ -std=c++11 file.cpp -o output` | Compila utilizzando la versione C++11 dello standard. |
| `g++ -std=c++17 file.cpp -o output` | Compila utilizzando la versione C++17 dello standard. |
| `chmod +x script.sh`    | Rende eseguibile uno script shell (`.sh`). |
| `./script.sh`           | Esegue uno script shell. |
#### Esempio programma cpp

>[!TIP] Scrivere un programma che:
> 1. Possa memorizzare 10 interi.
> 2. Stampare i numeri inseriti dall'utente. 

```cpp
#include <iostream>  // Libreria per input e output

using namespace std;

int main() {
    const int DIM = 10;  // Definiamo una costante per la dimensione dell'array
    int numeri[DIM];     // Dichiarazione dell'array di 10 interi

    // Input: L'utente inserisce 10 numeri
    cout << "Inserisci 10 numeri interi:\n";
    for (int i = 0; i < DIM; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> numeri[i];
    }

    // Output: Stampa dei numeri inseriti
    cout << "\nI numeri inseriti sono:\n";
    for (int i = 0; i < DIM; i++) {
        cout << numeri[i] << " ";
    }

    cout << endl;  // Nuova riga per migliore leggibilità
    return 0;
}
```

Spiegazione del codice:

Utilizziamo un array numeri[DIM] per memorizzare 10 interi.
Il ciclo for permette all'utente di inserire i numeri.
Un secondo ciclo for stampa i numeri inseriti sulla stessa riga.

---

## | Debug

> If debugging is the process of removing software bugs, then programming must be the process of putting them in | E. Dijkstra

- Diverse tecniche:
  - Testo
  - Visuale
  - “Debugger” (es GDB , DDD)
  - Compilatore
  - Analisi Memoria (Valgrind)
  

### Debug visuale:

Il debug visuale è una tecnica che sfrutta strumenti con interfacce grafiche per analizzare e correggere il comportamento di un'applicazione. Questi strumenti forniscono una rappresentazione visiva del codice e del suo stato durante l'esecuzione, facilitando l'identificazione e la risoluzione dei bug.

I'll help you continue the notes based on the PDF document. I'll provide a continuation in the same markdown style you've started:

---

### Debug Visuale - Esempio Pratico

```cpp
// Funzione per stampare l'array con un "buco"
void stampaArray(int arr[], int len, int buco) {
    for (int i = 0; i < len; ++i) {
        if (i == buco)
            cout << "\t";  // Lascia uno spazio vuoto nella posizione del "buco"
        else
            cout << arr[i] << "\t";  // Stampa normalmente
    }
    cout << endl;
}

// Funzione per stampare un "segno" in una posizione specifica
void stampaSegno(int posizione, int segno) {
    // Stampa spazi fino alla posizione desiderata
    for (int i = 0; i < posizione; ++i)
        cout << "\t";
    
    // Stampa il segno
    cout << segno << "\n";
}

int main() {
    const int len = 10;
    int arr[len] = {9, 5, 1, 14, 0, 9, 5, 1, 14, 0};
    
    // Esempio di debug visuale
    for (int i = 0; i < len; ++i) {
        // Stampa il valore corrente come "segno"
        stampaSegno(i, arr[i]);
        
        // Stampa l'array con "buco" per ogni iterazione
        for (int j = i; j >= 0; --j) {
            stampaArray(arr, len, j);
        }
        
        // Stampa l'array completo
        stampaArray(arr, len, -1);
        
        cout << "=======================================" << endl;
    }
    
    return 0;
}
```

### Nomi delle Variabili

> [!IMPORTANT]
> Utilizzare nomi significativi e chiari per le variabili è fondamentale per la leggibilità del codice.

Esempi:
- ❌ Evitare: `int a = 10;`
- ✅ Preferire: `const int arraySize = 10;`
- ❌ Evitare: `void prova(int* p, int x);`
- ✅ Preferire: `void printArray(int* array, int length);`

---

## Ordinamento: Insertion Sort

### Concetto base

L'Insertion Sort è un algoritmo di ordinamento che funziona in modo simile a come si ordinerebbero le carte da gioco in mano:
- Si prende un elemento alla volta
- Lo si inserisce nella posizione corretta rispetto agli elementi già ordinati

### Implementazione in C++

```cpp
void insertionSort(int arr[], int len) {
    for (int iter = 1; iter < len; ++iter) {
        int elementoCorrente = arr[iter];
        int posizioneCorrente = iter - 1;
        
        // Sposta gli elementi maggiori di elementoCorrente
        while (posizioneCorrente >= 0 && arr[posizioneCorrente] > elementoCorrente) {
            arr[posizioneCorrente + 1] = arr[posizioneCorrente];
            --posizioneCorrente;
        }
        
        // Inserisce l'elemento nella posizione corretta
        arr[posizioneCorrente + 1] = elementoCorrente;
    }
}
```

### Analisi delle Prestazioni

- **Caso Migliore**: Θ(n) - quando l'array è già ordinato
- **Caso Peggiore**: Θ(n²) - quando l'array è ordinato in ordine inverso
  - Esempio: `[10, 9, 8, 7, 6, 5, 4, 3, 2, 1]`

---
## Ordinamento: Insertion Sort

* **Idea:** Simula l'ordinamento delle carte da gioco.
* **Algoritmo:**
    1. Prendi un elemento dalla parte non ordinata dell'array.
    2. Inseriscilo nella posizione corretta nella parte ordinata.
    3. Ripeti finché l'array non è ordinato.
* **Codice:**
    ```cpp
    void insertionSort(int arr[], int len) {
        for (int i = 1; i < len; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }
    ```
* **Analisi:**
    * Complessità: O(n^2) nel caso peggiore (array ordinato al contrario).
    * Esempio di caso peggiore: 10, 9, 8, 7, 6, 5, 4, 3, 2, 1.

---

## Fusione di Array Ordinati (Combina)

* **Idea:** Prendi due array ordinati e produci un array ordinato che li contiene entrambi.
* **Algoritmo:**
    1. Crea un array temporaneo per il risultato.
    2. Confronta gli elementi dei due array di input e inserisci il più piccolo nel risultato.
    3. Ripeti finché entrambi gli array di input non sono vuoti.
    4. Copia il risultato nell'array originale.
* **Codice:**
    ```cpp
    void combina(int arr[], int start, int mid, int end) {
        int i = start, j = mid + 1, k = 0;
        int temp[end - start + 1];
        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp[k] = arr[i];
                ++i;
            } else {
                temp[k] = arr[j];
                ++j;
            }
            ++k;
        }
        while (i <= mid) {
            temp[k] = arr[i];
            ++i; ++k;
        }
        while (j <= end) {
            temp[k] = arr[j];
            ++j; ++k;
        }
        for (i = start; i <= end; ++i) {
            arr[i] = temp[i - start];
        }
    }
    ```