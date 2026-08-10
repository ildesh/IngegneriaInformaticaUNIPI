### 1. TEORIA E DEFINIZIONI CHIAVE

#### Limiti e continuità in più variabili

In una variabile avevamo solo due direzioni (destra e sinistra). In $\mathbb{R}^2$, ci si può avvicinare all'origine muovendosi su infinite rette, parabole o spirali.

- **Per dimostrare la NON-esistenza:** Basta trovare due curve passanti per il punto (es. $y=mx$ e $y=x^2$) lungo le quali la restrizione della funzione ha limiti diversi.
- **Per dimostrare l'esistenza:** Le direzioni non bastano. Dobbiamo usare il **Teorema dei Carabinieri** impostando una stima dall'alto e dal basso: $0 \le |f(x,y) - L| \le g(x,y)$, dove $g(x,y) \to 0$. Molto utile è il passaggio in **coordinate polari** $x = \rho \cos\theta, y = \rho \sin\theta$. Il limite esiste se la stima radiale tende a 0 in modo _uniforme_ rispetto a $\theta$ (cioè limitando la dipendenza da $\theta$ con costanti assolute).

#### Differenziabilità, piano tangente e gradiente

Una funzione si dice **differenziabile** se ammette un'approssimazione lineare (un piano tangente) nel punto. L'esistenza delle derivate parziali non basta (è una condizione troppo debole sui soli assi).

Il **piano tangente** in $(x_0, y_0)$ ha equazione:

$$z = f(x_0, y_0) + \nabla f(x_0, y_0) \cdot (x-x_0, y-y_0)$$

Il **Gradiente** $\nabla f$ ha un significato geometrico vitale: indica la direzione di **massima pendenza** della funzione. . Se mi muovo ortogonalmente al gradiente, sto camminando su una curva di livello (pendenza nulla). Questo si calcola:

$${\displaystyle \nabla =\left(\frac {\partial f }{\partial x},\frac {\partial f }{\partial y}\right)}$$
#### Ottimizzazione su compatti (Teorema di Weierstrass)

Se $f$ è continua e l'insieme $K$ è compatto (chiuso e limitato), **Weierstrass garantisce** l'esistenza di massimi e minimi assoluti.

I candidati punti di max/min si cercano in 3 categorie:

1. **Punti stazionari interni:** dove $\nabla f = 0$.
2. **Punti singolari interni:** dove $f$ non è differenziabile (punte, spigoli).
3. **Punti sul Bordo:** da studiare con parametrizzazione o Moltiplicatori.
#### Metodo dei Moltiplicatori di Lagrange

Serve per cercare max/min su un vincolo descritto dall'equazione $g(x,y)=0$. Geometricamente, stiamo cercando i punti in cui le curve di livello di $f$ sono tangenti al vincolo $g$. .

Si risolvono **sempre** due sistemi:

- **1° Sistema (Punti singolari del vincolo):**
    
    $\begin{cases} \nabla g(x,y) = 0 \\ g(x,y) = 0 \end{cases}$  (Cerca i punti in cui il vincolo non è una bella curva, ma ha spigoli o auto-intersezioni).
    
- **2° Sistema (Moltiplicatori veri e propri):**
    
    $\begin{cases} \nabla f(x,y) = \lambda \nabla g(x,y) \\ g(x,y) = 0 \end{cases}$
#### Bordo dei bordi ("Punti di taglio")

Quando il dominio è, ad esempio, un quadrato o un semicerchio, il bordo è fatto da più "pezzi" regolari. I punti in cui questi pezzi si incollano (i vertici del quadrato, o gli estremi del diametro del semicerchio) sono il _bordo del bordo_. Vanno sempre valutati a parte inserendoli nella lista dei candidati.

#### Limiti all'infinito e Weierstrass Generalizzato

Se il dominio non è limitato (es. tutto $\mathbb{R}^2$), Weierstrass salta. Tuttavia, se dimostriamo che $\lim_{x^2+y^2 \to +\infty} f(x,y) = +\infty$ (funzione coerciva), significa che all'infinito la funzione "va su". Di conseguenza, il **minimo globale esiste per forza**, e lo troveremo tra i punti stazionari al finito.

### 2. TRUCCHI DEL MESTIERE ("BRUTALMENTE")

- **Come indovinare se un limite in (0,0) esiste (Conta degli esponenti):**
    
    1. Se $f(x,y)$ è un rapporto di polinomi, contate il grado del numeratore e del denominatore.
    
    2. Se $Grado(Num) > Grado(Den)$, il limite fa 0.
    
    3. Se $Grado(Num) = Grado(Den)$, il limite dipende dalla direzione (non esiste).
    
    4. Se $Grado(Num) < Grado(Den)$, il limite esplode (o non esiste).
    
    _Attenzione ai pesi sbilanciati_: in $\frac {x^2} {(x^4 + y^2)}$, $x$ conta come $\sqrt{y}$ (peso 1), $y$ conta come $x^2$ (peso 2). In questo caso $x^4$ e $y^2$ hanno entrambi peso 4, il numeratore ha $x^2$ (peso 2). Quindi vince il sotto, il limite esplode.
    
- **Gestire i sistemi di Lagrange:**
    
    Non ricavate mai $\lambda$ dividendo per una variabile se prima non avete fatto il caso in cui quella variabile sia zero! Usate sempre la struttura ad albero:
    "Caso $x=0$ $\to$ ... " e "Caso $x \neq 0$, allora posso dividere e ottengo $\lambda = ...$".
    Sfruttate le simmetrie: sottraendo le equazioni spesso emerge $(x-y)(qualcosa) = 0$, portando ai casi $x=y$ o all'annullamento del termine tra parentesi.
    

