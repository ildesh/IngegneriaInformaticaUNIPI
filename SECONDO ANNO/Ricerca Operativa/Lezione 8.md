#### 1. Il Problema Duale

Ogni problema di Programmazione Lineare (PL) è intimamente legato a un secondo problema, costruito a partire dagli stessi identici dati ($A, b, c$), ma osservati da una prospettiva opposta.
Consideriamo il **Problema Primale (P)** in forma canonica di massimizzazione:

$$(P) \begin{cases} \max c^T x \\ Ax \le b \\ x \ge 0 \end{cases}$$

Dove $x \in \mathbb{R}^n$ sono le nostre variabili decisionali, $A$ è la matrice dei vincoli $m \times n$, $b \in \mathbb{R}^m$ è il vettore delle risorse e $c \in \mathbb{R}^n$ i costi/profitti.
Il **Problema Duale (D)** associato si costruisce scambiando righe con colonne, costi con risorse, e massimizzazione con minimizzazione:

$$(D) \begin{cases} \min b^T y \\ A^T y \ge c \\ y \ge 0 \end{cases}$$

Dove $y \in \mathbb{R}^m$ sono le variabili duali (una per ogni vincolo del primale!). I prezzi ombra che abbiamo calcolato nella scorsa lezione usando $y_B = (A_B^T)^{-1} c_B$ sono esattamente la soluzione di questo problema.
#### 2. Il Duale del Duale
Una domanda legittima è: cosa succede se calcoliamo il duale del problema duale?

> [!important] Proprietà Involutiva
> 
> **Il duale del duale è esattamente il problema primale.**

**Dimostrazione rapida:** Prendiamo il Duale $(D): \min b^T y$ con $A^T y \ge c$. Possiamo trasformarlo in un problema di massimo invertendo il segno: $\max -b^T y$ con $-A^T y \le -c$. Se applichiamo di nuovo le regole di dualità (trasponendo la matrice $-A^T$ che torna $-A$, scambiando costi e termini noti), otteniamo $\min -c^T x$ con $-A x \ge -b$. Moltiplicando tutto per $-1$, ritorniamo magicamente a: $\max c^T x$ con $Ax \le b$.

---
#### 3. Il Teorema della Dualità Forte (e Debole)
Questa è la colonna portante della Ricerca Operativa. Il rapporto tra Primale e Duale è governato da due teoremi.
- **Dualità Debole:** Per ogni soluzione ammissibile $x$ del Primale e per ogni soluzione ammissibile $y$ del Duale, vale sempre:
$$c^T x \le b^T y$$
	_Significato:_ In un problema di massimizzazione, qualsiasi soluzione del duale fornisce un "tetto" (un limite superiore) al nostro profitto.
- **Teorema della Dualità Forte:** Se il problema Primale $(P)$ ammette una Soluzione Ottima finita $x^*$, allora anche il problema Duale $(D)$ ammette una Soluzione Ottima finita $y^*$, e i loro valori ottimi coincidono perfettamente:
- $$c^T x^* = b^T y^*$$
    _Significato pratico:_ Se siete un'azienda che massimizza il profitto $(c^T x)$ e un compratore vuole acquisire le vostre risorse minimizzando il prezzo di acquisto $(b^T y)$, il punto di accordo perfetto è l'ottimo per entrambi.
---
#### 4. Soluzioni di Base Complementari (Scarti Complementari)
Come si legano i vertici (le soluzioni di base) dei due poliedri? Si legano tramite il **Teorema degli Scarti Complementari**, che abbiamo già intravisto parlando dell'algoritmo del simplesso.
Se $x^*$ e $y^*$ sono soluzioni ottime per i rispettivi problemi, allora deve valere:
1. $y_i^* (b_i - A_i x^*) = 0 \quad \forall i$ (Se un vincolo primale _non_ è attivo, la sua variabile duale associata deve essere zero).
2. $x_j^* (A_j^T y^* - c_j) = 0 \quad \forall j$ (Se un vincolo duale _non_ è attivo, la sua variabile primale associata deve essere zero).
Le variabili primali e duali si dicono **complementari**: dove una è positiva, l'altra "scarto" (o vincolo associato) deve essere strettamente a zero.
---
#### 5. Il Test di Ottimalità per i Vertici Primali

