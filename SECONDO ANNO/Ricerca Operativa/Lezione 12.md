# Problema lineare intero (P.L.I.)
La P.L.I. è un problema di ottimizzazione matematica in cui la funzione obiettivo e i vincoli sono lineari, e alle variabili decisionali viene imposto di assumere **valori interi**
$$
\begin{cases}
\text{max }C^Tx \\
Ax \le b \\
x \in \mathbb{Z}^n
\end{cases}
$$
## Problema di PLI in formato standard
Il formato standard di un problema di PLI richiede che tutti i vincoli siano espressi come equazioni (uguaglianze) e che tutte le variabili siano vincolate in segno (non negative):
$$\begin{cases} \text{max } C^T x \\ Ax = b \\ x \ge 0 \\ x \in \mathbb{Z}^n \end{cases}$$
Questo si ottiene introducendo variabili di scarto o surplus. Se i coefficienti di $A$ e $b$ sono interi, anche le variabili introdotte devono essere intere e non negative.

Dato un problema di PLI, il problema di PL che si ottiene eliminando i vincoli di interezza si chiama ***rilassato continuo***:
$$
\begin{cases}
\text{max }C^Tx \\
Ax \le b \\
x \in \mathbb{Z}^n
\end{cases}
\le
\begin{cases}
\text{max }C^Tx \\
Ax \le b \\
\end{cases}
$$
ovvero: $v_{pli} \le v_{pl} = V_S \ (\text{valutazione superiore o upper bound})$
La valutazione superiore è una stima per eccesso del **valore ottimo del problema originario (intero)**.

>[!warning]
>Non esiste un algoritmo autonomo diretto per la PLI
## Problema della stima nella PLI
Nei problemi di Programmazione Lineare Intera (PLI) di massimizzazione, l'insieme ammissibile è discreto e non possiamo utilizzare direttamente gli algoritmi continui come il Simplesso.

Per risolvere o stimare l'ottimo di un problema di PLI, la strategia fondamentale consiste nell'**intrappolare** il valore ottimo incognito $v_{pli}$ all'interno di un intervallo delimitato da due stime:
$$V_I \le v_{pli} \le V_S$$
- **$V_S$ (Valutazione Superiore o Upper Bound):** Rappresenta una stima _per eccesso_. Nel caso di massimizzazione, si ottiene risolvendo il **rilassato continuo** (eliminando il vincolo $x \in \mathbb{Z}^n$):
$$V_S = v_{pl} \ge v_{pli}$$
	- Poiché allarghiamo l'insieme ammissibile permettendo anche soluzioni frazionarie, il valore ottimo non può peggiorare rispetto all'intero.
	- Nel caso del minimo è pari a $C^T\overline{x}$ e $V_{pl}$ è pari a $V_I$
- **$V_I$ (Valutazione Inferiore o Lower Bound):** Rappresenta una stima _per difetto_. È il valore della funzione obiettivo fornito da una **qualsiasi soluzione ammissibile intera** per il problema originario.
	- Nel caso del massimo è pari a $C^T\overline{x}$
---
# Concetto di GAP di ottimalità
La differenza tra la stima superiore e quella inferiore definisce il cosiddetto **Gap di ottimalità**:
$$\text{Gap} = V_S - V_I$$
(spesso espresso in percentuale come $\frac{V_S - V_I}{V_I}$).
- Se $V_I = V_S$, allora il gap è zero: la soluzione intera trovata è matematicamente l'**ottimo globale** ($v_{pli} = V_I = V_S$).
- Finché $V_I < V_S$, il gap misura l'incertezza massima sul valore ottimo intero che non conosciamo ancora esattamente.
---
# Definizione dell'insieme $S$

Nei problemi di PLI, non possiamo muoverci su un'area continua, ma solo su punti interi. Chiamiamo **$S$** l'insieme di tutte le **soluzioni ammissibili intere** del nostro problema:
$$S = \{x \in \mathbb{Z}^n \mid Ax \le b\}$$
Questo insieme $S$ non è un poliedro continuo, ma una "nuvola" di punti discreti isolati.
1. **L'Inviluppo Convesso $conv(S)$**: Richiamando il Teorema di Weyl e la definizione di combinazione convessa che hai nei tuoi appunti, possiamo prendere tutti i punti isolati dell'insieme $S$ e costruire il loro **inviluppo convesso**, indicato con **$conv(S)$**. Geometricamente, $conv(S)$ è il più piccolo poliedro continuo che racchiude tutti i punti interi ammissibili di $S$ (immagina di avvolgere la nuvola di punti con una pellicola trasparente tesa). La proprietà fondamentale di questo nuovo poliedro $conv(S)$ è che **tutti i suoi vertici sono punti interi** appartenenti a $S$.

