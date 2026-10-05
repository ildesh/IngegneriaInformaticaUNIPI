\## 1. Geometria dei Poliedri: Vertici e Soluzioni di Base
### Definizione di Vertice
Un punto $\bar{x}$ di un poliedro $P$ si dice **vertice** se non si può scrivere come combinazione convessa di altri due punti del poliedro con coefficienti $\lambda \neq 0$ e $\lambda \neq 1$.
Ovvero, non può essere espresso come:
$$\lambda \bar{x} + (1-\lambda) \bar{y}$$
con $\bar{x} \in P$.
### Come si trovano i vertici?
Data una matrice $A$ di dimensioni $n \times m$ (con $m \ge n$) e rango pari a $n$:
1. Si definisce $B \subset \{1 \dots m\}$ un insieme di indici di riga (o colonna) di cardinalità $\vert{}B\vert{} = n$ tale che la sottomatrice $A_B$ sia **invertibile**.
    - $A_B$ è la sottomatrice di $A$ composta dagli indici appartenenti a $B$.
    - Gli indici $i \in B$ sono detti **indici di Base**.
2. Ponendo a sistema i vincoli corrispondenti a $B$, si ottiene l'equazione $A_B x_B = b_B$, che rappresenta la **Soluzione di Base** (dove $b_B$ sono i termini noti relativi ai vertici in $B$).
3. Essendo $A_B$ una matrice quadrata $n \times n$ invertibile, la soluzione si calcola come:
$$\bar{x} = A_B^{-1} b_B$$
### Esempio di calcolo di una Soluzione di Base
Dato il seguente sistema di disequazioni:
$$\begin{cases} 2x_1 + 3x_2 \le 7 \\ 3x_1 + x_2 \le 3 \\ x_1 + 2x_2 \le 5 \\ 4x_1 + 3x_2 \le 4 \end{cases}$$
Otteniamo la matrice $A$ e il vettore $b$:
$$A = \begin{pmatrix} 2 & 3 \\ 3 & 1 \\ 1 & 2 \\ 4 & 3 \end{pmatrix}, \quad b = \begin{pmatrix} 7 \\ 3 \\ 5 \\ 4 \end{pmatrix}$$
_(Con $m = 4$ vincoli e $n = 2$ variabili)._

Una sottomatrice è invertibile se il suo determinante è diverso da 0 ($\det \neq 0$). Se $\det = 0$, significa che le due rette sono parallele o sovrapposte.
Scegliamo ad esempio gli indici di base $B = \{2, 4\}$:
$$A_B = \begin{pmatrix} 3 & 1 \\ 4 & 3 \end{pmatrix}, \quad b_B = \begin{pmatrix} 3 \\ 4 \end{pmatrix}$$
Mettendo a sistema e intersecando questi 2 vincoli:
$$\begin{cases} 3x_1 + x_2 = 3 \\ 4x_1 + 3x_2 = 4 \end{cases} \implies \bar{x} = (1, 0)$$Quella trovata è **una soluzione di Base**.

