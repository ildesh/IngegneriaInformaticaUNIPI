(esercizi svolti sul simplesso - quaderno)

## Soluzioni ammissibili e non
$$
\text{Modello primale standard (P)}
\begin{cases}
\text{max } c^T \cdot x \\ Ax \le b
\end{cases}
\newline \ \ \ 
\text{Modello duale standard (D)}
\begin{cases}
\text{min } b^T \cdot y \\ A^Ty = C^T \\ y \ge 0 
\end{cases}
$$
Esistono 4 tipi di casi dati una base $B$:
1. Sol. ammissibile per entrambi i casi
2. Sol ammissibile per P e non per D $\rightarrow$ eseguo un altro passo
3. Non ammissibile per entrambi $\rightarrow$ cambio base
4. Sol. ammissibile per il D ma non per il P (ARGOMENTO DI OGGI)
---
## Simplesso Duale
$\overline{y}$ vertice di $D$ | $\overline{x}$ soluzione di base di A non rispettato

- $\underline{\text{Passo 1}}$ 
	$A_{\overline{x}} \overset{?}{\underset{\ge}{\le}} b$ ($\overline{Y_B},0$) con $\overline{Y_B} \ge 0$  
	Sia k il 1° vertice di riga di A non rispettato $\Rightarrow$ K indice entrante
	$A_kW^i$ è fissato e prendo solo $A_kW^i < 0$ 
	$$
	r_i \ = \frac{-\overline{y_i}}{A_kW^i} \ \ \ | \ \ \ A_kW^i < 0, \ \ i \in B
	$$ 
	il minimo di questi mi da l'indice uscente e può fare 0 se è degenere

---
