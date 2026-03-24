## Esercizi sulle relazioni di ricorrenza

>[!WARNING]
> Nello studio della complessità degli algoritmi, utilizziamo diverse notazioni per separare il tempo che un algoritmo impiega dal risultato che produce. 
>
>* **$n$**: Rappresenta la **dimensione dell'input**. È il parametro rispetto al quale misuriamo come cresce il tempo di esecuzione o il valore calcolato.
>* **$T(n)$ (Tempo / Costo Computazionale)**: Indica il tempo di esecuzione di un blocco di codice in funzione di $n$. 
  >* $T_{main}$ è il tempo totale del programma principale.
  >* $T_f(n)$ o $T_F(n)$ è il tempo impiegato unicamente dalla funzione $f$ per arrivare a conclusione.
>* **$R_f(n)$ (Return Value / Valore di Ritorno)**: Indica il **valore matematico** restituito dalla funzione $f$ al termine della sua esecuzione. È fondamentale calcolarlo quando il risultato di una funzione viene usato come limite per un ciclo (es. `i <= f(n)`).
>* **$g_{while}$ / $g_{for}$ (Guardia del ciclo)**: Rappresenta il numero di volte in cui viene valutata la condizione (guardia) di un ciclo, che è approssimativamente uguale al numero di iterazioni del ciclo stesso.
>* **$O(...)$ (O-Grande)**: È la notazione asintotica che descrive il **limite superiore** della crescita di una funzione. Ci dice, nel caso peggiore, come scala il tempo (o lo spazio) all'aumentare di $n$ (es. lineare $O(n)$, quadratico $O(n^2)$, logaritmico $O(\log n)$).
>* **$\Theta(...)$ (Theta-Grande)**: Simile a O-Grande, ma indica un limite **stretto** (sia superiore che inferiore). Quando scriviamo $\Theta(n)$, significa che la funzione cresce *esattamente* in modo proporzionale a $n$.
### Esercizio 1

>[!NOTE] A seguito del codice trovare: $T_{main} = T_{g(n)} \space x \space g_{while}$
>```cpp
>i = 1;
>while(i <= f(n)){
>	a = a*a;
>	i = i+1;
>}
>
>int f(int n){
>	if(n == 1) return 1;
>	else return n+f(n-1);
>}
>```

1. Troviamo la nostra $T_{f(n)}$;
$$
T_{f(n)} =\begin{cases}
c & n == 1\\
d + T_f(n-1)
\end{cases}
$$
	Possiamo dire che avrà una complessità $O(n)$ perché ad ogni chiamata, la funzione esegue un numero costante di operazioni $O(1)$, per il controllo if e una somma, poi richiama se stessa passado $n - 1$
	
2. Ricaviamo anche la $R_{f(n)}$

$$
R_{f(n)} =\begin{cases}
1 & n == 1\\
n + R_{f(n-1)}
\end{cases}
$$
	Invece qui si avrà una complessità $O(n^2)$ perché sviluppando questa ricorrenza, ci accorgiamo che calcola esattamente la somma dei primi n numeri naturali con la seguente formula: $R_{f(n)} = \sum_{k=1}^{n} k = \frac{n(n+1)}{2}$. In termini di complessità, il valore restituito cresce in modo quadratico e quindi vale come abbiamo detto in precedenza.
	
Il prodotto finale tra questi due quindi è pari a:
$$
T_{main} = O(n)\space x \space O(n^2) = O(n^3)
$$
---
### Esercizio 2
>[!NOTE] A seguito del codice calcolare: $T_{main} = T_{f(n)} + g_{for}$
>```cpp
> int main(){
> 	int i = F(n);
> 	for(int j = 1; j <= i; j++){
> 		 a+=b;
> 	}
>}
>
>int F(int x){
>	if(x==1) return 1;
>	else return 1+2*F(x-1); 
>}
>```

1. Per sapere quante iterazioni farà il ciclo for, dobbiamo prima scoprire qual'è il valore esatto restituito da $F(n)$. Troviamo $R_{f(n)}$:
$$
R_F(n) = \begin{cases}  1 & \text{se } n = 1 \\  1 + 2 R_{F(n-1)}& \text{se } n > 1  \end{cases}
$$

	Svolgendo questa ricorrenza, i valori restituito sono 1, 3, 7, 15. E quindi il valore restituito cresce in modo esponenziale, quindi $R_{F(n)} = O(2^n)$.

2. Ora calcoliamo quanto tempo ci mette $F(n)$ a calcolare questo numero gigantesco. Troviamo quindi $T_{F(n)}$:

$$
T_{F(n)} = \begin{cases}  O(1) & \text{se } n = 1 \\  T_F(n-1) + O(1) & \text{se } n > 1  \end{cases}
$$

	Anche se il valore restituito è esponenziali, la funzione si richiama semplicemente n volte (_con decremento di 1 ad ogni passo_), eseguendo operazioni di costo costante in ogni chiamata. Quindi il tempo impiegato per eseguire la funzione è pari a: $T_{F(n)} = O(n)$.

