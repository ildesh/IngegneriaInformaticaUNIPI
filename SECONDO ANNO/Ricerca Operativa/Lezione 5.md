## 1. Teoremi e Fondamenti
1. Teorema di Weyl $\rightarrow$ Un poliedro $P$ può essere descritto come intersezione di semispazi oppure come combinazione convessa di vertici e combinazione conica di direzioni:
$$ P(Ax \le b) \iff \exists V, \exists E \text{ t.c. } P = \text{conv}(V) + \text{cone}(E) $$
$$\text{Ogni formulazione di Weyl ha il suo poliedro e viceversa.}$$
2. Teorema Fondamentale della PL $\rightarrow$ Dato un problema associato a un poliedro, si verificano 3 casistiche per il problema di $\max c^T x$ con $Ax \le b$:
	  2.1 $P = \emptyset$ $\implies$ Ci sono troppi vincoli (ne vanno eliminati);
	  2.2$(P) = +\infty$ $\implies$ Il problema è illimitato.
	  2.3. $\exists \text{ S.O.} \in V$ $\implies$ Esiste una Soluzione Ottima e si trova in un vertice.
3. Caratterizzazione dei vertici $\rightarrow$ *(Argomento non ancora trattato)*

---
## 2. Quadro Pratico e Relazioni
**Elementi del quadro:**
*   **1:** $P$ limitato | **4:** Vertici | **7:** $(P) = +\infty$
*   **2:** $P$ illimitato | **5:** $V$ | **8:** $(P)$ finito
*   **3:** $P$ vuoto | **6:** $\emptyset$ | **9:** Soluzione ottima
**Principali relazioni:**
1. **Relazione tra 1 e 6:** Se 1 è vero $\implies E = \{0,0,0...0\}$
2. **Relazione tra 7 e 6:** Se 7 è vera $\implies E$ ha degli elementi.
3. **Relazione tra 4 e 5:** Quando un poliedro ha vertici $\implies V \neq \emptyset$. L'insieme dei vertici.

>[!note]
>I vertici sono insostituibili (non eliminabili in Weyl). I poliedri senza vertici sono tutti e soli quelli contenenti rette.

4. **Relazione tra 8 e 4:** L'ottimo **NON** è sempre nei vertici.
5. **Relazione tra 5 e 8:** Sempre vera.
**Note di topologia:**
*   **Chiuso $\neq$ Limitato:** *Chiuso* significa che contiene la frontiera; *Limitato* significa che lo puoi racchiudere.
*   L'ottimo di un problema di PL è sulla frontiera? **Sì, se $\exists$ l'ottimo!**
### Poliedri Senza Vertici
Geometricamente, un poliedro non possiede vertici se e solo se **contiene al suo interno almeno una retta intera** (cioè uno spazio affine illimitato in entrambe le direzioni, senza interruzioni).
- **Causa geometrica:** Avviene tipicamente quando mancano i vincoli di non negatività ($x \ge 0$) e le disequazioni non "chiudono" la regione in nessun angolo. Un singolo vincolo come $x_1 + x_2 \le 5$ definisce un semispazio completamente aperto, contenente infinite rette parallele alla sua frontiera e zero vertici.
- **Causa algebrica:** Si verifica se le righe della matrice dei coefficienti $A$ non contengono alcun sottoinsieme linearmente indipendente di cardinalità pari a $n$ (ovvero, il rango della matrice è inferiore al numero delle variabili).
- **Conseguenza teorica:** Per i poliedri privi di vertici, il Teorema di Weyl classico ($P = \text{conv}(V) + \text{cono}(E)$) e il Teorema Fondamentale della PL non possono essere applicati direttamente in quella forma, mancando strutturalmente l'insieme $V$.

---
## 3. Implementazione in MATLAB
MATLAB risolve nativamente problemi di minimizzazione in forma standard:
$$ \min c^T x $$
Soggetti a:
*   $Ax \le b$
*   $A_{eq} x = b_{eq}$
*   $LB \le x \le UB$ *(Lower Bound e Upper Bound)*
### Formula per MATLAB standard
```matlab
% Definizione dei parametri
>> c = [...]
>> A = [...]
>> b = [...]
>> Aeq = [...]
>> beq = [...]
>> LB = [...]
>> UB = [...]

% Funzione di ottimizzazione
>> [x, V] = linprog(c, A, b, Aeq, beq, LB, UB)

>> x % Restituisce la Soluzione Ottima (S.O.)
>> V % Restituisce il Valore Ottimo (v.O.)
```

---
## 4. Esercizi MATLAB

| Materiale          | Prodotto A | Prodotto B | Disponibilità |
| ------------------ | ---------- | ---------- | ------------- |
| Lana               | 2          | 3          | 375           |
| Cotone             | 2          | 1          | 192           |
| Nylon              | 2          | 2          | 283           |
| **Profitto/Costo** | 60         | 70         | -             |
Ora inseriamo i vari elementi su MathLab:

```mathlab
A = [2 3; 2 1; 2 2]; 
b = [375; 192; 283]; 
c = [-60 -70]; 
Aeq = []; 
beq = [] 
LB = [0 0]; 
UB = [];

[x,V] = linprog(c,A,b,Aeq,beq,LB,UB);

Vreale = -V;

disp('soluzione ottima:' )
disp(x);

disp('profitto massimo:' )
disp(Vreale);
```

Le soluzioni che usciranno fuori da questo esercizio sono i seguenti: 
- $x = \begin{bmatrix} 49.5 \\ 82.0 \end{bmatrix}$
- $V = -9410 \implies \text{al contrario } = 9410$

---
## 5. Problemi di Produzione di Minimo
Nei classici problemi di produzione di massimo, l'obiettivo è massimizzare il profitto operando al di sotto di un limite massimo di risorse disponibili (vincoli strutturati come $Ax \le b$). I problemi di minimo invertono questa logica: l'obiettivo è **minimizzare i costi** dovendo però garantire e superare determinate soglie minime di fabbisogno (vincoli strutturati come $Ax \ge b$).
- **Modello Matematico:**
$$\begin{cases} \min \ c^T x \\ Ax \ge b \\ x \ge 0 \end{cases}$$
- **L'esempio classico (Problema della Dieta):** Immagina di dover comporre un pasto nutrizionalmente completo. Le variabili $x$ rappresentano le quantità di vari cibi da acquistare. Il vettore $c$ rappresenta il prezzo di mercato di ciascun cibo (si vuole minimizzare lo scontrino). Il vettore $b$ rappresenta i livelli nutrizionali che il pasto **deve** obbligatoriamente raggiungere (es. almeno 2000 kcal, almeno 50g di proteine, almeno 10mg di ferro). I vincoli $\ge$ costringono il sistema a comprare abbastanza ingredienti per coprire tutte queste soglie di fabbisogno vitale, scegliendo però la combinazione di cibi complessivamente più economica.