Il Teorema Fondamentale della PL garantisce che, se un problema ammette una soluzione ottima finita, questa **si trova sempre in almeno un vertice del poliedro**.

2.**La Conclusione: $V_{PLI} = V_{conv(S)}$**: A questo punto, i pezzi del puzzle si uniscono:
- Se calcoliamo il massimo della funzione obiettivo $c^T x$ muovendoci _solo_ sui punti discreti interi $S$, otteniamo il valore ottimo intero **$V_{PLI}$**.
- Se invece "rilassiamo" il problema e calcoliamo il massimo della stessa funzione obiettivo sul poliedro continuo **$conv(S)$**, il Teorema Fondamentale della PL ci assicura che il Simplesso troverà l'ottimo in uno dei vertici di $conv(S)$.
- Poiché tutti i vertici di $conv(S)$ sono punti interi di $S$, la soluzione ottima continua su $conv(S)$ coinciderà esattamente con la soluzione ottima intera!
	Da qui nasce l'identità:
$$V_{PLI} = V_{conv(S)}$$
---
# Teorema di equivalenza tra PL e PLI e il ruolo di conv(S)
Il teorema stabilisce formalmente che se l'insieme ammissibile $S$ di un problema di PLI è limitato e non vuoto, il problema originale è matematicamente ed esattamente equivalente al problema di Programmazione Lineare continua sull'inviluppo convesso di S: $\text{max } \{C^T x \mid x \in S\} \equiv \text{max } \{C^T x \mid x \in conv(S)\}$ (Nella pratica non risolviamo questo problema equivalente con algoritmi per poliedri continui perché i vincoli per descrivere esplicitamente $conv(S)$ crescono in modo esponenziale).
## Algoritmi di rendimento

1. L'ottimo del rilassato continuosi trova sostituendolo con il bene di massimo rendimento
	- $r_i = \frac{v_i}{p_i}$ 
2. Metto il maggior numero possibile di elementi di rendimento massimo finché lo spazio disponibile nello zaino non si esaurisce. 
	- Se si tratta del problema rilassato (continuo), lo spazio rimanente viene riempito inserendo una frazione esatta dell'oggetto successivo in ordine di convenienza, garantendo così l'ottimo globale del rilassato (la Valutazione Superiore, $V_S$). 
	- Nel problema intero o binario, invece, si prosegue inserendo solo oggetti interi finché c'è capienza: questo fornisce rapidamente una soluzione ammissibile (una Valutazione Inferiore, $V_I$), ma non garantisce di aver trovato l'ottimo assoluto.
## Il problema dello zaino binario: Modello matematico
Dato uno zaino di capacità $P$ e $n$ oggetti con valore $v_i$ e peso $p_i$, la variabile decisionale è $x_i \in \{0, 1\}$ ($x_i=1$ se inserito, $0$ se non inserito). Il modello è:

$$\begin{cases} \text{max } \sum_{i=1}^{n} v_i x_i \\ \sum_{i=1}^{n} p_i x_i \le P \\ x_i \in \{0, 1\} \quad \forall i = 1, \dots, n \end{cases}$$
## Tecniche "greedy" e valutazioni $V_S$ / $V_I$ per lo zaino
Dopo aver ordinato gli oggetti per rendimento decrescente:

- **Soluzione del rilassamento continuo ($V_S$):** L'oggetto che sfora la capacità viene inserito in frazione esatta ($x_k = \frac{\text{Spazio residuo}}{p_k}$). Questo valore totale è $V_S$ (che se decimale, si arrotonda per difetto all'intero).
- **Ricerca di soluzioni ammissibili ($V_I$):** L'oggetto che sfora viene saltato ($x_k = 0$) e si procede scorrendo la lista per riempire lo spazio rimasto con oggetti interi più piccoli. Questo valore totale fornisce il $V_I$.

***Arrotondamento euristico***: Consiste nel calcolare prima la soluzione ottima del problema rilassato continuo (accettando valori frazionari) per poi arrotondare le coordinate all'intero più vicino. Fornisce un $V_I$ immediato solo nel caso fortunato in cui il punto risultante rispetti ancora tutti i vincoli. Spesso si rivela fallimentare perché l'arrotondamento fa cadere la soluzione al di fuori della regione ammissibile, violando le limitazioni del problema.
***Algoritmo Branch and Bound***: È l'algoritmo di esplorazione ad albero utilizzato per trovare l'ottimo globale esatto nella Programmazione Lineare Intera (PLI). Divide progressivamente lo spazio delle soluzioni imponendo vincoli di interezza stringenti. In ogni nodo valuta il limite superiore continuo: se questo risulta peggiore di una soluzione intera ammissibile già individuata ($V_I$), l'algoritmo effettua una potatura ("pruning") di quel ramo, interrompendone l'esplorazione.