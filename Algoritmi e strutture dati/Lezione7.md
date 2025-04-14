<h1> Lezione 5 - 12-03-2025 18-03-2025 </h1>

## 📚 Indice

1. [Limiti inferiori](#limiti-inferiori)  
   1.1 [Alberi di decisione](#alberi-di-decisione)  
2. [Ordinamenti con complessità minore di O(nlogn)](#ordinamenti-con-complessit%C3%A0-minore-di-onlogn)  
   2.1 [Counting Sort](#counting-sort---definizione)  
   2.1.1 [Esempio](#esempio)  
   2.1.2 [Algoritmo](#counting-sort---algoritmo)  
   2.2 [Radix Sort](#radix-sort---definizione)  
   2.2.1 [Esempio](#esempio-1)  
   2.2.2 [Algoritmo](#radix-sort---algoritmo)

---

# Limiti inferiori

## Alberi di decisione

> [!NOTE]
> ### Definizione
> Un albero di decisione è un albero binario in cui ogni nodo interno rappresenta una domanda e ogni foglia rappresenta una risposta / soluzione. La profondità dell'albero rappresenta il numero di domande necessarie per arrivare alla risposta.
> Ogni cammino dalla radice ad una foglia rappresenta una esecuzione dell'algoritmo (sequenza di confronti) per giungere alla soluzione relativa a quella foglia.

Ogni algoritmo che risolve un problema che ha s soluzioni ha un albero di decisione corrispondete con almeno s foglie.

Fra tutti gli alberi di decisione per un particolare problema con s soluziooni:

- L'albero di decisioone che minimizza la **_lunghezza massima_** dei percorsi fornisce un **_limite inferiore_** al numero di confronti che un algorimo che risolve il problema deve fare nel **_caso peggiore_**. 
- L'albero di decisione che minimizza la **_lunghezza media_** dei percorsi fornisce un **_limite inferiore_** al numero di confronti che un algoritmo che risolve il problema deve fare nel **_caso medio_**.

>[!TIP]
>#### Considerazioni
> 1. Un albero binario con **_k livelli_** **_ha al massimo 2<sup>k</sup>_** foglie (quando è bilanciato).
> 2. Un albero binario con**_ s foglie_** **_ha almeno log<sub>2</sub>s_** livelli (quando è sbilanciato).
> 3. Gli **_alberi binari bilanciati_** minimizzano sia il caso peggiore che quello medio: hanno **_logs(n)_** livelli.

## Ordinamenti con complessità minore di O(nlogn)

- Counting sort
- Radix sort

### Counting sort - Definizione

> [!NOTE]
> - Il counting sort ordina una sequenza di interi compresi in un intervallo [0, k] in O(n + k) tempo e O(k) spazio. 
>   - Si può usare quando si conoscono i valori minimo e massimo degli elementi da ordinare.
>   - Per ogni valore presente nell'array, si contano gli elementi con quel valore utilizzando un array ausiliario avente come dimensione **_l'intervallo dei valori_**
>   - Successivamente si ordinano i valori tenendo conto dell'array ausiliario.

#### Esempio:

- L’array originale è: `[4, 2, 2, 8, 3, 3, 1]`
- L’intervallo specificato è `[0, 8]`, quindi l’array ausiliario (di conteggio) ha lunghezza `9`
- Si contano le occorrenze di ogni valore
- Si usano queste frequenze per costruire l’array ordinato


**1. Array originale**:  
`[4, 2, 2, 8, 3, 3, 1]`

**2. Inizializzazione array ausiliario (contatore)**:  
`count = [0, 0, 0, 0, 0, 0, 0, 0, 0]` (lunghezza = 9)

**3. Conteggio delle occorrenze**:
- `4` → `count[4] += 1`
- `2` → `count[2] += 1` (x2)
- `8` → `count[8] += 1`
- `3` → `count[3] += 1` (x2)
- `1` → `count[1] += 1`

**4. Resulting count**:  
`count = [0, 1, 2, 2, 1, 0, 0, 0, 1]`

**5. Costruzione dell’array ordinato** (riempiamo l’output array):
- Aggiungi `1` una volta
- Aggiungi `2` due volte
- Aggiungi `3` due volte
- Aggiungi `4` una volta
- Aggiungi `8` una volta

**6. Array ordinato risultante**:  
`[1, 2, 2, 3, 3, 4, 8]`

---

#### Counting sort - Algoritmo

```cpp
void counting_sort(int A[], int k, int n){ // valori distinti fino a k, C array ausiliario
    int i,j; int C[k+1]; // array ausiliario di conteggio
    for(i=0; i<=k; i++) C[i] = 0; // inizializza l'array di conteggio
    for(j=0; j<n; j++) C[A[j]]++; // conta le occorrenze di ogni valore
    j = 0;
    for(i=0; i<=k; i++){
        while(C[i] > 0){
            A[j] = i; // riempi l'array ordinato
            C[i]--;
            j++;
        }
    }
}
```

- Il costo di questo algoritmo è O(n + k) in tempo e O(k) in spazio, dove n è il numero di elementi da ordinare e k è l'intervallo dei valori.

>[!WARNING]
> 1. Non basato su confronti.
> 2. Complessità O(n + k) - (nel caso sopra citato O(n + 8)).
> 3. Conveniente quando k è O(n).
> 4. Necessaria memoria ausiliaria.

--- 

### Radix sort - Definizione

> [!NOTE]
> Il radix sort è un algoritmo di ordinamento che ordina i numeri interi in O(d(n + k)) tempo, dove d è il numero di cifre dei numeri da ordinare e k è l'intervallo dei valori delle cifre (0-9 per i numeri decimali).
>
>Si eseguono d passate ripartendo, in base alla d-esima cifra, i numeri in j contenitori, dove k sono i possibili valori di una cifra, e rileggendo il risutlato con un determinato ordine.

#### Esempio:

Numeri da ordinare (d=3, k=10): 190, 051, 054, 207, 088, 010


##### **1° Passata – Cifra delle unità (`d=1`)**

Ordiniamo in base alla cifra più a **destra** (unità):

| Numero | Cifra unità |
|--------|--------------|
| 190    | 0            |
| 051    | 1            |
| 054    | 4            |
| 207    | 7            |
| 088    | 8            |
| 010    | 0            |

Ordinando in modo **stabile** per la cifra delle unità:

→ **[190, 010, 051, 054, 207, 088]**

📌 Dopo questa passata, i numeri sono ordinati in base alla cifra delle unità, ma l’ordine relativo degli altri valori resta invariato.

---

##### **2° Passata – Cifra delle decine (`d=2`)**

Ora ordiniamo per la **seconda cifra da destra**, cioè le decine:

| Numero | Cifra decine |
|--------|--------------|
| 190    | 9            |
| 010    | 1            |
| 051    | 5            |
| 054    | 5            |
| 207    | 0            |
| 088    | 8            |

Ordinando stabilmente:

→ **[207, 010, 051, 054, 088, 190]**

📌 Ora i numeri sono ordinati rispetto alle decine, mantenendo il precedente ordinamento delle unità tra numeri con la stessa cifra decine.

---

##### **3° Passata – Cifra delle centinaia (`d=3`)**

Ora ordiniamo per la **cifra più a sinistra**, cioè le centinaia:

| Numero | Cifra centinaia |
|--------|------------------|
| 207    | 2                |
| 010    | 0                |
| 051    | 0                |
| 054    | 0                |
| 088    | 0                |
| 190    | 1                |

Ordinando stabilmente:

→ **[010, 051, 054, 088, 190, 207]**

📌 Dopo l'ultima passata, i numeri sono completamente ordinati in base alle centinaia, e l’ordine tra numeri con la stessa cifra centinaia segue quanto ottenuto nelle passate precedenti.

✅ **Risultato finale ordinato**:
**[010, 051, 054, 088, 190, 207]**

---

#### Radix sort - Algoritmo

Creiamo due funzioni:

1. `bucketSort`
2. `radixSort`

```cpp
#include <vector>
#include <cmath>
using namespace std;

void bucketSort(int A[], int n, int b, int t) {
    vector<int> Y[b];  // Array di b bucket, ognuno è una lista

    // Inserisci ogni elemento nel bucket corretto in base alla cifra t-esima
    for (int i = 0; i < n; i++) {
        int cifra = (A[i] / (int)pow(b, t)) % b;
        Y[cifra].push_back(A[i]);
    }

    // Ricopia ordinatamente i valori da Y[] in A[]
    int index = 0;
    for (int i = 0; i < b; i++) {
        for (int x : Y[i]) {
            A[index++] = x;
        }
    }
}

void radixSort(int A[], int n, int t) {
    for (int i = 0; i < t; i++) {
        bucketSort(A, n, 10, i);
    }
}
```

- La complessità temporale di questo algoritmo è O(d(n + k)), dove d è il numero di cifre dei numeri da ordinare e k è l'intervallo dei valori delle cifre (0-9 per i numeri decimali).