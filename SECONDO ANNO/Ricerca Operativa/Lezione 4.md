## Teorema di Weyl | Esempio 1
### Risoluzione: Identificazione di $A, b, V, E$ per il quadrato limitato

<svg width="400" height="400" viewBox="0 0 400 400" xmlns="http://www.w3.org/2000/svg">
  <!-- Definizioni per le frecce degli assi -->
  <defs>
    <marker id="arrow" markerWidth="10" markerHeight="10" refX="0" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#000" />
    </marker>
  </defs>

  <!-- Assi Cartesiani -->
  <line x1="50" y1="350" x2="380" y2="350" stroke="black" stroke-width="1" marker-end="url(#arrow)" />
  <line x1="50" y1="350" x2="50" y2="20" stroke="black" stroke-width="1" marker-end="url(#arrow)" />
  <text x="385" y="345" font-family="Arial" font-size="16" font-style="italic">x₁</text>
  <text x="30" y="25" font-family="Arial" font-size="16" font-style="italic">x₂</text>

  <!-- Marcatori dei valori sugli assi (scala 1 unità = 250px) -->
  <line x1="300" y1="350" x2="300" y2="340" stroke="black" stroke-width="1" />
  <text x="295" y="365" font-family="Arial" font-size="14">1</text>
  
  <line x1="50" y1="100" x2="60" y2="100" stroke="black" stroke-width="1" />
  <text x="35" y="105" font-family="Arial" font-size="14">1</text>
  
  <text x="40" y="365" font-family="Arial" font-size="14">0</text>

  <!-- Area del poliedro P (Quadrato limitato) -->
  <!-- Rappresenta P = conv(V) + cono(E), dove cono(E) = {0} -->
  <rect x="50" y="100" width="250" height="250" fill="#deebf7" stroke="#3182bd" stroke-width="3" />

  <!-- I quattro vertici V -->
  <circle cx="50" cy="350" r="5" fill="#e6550d" />
  <text x="15" y="345" font-family="Arial" font-size="14" font-weight="bold" fill="#e6550d">v¹ (0,0)</text>

  <circle cx="300" cy="350" r="5" fill="#e6550d" />
  <text x="310" y="360" font-family="Arial" font-size="14" font-weight="bold" fill="#e6550d">v² (1,0)</text>

  <circle cx="300" cy="100" r="5" fill="#e6550d" />
  <text x="310" y="95" font-family="Arial" font-size="14" font-weight="bold" fill="#e6550d">v³ (1,1)</text>

  <circle cx="50" cy="100" r="5" fill="#e6550d" />
  <text x="10" y="90" font-family="Arial" font-size="14" font-weight="bold" fill="#e6550d">v⁴ (0,1)</text>

</svg>
Qui possiamo identificare il sistema dicendo: $\begin{cases}x_1 \ge 0 \\ x_2 \ge 0 \\ x_1 \le 1 \\ x_2 \le 1 \end{cases}$ .

>[!info]
>Dobbiamo identificare le due rappresentazioni del poliedro:
>1. **Rappresentazione Esterna** (tramite matrici $A$ e $b$)
>2. **Rappresentazione Interna / Teorema di Weyl** (tramite vertici $V$ e direzioni $E$)
##### 1. Trovare $A$ e $b$ (Rappresentazione Esterna)
Per esprimere il sistema nella forma matriciale standard $Ax \le b$, dobbiamo assicurarci che tutti i vincoli abbiano il segno "minore o uguale". I primi due vincoli del tuo sistema ($x_1 \ge 0$ e $x_2 \ge 0$) devono essere moltiplicati per $-1$ invertendo il segno:

