### 1. TEORIA E DEFINIZIONI CHIAVE

#### Derivate successive, Teorema di Schwarz e Matrice Hessiana

Quando deriviamo due volte una funzione $f(x,y)$, otteniamo quattro derivate parziali seconde. Il **Teorema di Schwarz** ci assicura che, se queste sono continue, l'ordine di derivazione non conta: $f_{xy} = f_{yx}$.

Questo ci permette di costruire la **Matrice Hessiana** $H_f(x_0, y_0)$, che è simmetrica.

Per classificare i punti stazionari ($\nabla f = 0$), guardiamo la **segnatura degli autovalori** dell'Hessiana:

- Tutti autovalori $> 0$ (o $\det H > 0, f_{xx} > 0$): **Minimo locale**.
- Tutti autovalori $< 0$ (o $\det H > 0, f_{xx} < 0$): **Massimo locale**.
- Autovalori con segni discordi ($\det H < 0$): **Punto di Sella** .
- Autovalori nulli ($\det H = 0$): **Caso Degenere**. L'Hessiano non decide. Serve uno studio locale.

#### Formula di Taylor in più variabili e Hessiano Degenere

La formula di Taylor con centro nel punto stazionario $(x_0, y_0)$ si scrive come:

$$f(x,y) = f(x_0, y_0) + \frac{1}{2} (x-x_0, y-y_0) H_f(x_0,y_0) \begin{pmatrix} x-x_0 \\ y-y_0 \end{pmatrix} + o(||\mathbf{h}||^2)$$

Spesso non serve calcolare decine di derivate: per sviluppare $f(x,y)$ basta sostituire i monomi negli sviluppi di Maclaurin noti di Analisi 1: $$e^x = 1 + x + \frac{x^2}{2!} + \frac{x^3}{3!} + \dots$$$$\sin(x) = x - \frac{x^3}{3!} + \frac{x^5}{5!} - \dots$$$$\cos(x) = 1 - \frac{x^2}{2!} + \frac{x^4}{4!} - \dots$$$$\ln(1+x) = x - \frac{x^2}{2} + \frac{x^3}{3} - \dots$$ $$\frac{1}{1-x} = 1 + x + x^2 + x^3 + \dots$$ $$\arctan(x) = x - \frac{x^3}{3} + \frac{x^5}{5} - \dots$$$$(1+x)^\alpha = 1 + \alpha x + \frac{\alpha(\alpha-1)}{2!} x^2 + \dots$$

Se l'Hessiano è degenere, lo sviluppo di Taylor di ordine superiore o lo **studio del segno della funzione** $\Delta f = f(x,y) - f(x_0, y_0)$ ci dirà la natura del punto (vedremo come nell'Esempio 1).

#### Funzioni vettoriali e Chain Rule

Quando abbiamo una funzione $F: \mathbb{R}^n \to \mathbb{R}^m$, la generalizzazione della derivata è la **Matrice Jacobiana** $J_F$, una matrice $m \times n$ le cui righe sono i gradienti delle singole componenti.
La **Chain Rule** (regola della catena) per funzioni composte $H(x) = F(G(x))$ si traduce nel prodotto riga per colonna delle matrici Jacobiane: $J_H(x) = J_F(G(x)) \cdot J_G(x)$.

#### Integrali multipli: Riduzione e Domini

L'integrale doppio o triplo di Riemann rappresenta rispettivamente il volume sotto una superficie o l'ipervolume/massa di un solido. Si calcola riducendolo a integrali 1D annidati.

- **Integrazione per colonne (fili):** Si fissa un punto sulla base (dominio 2D) e si integra la quota $z$ tra un "pavimento" e un "soffitto".
- **Integrazione per sezioni (strati):** Si fissa la quota $z$ e si integra sull'area della "fetta" orizzontale tagliata dal piano $z=costante$.

#### Cambi di variabile e il "Pagamento" (Determinante Jacobiano)

Se le coordinate cartesiane complicano il dominio, si cambia mappa: $(x,y) \to (u,v)$. Ma attenzione, l'area/volume si deforma! Bisogna moltiplicare per il valore assoluto del **Determinante della Matrice Jacobiana** del cambio di coordinate. Questo è il "pagamento" per la semplificazione.

- **Polari (2D):** $x = \rho\cos\theta, y = \rho\sin\theta$. Pagamento: $\rho$.
- **Cilindriche (3D):** $x = \rho\cos\theta, y = \rho\sin\theta, z = z$. Pagamento: $\rho$.
- **Sferiche (3D):** $x = r\sin\phi\cos\theta, y = r\sin\phi\sin\theta, z = r\cos\phi$. Pagamento: $r^2 \sin\phi$.

### 2. TRUCCHI DEL MESTIERE ("BRUTALMENTE")

- **L'occhio magico per le simmetrie:** Prima di integrare, guardate la funzione e il dominio. Se il dominio è simmetrico rispetto all'asse $x$ (se $(x,y) \in D$, allora anche $(x,-y) \in D$) e la funzione integranda è _dispari_ in $y$ (cioè $f(x,-y) = -f(x,y)$), l'integrale è **ZERO**. Fine dei calcoli. Risparmiate ore di conti.
- **Scelta tra Sezioni e Colonne (Integrali Tripli):** * Usate le **Colonne** se vedete chiaramente la proiezione del solido sul piano $xy$ e se il solido è delimitato in alto e in basso da grafici di funzioni del tipo $z=f(x,y)$.
    - Usate le **Sezioni** se il solido è un solido di rotazione (es. coni, sfere, paraboloidi ruotati attorno a $z$). Fissando $z$, la fetta è un cerchio perfetto, la cui area è banalmente $\pi R(z)^2$.

