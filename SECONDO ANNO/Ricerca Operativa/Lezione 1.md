## 1. Struttura del Corso e Date

La ricerca operativa si divide in 4 parti:
1. **PL** (Programmazione Lineare)
2. **PLI** (Programmazione Lineare Intera)
3. **PL su "reti"**
4. **PNL** (Programmazione Non Lineare)

> [!NOTE]
> **Info sui Compitini:**
> *   **PRIMA PARTE:** PL e PLI (31 ottobre)
> *   **SECONDA PARTE:** PL su "reti" e PNL (metà dicembre)
> *   Se passo i compitini, c'è la possibilità di fare gli orali prima di dicembre, altrimenti a gennaio.

---
## 2. Che cos'è la Ricerca Operativa

Per descrivere che cos'è la ricerca operativa, partiamo da un caso pratico:
### Problema di Produzione
Un'azienda produce 2 tipi di prodotti con l'acciaio per l'edilizia (travi reticolari e pilastri compositi). La produzione richiede l'impiego di 3 risorse principali:
* Acciaio (materia prima)
* Lavorazione (taglio e saldatura)
* Collaudo e verniciatura
Di seguito la tabella con i requisiti unitari e la disponibilità massima delle risorse:

| Risorsa / Prodotto | Travi reticolari ($X_1$) | Pilastri compositi ($X_2$) | Disponibilità Totale |
|---|---|---|---|
| **Profitto / Valore unitario** | 300 | 200 | - |
| **Acciaio** (kg/unità) | 20 | 10 | 950 |
| **Lavorazione** (ore) | 2 | 3 | 120 |
| **Collaudo e Verniciatura** (ore) | 1 | 2 | 70 |

---
## 3. Terminologia Fondamentale

* **Ottimizzazione:** Comprende la ricerca di un massimo o di un minimo.
* **Vincolo nell'ottimizzazione:** Rappresenta la disponibilità limitata di risorse.
* **Variabili decisionali:** Servono a trasformare un problema concreto in un modello matematico. Sono le incognite del problema (rappresentano le scelte quantitative da prendere, es. quanto produrre).
* **Classificazione:** Riconoscere dalle variabili e dai dati se si può trattare di un problema di PL o PLI.

