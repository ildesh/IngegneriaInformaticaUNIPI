
### Cinematica, Dinamica del Punto Materiale, Lavoro, Energia e Urti

---

## 1. Cinematica del Punto Materiale

La cinematica studia il moto dei corpi a prescindere dalle cause (forze) che lo generano.

### 1.1 Vettori e Grandezze Cinematiche Fondamentali

- **Posizione ($\vec{r}$)**: Individua la posizione del punto nello spazio rispetto a un'origine $O$. In coordinate cartesiane 3D: $$\vec{r}(t) = x(t)\hat{i} + y(t)\hat{j} + z(t)\hat{k}$$
- **Velocità ($\vec{v}$)**: Derivata temporale della posizione: $$\vec{v}(t) = \frac{d\vec{r}}{dt} = v_x \hat{i} + v_y \hat{j} + v_z \hat{k}$$
- **Accelerazione ($\vec{a}$)**: Derivata temporale della velocità: $$\vec{a}(t) = \frac{d\vec{v}}{dt} = \frac{d^2\vec{r}}{dt^2} = a_x \hat{i} + a_y \hat{j} + a_z \hat{k}$$

---

### 1.2 Moti Unidimensionali Notevoli

#### Moto Rettilineo Uniforme (MRU)

Con velocità costante ($v = \text{cost}$, $a = 0$): $$x(t) = x_0 + v_x t$$

#### Moto Rettilineo Uniformemente Accelerato (MRUA)

Con accelerazione costante ($a = \text{cost}$): $$v(t) = v_0 + a t$$ $$x(t) = x_0 + v_0 t + \frac{1}{2} a t^2$$ $$v_f^2 = v_0^2 + 2 a (x_f - x_0)$$

---

### 1.3 Moti in Due Dimensioni

#### Moto Parabolico (Proiettili)

Disaccoppiamento dei moti lungo gli assi cartesiani ($a_x = 0$, $a_y = -g$): $$\begin{cases} x(t) = x_0 + v_{0x} t \ y(t) = y_0 + v_{0y} t - \frac{1}{2} g t^2 \end{cases}$$ con $v_{0x} = v_0 \cos\theta$ e $v_{0y} = v_0 \sin\theta$.

```
Y ^
  |       * * * (Vertice H_max)
  |     *       *
  |   *           *
  | *               *
  +--------------------> X
  O                 Gittata (R)
```

- **Tempo di volo**: $t_v = \frac{2 v_0 \sin\theta}{g}$
- **Gittata massima**: $R = \frac{v_0^2 \sin(2\theta)}{g}$
- **Altezza massima**: $H_{max} = \frac{v_0^2 \sin^2\theta}{2g}$

#### Moto Circolare (Accelerazione Centripeta e Tangenziale)

L'accelerazione totale $\vec{a}$ si scompone lungo la direzione tangenziale $\hat{u}_t$ e normale/centripeta $\hat{u}_n$: $$\vec{a} = \vec{a}_t + \vec{a}_c = \frac{dv}{dt} \hat{u}_t + \frac{v^2}{r} \hat{u}_n$$ con $\omega = \frac{d\theta}{dt}$ (velocità angolare) e $a_c = \omega^2 r = \frac{v^2}{r}$.

```
        ^ a_t (tangenziale)
        |
        +------> a_c (centripeta, verso il centro O)
       /
      O (Centro della traiettoria)
```

---

### Esempio Guidato 1: Calcolo della Gittata nel Moto Parabolico

**Testo**: Un proiettile viene lanciato da terra con velocità iniziale $v_0 = 20\text{ m/s}$ ad un angolo $\theta = 30^\circ$ rispetto all'orizzontale ($g = 9.81\text{ m/s}^2$). **Svolgimento**:

