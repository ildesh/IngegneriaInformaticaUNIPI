## 1. Poliedri in Forma Standard e Duale
Per trovare la soluzione ottima all'interno di un poliedro, il numero di combinazioni possibili per trovare un vertice è dato dal coefficiente binomiale:
$$\binom{n}{m} = \frac{n!}{m!(n-m)!}$$
Un poliedro si definisce in **Forma Standard** quando il sistema è descritto in questo modo:
$$\begin{cases} Ax = b \\ x \ge 0 \end{cases}$$
>[!info] **Regole di conversione per passare alle diverse forme:**
>1. Passaggio da $\min$ a $\max$ (e viceversa).
>2. Cambio di verso nelle disuguaglianze: $\le \leftrightarrow \ge$ (moltiplicando per $-1$).
>3. Da uguaglianza a disuguaglianza: $=$ si trasforma in $\le$ e $\ge$.
>4. **Da disuguaglianza a uguaglianza (Aggiunta variabili di scarto):** Per passare dal $\le$ (o $\ge$) all'$=$ si aggiunge (o sottrae) una "variabile di scarto". _Esempio:_ 
>$$3x_1 + 2x_2 \le 7 \implies \begin{cases} 3x_1 + 2x_2 + x_3 = 7 \\ x_3 \ge 0 \end{cases}$$
>5. **Variabili non vincolate in segno:** Se una variabile non ha il vincolo $x \ge 0$, si può scrivere: $x_1 = x_1' - x_1''$ con $x_1', x_1'' \ge 0$.

**ESEMPIO 1**
Dato il sistema:
$$\begin{cases} 3x_1 + x_2 \ge 9 \\ 2x_1 + 3x_2 = 6 \\ 4x_1 - 5x_2 \le -3 \\ x_1 \ge 0 \end{cases}$$
Si può portare in 3 forme:
1. $Ax \le b$ 
2. MATLAB ($Aeq, beq...$)
3. $Ax = b, x \ge 0$
Se lo portiamo nella forma (1) $Ax \le b$, otteniamo matrici di questo tipo:
$$A = \begin{pmatrix} -3 & -1 \\ 2 & 3 \\ -2 & -3 \\ 4 & -5 \\ -1 & 0 \end{pmatrix}, \quad b = \begin{pmatrix} -9 \\ 6 \\ -6 \\ -3 \\ 0 \end{pmatrix}$$

_(Per la forma 2, in MATLAB si avranno $A = 2 \times 2$, $Aeq = 1 \times 2$, ecc.)_.