> [!TIP]
> **La domanda da porsi è:** *Quante variabili devo produrre?*
> Impostiamo il vettore $X = (x_1, x_2)$. 
> Possiamo testare un'ipotesi, ad esempio $X = (20, 20)$. 
> Bisogna controllare se questa soluzione è **ammissibile**.
> *Calcolo da fare (es. sull'acciaio):* $(20 \times 20) + (10 \times 20) = 400 + 200 = 600$. Poiché $600 \le 950$, la soluzione è ammissibile.

### Modello Matematico del Problema
Scriviamo la funzione obiettivo e il sistema sapendo queste terminologie:

$$
\begin{cases}
\max \ 300x_1 + 200x_2 = c_1x_1 + c_2x_2 = c^Tx & \text{(Funzione obiettivo)} \\
20x_1 + 10x_2 \le 950 & \text{(Vincolo disponibilità acciaio)} \\
2x_1 + 3x_2 \le 120 & \text{(Vincolo ore di lavorazione)} \\
x_1 + 2x_2 \le 70 & \text{(Vincolo ore di collaudo e verniciatura)} \\
x_1 \ge 0, x_2 \ge 0 & \text{(Vincoli di segno / non negatività)}
\end{cases}
$$

> [!IMPORTANT]
> **Regione di ammissibilità:** Tutta la parte del sistema contenente i vincoli (disponibilità acciaio, lavorazione, collaudo e vincoli di segno) è dichiarata con il termine di *regione di ammissibilità*. Essa rappresenta geometricamente l'insieme di tutte le soluzioni possibili.

---
## 4. Formalizzazione della Programmazione Lineare (PL)

> [!IMPORTANT]
> **Definizione:** Dicesi problema di PL, un problema di massimo o di minimo di una funzione lineare soggetta a vincoli lineari di $\le$, $\ge$ o $=$.

La **formula generale** (o forma matriciale compatta) di un problema di PL è:
$$
\begin{cases}
\max (\text{o } \min) \ Z = c^T x \\
Ax \le b \\
x \ge 0
\end{cases}
$$

### Scrittura Matriciale

> [!NOTE]
> Scrivere il problema tramite le matrici permette di isolare i coefficienti numerici dalle variabili. La moltiplicazione righe-per-colonne ricrea esattamente il sistema di equazioni:

$$
\underbrace{
\begin{bmatrix}
20 & 10 \\
2 & 3 \\
1 & 2 
\end{bmatrix}
}_{A}
\times
\underbrace{
\begin{bmatrix}
x_1 \\
x_2 
\end{bmatrix}
}_{x}
= 
\underbrace{
\begin{bmatrix}
20x_1 + 10x_2 \\
2x_1 + 3x_2 \\
x_1 + 2x_2 
\end{bmatrix}
}_{Ax}
\le
\underbrace{
\begin{bmatrix}
950 \\
120 \\
70
\end{bmatrix}
}_{b}
$$

---
## 5. Massimo vs Minimo e argmax/argmin

### Relazione tra Massimo e Minimo
Qualsiasi problema di massimizzazione può essere trasformato in un problema di minimizzazione (e viceversa) cambiando il segno della funzione obiettivo:
$$ \max f(x) = -\min(-f(x)) $$
### Significato di argmax e argmin

> [!IMPORTANT]
> Le funzioni **argmax** e **argmin** indicano i *valori delle variabili* che rendono una funzione rispettivamente massima o minima (la "ricetta"), non il risultato numerico finale.
> *   **$\max$ / $\min$** = Il risultato migliore possibile.
> *   **$\text{argmax}$ / $\text{argmin}$** = Le scelte da fare per ottenere quel risultato.

Nella Ricerca Operativa si cerca l'**argmax** (il piano d'azione ottimale). Il punto di ottimo obbedisce a questa relazione:
$$ \bar{x} \in \text{argmax } f(x) \iff \bar{x} \in \text{argmin }(-f(x)) $$
Ciò significa che le quantità esatte da produrre per massimizzare i profitti sono le stesse che minimizzerebbero l'opposto dei profitti (le perdite).

---
## 6. Esercizi ed Estrazione delle Matrici

### Esercizio 1 (Conversione in Forma Standard)
Dato il seguente modello:
$$
\begin{cases}
\max \ x_1 - 2x_2 + 3x_3 \\ 
6x_1 - 7x_3 \le 9 \\ 
x_1 + 4x_2 + 5x_3 \ge 8
\end{cases}
$$

> [!WARNING]
> **Regola di conversione:** Per riportare tutto alla forma matriciale standard $Ax \le b$, i vincoli con il segno $\ge$ devono essere capovolti moltiplicando tutta la disequazione per $-1$. Il secondo vincolo diventa quindi: $-x_1 - 4x_2 - 5x_3 \le -8$.

*   **Vettore dei costi ($c^T$):** $c^T = \begin{bmatrix} 1 & -2 & 3 \end{bmatrix}$
*   **Matrice dei coefficienti ($A$):** *(Nota: $x_2$ manca nel primo vincolo, vale 0)*:  $A = \begin{bmatrix} 6 & 0 & -7 \\ -1 & -4 & -5 \end{bmatrix}$
*   **Vettore dei termini noti ($b$):** $b = \begin{bmatrix} 9 \\ -8 \end{bmatrix}$
### Esercizio 2 (Problema di Minimizzazione)
Dato il seguente modello:
$$
\begin{cases}
\min \ 5x_1 - 6x_2 \\
4x_1 + 6x_2 \le 9 \\
2x_1 - 6x_2 \le 8 \\
x_1 \ge 0 \\
x_2 \ge 0
\end{cases}
$$
Estrazione delle matrici (in questo caso i vincoli sono già tutti in forma $\le$):
*   **Vettore dei costi ($c^T$):** $c^T = \begin{bmatrix} 5 & -6 \end{bmatrix}$
*   **Matrice dei coefficienti ($A$):** $A = \begin{bmatrix} 4 & 6 \\ 2 & -6 \end{bmatrix}$
*   **Vettore dei termini noti ($b$):** $b = \begin{bmatrix} 9 \\ 8 \end{bmatrix}$