In conclusione la nostra somma $T_{main} = T_{f(n)} + g_{for}$ sarà pari a:
$$
T_{main} = O(n) + O(2^n) = O(2^n)
$$
---
### Esercizio 3
​
>[!NOTE] A seguito del codice trovare: $T_{main}(n) = T_{f}(n) \space x \space g_{for}$
>
>```cpp
>for (int j=1; j<=F(n)*F(n); j++){
>	a+=F(n);
>}
>int F(int x){
>	if(x<=2) return 1;
>	else return 3+3*F(x/3);
>}
>```

Per risolvere il seguente esercizio dobbiamo utilizzare il **_Master Theorem_** per risolvere le equazioni di ricorrenza.

>[!IMPORTANT] Che cos'è il **_Master Theorem_** e perché dobbiamo utilizzarlo qui?
> ​Il **Master Theorem** (o Teorema Principale / Metodo dell'Esperto) è una "ricetta matematica" preconfezionata che permette di risolvere istantaneamente un tipo molto specifico di **equazioni di ricorrenza**.
> Serve per calcolare la complessità di algoritmi basati sulla tecnica del _Divide et Impera_ (Divide and Conquer), dove un problema viene spezzato in sotto-problemi più piccoli.
>
>Si applica **solo** quando l'equazione di ricorrenza ha questa forma esatta:
> $$ T(n) = a \cdot T\left(\frac{n}{b}\right) + \Theta(n^k) $$
> Dove:
>- ​**a**: è il numero di chiamate ricorsive che la funzione fa al suo interno (quanti sotto-problemi genera).
>- ​**b**: è il fattore per cui l'input n viene **diviso** a ogni passo.
>- ​**k**: rappresenta l'esponente del costo delle operazioni extra fatte fuori dalla ricorsione.
> A seconda del rapporto tra a, b e k, il teorema offre tre "Casi" (tre formule già pronte) che ti danno immediatamente la complessità O(...) senza dover fare lunghi calcoli.
> 
> Qui lo usiamo perché la funzione ricorsiva faceva $F(n/3)$. L'input veniva ridotto tramite **divisione**. Le equazioni erano del tipo $T_f(n) = T_f(n/3) + c$.
> In questo caso l'input viene frazionato geometricamente ad ogni passo, creando un albero di chiamate con profondità logaritmica. Invece di calcolare a mano la somma di tutti i nodi di questo albero, applichiamo il Master Theorem e otteniamo subito la risposta in base al valore di $\log_b a$.

1. Per calcolare il tempo di esecuzione della funzione ricorsiva F(n), scriviamo l'equazione di ricorrenza. Ad ogni chiamata, la funzione esegue operazioni costanti O(1) e richiama se stessa dividendo l'input per 3.

$$
T_{f(n)} = \begin{cases}  c & \text{se } n \le 2 \\  d + T_f(n/3) & \text{se } n > 2  \end{cases}
$$
	Possiamo risolvere questa ricorrenza con il **Master Theorem**: $T(n) = aT(n/b) + \Theta(n^k)$.
	- ​a = 1 (numero di chiamate ricorsive)
	- ​b = 3 (fattore di divisione dell'input)
	- ​k = 0 (poiché il costo extra è una costante $d = \Theta(n^0)$)
	Calcoliamo il $log_ba$: $log_31 = 0$.

	Poiché $log_b a = k$ (cioè 0 = 0), ci troviamo nel **Caso 2** del Master Theorem. La complessità è data da $\Theta(n^k \log n) = T_f(n) = O(log(n))$.

2. Adesso determiniamo quanto vale il numero restituito da F(n). Scriviamo l'equazione di ricorrenza per il valore di ritorno:

$$
R_{f(n)} = \begin{cases}  1 & \text{se } n \le 2 \\  3 + 3 R_f(n/3) & \text{se } n > 2  \end{cases}
$$
	Applichiamo di nuovo il **Master Theorem**:
	- ​a = 3 (il valore restituito dalla ricorsione viene moltiplicato per 3)
	- ​b = 3 (l'input viene diviso per 3)
	- ​k = 0 (il termine da sommare è la costante 3 = $\Theta(n^0))$
	​Calcoliamo $log_b a$: $log_33 = 1$.
	Poiché $log_b a > k$ (cioè 1 > 0), ci troviamo nel **Caso 1** del Master Theorem. La complessità è dominata dalle foglie dell'albero di ricorsione, ed è data da $\Theta(n^{\log_b a}) = R_{f(n)} = O(n^1) = O(n)$

3. Calcoliamo la complessità del $T_{main}(n) = T_{f}(n) \space x \space g_{for}$
	Essendo che la $g_{for}$ è un ciclo che si ripete finchè $j \le F(n) \times F(n)$, allora sappiamo che $F(n)$ restituisce un valore asintotico di $O(n)$. 
	- Risultato: $g_{for} = O(n^2)$
	Riguardo a $T_{f(n)}$ possiamo dire che ad ogni iterazione, la guardia del ciclo valuta $F(n) \times F(n)$ e il corpo esegue $a+=F(n)$. L'operazione più costosa che viene ripetuta a ogni singolo giro è proprio la chiamata alla funzione $F(n)$, che abbiamo mostrato che costa $O(log(n)$.

Unendo i risultati otteniamo la complessità finale che risulta essere: 
$$
T_{main}(n) = O(\log n) \times O(n^2) = O(n^2 \log n)
$$
---