>[!warning] **Attenzione:**
>Non è detto che l'intersezione tra due vincoli sia automaticamente un vertice ammissibile; il punto di intersezione potrebbe cadere al di fuori del poliedro.
### Classificazione delle Soluzioni di Base
Le soluzioni di base si dividono in due categorie principali e relative sottocategorie:
- **Ammissibili** $\rightarrow$ Degeneri o Non degeneri
- **Non Ammissibili** $\rightarrow$ Degeneri o Non degeneri
### Teorema 3: Caratterizzazione dei Vertici
$$\text{Un punto } \bar{x} \in P \text{ è un vertice se è una soluzione di Base ammissibile.}$$
**Definizione di Degenerazione:**
Una soluzione di base si dice **degenere** se soddisfa (come uguaglianza) almeno uno dei vincoli _non di base_. Geometricamente, significa che in quel vertice convergono più vincoli (iperpiani) di quanti siano strettamente necessari per definirlo (ha più basi che lo generano).
- **Esempio del pentagono:** questo vertice è ammissibile degenere perché si può generare con B={2,3}, B={2,6}, B={3,6}.
**Esempio geometrico nel piano ($\mathbb{R}^2$):**
Una base in $\mathbb{R}^2$ deve avere dimensione 2 (deve essere formata da esattamente due indici, es. $B=\{3, 5\}$).
- Se provassimo a usare $B=\{1, 3, 5\}$, _non_ sarebbe una base valida.
- Riprendendo l'esempio di prima, per la base $B=\{2,4\}$ l'insieme degli indici non di base è $N = \{1,3\}$. Se il punto $(1,0)$ non annulla i vincoli 1 e 3, la soluzione ammissibile si dice **non degenere**.
### Altro Esempio Grafico (Ammissibilità e Basi)
Dato il sistema:
$$\begin{cases} x_1 + 2x_2 \le 7 \\ 2x_1 + x_2 \le 6 \\ x_1, x_2 \ge 0 \end{cases} \implies \begin{cases} x_1 + 2x_2 \le 7 \quad \text{(1)}\\ 2x_1 + x_2 \le 6 \quad \text{(2)}\\ -x_1 \le 0 \quad \text{(3)}\\ -x_2 \le 0 \quad \text{(4)} \end{cases}$$
Analizzando alcune possibili basi:
- $B = \{3, 4\} \implies \bar{x} = (0,0)$. È una soluzione di base ammissibile e **NON degenere**.
- $B = \{1, 3\} \implies \bar{x} = (0, \frac{7}{2})$. (Soluzione ammissibile).
- $B = \{2, 3\} \implies \bar{x} = (0, 6)$. Sostituendo nel vincolo (1) si ottiene $0 + 12 \le 7$, che è falso. Quindi **NON è una soluzione ammissibile**.
## 2. Tipologie di Problemi di Programmazione Lineare (PL)
Nei problemi di PL classici (dove l'origine $0$ è spesso un vertice ammissibile per i vincoli di non negatività, ma non necessariamente l'ottimo), abbiamo tre grandi categorie affrontate:
### 1) Problema di Produzione
Formulazioni tipiche (Primale / Duale o conversioni standard):
- $\max c^T x \quad \iff \quad \min c^T x$
- $Ax \le b \quad \iff \quad Ax \ge b$
- $x \ge 0 \quad \iff \quad x \ge 0$
### 2) Problema di Assegnamento
Può essere diviso in:
- **Cooperativo:** Sono accettate soluzioni frazionarie.
- **Non cooperativo:** Non sono accettate soluzioni frazionarie (solo assegnamenti interi/binari).
### 3) Problema di Trasporto Ottimo
**Esempio pratico (Il problema del latte):**
Abbiamo 2 Depositi di latte ($D_1, D_2$) che forniscono 3 Supermercati ($S_1, S_2, S_3$).
- **Disponibilità** per i depositi: $D_1 = 50$, $D_2 = 40$
- **Richiesta** per i supermercati (Prezzo di trasporto/Fabbisogno): 30 ciascuno.

| **Costi cij​**        | **S1​** | **S2​** | **S3​** | **Disponibilità (di​)** |
| --------------------- | ------- | ------- | ------- | ----------------------- |
| **$D_1$**             | 26      | 21      | 22      | **50**                  |
| **$D_2$**             | 32      | 18      | 26      | **40**                  |
| **Richiesta ($r_j$)** | **30**  | **30**  | **30**  |                         |

Un possibile vettore soluzione di assegnamento logistico per questo caso:
$x = (x_{11}, x_{12}, x_{13}, x_{21}, x_{22}, x_{23}) = (30, 20, 0, 0, 10, 30)$

**Formulazione del sistema specifico per l'esempio:**
$$\begin{cases} \min c^T x \\ x_{11} + x_{12} + x_{13} = 50 \\ x_{21} + x_{22} + x_{23} = 40 \\ x_{11} + x_{21} = 30 \\ x_{12} + x_{22} = 30 \\ x_{13} + x_{23} = 30 \\ x \ge 0 \quad \text{con } x \in \mathbb{Z}^{n \times m} \text{ (se richieste quantità intere)} \end{cases}$$
#### Modello Matematico Generale del Problema di Trasporto
$$\min c^T x$$
Soggetto a:
- **Vincoli di disponibilità (Depositi):**
$$\sum_{j=1}^{m} x_{ij} \le d_i \quad \forall i = 1 \dots n$$
- **Vincoli di domanda (Clienti/Supermercati):**
$$\sum_{i=1}^{n} x_{ij} \ge r_j \quad \forall j = 1 \dots m$$
- **Condizione di non negatività:**
$$x \ge 0$