# LAB 2 - 17-03-2025

## MergeSort

Il mergeSort è un algoritmo di ordinamento che utilizza il paradigma divide et impera. L'idea principale è di dividere l'array da ordinare in due metà, ordinare ricorsivamente ciascuna metà e poi unire le due metà ordinate per ottenere l'array ordinato finale.

L'algoritmo si divide in tre passaggi:
1. **_Divide_**: Dividi l'array in due metà.
2. **_Conquer_**: Ordina ricorsivamente ciascuna metà.
3. **_Combina_**: Unisci le due metà ordinate per ottenere l'array ordinato finale.


Apriamo il terminale di UNIX, creiamo il file e modifichiamolo tramite NANO:

```bash
# Creiamo il file per mergeSort:
touch mergeSort.cpp

# Creiamo anche una cartella per il laboratorio 2:
mkdir LAB2

# Spostiamo il file nella cartella:
mv mergeSort.cpp LAB2

# Spostiamoci nella cartella:
cd LAB2

# Modifichiamo tramite NANO il file .cpp
nano mergeSort.cpp
```

Si aprirà un interfaccia per modificare il file e noi dovremmo implementare la nostra funzione **`mergeSort`**


```cpp
void combina(int arr[], intstart, int mid, int end){
    int iSx = start, iDx = mid;
    int * tempResult = new int[end-start+1];
    int vector_index = 0;
    while(1){
        if(arr[iSx] < arr[iDx]){
        tempResult[vector_index++] = arr[iSx++];
        if(iSx == mid) 
            break;
        }else{
        tempResult[vector_index++] = arr[iDx++];
        if(iDx == end + 1) 
            break;
        }
    }
    while(iSx < mid){
        tempResult[vector_index++] = arr[iSx++];
    }
    while(iDx <= end){
        tempResult[vector_index++] = arr[iDx++];
    }
    for(int i = 0; i <= end; i++){
        arr[i+start] = tempResult[i];
    }
    for(int i = 0; i <= end; i++){
        cout<<arr[i]<<endl;
    }
}

/* ---------------------------------------------------- */

void mergeSort(int* arr, int start, int end)
{
    int mid;
    if(start<end){
        mid = (start + end)/2; // Passaggio DIVIDE
        mergeSort(arr, start , mid); // Passaggio CONQUER
        mergeSort(arr, mid , end); // Passaggio CONQUER;
        combina(arr, start, mid+1, end); // Passaggio COMBINA;
    }
}
```

La complessità di questo algoritmo è *`O(log(n))`* 

---

## Lettura Input

Partiamo con il seguente esercizio:

>[!TIP] Esercizio
>Crea due file input.txt contentente:
>```txt
>5
>10
>9
>15
>2
>12
>```
>e un file output.txt:
>```
>48
>32400
>2 9 10 12 15
>```
>Dobbiamo vedere se esistono differenze tra l'output che andremo a compilare e l'output già costruito.

```bash
# Creiamo i due file .txt:
touch input.txt
touch output.txt

# ---------------------------------- #

# Inserire i valori tramite NANO nei vari .txt:
nano input.txt
# Scrivi qualcosa...
5
10
9
15
2
12
CTRL + O            # Salva il file
CTRL + X            # Esci da nano

## e...

nano input.txt
# Scrivi qualcosa...
48
32400
2 9 10 12 15
CTRL + O            # Salva il file
CTRL + X            # Esci da nano

# ---------------------------------- #

# Creiamo il nostro file .cpp di nome letturaInput.cpp e lo spostiamo nella cartella LAB2

touch letturaInput.cpp
mv letturaInput.cpp LAB2
cd LAB2
```

```cpp
// Versione senza VECTOR
int * leggiInput( ){
    int len;
    cin >> len;
    int * arr = new int[len];
    for( int i = 0 ; i < len ; ++i )
        cin >> arr[i];
    return arr;
}

// Versione con VECTOR

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
 
void leggiInput( vector<int> &arr ){
	int len;
	cin >> len;
	int val;
	for( int i = 0 ; i < len ; ++i ){
		cin >> val;
		arr.push_back(val);
	}
	return;
}
 
 
int main(){
	vector<int> vettore;
	leggiInput(vettore);
	int somma = 0;
	int prodotto = 1;
	sort(vettore.begin(),vettore.end());
	for (int val : vettore) {
		somma += val;
		prodotto *= val;
    	}
	cout << somma << endl;
	cout << prodotto << endl;
	for (int val : vettore){
		cout << val << " ";
	}
	cout << endl;

    return 0;
}
```

Alla fine dovremmo digitare il seguente comando sul prompt dei comandi linux

```bash
./eseguibile < input.txt | diff - output.txt
```

e dovrebbe mostrare le differenze (che alla fine non ci saranno e quindi non apparirà nulla).

Adesso però parliamo della classe `vector`:


>[!IMPORTANT]
>La classe `vector` è una delle più potenti e flessibili di C++. Può sostituire gli array tradizionali con molte funzionalità aggiuntive come ridimensionamento automatico, metodi per l'ordinamento e ricerca, iteratori e molto altro.

| Funzione         | Descrizione |
|-----------------|-------------------------------------------------------------|
| `push_back(val)` | Aggiunge `val` alla fine del `vector`. |
| `pop_back()`    | Rimuove l'ultimo elemento del `vector`. |
| `insert(pos, val)` | Inserisce `val` in una posizione specifica (iteratore). |
| `erase(pos)`    | Rimuove l'elemento in una posizione specifica (iteratore). |
| `clear()`       | Rimuove tutti gli elementi dal `vector`. |
| `resize(n)`     | Cambia la dimensione del `vector` a `n`. Se `n` è maggiore, riempie gli spazi con valori di default. |


