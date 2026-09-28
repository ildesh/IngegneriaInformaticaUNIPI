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

> I vertici sono insostituibili (non eliminabili in Weyl). I poliedri senza vertici sono tutti e soli quelli contenenti rette.

4. **Relazione tra 8 e 4:** L'ottimo **NON** è sempre nei vertici.
5. **Relazione tra 5 e 8:** Sempre vera.
**Note di topologia:**
*   **Chiuso $\neq$ Limitato:** *Chiuso* significa che contiene la frontiera; *Limitato* significa che lo puoi racchiudere.
*   L'ottimo di un problema di PL è sulla frontiera? **Sì, se $\exists$ l'ottimo!**

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
Se io dovessi inseri