### 3. ESEMPI SVOLTI PASSO-PASSO

#### Esempio 1: Limite ambiguo e stime

Calcoliamo:

$$\lim_{(x,y)\to(0,0)} \frac{x^2 y}{x^4 + y^2}$$

_Brutalmente:_ il peso al denominatore è misto. Poniamo che $y$ abbia peso "2" (perché $y^2$ si sommi in modo omogeneo a $x^4$). Il numeratore ha peso $2+2=4$. Il denominatore ha peso 4. Pareggio. **Il limite non esiste**.

_Dimostrazione rigorosa:_

Sulla retta $y=mx$: $\frac{x^2(mx)}{x^4 + m^2 x^2} = \frac{m x^3}{x^2(x^2 + m^2)} = \frac{mx}{x^2+m^2} \to 0$.

Sembra 0? Proviamo la parabola $y=x^2$:

$$f(x,x^2) = \frac{x^2 \cdot x^2}{x^4 + (x^2)^2} = \frac{x^4}{2x^4} = \frac{1}{2}$$

Esistono due percorsi con limiti diversi ($0 \neq 1/2$). **Il limite non esiste.**

Se invece fosse stato $f(x,y) = \frac{x^3 y}{x^4 + y^2}$, per la disuguaglianza $x^2 y \le \frac{1}{2}(x^4 + y^2)$ (che segue da $(x^2-y)^2 \ge 0$), avremmo:

$$|f(x,y)| = |x| \frac{x^2 |y|}{x^4+y^2} \le |x| \frac{1}{2} \to 0$$

Per i carabinieri, il limite è 0.

#### Esempio 2: Ottimizzazione su un semidisco (Gestione del Bordo e Bordo dei Bordi)

Massimizzare e minimizzare $f(x,y) = x+y$ sull'insieme $D = \{ (x,y) \in \mathbb{R}^2 \mid x^2+y^2 \le 1, y \ge 0 \}$.

Il dominio è un semicerchio superiore. È chiuso e limitato. Weierstrass si applica.

1. **Punti interni:** $\nabla f = (1,1) = (0,0)$ impossibile. Nessun candidato interno.
2. **Bordo 1 (il diametro):** Lo parametrizzo banalmente: $y=0$, con $x \in [-1, 1]$.
    Studio $h(x) = f(x,0) = x$ per $x \in [-1,1]$.
    
    Candidati: $x=1 \implies P_1 = (1,0)$ con valore $1$. E $x=-1 \implies P_2 = (-1,0)$ con valore $-1$.
    
3. **Bordo 2 (l'arco di circonferenza):** Uso Lagrange con vincolo $g(x,y) = x^2+y^2-1=0$, solo per $y > 0$.
    _1° sistema:_ $\nabla g = (2x, 2y) = (0,0) \implies (0,0)$, ma non sta sul vincolo.
    _2° sistema:_
    
    $\begin{cases} 1 = 2\lambda x \\ 1 = 2\lambda y \\ x^2+y^2=1 \end{cases}$
    
    Dalle prime due ricavo $2\lambda x = 2\lambda y \implies \lambda(x-y)=0$.
    Se $\lambda=0$, la prima equazione diventa $1=0$ (impossibile).
    Quindi $x=y$. Sostituisco nel vincolo: $2x^2 = 1 \implies x = \pm \frac{\sqrt{2}}{2}$.
    Poiché siamo sul semidisco superiore ($y \ge 0$), il candidato valido è $P_3 = (\frac{\sqrt{2}}{2}, \frac{\sqrt{2}}{2})$ con valore $f(P_3) = \sqrt{2}$.
    
4. **Bordo dei bordi:** I punti dove il diametro e l'arco si incontrano sono $(1,0)$ e $(-1,0)$. Li abbiamo già trovati e calcolati, ma se non l'avessimo fatto parametrizzando il diametro, avremmo dovuto inserirli manualmente!


Confronto i valori: $f(P_1)=1$, $f(P_2)=-1$, $f(P_3)=\sqrt{2}$.

**Massimo globale:** $\sqrt{2}$. **Minimo globale:** $-1$.

#### Esempio 3: Weierstrass Generalizzato su insieme non compatto

Studiare $f(x,y) = x^2 + y^2 - xy - x$ su tutto $\mathbb{R}^2$.

Non è compatto. Però proviamo a scrivere in coordinate polari o a usare trucchi algebrici sulla parte di grado massimo ($x^2+y^2-xy$):

$$x^2 + y^2 - xy = \frac{1}{2}(x^2+y^2) + \frac{1}{2}(x-y)^2 \ge \frac{1}{2}(x^2+y^2) = \frac{1}{2}\rho^2$$

Quindi, per $\rho \to +\infty$:

$$f(x,y) \ge \frac{1}{2}\rho^2 - \rho \to +\infty$$

La funzione è coerciva. Per il Teorema di Weierstrass Generalizzato, $f$ ammette **minimo assoluto** (mentre il sup è chiaramente $+\infty$).

Cerchiamolo! L'unico posto dove può nascondersi è tra i punti stazionari:

$\nabla f = (2x-y-1, 2y-x) = (0,0)$.

Dal sistema:

$\begin{cases} 2x-y = 1 \\ -x+2y = 0 \implies x = 2y \end{cases} \implies 4y - y = 1 \implies 3y = 1 \implies y = 1/3, x = 2/3$.

L'unico punto critico è $(2/3, 1/3)$. Poiché il minimo globale deve esistere per W.G., e questo è l'unico candidato, esso **è per forza il punto di minimo assoluto**.