1. Componenti della velocità iniziale: $$v_{0x} = 20 \cdot \cos(30^\circ) = 20 \cdot 0.866 = 17.32\text{ m/s}$$ $$v_{0y} = 20 \cdot \sin(30^\circ) = 20 \cdot 0.5 = 10.0\text{ m/s}$$
2. Calcolo della gittata $R$: $$R = \frac{v_0^2 \sin(2\theta)}{g} = \frac{400 \cdot \sin(60^\circ)}{9.81} = \frac{400 \cdot 0.866}{9.81} \approx 35.31\text{ m}$$

---

## 2. Dinamica del Punto Materiale e Leggi di Newton

### 2.1 I tre Principi della Dinamica

1. **Primo Principio (Inerzia)**: In assenza di forze esterne risultanti ($\sum \vec{F} = 0$), un corpo rimane in quiete o prosegue di moto rettilineo uniforme.
2. **Secondo Principio**: La forza risultante agente su un corpo è pari alla variazione temporale della quantità di moto (o alla massa per l'accelerazione): $$\sum \vec{F} = m \vec{a}$$
3. **Terzo Principio (Azione e Reazione)**: Se un corpo A esercita una forza $\vec{F}_{AB}$ su B, B esercita su A una forza uguale e contraria: $$\vec{F}_{BA} = -\vec{F}_{AB}$$

---

### 2.2 Forza d'Attrito e Piano Inclinato

#### Forza d'Attrito

- **Attrito Statico**: $f_s \le \mu_s N$. Il valore massimo prima dello scivolamento è $f_{s,max} = \mu_s N$.
- **Attrito Dinamico**: $f_d = \mu_d N$ (diretta in verso opposto alla velocità relativa).

#### Diagramma di Corpo Libero sul Piano Inclinato

Scomposizione della forza peso $m\vec{g}$ lungo le direzioni parallela ($x$) e normale ($y$) al piano di inclinazione $\theta$:

```
          N (Forza Normale)
          ^   /
          |  /  f_a (Attrito)
   +------+--+-----> (Direzione parallela al piano, x)
   |  [ m ]  |
   +---------+
        | \
        |  \ mg sin(theta)
        v   v
       mg   mg cos(theta)
```

Equazioni di equilibrio / moto: $$\begin{cases} N - m g \cos\theta = 0 \implies N = m g \cos\theta \ m g \sin\theta - f_a = m a \end{cases}$$

Se il corpo scivola ($f_a = \mu_d N = \mu_d m g \cos\theta$): $$a = g (\sin\theta - \mu_d \cos\theta)$$

L'angolo critico $\theta_c$ per cui il blocco inizia a scivolare da fermo soddisfa: $$\tan\theta_c = \mu_s$$

---

### Esempio Guidato 2: Blocco su Piano Inclinato con Attrito

**Testo**: Un blocco di massa $m = 5\text{ kg}$ scivola lungo un piano inclinato di $\theta = 30^\circ$ con coefficiente di attrito dinamico $\mu_d = 0.2$. Determinare l'accelerazione $a$ del blocco. **Svolgimento**:

1. Calcolo di forza normale e attrito: $$N = m g \cos(30^\circ) = 5 \cdot 9.81 \cdot 0.866 \approx 42.48\text{ N}$$ $$f_d = \mu_d N = 0.2 \cdot 42.48 \approx 8.50\text{ N}$$
2. Applicazione della 2ª legge di Newton lungo il piano: $$m g \sin(30^\circ) - f_d = m a$$ $$5 \cdot 9.81 \cdot 0.5 - 8.50 = 5 a \implies 24.525 - 8.50 = 5 a \implies 16.025 = 5 a$$ $$a \approx 3.21\text{ m/s}^2$$

---

## 3. Lavoro, Energia e Conservazione

### 3.1 Lavoro di una Forza

Il lavoro $\mathcal{L}$ compiuto da una forza $\vec{F}$ lungo uno spostamento $d\vec{r}$ è definito come: $$\mathcal{L} = \int_{A}^{B} \vec{F} \cdot d\vec{r} = \int_{A}^{B} |\vec{F}| |d\vec{r}| \cos\theta$$

- **Forza costante**: $\mathcal{L} = \vec{F} \cdot \Delta\vec{r} = F \Delta r \cos\theta$
- **Forza elastica (Legge di Hooke $\vec{F}_e = -k x \hat{i}$)**: $$\mathcal{L}_e = \int_{x_i}^{x_f} (-k x) dx = \frac{1}{2} k x_i^2 - \frac{1}{2} k x_f^2 = -\Delta U_e$$

---

### 3.2 Energia Cinetica e Teorema delle Forze Vive

L'energia cinetica di un punto materiale di massa $m$ e velocità $v$ è: $$K = \frac{1}{2} m v^2$$

**Teorema dell'Energia Cinetica (delle Forze Vive)**: Il lavoro totale compiuto da TUTTE le forze (conservative e non conservative) agenti su un corpo è pari alla variazione della sua energia cinetica: $$\mathcal{L}_{tot} = \Delta K = K_f - K_i = \frac{1}{2} m v_f^2 - \frac{1}{2} m v_i^2$$

---

### 3.3 Forze Conservative ed Energia Potenziale

Una forza è **conservativa** se il lavoro compiuto lungo un percorso chiuso è nullo ($\oint \vec{F} \cdot d\vec{r} = 0$), ovvero se il lavoro dipende solo dai punti iniziale e finale. Si definisce l'energia potenziale $U$ tramite: $$\mathcal{L}_{cons} = -\Delta U = U_i - U_f \iff \vec{F} = -\nabla U$$

- **Energia potenziale gravitazionale**: $U_g = m g h$
- **Energia potenziale elastica**: $U_e = \frac{1}{2} k x^2$

#### Principio di Conservazione dell'Energia Meccanica

In presenza di sole forze conservative: $$E_m = K + U = \text{costante} \implies K_i + U_i = K_f + U_f$$

Se agiscono forze non conservative (es. attrito): $$\mathcal{L}_{nc} = \Delta E_m = E_{m,f} - E_{m,i}$$

---

### Esempio Guidato 3: Scivolamento con Molla e Attrito

**Testo**: Una massa $m = 2\text{ kg}$ parte da ferma da un'altezza $h = 1\text{ m}$ lungo uno scivolo privo di attrito e va ad urtare una molla di costante elastica $k = 400\text{ N/m}$ posta su un piano orizzontale privo di attrito. Calcolare la massima compressione $x_{max}$ della molla.

```
  \ (m)
   \ h = 1m
    \__________[  Molla k  ]=======|
```

**Svolgimento**:

1. Poiché non vi sono attriti, l'energia meccanica si conserva tra il punto iniziale (in cima) e il punto di massima compressione della molla (dove la velocità si azzera): $$E_{m,i} = m g h + 0 = 2 \cdot 9.81 \cdot 1 = 19.62\text{ J}$$ $$E_{m,f} = 0 + \frac{1}{2} k x_{max}^2 = \frac{1}{2} \cdot 400 \cdot x_{max}^2 = 200 x_{max}^2$$
2. Uguagliando $E_{m,i} = E_{m,f}$: $$19.62 = 200 x_{max}^2 \implies x_{max}^2 = \frac{19.62}{200} = 0.0981 \implies x_{max} = \sqrt{0.0981} \approx 0.313\text{ m} = 31.3\text{ cm}$$

---

## 4. Quantità di Moto, Impulso e Urti

### 4.1 Quantità di Moto e Impulso

- **Quantità di moto**: $\vec{p} = m \vec{v}$
- **Impulso di una forza**: $\vec{I} = \int_{t_1}^{t_2} \vec{F} dt = \langle\vec{F}\rangle \Delta t$
- **Teorema dell'Impulso**: $\vec{I} = \Delta \vec{p} = \vec{p}_f - \vec{p}_i$

---

### 4.2 Conservazione della Quantità di Moto

Se la risultante delle forze esterne agenti su un sistema è nulla ($\sum \vec{F}_{est} = 0$): $$\vec{P}_{tot} = \sum m_i \vec{v}_i = \text{costante}$$

---

### 4.3 Classificazione degli Urti

```
               [ m1 ] v1 --->   <--- v2 [ m2 ]
                         \     /
                          ( URTO )
                         /     \
  Urti Elastici:                    Urti Anelastici:
  Conservazione di p E K            Conservazione di p (K NON si conserva)
```

1. **Urto Perfettamente Elastico**:
    
    - Conservazione della quantità di moto: $\vec{p}_i = \vec{p}_f$
    - Conservazione dell'energia cinetica: $K_i = K_f$
    - Per un urto unidimensionale ($m_2$ inizialmente ferma, $v_{2i} = 0$): $$v_{1f} = \frac{m_1 - m_2}{m_1 + m_2} v_{1i}, \quad v_{2f} = \frac{2 m_1}{m_1 + m_2} v_{1i}$$
2. **Urto Completamente Anelastico**:
    
    - I due corpi rimangono attaccati dopo l'urto e procedono con velocità comune $\vec{v}_f$: $$m_1 \vec{v}_{1i} + m_2 \vec{v}_{2i} = (m_1 + m_2) \vec{v}_f \implies \vec{v}_f = \frac{m_1 \vec{v}_{1i} + m_2 \vec{v}_{2i}}{m_1 + m_2}$$
    - Massimo ammontare di energia cinetica dissipata in deformazione/calore.

---

### Esempio Guidato 4: Urto Completamente Anelastico

**Testo**: Un proiettile di massa $m = 0.05\text{ kg}$ muovendosi alla velocità $v_0 = 200\text{ m/s}$ colpisce un blocco di legno di massa $M = 1.95\text{ kg}$ inizialmente fermo su una superficie orizzontale liscia e vi si conficca. Determinare la velocità finale $v_f$ del sistema e la quantità di energia cinetica persa nell'urto.

**Svolgimento**:

1. Conservazione della quantità di moto: $$m v_0 = (m + M) v_f \implies 0.05 \cdot 200 = (0.05 + 1.95) v_f$$ $$10 = 2.0 \cdot v_f \implies v_f = 5.0\text{ m/s}$$
2. Energia cinetica iniziale e finale: $$K_i = \frac{1}{2} m v_0^2 = \frac{1}{2} (0.05) (200)^2 = 1000\text{ J}$$ $$K_f = \frac{1}{2} (m + M) v_f^2 = \frac{1}{2} (2.0) (5)^2 = 25\text{ J}$$
3. Energia cinetica dissipata: $$\Delta K = K_i - K_f = 1000 - 25 = 975\text{ J} \quad (97.5%\text{ dell'energia cinetica iniziale})$$

---

## Mappa delle Formule Chiave (Pronto Soccorso Meccanica)

|Argomento|Formula Principale|Note|
|---|---|---|
|**MRUA**|$x(t) = x_0 + v_0 t + \frac{1}{2} a t^2$|$a = \text{costante}$|
|**Acc. Centripeta**|$a_c = \frac{v^2}{r} = \omega^2 r$|Diretta verso il centro|
|**Legge di Newton**|$\sum \vec{F} = m \vec{a}$|Valida nei SdR inerziali|
|**Attrito Dinamico**|$f_d = \mu_d N$|Opposto al moto|
|**Lavoro**|$\mathcal{L} = \int \vec{F} \cdot d\vec{r}$|Prodotto scalare|
|**Energia Cinetica**|$K = \frac{1}{2} m v^2$|Teorema $L_{tot} = \Delta K$|
|**Energia Potenziale**|$U_g = m g h, ; U_e = \frac{1}{2} k x^2$|Per forze conservative|
|**Quantità di Moto**|$\vec{p} = m \vec{v}$|$\vec{I} = \Delta \vec{p}$|
|**Urto Anelastico**|$v_f = \frac{m_1 v_{1i} + m_2 v_{2i}}{m_1 + m_2}$|Corpi uniti dopo l'urto|