$$\begin{cases} -x_1 \le 0 \\ -x_2 \le 0 \\ x_1 \le 1 \\ x_2 \le 1 \end{cases}$$
Ora possiamo estrarre la matrice dei coefficienti $A$ e il vettore dei termini noti $b$:
$$A = \begin{pmatrix} -1 & 0 \\ 0 & -1 \\ 1 & 0 \\ 0 & 1 \end{pmatrix} \qquad b = \begin{pmatrix} 0 \\ 0 \\ 1 \\ 1 \end{pmatrix}$$
##### 2. Trovare $V$ ed $E$ (Rappresentazione Interna - Teorema di Weyl)
Guardando il grafico in, possiamo individuare facilmente i componenti per il Teorema di Weyl:
- **L'insieme dei Vertici ($V$):** I vertici sono i quattro punti estremi del quadrato esplicitati nella figura.
$$V = \left\{ \begin{pmatrix} 0 \\ 0 \end{pmatrix}, \begin{pmatrix} 1 \\ 0 \end{pmatrix}, \begin{pmatrix} 1 \\ 1 \end{pmatrix}, \begin{pmatrix} 0 \\ 1 \end{pmatrix} \right\}$$
- **L'insieme delle Direzioni ($E$):**
    Poiché il quadrato è una figura chiusa e limitata, **non si estende all'infinito** in nessuna direzione. Questo significa che non ci sono direzioni estreme!    $$E = \emptyset \quad \text{(Insieme vuoto)}$$Di conseguenza, l'inviluppo conico è semplicemente l'origine: $\text{cono}(E) = \{0\}$.

Per questo specifico poliedro, il Teorema di Weyl ($P = \text{conv}(V) + \text{cono}(E)$) si riduce a:
$$P = \text{conv}(V)$$
Questo significa che **qualsiasi punto all'interno del quadrato è unicamente esprimibile come combinazione convessa dei suoi 4 vertici**, senza alcun bisogno di combinazioni coniche (spostamenti all'infinito).

---
## Esempio 2 
### Rappresentazione tramite $V$ ed $E$

- $V = \{ (1,1) \ (2,2) \}$
- $E = \{ (0,0) \}$ 

Sapendo che la direzione $E$ è pari a $(0,0)$ allora **il poliedro è limitato**. 

 **1. Forma geometrica e Dimensione**: Poiché hai solo due vertici, il tuo poliedro $P$ corrisponde esattamente al **segmento chiuso** che unisce i punti $(1,1)$ e $(2,2)$ nel piano cartesiano. È un poliedro "degenere" di dimensione 1 all'interno di uno spazio a 2 dimensioni ($\mathbb{R}^2$), poiché non racchiude un'area ma si sviluppa solo su una linea.
 
  **2. Espressione secondo il Teorema di Weyl**:  Dato che il cono è nullo, il teorema si riduce alla sola combinazione convessa dei vertici ($P = \text{conv}(V)$). Richiamando la definizione formale, ogni punto $y \in P$ può essere espresso unicamente come:
