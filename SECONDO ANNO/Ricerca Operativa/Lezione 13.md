# Valutazioni superiori e inferiori
$$
V_I \le
\begin{cases}
\text{max } C^Tx \\
Ax \le b \\
x \in \mathbb{Z}^n
\end{cases}
\le V_S
$$
che equivale a dire $V_I(P) \le V_{pli} \le V_S(P)$, sapendo che la differenza tra $V_S(P)$ e $V_I(P)$ è identificato come ***gap***. 
La valutazione superiore, per antonomasia, è classificato come il seguente sistema: $\begin{cases} \text{max } C^Tx \\ Ax \le b \end{cases}$.

>[!info] Definizione greedy:
>Bisogna partire con un buon gap, sapendo che $V_I$ deve essere abbastanza grande e $V_S$ piccola.

Attraverso l'eliminazione dei vincoli, la $V_S$ deve essere ***facile*** e ***greedy*** da calcolare. 
Il valore $V_I(P) = C^T \tilde{x}$ è valido ***sempre*** solo se il valore $\tilde{x}$ è una soluzione ammissibile.

Per il seguente teorema 1, abbiamo scoperto che $V_{pli} = V_{conv_S}$ e da qui abbiamo avuto un idea chiara su come costruire il gap.

>[!attention]
>Seguendo il teorema 1 però dobbiamo dire che non si può trovare la PLI facendo il simplesso e per ridurre il gap possiamo dire che $V_{conv_S}$ ci può bastare come la nostra $V_S$ 

---
## Matrice Unimodulare: definizione
Una matrice $A$ si dice ***unimodulare*** se i determinanti delle sottomatrici quadrate di rango massimo (*sono le basi nel problema di PL*) sono tutti $+$ o $- 1$. 

>[!question]- Cosa comporta avere le basi $+$ o $- 1$?
>$$\overline{x} = A_{B}^-1b_B$$
> - I problemi di PL con la matrice $A$ unimodulare, hanno una proprietà importante: i vertici sono a componenti intere $\Rightarrow$ comporta dei cambiamenti. 
> - Se risolvo il rilassato continuo e vengono fuori delle componenti intere, allora abbiamo trovato la soluzione ottima.
> - E come risolviamo i problemi di PLI con questo tipo di matrici? Utilizzando il **Simplesso**.
### Teorema 2: teorema dell'interezza
1. La matrice $A$ del problema dell'assegnamento è "**unimodulare**".
	Questo teorema comporta che la distinzione della assegnamento cooperativo e assegnamento non coperativo non è importante e quindi questi non sono veri problemi di PLI. Utilizzando il **simplesso** riesco a risolvere il problema di assegnamento, in qualsiasi caso.

2. La matrice $A$ del problema del trasporto è "**unimodulare**". E quindi questo tipo di problema, non è un vero di problema di PLI.

>[!question]- Una soluzione ottima di assegnamento è tutta a componenti intere? 
>La risposta è no. Però bisogna stare attenti a come viene posta la domanda perché potrebbe esistere come non potrebbe esistere. E se esiste quale sarebbe? ***La soluzione ottima del rilassato continuo.***

