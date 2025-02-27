# Lezione 2 - Algoritmi e strutture dati
## | Complessitá Algoritmo vs Velocitá Programma
> Tempi di esecuzione di differenti algorimi per istanze di dimensione crescente su un processore che sa eseguire un **milione di istruzioni** di alto livello **_al secondo_**. L’indicazione **_very long_** indica che il tempo di calcolo supera 1025 anni.


| n           | complessità A | complessità B | complessità C | complessità D | complessità E  | complessità F     | complessità G       |
|-------------|---------------|---------------|---------------|---------------|----------------|--------------------|---------------------|
| 10          | < 1 sec       | < 1 sec       | < 1 sec       | < 1 sec       | < 1 sec        | < 1 sec            | 4 sec               |
| 30          | < 1 sec       | < 1 sec       | < 1 sec       | < 1 sec       | < 1 sec        | 18 min             | \(10^{25}\) years   |
| 50          | < 1 sec       | < 1 sec       | < 1 sec       | < 1 sec       | 11 min         | 36 years           | very long           |
| 100         | < 1 sec       | < 1 sec       | < 1 sec       | 1 sec         | 12,892 years   | \(10^{17}\) years   | very long           |
| 1,000       | < 1 sec       | < 1 sec       | 1 sec         | 18 min        | very long      | very long          | very long           |
| 10,000      | < 1 sec       | < 1 sec       | 2 min         | 12 days       | very long      | very long          | very long           |
| 100,000     | < 1 sec       | 2 sec         | 3 hours       | 32 years      | very long      | very long          | very long           |
| 1,000,000   | 1 sec         | 20 sec        | 12 days       | 31,710 years  | very long      | very long          | very long           |


### Teorema:

per ogni k, n<sup>k</sup> appartenente a O(a<sup>n</sup>), per ogni a > 1, una qualsiasi funzione polinomiale ha **_minore complessità_** di una qualsiasi funzione esponenziale.

* Notazione Ω (omega grande) - (limite asintotico inferiore):
    - f(n) è Ω(g(n)) se esistono un intero n<sub>0</sub> e una costante c > 0 tali che f(n) ≥ cg(n) per ogni n ≥ n<sub>0</sub>.
      - Esempi: 
       1. 2n<sup>2</sup> + 3n + 1 è **Ω(n<sup>2</sup>)**; 
       2. 100n<sup>3</sup> è **Ω(n<sup>3</sup>)**;
       3. 2<sup>n</sup> è **Ω(2<sup>n/2</sup>)**;
       4. 2<sup>n</sup> **NON è Ω(n<sup>2</sup>)**.

* Notazione Θ (theta grande) (limite asintotico stretto)
    - f(n) è Θ(g(n)) se f(n) è O(g(n)) e f(n) è Ω(g(n)).
       >f(n) è Θ( g(n) ) quando f e g hanno lo stesso ordine di complessità
       - Risultati:
          - f(n) è O(g(n)) se e solo se g(n) è Ω(f(n));
          - se f(n) è Θ(g(n)) allora g(n) è Θ (f(n));
          -  Per Ω e Θ valgono le regole dei fattori costanti, del prodotto e della somma;
          -  un polinomio di grado m è Θ (nm);
          - O, Ω e Θ sono relazioni transitive;

---
## | Complessità dei Programmi Iterativi

### Variabili e Complessità Associata

| Tipo        | Descrizione                                  | Classe di Complessità  |
|-------------|----------------------------------------------|------------------------|
| **C**       | Costo - Complessità                          | O(1), O(n), O(n²), ecc.|
| **V**       | Costante                                     | O(1)                   |
| **I**       | Variabile                                    | O(1)                   |
| **E**       | Espressione (Combinazione di variabili, costanti, operazioni) | O(1), O(n), ecc.      |
| **g(n)**    | Numero di iterazioni (funzione di complessità) |                        |

## Regole di Complessità

1. **C [ V ] = C [ I ] = O(1)**  
   La complessità di una costante (V) o di una variabile (I) è costante, ovvero **O(1)**.

2. **C [ E1 op E2 ] = C [ E1 ] + C [ E2 ]**  
   La complessità di un'operazione tra due espressioni (ad esempio, `E1 + E2`) è la somma delle complessità di ciascuna delle espressioni.

3. **C [ I[E] ] = C [ E ]**  
   La complessità di un accesso a un elemento di un array o lista (`I[E]`) è pari alla complessità dell'espressione che fornisce l'indice (`E`).