$$y = \lambda_1 \begin{pmatrix} 1 \\ 1 \end{pmatrix} + \lambda_2 \begin{pmatrix} 2 \\ 2 \end{pmatrix}$$con i vincoli fondamentali della combinazione convessa:
$$\lambda_1 + \lambda_2 = 1 \quad \text{e} \quad \lambda_1, \lambda_2 \ge 0$$
**3. Rappresentazione Esterna (Sistema di vincoli $Ax \le b$)**: Se volessimo trovare le equazioni/disequazioni che definiscono questo poliedro (il percorso inverso rispetto al trovare $V$ ed $E$), potremmo notare che entrambi i punti giacciono sulla retta bisettrice del primo quadrante, dove $x_1 = x_2$.
Il sistema che definisce questo poliedro è quindi: 
$$\begin{cases} x_1 - x_2 = 0 \quad \text{(Giace sulla retta)} \\ x_1 \ge 1 \quad \text{(Limitazione inferiore)} \\ x_1 \le 2 \quad \text{(Limitazione superiore)} \end{cases}$$ _(Nota: I vincoli su $x_2$ sono impliciti grazie all'equazione $x_1 = x_2$)_.

<svg width="400" height="400" viewBox="0 0 400 400" xmlns="http://www.w3.org/2000/svg">
  <!-- Definizioni per le frecce degli assi -->
  <defs>
    <marker id="arrow" markerWidth="10" markerHeight="10" refX="0" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#000" />
    </marker>
  </defs>

  <!-- Griglia di riferimento (scala 1 unità = 100px) -->
  <line x1="150" y1="350" x2="150" y2="50" stroke="#eee" stroke-dasharray="4" />
  <line x1="250" y1="350" x2="250" y2="50" stroke="#eee" stroke-dasharray="4" />
  <line x1="50" y1="250" x2="350" y2="250" stroke="#eee" stroke-dasharray="4" />
  <line x1="50" y1="150" x2="350" y2="150" stroke="#eee" stroke-dasharray="4" />

  <!-- Assi Cartesiani -->
  <line x1="50" y1="350" x2="380" y2="350" stroke="black" stroke-width="1.5" marker-end="url(#arrow)" />
  <line x1="50" y1="350" x2="50" y2="20" stroke="black" stroke-width="1.5" marker-end="url(#arrow)" />
  
  <text x="385" y="345" font-family="Arial" font-size="16" font-style="italic">x₁</text>
  <text x="30" y="25" font-family="Arial" font-size="16" font-style="italic">x₂</text>

  <!-- Etichette numeriche assi -->
  <text x="145" y="370" font-family="Arial" font-size="14">1</text>
  <text x="245" y="370" font-family="Arial" font-size="14">2</text>
  <text x="30" y="255" font-family="Arial" font-size="14">1</text>
  <text x="30" y="155" font-family="Arial" font-size="14">2</text>
  <text x="35" y="365" font-family="Arial" font-size="14">0</text>

  <!-- Poliedro: Segmento conv(V) -->
  <line x1="150" y1="250" x2="250" y2="150" stroke="#3182bd" stroke-width="4" />
  
  <g transform="translate(180, 215) rotate(-45)">
    <text x="0" y="0" font-family="Arial" font-size="16" font-weight="bold" fill="#3182bd">conv(V)</text>
  </g>

  <!-- Vertici V -->
  <circle cx="150" cy="250" r="6" fill="#e6550d" />
  <text x="165" y="265" font-family="Arial" font-size="14" font-weight="bold" fill="#e6550d">v¹ (1,1)</text>

  <circle cx="250" cy="150" r="6" fill="#e6550d" />
  <text x="265" y="145" font-family="Arial" font-size="14" font-weight="bold" fill="#e6550d">v² (2,2)</text>
</svg>
In sintesi, avere un $E$ nullo e soli due punti in $V$ ti dice subito tutto: è un semplice segmento, è limitato, ed è interamente descrivibile dalle variazioni dei due coefficienti $\lambda_1$ e $\lambda_2$ tra $0$ e $1$.

---
## Teorema fondamentale della PL
Per il teorema di Weyl possiamo dire che: 
$$
x \in P \ \rightarrow \ C^T\cdot x =  C^T \cdot ( \ \sum_{i=1}^K\overline{\lambda}_iv^i \ + \ \sum_{j=1}^P \overline{\mu}_je^j \ )
$$
questo sapendo che: $\begin{cases} \lambda_i \in [0, 1] \quad \\ \sum_{i} \lambda_i = 1 \end{cases}$ e $\overline{\mu_j} \ge 0$

In parole povere: il poliedro è la **somma di tutti i punti $\text{conv }V$ e i punti del $\text{cono } E$** e questo perché l'intero spazio del poliedro si genera unendo la sua componente chiusa e limitata (le combinazioni convesse dei vertici) con i suoi eventuali prolungamenti verso l'infinito (le combinazioni coniche delle direzioni)."
Ci sono due casi che dobbiamo però identificare:
- **Poliedro limitato _(CASO DA SEGUIRE MEGLIO PER L'OTTIMO)_**: Se abbiamo un poliedro limitato, significa che la $e$ è pari all'insieme vuoto. Per questa cosa appunto, ponendo $c \cdot e^j \le 0$, la sommatoria dei punti del cono $E$ è pari a 0 e quindi ci rimane che:
	$$
	x \in P \ \rightarrow \ C^T\cdot x \ = \ \sum_{i=1}^K\overline{\lambda}_iv^i \ = \sum_{i=1}^K\overline{\lambda}_i \cdot (c \cdot v^i)
	$$
- **Poliedro illimitato**: Riguardo questo tipo di poliedro, non ha nemmeno senso andare a cercare la soluzione ottima perché qualsiasi valore ci sia all'interno di $E$ si tenderà sempre verso l'infinito.
### Dal Modello Matematico alla Rappresentazione di Weyl
Consideriamo un problema di Programmazione Lineare (PL) in forma standard:

$$\begin{cases} \max c^T x \\ Ax \le b \end{cases}$$

L'insieme delle soluzioni ammissibili definito dal sistema $Ax \le b$ rappresenta geometricamente un poliedro $P$, che tramite il Teorema di Weyl possiamo tradurre nella rappresentazione interna basata sugli insiemi $V$ (vertici) ed $E$ (direzioni).

***La Funzione Obiettivo e la Combinazione Convessa***: Considerando un poliedro limitato, possiamo sostituire la variabile decisionale $x$ con la combinazione convessa dei suoi vertici:
$$\max_{x \in P} c^T x = \max_{\substack{\lambda_i \ge 0 \\ \sum \lambda_i = 1}} \sum_{i=1}^{k} \lambda_i (c^T \cdot v^i)$$
Sviluppando la sommatoria per tutti i $k$ vertici otteniamo $\max \left[ \lambda_1 (c^T v^1) + \dots + \lambda_k (c^T v^k) \right]$. Se individuiamo un vertice $v^r$ che garantisce il valore massimo assoluto, poiché la combinazione convessa è una media pesata (i $\lambda_i$ sommano a $1$), la somma complessiva non potrà mai superare il valore di quel vertice:
$$\sum_{i=1}^{k} \lambda_i (c^T \cdot v^i) \ge (c^T \cdot v^r) \cdot (\lambda_1 + \dots + \lambda_k) = c^T \cdot v^r$$
Da questa disuguaglianza logica si deduce infine che:
$$c^T \cdot v^r \ge \max_{x \in P} c^T x \implies \max_{x \in P} c^T x = c^T \cdot v^r$$
Questo dimostra matematicamente che la soluzione ottima risiede sempre in un vertice.
### Definizione teorema fondamentale della PL

>[!IMPORTANT] Definizione:
>Sia dato un **problema di PL** in formato $\begin{cases}\text{max }C^T \ \cdot x \\ Ax \le b\end{cases}$ e siano $V$,$E$, **l'insieme della rappresentazione di Weyl per la regione ammissibile**. Allora può succedere uno e uno solo dei seguenti tre casi:
>1. ***Il poliedro è vuoto***: troppi vincoli, problema reale e quindi vanno eliminati i vincoli;
>2. ***Il problema va a $+\infty$*** $\rightarrow$ ci sono pochi vincoli;
>3. ***Uno dei punti di $V$ è sicuramente ottimo***.
#### Esempio

**Dati del problema:**
- Insieme dei vertici: $V = \{ (1,1), (2,3), (-1,0) \}$
- Insieme delle direzioni: $E = \{ (0,1), (1,4) \}$
- Vettore dei costi: $c = (4, -3)$
**Valutazione della Funzione Obiettivo nei vertici ($\max c^T x = c^T v^r$):**
- $c^T v^1 = (4, -3) \cdot (1, 1) = 4 - 3 = 1 \quad \leftarrow \textbf{Ottimo}$
- $c^T v^2 = (4, -3) \cdot (2, 3) = 8 - 9 = -1$
- $c^T v^3 = (4, -3) \cdot (-1, 0) = -4 + 0 = -4$
### Analisi del Teorema Fondamentale della PL
Richiamando i tre casi del Teorema Fondamentale della Programmazione Lineare, ecco la spiegazione matematica sul perché in questo specifico esercizio i primi due punti vengano esclusi, portandoci direttamente a scegliere il vertice come soluzione ottima.
- **Perché si scarta il Punto 1 (Poliedro vuoto):** Il primo caso si verifica quando il sistema di vincoli non ammette alcuna soluzione ammissibile. Come annotato nei tuoi appunti, "non siamo nel caso 1" perché possediamo già delle soluzioni. Essendo l'insieme dei vertici $V$ popolato da ben tre punti, abbiamo la certezza che il poliedro esista nello spazio e non sia vuoto.
- **Perché si scarta il Punto 2 (Problema illimitato a $+\infty$):** In un problema di massimizzazione, il valore tende a $+\infty$ solo se esiste almeno una direzione $e^j \in E$ lungo la quale la funzione obiettivo continua a crescere. Matematicamente, questo significa cercare una direzione tale per cui $c^T e^j > 0$. Proviamo a calcolare il prodotto scalare tra il vettore dei costi $c$ e le due direzioni a nostra disposizione: