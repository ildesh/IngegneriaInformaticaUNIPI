# Algoritmo del simplesso primale

L'algoritmo del Simplesso è un metodo algebrico e iterativo per risolvere problemi di Programmazione Lineare. Invece di calcolare tutte le infinite soluzioni ammissibili, l'algoritmo esplora i vertici del poliedro (la regione ammissibile) spostandosi da un vertice a uno dei suoi adiacenti, fino a trovare quello che massimizza (o minimizza) la funzione obiettivo.

Consideriamo un problema primale nella sua forma classica
$$
\begin{cases}
\text{max }c^T \cdot x \\
Ax \le b
\end{cases}
$$
Per identificare un **vertice** $\overline{x}$ del poliedro $P$, dobbiamo estrarre un sottoinsieme di vincoli che in quel punto sono "attivi" (cioè soddisfatti come uguaglianza).
Definiamo quindi due insiemi di indici per le righe della matrice $A$:
- **$B$ (Indici di Base):** I vincoli attivi nel vertice. La sottomatrice quadrata $A_B$ formata da queste righe deve essere invertibile.
- **$N$ (Indici Non di Base):** I restanti vincoli, che in quel vertice non sono attivi (hanno uno "scarto").

Il sistema si divide quindi in:

$$\begin{cases} A_B \overline{x} = b_B \implies \overline{x} = A_B^{-1} \cdot b_B \quad \text{(Calcolo del vertice)} \\ A_N \overline{x} \le b_N \implies b_N - A_N\overline{x} \ge 0 \quad \text{(Verifica di ammissibilità)} \end{cases}$$

Scriviamo la sua versione in duale:
$$
\begin{cases}
\text{min } b^Ty \\
A^Ty = C^T \\
y \ge 0
\end{cases}
$$
e abbiamo una variabile $h = \text{min}\begin{cases}i \in B : y_i < 0\end{cases}$
**Poiché per il Teorema degli Scarti Complementari le variabili duali $y_N$ associate ai vincoli primali non attivi si annullano, l'equazione $A^T y = C^T$ si riduce alla sola parte di base**, da qui possiamo dire che $A_B^T\cdot y_B = C^T$ da cui si ricava $y_B = C^T \cdot (A_B^T)^{-1}$ 

>[!note] Vertici adiacenti
>Due vertici si dicono adiacenti quando si differiscono per un solo indice di base.

Geometricamente, questo significa che i due vertici sono collegati da uno spigolo del poliedro. L'algoritmo del Simplesso si muove esattamente lungo questi spigoli: ad ogni iterazione effettua un "cambio di base", facendo uscire un indice dall'insieme B e facendone entrare uno dall'insieme N, spostandosi così da un vertice a un vertice adiacente migliore.

Per comodità possiamo inizializzare una nuova variabile: $W = -A_B^{-1}$.
#### Esempio:
<svg width="400" height="400" viewBox="0 0 400 400" xmlns="http://www.w3.org/2000/svg">
  <!-- Area del poliedro P (Esagono) -->
  <polygon points="100,280 200,350 320,300 350,180 260,80 120,120" fill="#deebf7" stroke="#3182bd" stroke-width="3" />
  
  <!-- Vertice di partenza x_bar -->
  <circle cx="100" cy="280" r="7" fill="#e6550d" />
  <text x="60" y="300" font-family="Arial" font-size="18" font-weight="bold" fill="#e6550d">x̄</text>

  <!-- Direzione W^1 -->
  <!-- Vettore -->
  <line x1="100" y1="280" x2="160" y2="322" stroke="#31a354" stroke-width="4" marker-end="url(#arrow_w)" />
  <!-- Spigolo rimanente -->
  <line x1="160" y1="322" x2="200" y2="350" stroke="#3182bd" stroke-width="3" stroke-dasharray="4" />
  <text x="140" y="345" font-family="Arial" font-size="16" font-weight="bold" fill="#31a354">W¹</text>

  <!-- Direzione W^5 -->
  <!-- Vettore -->
  <line x1="100" y1="280" x2="110" y2="200" stroke="#756bb1" stroke-width="4" marker-end="url(#arrow_w_alt)" />
  <!-- Spigolo rimanente -->
  <line x1="110" y1="200" x2="120" y2="120" stroke="#3182bd" stroke-width="3" stroke-dasharray="4" />
  <text x="65" y="215" font-family="Arial" font-size="16" font-weight="bold" fill="#756bb1">W⁵</text>

  <!-- Definizione frecce -->
  <defs>
    <marker id="arrow_w" markerWidth="10" markerHeight="10" refX="5" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#31a354" />
    </marker>
    <marker id="arrow_w_alt" markerWidth="10" markerHeight="10" refX="5" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#756bb1" />
    </marker>
  </defs>
  
  <!-- Etichetta -->
  <text x="210" y="200" font-family="Arial" font-size="20" font-weight="bold" fill="#3182bd">Poliedro P</text>
</svg>
> [!example] Esercizio Tipo: Iterazione dell'Algoritmo del Simplesso
> Quando un esercizio chiede di verificare se un vertice è ottimo o di calcolare lo spostamento verso il vertice adiacente successivo, bisogna seguire questi 5 passaggi ordinati:
> 

1. Dati del Vertice Attuale (Punto di Partenza)
	Definiamo la situazione nel vertice $\overline{x}$ attuale, separando la matrice in base e non base:
	* **Indici di Base ($B$):** Le variabili che formano la sottomatrice invertibile $A_B$ (es. $B = \{1, 5\}$).
	* **Indici Non di Base ($N$):** Le variabili restanti, che vengono imposte a zero ($\overline{x}_N = 0$).
	Calcoliamo le coordinate del vertice attuale risolvendo il sistema:
