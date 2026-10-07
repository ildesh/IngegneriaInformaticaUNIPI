# Poliedri vuoti

$\begin{cases}Ax =b \\x \ge 0\end{cases}\text{ è vuoto?}$     Supponiamo che $A \in R^{n \cdot m}$, $b \in R^n$ e $x \in R^m$. 

> [!important] **Definizione utile:** 
> Un poliedro si dice _vuoto_ quando il sistema di equazioni e disequazioni che lo descrive è incompatibile, ovvero non ammette alcuna soluzione ammissibile (non esiste nessun punto $x$ che rispetti contemporaneamente tutti i vincoli imposti).
## Teorema del problema ausiliario
Per capire se un poliedro è vuoto dobbiamo creare un problema ausiliario che si presenterà nella seguente forma:
$$
\begin{cases}
min \sum \epsilon_i \\
Ax + I\epsilon = b \\
x_i\epsilon \ge 0
\end{cases}
\ \ \text{dove I è la matrice identità}
$$
e quindi a noi ci basta risolvere questo problema ausiliario. Le variabili $\epsilon_i$ (epsilon) sono chiamate **variabili artificiali**. Vengono introdotte per creare forzatamente una "soluzione di base iniziale" ammissibile, necessaria per poter avviare l'algoritmo del Simplesso (questa procedura è nota come _Metodo delle due fasi_ o _Fase 1_). L'obiettivo $\min \sum \epsilon_i$ spinge l'algoritmo a cercare di azzerare ("spegnere") tutte queste variabili finte. _(Nota per la trascrizione: la dicitura $x_i\epsilon \ge 0$ intende solitamente che sia le variabili originali $x$ sia le variabili artificiali $\epsilon$ devono essere non negative: $x \ge 0, \epsilon \ge 0$)_.

L'ottimo può valere:
1. $V_{ottimo} = 0 \rightarrow$ il poliedro D è non vuoto   
2. $V_{ottimo} > 0 \rightarrow$ il poliedro D è vuoto
---
# Problema di caricamento ottimo - zaino

- $v = (5,7,9,10,12)$
- $p = (8,9,11,13,15)$
- $P = 29$

Dobbiamo trovare un modo per ***massimizzare*** il profitto totale (o valore) degli oggetti scelti, senza superare la capacità massima P (29). Matematicamente, la funzione obiettivo è massimizzare $v^T \cdot x$ (il prodotto scalare tra i valori e le variabili di scelta $x_i$). Il vincolo principale è il peso $p^T \cdot x \le P$, che impedisce matematicamente che la somma dei pesi degli oggetti scelti ecceda la capienza massima (P = 29).

$x_i = \begin{cases} 0 \\ 1 \end{cases} i = 1,5$  | $x = (1,1,1,0,0) \rightarrow v = 21$ 

$\begin{cases} \text{max } v^T \cdot x \\ p^T \cdot x \le P \\ (1) \rightarrow x \in \{0,1\}^n\end{cases}$ | $\begin{cases} \text{max } v^T \cdot x \\ p^T \cdot x \le P \\ (2) \rightarrow x \in \mathbb{Z}^{n}_+\end{cases}$ | $(3) \rightarrow x \in [0,1]$ | $(4) \rightarrow x \ge 0$

>[!note] per sapere di più...
>- $(1) \rightarrow \text{binario}$ 
>- $(2) \rightarrow \text{intero}$
>- $(3) \rightarrow \text{binario rilassato}$
>- $(4) \rightarrow \text{intero rilassato}$

In questa lezione analizziamo un problema (quaderno) il tipo (4).

>[!defintion] Algoritmo dei rendimenti
>Il rendimento dei beni è pari al rapporto tra il valore $v_i$ e il peso $p_i$
>$$
>r_i = \frac{v_i}{p_i}
>$$
>Questo approccio è noto anche come _metodo Greedy_ (ingordo). L'idea è calcolare il rendimento ri​ di ogni oggetto e ordinarli in senso decrescente. Si riempie lo zaino partendo dagli oggetti con il rendimento più alto (che offrono più valore per ogni singolo chilo occupato) fino a esaurire lo spazio disponibile. _Attenzione Teorica:_ Questo algoritmo restituisce la soluzione ottima matematica assoluta **solo per le varianti rilassate** (es. tipo 3, in cui puoi riempire lo spazio rimanente tagliando a metà l'ultimo oggetto). Per il problema di tipo (1) binario, questo metodo fornisce solo una buona approssimazione (soluzione euristica). Per trovare l'ottimo globale esatto in un problema di Programmazione Lineare Intera (PLI) servono solitamente algoritmi di esplorazione ad albero, come il _Branch and Bound_.