```mathlab
A = [-3 -1; 2 3; -2 -3; 4 -5; -1 0]
b = [-9 6 -6 -3 0]
```
#### 2. Formato Duale Standard
**Continuazione Esempio verso il Formato (3) $Ax = b, x \ge 0$:** Consideriamo il sistema:
$$\begin{cases} -3x_1 - x_2 + x_3 = -9 \\ 2x_1 + 3x_2 = 6 \\ 4x_1 - 5x_2 + x_4 = -3 \\ x_1, x_3, x_4 \ge 0 \end{cases}$$
$\implies$ **Non è in formato duale standard** perché manca $x_2 \ge 0$. Posso scrivere $x_2$ come $x_2 = x_2' - x_2''$:
$$\begin{cases} -3x_1 - (x_2' - x_2'') + x_3 = -9 \\ 2x_1 + 3(x_2' - x_2'') = 6 \\ 4x_1 - 5(x_2' - x_2'') + x_4 = -3 \\ x_2', x_2'' \ge 0 \\ x_1, x_3, x_4 \ge 0 \end{cases}$$
$\implies$ **Ora è in formato duale standard**. $\implies$ Anche se è in $\mathbb{R}^5$ è equivalente al problema originale in $\mathbb{R}^4$.
Matrice e vettore risultanti:
$$A = \begin{pmatrix} -3 & -1 & 1 & 1 & 0 \\ 2 & 3 & -3 & 0 & 0 \\ 4 & -5 & 5 & 0 & 1 \end{pmatrix}, \quad b = \begin{pmatrix} -9 \\ 6 \\ -3 \end{pmatrix}, \quad x \ge 0$$
**ESEMPIO 2**
$$\begin{cases} 2x_1 + x_2 \le 5 \\ x_1 - x_2 = 3 \\ -x_1 - 5x_2 \ge -1 \\ x_1 \ge 0 \end{cases}$$
Mettiamo caso che l'ottimo sia $\bar{x} = (2, -1)$. Ma se lo portiamo in duale, con il vettore espresso come $(x_1, x_2', x_2'', x_3, x_4)$, diventa:
$$\bar{x} = (2, 0, 1, 2, 4)$$
Da $\bar{x} = (2, 0, 1, 2, 4)$ si torna a $\bar{x} = (2, -1)$ proprio perché $x_2 = x_2' - x_2'' \implies x_2 = 0 - 1 = -1$.
**ESEMPIO 3**
$$\begin{cases} 4x_1 + x_2 \le 9 \\ 7x_1 - x_2 \ge 8 \end{cases}$$
Se abbiamo $\bar{x} = (2,0)$, espresso con tutte le variabili di scarto lo posso scrivere in entrambi i modi:
$$x = (2, 0, 0, 0, 1, 6) \quad \text{oppure} \quad x = (5, 3, 0, 0, 1, 6)$$
#### 3. Calcolo dei Vertici in Duale Standard
Dato il sistema generale $\begin{cases} Ax = b \\ x \ge 0 \end{cases}$. In forma matriciale:
$$[A] \cdot [x] = [b]$$
Esempio numerico:
$$\begin{cases} 3x_1 + 2x_2 + 5x_3 = 8 \\ 4x_1 + x_2 + 2x_3 = 9 \\ x \ge 0 \end{cases}$$Qui $A$ è $2 \times 3$, $x$ è $3 \times 1$, e $b$ è $2 \times 1$.
Procedura:
1. Si prende un sottoinsieme $B \subseteq \{1, \dots, n\}$ tale per cui $A_B$ è invertibile.
2. Si divide il vettore $x = (x_B, x_N)$ e la matrice $A = [A_B \vert{} A_N]$.
3. Si ha $\begin{pmatrix} A_B & A_N \end{pmatrix} \begin{pmatrix} x_B \\ x_N \end{pmatrix} = b$.
4. Pongo $x_N = 0 \implies A_B x_B = b \implies x_B = A_B^{-1} b$.
5. La soluzione sarà $\bar{x} = (x_B, 0)$.
#### 4. Teoremi e Soluzioni di Base

>[!important] **TEOREMA (1):** 
>Un punto $x$ appartenente al duale standard è un **vertice** se e solo se è una **soluzione di base ammissibile**.

- Una soluzione di base duale si dice **degenere** se ha una sua componente di $x_B = 0$.
- Si dice **ammissibile** se $x_B \ge 0$.
**ESERCIZIO 2**
$$\begin{cases} 2x_1 + 3x_2 + x_3 + 4x_4 = 3 \\ 4x_1 + x_2 + 3x_3 + x_4 = 7 \\ x \ge 0 \end{cases}$$
Scelgo $B = \{1, 3\}$.
$$A_B x_B = b \implies \begin{pmatrix} 2 & 1 \\ 4 & 3 \end{pmatrix} \begin{pmatrix} x_1 \\ x_3 \end{pmatrix} = \begin{pmatrix} 3 \\ 7 \end{pmatrix}$$
Risolvendo, otteniamo $x_B = (1, 1)$. Il vettore completo è $x = (1, 0, 1, 0)$ (dove le componenti 1 e 3 sono 1, e le 2 e 4 non di base sono 0). $\implies$ È una **soluzione di base ammissibile non degenere**.
#### 5. Il Problema di Assegnamento
Il problema di assegnamento è già nativamente in formato duale:
$$\begin{cases} x_{11} + x_{12} + x_{13} = 1 \\ x_{21} + x_{22} + x_{23} = 1 \\ x_{31} + x_{32} + x_{33} = 1 \\ x_{11} + x_{21} + x_{31} = 1 \\ x_{12} + x_{22} + x_{32} = 1 \\ x_{13} + x_{23} + x_{33} = 1 \\ x \ge 0 \end{cases}$$
Se analizziamo un vettore soluzione del tipo:
$$x = (1, 0, 0, 0, 1, 0, 0, 0, 1)$$
$\implies$ **È una soluzione di base?**
Essendo una matrice $5 \times 9$ (considerando la dipendenza lineare dei 6 vincoli, si riduce a 5), devo avere una base $B$ in $\mathbb{R}^5$ e la componente non di base $N$ in $\mathbb{R}^4$.