4. **C [ I=E; ] = C [ E ]**  
   La complessità di un'operazione di assegnazione (`I = E`) è determinata dalla complessità dell'espressione `E`.

5. **C [ I[E1] = E2; ] = C [ E1 ] + C [ E2 ]**  
   La complessità di un'assegnazione a un elemento di un array o lista (`I[E1] = E2`) è la somma delle complessità per calcolare l'indice `E1` e assegnare il valore `E2`.

6. **C [ return E; ] = C [ E ]**  
   La complessità di un'istruzione di ritorno (`return E;`) è la stessa della complessità dell'espressione `E`.

7. **C [ if ( E ) C ] = C [ E ] + C [ C ]**  
   La complessità di una condizione `if` che esegue il comando `C` se la condizione `E` è vera è la somma della complessità della condizione `E` e del comando `C`.

8. **C [ if ( E ) C1 else C2 ] = C [ E ] + C [ C1 ] + C [ C2 ]**  
   La complessità di una condizione `if-else` è la somma della complessità della condizione `E` e delle complessità dei due comandi `C1` e `C2`.

9. **C [ for ( E1; E2; E3 ) C ] = C [ E1 ] + C [ E2 ] + ( C [ C ] + C [ E2 ] + C [ E3 ] ) O( g(n))**  
   La complessità di un ciclo `for` che esegue il comando `C` e ha le espressioni `E1`, `E2`, e `E3` come condizioni di inizializzazione, continuazione e aggiornamento, è la somma delle complessità di `E1`, `E2`, `E3` e delle iterazioni del ciclo stesso, che sono rappresentate come **O(g(n))**, dove `g(n)` è una funzione che rappresenta il numero di iterazioni.

10. **C [ while (E) C ] = C [ E ] + ( C [ C ] + C [ E ] ) O( g(n))**  
    La complessità di un ciclo `while` che esegue il comando `C` finché la condizione `E` è vera è la somma della complessità della condizione `E` e delle iterazioni del ciclo, anch'esse rappresentate come **O(g(n))**.

11. **C [ { C1 … Cn } ] = C [ C1 ] + … + C [ Cn ]**  
    La complessità di un blocco di codice che contiene più comandi (`C1` … `Cn`) è la somma delle complessità di ciascun comando.

12. **C [ F ( E1, .. En ) ] = C [ E1 ] + … + C [ En ] + C [ { C … C } ]**  
    La complessità di una chiamata a funzione `F(E1, ..., En)` è la somma delle complessità delle espressioni di input `E1` … `En`, più la complessità del corpo della funzione.


>N.B. - **g(n)** rappresenta il numero di iterazioni di un ciclo, che può variare in base alla logica del ciclo stesso. Ad esempio, un ciclo `for` che iteri da 1 a `n` avrà una complessità **O(n)**.
>> La complessità complessiva di un programma dipende dal tipo di costrutti utilizzati e dal numero di iterazioni di ciascun ciclo. È importante considerare come ogni operazione si combina con le altre per determinare la complessità totale.

---

## | SelectionSort


Selection Sort è un algoritmo di ordinamento che funziona selezionando ripetutamente l'elemento minimo (o massimo) dall'array non ordinato e spostandolo nella posizione corretta. Ecco una descrizione dettagliata dell'algoritmo:

### Descrizione dell'Algoritmo:

1. **Inizializzazione**: Seleziona il primo elemento dell'array come il minimo.
2. **Scansione**: Scansiona l'array per trovare l'elemento minimo. Se si trova un elemento più piccolo del minimo corrente, aggiorna il minimo. Continua fino alla fine dell'array.
3. **Scambio**: Una volta trovato l'elemento minimo, scambialo con il primo elemento dell'array non ordinato. Questo posiziona l'elemento minimo nella sua posizione corretta.
4. **Ripetizione**: Ripeti i passaggi 1-3 per il resto dell'array, escludendo l'elemento già ordinato. Continua fino a quando l'intero array è ordinato.

```cpp
void exchange( int& x, int& y) {
    int temp = x; // O(1)
    x = y; // O(1)
    y = temp; // O(1)
}

void selectionSort(int A[ ], int n) {
    for (int i=0; i< n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (A[j] < A[min]) min = j;
        }
        exchange(A[i], A[min]);
    }
}
```
Valutiamo quanto è "costoso" questo algoritmo (spoiler: _O(n<sup>2</sup>)_):

