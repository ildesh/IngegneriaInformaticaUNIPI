<h1> Lezione 8 - 07-05-2025 </h1>

## 📚 Indice



---


# Problemi difficili: cenni alla NP-completezza

La NP-completezza è un concetto fondamentale nella teoria della complessità computazionale. Si riferisce a una classe di problemi che sono difficili da risolvere, ma facili da verificare una volta che hai una soluzione proposta.

>[!NOTE]
>## Cosa significa NP?
>**_NP_** sta per nondeterministic polynomial time. Sono quei problemi per cui, se qualcuno ti dà una soluzione, tu puoi verificarla in tempo polinomiale (ossia relativamente veloce, in termini di dimensione dell’input).

I tre problemi difficili più conosciuti sono:

- [Problemi difficili: cenni alla NP-completezza](#problemi-difficili-cenni-alla-np-completezza)
    - [Problema dello zaino](#problema-dello-zaino)
    - [Problema del commesso viaggiatore:](#problema-del-commesso-viaggiatore)
    - [Ciclo Hamiltoniano](#ciclo-hamiltoniano)
    - [Problema della soddisfacibilità booleana](#problema-della-soddisfacibilità-booleana)
  - [Teoria della NP-completezza](#teoria-della-np-completezza)
    - [Algoritmi nondeterministici](#algoritmi-nondeterministici)
      - [Algoritmo non deterministico per la soddisfattibilità](#algoritmo-non-deterministico-per-la-soddisfattibilità)
      - [Algoritmo non deterministico di ordinamento](#algoritmo-non-deterministico-di-ordinamento)
  - [Relazione fra deterministico e nondeterminismo](#relazione-fra-deterministico-e-nondeterminismo)
    - [P e NP](#p-e-np)
    - [Caratterizzazione alternativa della classe NP:](#caratterizzazione-alternativa-della-classe-np)
  - [Riducibilità](#riducibilità)

---

### Problema dello zaino

Situazione: Hai uno zaino che può sopportare un peso massimo (capacità).

Input: Una serie di oggetti, ognuno con un peso e un valore.

Obiettivo: Selezionare un sottoinsieme di oggetti da mettere nello zaino in modo da massimizzare il valore totale, senza superare il peso massimo.

Esempio semplice:
Zaino può reggere 10 kg.

Hai:

Oggetto A: 3 kg, valore 40€

Oggetto B: 4 kg, valore 50€

Oggetto C: 5 kg, valore 60€

Quale combinazione massimizza il valore senza sforare 10 kg?

Perché è difficile:
Devi provare tantissime combinazioni diverse (crescita esponenziale). La versione decisionale (esiste una combinazione di valore almeno X?) è NP-completa.

---

### Problema del commesso viaggiatore:

ituazione: Un venditore deve visitare una serie di città e tornare alla città di partenza.

Input: Una mappa con distanze tra ogni coppia di città.

Obiettivo: Trovare il percorso più corto che passa per ogni città una volta sola e torna all’inizio.

Esempio semplice:
Città: A, B, C, D.

Devi trovare il giro più breve tipo: A → B → C → D → A.

Perché è difficile:
Quando le città diventano tante, il numero di percorsi possibili esplode (n! percorsi). Il TSP è un problema NP-difficile (più precisamente, la versione decisionale esiste un giro più corto di X? è NP-completa).


---

### Ciclo Hamiltoniano

Situazione: Hai un grafo (rete di nodi collegati da archi).

Obiettivo: Trovare un ciclo che passa per ogni nodo una e una sola volta e torna al punto di partenza.

Esempio semplice:
Nodo A collegato a B e C, B collegato a C e D... e così via.

La domanda: esiste un giro che tocca ogni nodo una volta sola e torna al punto di partenza? (tipo A → B → C → D → A)

Legame con TSP:
È una versione semplificata del TSP:

Hamiltoniano: Conta solo se il ciclo esiste.

TSP: Cerca il ciclo più corto.

Perché è difficile:
Anche questo è NP-completo. Verificare un ciclo è facile, trovarlo no.


---

Esistono anche altri tipo di problemi come:

1. Problema del ciclo Euleriano
   1. (con esempio) Ponti di Konigsberg
2. Problema della soddisfacibilità booleana (SAT)

---

### Problema della soddisfacibilità booleana 

>[!IMPORTANT]
> Data una formula F  con n variabili, trovare, se esiste una combinazioni di valore booleani che, assegnati alle variabili di F, la rendono vera.
>
> La SAT corrisponde a dire "Soddisfattibilità di una formula nella logica dei predicati"

Per risolvere tutti questi problemi difficili bisogna andare a tentativi, ovvero cercare tutte le possibili combinazioni. Se si prova a risolvere un esercizio e non si riesce a trovare un algoritmo in grado di svolgerlo allora bisogna ricorrere al brute forcing.

---

## Teoria della NP-completezza

-  Classifica un insieme di problemi dificili
-  Si applica a problemi decisionali: con risposta SI o NO

- Ogni problmea può essere riformulato come problema decisionale
- Il problema decisionale ha complessitò minore o uguale al problema non decisionale corrispondente.
- Quindi se il problema decisionale è difficile, a maggior ragione lo sarà il corrispondente non decisionale.


Per i vari problemi:
- Commesso viaggiatore: dato un intero k, esiste nel grafo un ciclo
senza ripetizione di nodi di lunghezza minore di k?
- Zaino: dato un valore v, esiste un riempimento dello zaino con
valore maggiore o uguale a v?
- Ciclo Hamiltoniano: dato un grafo, esiste un ciclo Hamiltoniano?
- Ciclo Euleriano: dato un grafo, esiste un ciclo Euleriano?
- Formula logica: data una formula, esiste un assegnamento alle
variabili che rende vera la formula?

---

### Algoritmi nondeterministici

SI aggiunge il comando (`choice(I)`) dove I è un insieme e quest'ultimo sceglie arbitrariamente un elemento dell'insieme I.

#### Algoritmo non deterministico per la soddisfattibilità

```cpp
int nsat(Formula f,int *a,int n) {
    for (int i=0; i < n; i++) a[i]=choice({0,1});
    if (value(f,a)) return 1;
    else return 0;
}

// restituisce 1 se esiste almeno una scelta con risultato 1 ma la complessità è O(n).
```

#### Algoritmo non deterministico di ordinamento

```cpp
    int nsort(int* a, int n) {
        int b [n];
        for (int i=0; i<n; i++)
            b[i]=a[i];
        for (int i=0; i<n; i++)
            a[i]=b[choice({0..n-1})];
        if (ordinato(a)) return 1;
        return 0;
}
```

---

## Relazione fra deterministico e nondeterminismo

- Per ogni algoritmo nondeterministico ne esiste
uno deterministico che lo simula, esplorando lo
spazio delle soluzioni, fino a trovare un successo.

- Se le soluzioni sono in numero esponenziale,
l'algoritmo deterministico avrà complessità
esponenziale.

### P e NP
1- P = insieme di tutti i problemi decisionali risolubili in tempo Polinomiale con un algoritmo  ( problemi decisionali facili da risolvere)
2. NP = insieme di tutti i problemi decisionali risolubili in tempo Polinomiale con un algoritmo Nondeterministico (problemi decisionali facili da verificare)
   1. NP : Nondeterministico Polinomiale

---

### Caratterizzazione alternativa della classe NP:


- NP = insieme di tutti i problemi decisionali che
ammettono un algoritmo deterministico polinomiale
di verifica di una soluzione (certificato).

Per dimostrare che un problema R appartiene a NP si
dimostra che la verifica di una soluzione di R è fatta in tempo polinomiale.

---

Il problema che non verrà mai risolto è P = NP:

- Uno dei 7 problemi del millennio (Clay Mathematical Institute, 2000) Un milione di dollari per chi lo risolve (in un senso o nell’altro)

---

## Riducibilità

La riducibilità è un metodo per convertire l'istanza di un problema P1 in un'istanza di un problema P2 e utilizzare la soluzione di quest'ultimo per ottenere la soluzione di P1.

Un problema P1 si riduce in tempo polinomiale a un problema P2 se ogni soluzione di P1 può ottenersi deterministicamente in tempo polinomiale da una soluzione di P2

INPUT di P1 --(completamento polinomiale)--> INPUT DI P2 

(Dall'input di P2 a soluzione di P2)

SOLUZIONE di P1 --(completamento polinomiale)--> SOLUZIONE DI P2 

La conclusione sarà P1 <= P2