### 3. ESEMPI SVOLTI PASSO-PASSO

#### Esempio 1: Hessiano degenere e studio del segno locale

Sia $f(x,y) = x^2 y^3$. Troviamo e classifichiamo i punti stazionari.

Il gradiente è $\nabla f = (2xy^3, 3x^2y^2)$. Si annulla in tutti i punti sugli assi $x=0$ e $y=0$. Prendiamo l'origine $(0,0)$.

Costruiamo l'Hessiano in $(0,0)$.

$f_{xx} = 2y^3 \to 0$, $f_{yy} = 6x^2y \to 0$, $f_{xy} = 6xy^2 \to 0$. L'Hessiana è una matrice di zeri. È palesemente degenere ($\det = 0$).

_Come si procede?_ Valutiamo l'incremento $\Delta f = f(x,y) - f(0,0) = x^2 y^3$.

In ogni intorno dell'origine, il termine $x^2$ è sempre $\ge 0$. Il termine $y^3$ invece mantiene il segno di $y$. Quindi:

- Per $y > 0$, $\Delta f > 0$.
- Per $y < 0$, $\Delta f < 0$.
    In ogni palla centrata nell'origine esistono punti in cui la funzione "sale" e punti in cui "scende". L'origine è un **punto di sella**.

#### Esempio 2: Integrale doppio con valore assoluto (Bordo dei bordi interno)

Calcolare $I = \iint_D |x-y| \, dx dy$, con $D = [0,1] \times [0,1]$.

Il valore assoluto rompe la regolarità. Dobbiamo spezzare il dominio $D$ usando la bisettrice $y = x$, che è il luogo dove si annulla l'argomento.

Definiamo:

- $D_1 = \{(x,y) \in D \mid x > y\}$ (triangolo inferiore). Qui $|x-y| = x-y$.
- $D_2 = \{(x,y) \in D \mid x < y\}$ (triangolo superiore). Qui $|x-y| = y-x$.
    Per simmetria spaziale rispetto alla bisettrice, i due integrali sono identici. Calcoliamo il primo e raddoppiamo:
    
    $$I = 2 \iint_{D_1} (x-y) \, dx dy = 2 \int_0^1 \left( \int_0^x (x-y) \, dy \right) dx$$
    Calcoliamo l'integrale interno:
    $$\int_0^x (x-y) \, dy = \left[ xy - \frac{y^2}{2} \right]_0^x = x^2 - \frac{x^2}{2} = \frac{x^2}{2}$$
    Torniamo all'esterno:
    $$I = 2 \int_0^1 \frac{x^2}{2} \, dx = \int_0^1 x^2 \, dx = \left[ \frac{x^3}{3} \right]_0^1 = \frac{1}{3}$$

#### Esempio 3: Volume intersezione Sfera e Cono (Il "cono gelato")

Calcolare il volume del solido $V$ definito dall'intersezione tra la sfera $x^2+y^2+z^2 \le 2$ e il cono superiore $z \ge \sqrt{x^2+y^2}$.

**Approccio in coordinate sferiche:**

Sia la sfera che il cono si esprimono benissimo in sferiche (usiamo la colatitudine $\phi$ dall'asse $z$):

1. Sfera: $r^2 \le 2 \implies 0 \le r \le \sqrt{2}$.
2. Cono: $r\cos\phi \ge \sqrt{r^2\sin^2\phi\cos^2\theta + r^2\sin^2\phi\sin^2\theta} = r\sin\phi \implies \tan\phi \le 1 \implies 0 \le \phi \le \frac{\pi}{4}$.
3. Nessuna restrizione azimutale: $0 \le \theta \le 2\pi$.

Impostiamo l'integrale ricordando il "pagamento" ($r^2 \sin\phi$):

$$Vol(V) = \iiint_V 1 \, dx dy dz = \int_0^{2\pi} d\theta \int_0^{\pi/4} d\phi \int_0^{\sqrt{2}} r^2 \sin\phi \, dr$$

Integro le tre variabili separate (sono domini indipendenti!):

- In $r$: $\int_0^{\sqrt{2}} r^2 \, dr = \left[ \frac{r^3}{3} \right] = \frac{2\sqrt{2}}{3}$
- In $\theta$: $\int_0^{2\pi} d\theta = 2\pi$
- In $\phi$: $\int_0^{\pi/4} \sin\phi \, d\phi = [-\cos\phi] = 1 - \frac{\sqrt{2}}{2}$

Prodotto finale:

$$Vol(V) = 2\pi \cdot \left(1 - \frac{\sqrt{2}}{2}\right) \cdot \frac{2\sqrt{2}}{3} = \frac{4\pi\sqrt{2}}{3} - \frac{4\pi}{3}$$

L'uso oculato delle coordinate sferiche ci ha risparmiato di integrare fastidiose radici in $z$. Il "pagamento" dello Jacobiano è l'investimento più fruttuoso che abbiate fatto oggi.