1. Nella funzione exchange abbiamo tre operazioni di assegnamento, quindi il costo è _O(1)_.
2. Nella funzione selectionSort sono presenti 2 for annidati, quindi il costo è O(n)*O(n) = _O(n<sup>2</sup>)_.

--- 
## | BubbleSort


BubbleSort è un altro algoritmo di ordinamento semplice e intuitivo. Funziona scambiando ripetutamente gli elementi adiacenti se sono nell'ordine sbagliato. Questo processo viene ripetuto fino a quando l'array è completamente ordinato. Il termine "bubble" ("bolla") è utilizzato per descrivere come gli elementi più grandi (o più piccoli, a seconda della versione dell'algoritmo) "risalgano" o "galleggiano" lentamente verso la fine dell'array (o all'inizio, a seconda di come viene implementato l'ordinamento).

```cpp
void exchange( int& x, int& y) {
    int temp = x; // O(1)
    x = y; // O(1)
    y = temp; // O(1)
}

void bubbleSort(int A[], int n) {
    for (int i=0; i < n-1; i++){ // O(n)
        for (int j=n-1; j >= i+1; j--){ // O(n)
            if (A[j] < A[j-1]) exchange(A[j], A[j-1]); // O(1) 
        }
    }
} 
```
Il bubble sort ha costo _O(n<sup>2</sup>)_ perché ha due cicli for annidati.
Questo perché (stessa cosa per il _selectionSort_):
1. Ciclo esterno: Il ciclo esterno (for) esegue 𝑛 − 1 iterazioni (dove  𝑛 n è la lunghezza dell'array).
2. Ciclo interno: Il ciclo interno (anch'esso un for) esegue 𝑛 − 𝑖 − 1 iterazioni per ogni passaggio del ciclo esterno.

### Algoritmi di ordinamento e limiti asintotici
* Possiamo applicare I limiti asintotici sia al **costo** di un algoritmo sia alla **complessità** di un problema
* Limite asintotico superiore e complessitá di un problema.
  - e.g.: bubblesort e selection sort
  - e.g.: algoritmi O(n log n)
  - possiamo fare meglio?
* Limiti asintotici inferiori per ordinamenti basati su confronto
  - limite inferiore intuitivo
  - limite inferiore ’’piú stretto’’

#### Esempi:

1. ```c++
    int f(int x) {
    return x; // Risultato: O(n) - Complessità O(1)
    }
   ```
2. ```cpp
    int h(int x) {
    return x * x; // Risultato: O(n^2) - Complessità O(1)
    }
   ```
3. ```cpp
    int k(int x) {
    int a = 0;
    for (int i = 1; i <= x; i++) // Risultato: O(n) - Complessità O(n)
        a++;
    return a;
    }
   ```
4. ```cpp 
    void g (int n){ // n>=0
        for (int i=1; i<= f(n); i++){ // Complessità O(n)
            cout << f(n);}
    }
    ```
5. ```cpp
    void g (int n){
    for (int i=1; i<= h(n); i++) // Complessità O(n^2)
        cout << h(n);
    }
   ```
6. ```cpp
    void g (int n){
    for (int i=1; i<= k(n); i++) // Complessità O(n^2)
    cout << k(n);
    }
   ```
7. ```cpp
    void p(int n) {
        int b = f(n);
        for (int i = 1; i <= b; i++) // Complessità: O(n)
            cout << b;
    }
    ```

8. ```cpp
    void p(int n) {
        int b = h(n);
        for (int i = 1; i <= b; i++) // Complessità: O(n) - 
            cout << b;
    }
    
    ```

9. ```cpp
    void p(int n) {
        int b = k(n);
        for (int i = 1; i <= b; i++)
            cout << b;
    }
    // Complessità: O(n^2) - Correto
    ```

#### Esempio Ricerca lineare e div2

```cpp
int linearSearch(int A [], int n, int x) {
    int b=0; // O(1)
    for (int i=0; !b & (i<n); i++){ // O(n)
        if (A[ i ] == x) b=1; // O(1)
    }
    return b; // O(1)

    // Complessità totale: O(n)
}
```
```cpp
int div2(int n) {
    int i=0; // O(1)
    while (n > 1) { // O(log n) --> caso peggiore
        n=n/2; // O(1)
        i++; // O(1)
    }
    return i; // O(1)
}
```
Per concludere...

> La ricerca lineare è un algoritmo semplice ma inefficiente per array non ordinati, con una complessità lineare.

> La divisione per 2 è un algoritmo efficiente con una complessità logaritmica, utile per problemi che coinvolgono la divisione ripetuta di un valore.