$$ \overline{x}_B = A_B^{-1} \cdot b_B $$
2.  Calcolo delle Variabili Duali ($y_B$)
	Dobbiamo capire quanto "costa" muoversi. Troviamo il valore delle variabili duali (i prezzi ombra) associate alla base attuale usando la formula:
$$ y_B = C_B^T \cdot (A_B^T)^{-1} $$
3. Calcolo dei Costi Ridotti e Scelta della Direzione
	Per capire se ci conviene spostarci lungo uno spigolo per far entrare in base una variabile non di base $i$, valutiamo la variazione della funzione obiettivo lungo la direzione $W^i$:
	$$ C^T W^i = -\overline{y}_i $$
	*Se usiamo la notazione standard dei costi ridotti $\bar{c}_i$, si calcola come: $\bar{c}_i = c_i - y_B^T \cdot A_i$*
	
	**Regola di arresto (per problemi di MAX):**
	* Se **$C^T W^i \le 0$** per tutte le direzioni: Il vertice attuale è l'OTTIMO. L'algoritmo si ferma.
	* Se esiste un **$C^T W^i > 0$**: Il profitto può ancora migliorare. Scegliamo la direzione $W^i$ con il valore positivo più alto (ovvero quella che fa crescere di più la funzione obiettivo) e decidiamo di esplorarla.

4. Calcolo del Passo ($\lambda$)
	Una volta scelta la direzione $W^i$, dobbiamo calcolare "quanto" possiamo camminare lungo quello spigolo prima di sbattere contro un nuovo vincolo (cioè prima di uscire dal poliedro).
	Calcoliamo il passo massimo ammissibile $\lambda$:
	$$ \lambda = \min \left\{ \frac{\overline{x}_j}{-W_j^i} \ \Bigg| \ W_j^i < 0 \right\} $$
	*(Nota teorica: se tutti i componenti del vettore direzione $W_j^i$ fossero $\ge 0$, significherebbe che possiamo camminare all'infinito e il problema sarebbe illimitato a $+\infty$).*

5. Calcolo del Nuovo Vertice Adiacente
	Trovata la direzione $W^i$ e calcolato il passo $\lambda$, ci spostiamo fisicamente sul nuovo vertice adiacente applicando la formula del segmento:
	$$ \overline{x}_{nuovo} = \overline{x}_{vecchio} + \lambda W^i $$
A questo punto:
6. La variabile $i$ **entra** nella base $B$.
7. La variabile che ha determinato il limite $\lambda$ **esce** dalla base.
8. L'algoritmo riparte dal Punto 1 sul nuovo vertice, fino a trovare l'ottimo. W^1) = C^T\overline{x} + \lambda C^T\cdot W^1$
---
### Indice uscente, indice entrante

Ci chiediamo se, muovendoci lungo la direzione $W^h$ scelta, rimaniamo all'interno del poliedro ammissibile. Affinché il nuovo punto sia ammissibile, deve valere: $$ A(\overline{x} + \lambda W^h) \le b $$ Analizzando il singolo vincolo $i$-esimo, dobbiamo verificare che: $$ A_i \overline{x} + \lambda A_i W^h \le b_i \quad \forall \lambda \ge 0 $$ Sappiamo già che $\overline{x}$ è ammissibile, quindi $A_i \overline{x} \le b_i$. A questo punto si presentano due casi, a seconda del segno della quantità $A_i W^h$: **Caso 1: $A_i W^h \le 0$** Poiché $\lambda \ge 0$, il termine $\lambda A_i W^h$ sarà sempre negativo o nullo. Di conseguenza, la disuguaglianza è **sempre verificata** per qualsiasi valore di $\lambda$. Questo vincolo non bloccherà mai il nostro cammino. *(Nota: se questo caso si verifica per tutti i vincoli, significa che possiamo camminare all'infinito lungo $W^h$ e il problema è **illimitato**).* **Caso 2: $A_i W^h > 0$** In questo caso, all'aumentare di $\lambda$, il termine a sinistra cresce fino a rischiare di superare $b_i$. Dobbiamo quindi imporre un limite superiore al nostro passo $\lambda$: $$ \lambda A_i W^h \le b_i - A_i \overline{x} \implies \lambda \le \frac{b_i - A_i \overline{x}}{A_i W^h} $$ #### Test del Minimo Rapporto (Scelta degli indici) Per garantire che *tutti* i vincoli del poliedro siano rispettati simultaneamente, non possiamo superare il limite più stringente. Pertanto, il passo $\lambda$ massimo che possiamo compiere si calcola come: $$ \lambda = \min_{i \ | \ A_i W^h > 0} \left\{ \frac{b_i - A_i \overline{x}}{A_i W^h} \right\} $$
* **Indice Uscente:** È l'indice di riga $i$ (appartenente alla base attuale) per il quale si realizza questo minimo. Fisicamente, rappresenta il primo vincolo contro cui "andiamo a sbattere" muovendoci lungo lo spigolo. Questa variabile esce dalla base. 
* **Indice Entrante:** È l'indice $h$ (non di base) relativo alla direzione $W^h$ che avevamo precedentemente scelto di esplorare perché migliorava la funzione obiettivo. Questa variabile entra nella base.

---
### Esercizio sul simplesso