Grazie alla dualità, non abbiamo più bisogno di esplorare "alla cieca" tutti i vertici del Simplesso. Possiamo usare il duale per il **Test di Ottimalità**.

Siamo su un vertice primale $\bar{x} = (x_B, x_N)$ con base $B$. Questo vertice è ammissibile ($x_B = A_B^{-1}b \ge 0$). È anche l'ottimo assoluto?**Procedura del Test:*
1. Calcoliamo le variabili duali associate a questa base: $y_B = (A_B^T)^{-1} c_B$.
2. Calcoliamo i Costi Ridotti per le variabili non di base $N$: $\bar{c}_N = c_N - A_N^T y_B$.
3. **Esito:** Se $\bar{c}_N \le 0$ per tutte le variabili non di base, allora non esiste alcuna direzione di miglioramento ($C^T W^i \le 0$). Il vertice primale in cui ci troviamo è l'**OTTIMO**.
---
#### 6. Test di Ottimalità per i Vertici Duali

Simmetricamente, se stiamo risolvendo il problema partendo dal Duale (ad esempio applicando il Simplesso Duale, utile per analisi di sensitività), il test si inverte.
Siamo su un vertice duale $\bar{y}$ definito dalla base $B$. È la soluzione ottima duale?**Procedura del Test:**
1. Garantiamo che il vertice duale sia ammissibile (cioè che rispetti $A^T y \ge c$, il che equivale a dire che i costi ridotti primali sono di segno corretto).
2. Calcoliamo i valori delle variabili primali associate alla base: $x_B = A_B^{-1} b$.
3. **Esito:** Se $x_B \ge 0$ (ovvero, se il vertice primale "ombra" non viola la non negatività), allora il vertice duale è l'**OTTIMO**.
---
#### 7. Esercizio Pratico Completo
Applichiamo la teoria a un caso concreto.
**Problema Primale (P):**

$$\max z = 3x_1 + 2x_2$$
Soggetto a:
$$\begin{cases} x_1 + x_2 \le 4 \quad (y_1) \\ 2x_1 + x_2 \le 5 \quad (y_2) \\ x_1, x_2 \ge 0 \end{cases}$$
**Costruiamo il suo Duale (D):** Assegniamo una variabile duale $y_1, y_2$ a ogni vincolo.

$$\min w = 4y_1 + 5y_2$$
Soggetto a (trasponiamo le colonne di $x_1$ e $x_2$ in righe per i vincoli duali):

$$\begin{cases} 1y_1 + 2y_2 \ge 3 \quad (\text{vincolo da } x_1) \\ 1y_1 + 1y_2 \ge 2 \quad (\text{vincolo da } x_2) \\ y_1, y_2 \ge 0 \end{cases}$$
**Test di Ottimalità (Forte Dualità in azione):** Se risolviamo geometricamente il primale, l'intersezione dei due vincoli ci dà il vertice $\bar{x} = (1, 2)$. Il valore ottimo primale è: $z = 3(1) + 2(2) = 7$.

Applicando il teorema degli scarti complementari, poiché in $x = (1,2)$ entrambi i vincoli primali sono attivi (soddisfatti come uguaglianza: $1+2=3 \le 4$ NO aspetta, $1+2=3 < 4$. Il vincolo 1 NON è attivo! $2(1)+2 = 4 < 5$. Errore di calcolo nell'intersezione!).

Ricalcoliamo il vertice intersezione corretto:

$$\begin{cases} x_1 + x_2 = 4 \\ 2x_1 + x_2 = 5 \end{cases} \implies x_1 = 1, x_2 = 3$$

Verifica: $1+3=4$ (attivo), $2(1)+3=5$ (attivo). Nuovo valore primale: $z = 3(1) + 2(3) = \mathbf{9}$.
Troviamo le variabili duali risolvendo le uguaglianze dei vincoli duali (poiché $x_1, x_2 > 0$):
$$\begin{cases} y_1 + 2y_2 = 3 \\ y_1 + y_2 = 2 \end{cases} \implies y_2 = 1, y_1 = 1$$

Verifica ammissibilità duale: $y_1, y_2 \ge 0$ (OK). Valore ottimo duale: $w = 4(1) + 5(1) = \mathbf{9}$.
**Conclusione matematica:** $z = 9$ e $w = 9$. Il teorema della **Dualità Forte** è dimostrato! La soluzione è ottima.