## Problema di assegnamento
Adesso riprendiamo l'argomento trattato a fine lezione 2.

n. persone | n. lavori

Dobbiamo trovare un modo per **minimizzare** questi tipi di problemi.

|         | **_1_** | **_2_** | **_3_** | **_4_** |
| ------- | ------- | ------- | ------- | ------- |
| **_1_** | 8       | 6       | 9       | 4       |
| **_2_** | 7       | 5       | 6       | 10      |
| **_3_** | 3       | 8       | 2       | 7       |
| **_4_** | 4       | 9       | 6       | 5       |
Qualunque permutazione è un assegnamento ed è appunto per questo che le permutazioni sono $n!$.
L'**algoritmo di forza bruta** riguarda l'elencare di tutte le permutazioni che questi problemi possono offrirci e questo lo _escludiamo_.

Per trovare il possibile ottimo dobbiamo cercare ogni elemento per riga con il costo minore (che però non sia sovrapposto a un altro elemento)

|         | **_1_** | **_2_** | **_3_** | **_4_** |
| ------- | ------- | ------- | ------- | ------- |
| **_1_** | 8       | 6       | 9       | (4)     |
| **_2_** | 7       | (5)     | 6       | 10      |
| **_3_** | 3       | 8       | (2)     | 7       |
| **_4_** | (4)     | 9       | 6       | 5       |
### Modello matematico
Abbiamo diversi punti da seguire per eseguire questo modello matematico:
1. Dati
2. Variabili
3. Funzione Obiettivo
4. VIncoli
5. Scelta dell'algoritmo
6. _FeedBack_

>[!IMPORTANT]
> - **_Dati_** $\rightarrow$ possiamo già saltare questo punto perché tanto per l'esame i dati che verranno dati saranno e andranno utilizzati tutti.
> - **_Variabili_** $\rightarrow$ l'azienza qui deve essere in grado di capire quali valori possono prendere in considerazione
> 	- Per scrivere la soluzione possibile bisogna scrivere nel seguente modo: $x_{i,j} = \begin{cases}0 \\ 1 \end{cases}$, dove $i$ sono i progetti e $j$ sono gli studi.
> 	$$X = (\ 1 \ 0 \ 0 \ 0 \ | \ 0 \ 1 \ 0 \ 0 \ | \ 0 \ 0 \ 1 \ 0 \ | \ 0 \ 0 \ 0 \ 1 \ )$$
> - **_Funzione obiettivo_** $\rightarrow$ Ora chiediamoci quanto costa questo tipo di assegnamento (guardando a quale variabile costa): 8 + 5 + 2 + 5 = 20
> 	- Scriviamo il sistema che rappresenta questo problema:
> 	$$\begin{cases}\text{min } 8x_{1,1} + 6x_{1,2} + 9x_{1,3} + 4x_{1,4} + 7x_{2,1} + 5x_{2,2} + 6x_{2,3} + 10x_{2,4} + 3x_{3,1} + 8x_{3,2} + 2x_{3,3} + 7x_{3,4} + 4x_{4,1} + 9x_{4,2} + 6x_{4,3} + 5x_{4,4}\end{cases}$$
> - **_Vincoli_** $\rightarrow$ Adesso troviamo i vincoli che possono definire questo problema, ma come li troviamo?
> 	- **ogni risorsa (riga) deve essere assegnata a una e una sola attività (colonna), e ogni attività deve essere svolta da una e una sola risorsa**.
> 	- Introduciamo quindi due concetti: 
> 		1. **Vincoli di assegnamento (Righe):** Ogni risorsa (1, 2, 3, 4) fa esattamente un'attività.
> 		2. **Vincoli di copertura (Colonne):** Ogni attività (1, 2, 3, 4) è assegnata a esattamente una risorsa.
> 	- Quindi avremmo: 
> 	$$\begin{cases}\text{min } 8x_{1,1} + 6x_{1,2} + 9x_{1,3} + 4x_{1,4} + 7x_{2,1} + 5x_{2,2} + 6x_{2,3} + 10x_{2,4} + 3x_{3,1} + 8x_{3,2} + 2x_{3,3} + 7x_{3,4} + 4x_{4,1} + 9x_{4,2} + 6x_{4,3} + 5x_{4,4} \\
> 	x_{1,1} + x_{1,2} + x_{1,3} + x_{1,4} = 1 \\
> 	x_{2,1} + x_{2,2} + x_{2,3} + x_{2,4} = 1 \\
> 	x_{3,1} + x_{3,2} + x_{3,3} + x_{3,4} = 1 \\
> 	x_{4,1} + x_{4,2} + x_{4,3} + x_{4,4} = 1 \\
> 	x_{1,1} + x_{2,1} + x_{3,1} + x_{4,1} = 1 \\ 
> 	x_{1,2} + x_{2,2} + x_{3,2} + x_{4,2} = 1 \\ 
> 	x_{1,3} + x_{2,3} + x_{3,3} + x_{4,3} = 1 \\ 
> 	x_{1,4} + x_{2,4} + x_{3,4} + x_{4,4} = 1
> 	\end{cases}$$
> - **_Scelta dell'algoritmo_** $\rightarrow$ Esistono due tipi di assegnamenti:
> 	1. **_Cooperativo_**: Vengono accettate soluzioni anche frazionarie;
> 	2. **_Non cooperativo_**: Non vengono accettate soluzioni frazionarie ma solo 1 o 0.

>[!question]- Quali sono i valori di A, b e c ??
> $A \ = \begin{pmatrix}1 \\ -1 \\ 1 \\ -1 \\ 1 \\ -1 \\ 1 \\ -1 \\ 1 \\ -1 \\ 1 \\ -1 \\ 1 \\ -1 \\ 1 \\ -1\end{pmatrix} \ b \ = \begin{bmatrix}{1 \ 1 \ 1 \ 1}\end{bmatrix} c \ = \begin{bmatrix}\end{bmatrix}$ 

---
## Poliedri
$\text{A}x \le \text{b}$, ricordando che $A \in \mathbb{R}^{n \ x \ m}$, $x \in \mathbb{R}^n$ e $b \in \mathbb{R}^m$  dobbiamo dare due definizioni per parlare di poliedri:

>[!info] Definizione 1: Combinazione convessa 
>Dati $k$ vettori $x^1, x^2, \dots, x^k \in \mathbb{R}^n$, un vettore $y \in \mathbb{R}^n$ si dice **combinazione convessa** dei vettori $x^i$ se esistono $k$ coefficienti $\lambda_i$ tali che: > $$ \begin{align*} y &= \sum_{i=1}^{k} \lambda_i x^i \\ \sum_{i=1}^{k} \lambda_i &= 1 \\ \lambda_i &\ge 0 \quad \forall i = 1, \dots, k \end{align*} $$
### Esempio 1
Dati $k$ vettori per cui $k = 2$ e $n = 2$ e un vettore $y = \lambda_{1}x^1 + \lambda_{2}x^2$

<svg width="350" height="250" style="background-color=#fffff;" xmlns="http://www.w3.org/2000/svg">
  <!-- Assi Cartesiani -->
  <line x1="30" y1="220" x2="320" y2="220" stroke="black" marker-end="url(#arrow)" />
  <line x1="30" y1="220" x2="30" y2="20" stroke="black" marker-end="url(#arrow)" />
  <text x="325" y="215" font-family="Arial" font-size="14" font-style="italic">x₁</text>
  <text x="10" y="20" font-family="Arial" font-size="14" font-style="italic">x₂</text>
  
  <!-- Inviluppo convesso (Segmento) -->
  <line x1="80" y1="180" x2="250" y2="70" stroke="#3182bd" stroke-width="3" />
  
  <!-- Punti x1 e x2 -->
  <circle cx="80" cy="180" r="5" fill="#e6550d" />
  <text x="55" y="195" font-family="Arial" font-size="16" font-weight="bold">x¹</text>
  
  <circle cx="250" cy="70" r="5" fill="#e6550d" />
  <text x="260" y="75" font-family="Arial" font-size="16" font-weight="bold">x²</text>
  
  <!-- Punto y (Combinazione convessa) -->
  <circle cx="165" cy="125" r="6" fill="#31a354" />
  <text x="180" y="120" font-family="Arial" font-size="14" font-weight="bold" fill="#31a354">y = λ₁x¹ + λ₂x²</text>
  
  <defs>
    <marker id="arrow" markerWidth="10" markerHeight="10" refX="0" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#000" />
    </marker>
  </defs>
</svg>
---
### Esempio 2
Dati $k$ vettori per cui $k = 3$ e $n = 2$ e un vettore $y = \lambda_{1}x^1 + \lambda_{2}x^2 + \lambda_{3}x^3$ 

<svg width="350" height="250" xmlns="http://www.w3.org/2000/svg">
  <!-- Assi Cartesiani -->
  <line x1="30" y1="220" x2="320" y2="220" stroke="black" marker-end="url(#arrow2)" />
  <line x1="30" y1="220" x2="30" y2="20" stroke="black" marker-end="url(#arrow2)" />
  <text x="325" y="215" font-family="Arial" font-size="14" font-style="italic">x₁</text>
  <text x="10" y="20" font-family="Arial" font-size="14" font-style="italic">x₂</text>
  
  <!-- Inviluppo convesso (Triangolo) -->
  <polygon points="80,180 230,60 280,190" fill="#deebf7" stroke="#3182bd" stroke-width="2" />
  
  <!-- Punti x1, x2, x3 -->
  <circle cx="80" cy="180" r="5" fill="#e6550d" />
  <text x="55" y="195" font-family="Arial" font-size="16" font-weight="bold">x¹</text>
  
  <circle cx="230" cy="60" r="5" fill="#e6550d" />
  <text x="240" y="55" font-family="Arial" font-size="16" font-weight="bold">x²</text>
  
  <circle cx="280" cy="190" r="5" fill="#e6550d" />
  <text x="290" y="195" font-family="Arial" font-size="16" font-weight="bold">x³</text>
  
  <!-- Punto y (Combinazione convessa) -->
  <circle cx="196" cy="143" r="6" fill="#31a354" />
  <text x="105" y="135" font-family="Arial" font-size="14" font-weight="bold" fill="#31a354">y = λ₁x¹ + λ₂x² + λ₃x³</text>
  <text x="210" y="155" font-family="Arial" font-size="12" fill="#31a354">(λ₁ + λ₂ + λ₃ = 1)</text>
  
  <defs>
    <marker id="arrow2" markerWidth="10" markerHeight="10" refX="0" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#000" />
    </marker>
  </defs>
</svg>
	$\Rightarrow$ Le **_combinazioni convesse_** di 3 punti rappresentano l'interno del triangolo.

>[!info] Definizione 2: Combinazione conica 
>Dati $k$ vettori $x^1, x^2, \dots, x^k \in \mathbb{R}^n$, un vettore $y \in \mathbb{R}^n$ si dice **combinazione conica** dei vettori $x^i$ se esistono $k$ coefficienti $\lambda_i$ tali che: $$ \begin{align*} y &= \sum_{i=1}^{k} \lambda_i x^i \\ \lambda_i &\ge 0 \quad \forall i = 1, \dots, k \end{align*} $$
### Esempio 1
Dati $k$ vettori per cui $k = 2$ e $n = 2$, a differenza della combinazione convessa, qui manca il vincolo $\sum_{i=1}^{k} \lambda_i = 1$. Questo significa che i coefficienti $\lambda_i$ possono assumere qualsiasi valore positivo o nullo. Geometricamente, combinando due vettori in questo modo, si genera un **cono infinito** (un settore angolare illimitato) che ha come vertice l'origine degli assi. Il punto $y$ può trovarsi in qualsiasi punto all'interno di quest'area grigia.

<svg width="350" height="250" xmlns="http://www.w3.org/2000/svg">
  <!-- Assi Cartesiani -->
  <line x1="30" y1="220" x2="320" y2="220" stroke="black" marker-end="url(#arrow3)" />
  <line x1="30" y1="220" x2="30" y2="20" stroke="black" marker-end="url(#arrow3)" />
  <text x="325" y="215" font-family="Arial" font-size="14" font-style="italic">x₁</text>
  <text x="10" y="20" font-family="Arial" font-size="14" font-style="italic">x₂</text>
  
  <!-- Inviluppo conico (Cono illimitato) -->
  <polygon points="30,220 320,147.5 320,20 130,20" fill="#deebf7" />
  
  <!-- Vettori x1 e x2 -->
  <line x1="30" y1="220" x2="230" y2="170" stroke="#e6550d" stroke-width="2" marker-end="url(#arrow_vec)" />
  <text x="235" y="185" font-family="Arial" font-size="16" font-weight="bold">x¹</text>
  
  <line x1="30" y1="220" x2="90" y2="100" stroke="#e6550d" stroke-width="2" marker-end="url(#arrow_vec)" />
  <text x="70" y="95" font-family="Arial" font-size="16" font-weight="bold">x²</text>
  
  <!-- Punto y (Combinazione conica) -->
  <circle cx="180" cy="90" r="5" fill="#31a354" />
  <text x="190" y="85" font-family="Arial" font-size="14" font-weight="bold" fill="#31a354">y = λ₁x¹ + λ₂x²</text>
  <text x="190" y="105" font-family="Arial" font-size="12" fill="#31a354">(λ₁, λ₂ ≥ 0)</text>
  
  <defs>
    <marker id="arrow3" markerWidth="10" markerHeight="10" refX="0" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#000" />
    </marker>
    <marker id="arrow_vec" markerWidth="10" markerHeight="10" refX="5" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#e6550d" />
    </marker>
  </defs>
</svg>
---
### Esempio 2
Dati $k$ vettori per cui $k = 3$ e $n = 2$, aggiungendo un terzo vettore $x^3$, l'area generata (il cono) è determinata esclusivamente dai vettori più "esterni" (in questo caso $x^1$ e $x^3$). Il vettore $x^2$, trovandosi già all'interno del cono generato dagli altri due, non espande lo spazio delle soluzioni possibili. Qualsiasi punto $y$ nel settore angolare può essere ottenuto combinando linearmente questi tre vettori con pesi non negativi.

<svg width="350" height="250" xmlns="http://www.w3.org/2000/svg">
  <!-- Assi Cartesiani -->
  <line x1="30" y1="220" x2="320" y2="220" stroke="black" marker-end="url(#arrow4)" />
  <line x1="30" y1="220" x2="30" y2="20" stroke="black" marker-end="url(#arrow4)" />
  <text x="325" y="215" font-family="Arial" font-size="14" font-style="italic">x₁</text>
  <text x="10" y="20" font-family="Arial" font-size="14" font-style="italic">x₂</text>
  
  <!-- Inviluppo conico (Cono illimitato) -->
  <polygon points="30,220 320,147.5 320,20 130,20" fill="#deebf7" />
  
  <!-- Vettori x1, x2, x3 -->
  <line x1="30" y1="220" x2="230" y2="170" stroke="#e6550d" stroke-width="2" marker-end="url(#arrow_vec2)" />
  <text x="235" y="185" font-family="Arial" font-size="16" font-weight="bold">x¹</text>
  
  <line x1="30" y1="220" x2="160" y2="120" stroke="#e6550d" stroke-width="2" marker-end="url(#arrow_vec2)" />
  <text x="165" y="115" font-family="Arial" font-size="16" font-weight="bold">x²</text>

  <line x1="30" y1="220" x2="90" y2="100" stroke="#e6550d" stroke-width="2" marker-end="url(#arrow_vec2)" />
  <text x="70" y="95" font-family="Arial" font-size="16" font-weight="bold">x³</text>
  
  <!-- Punto y (Combinazione conica) -->
  <circle cx="140" cy="70" r="5" fill="#31a354" />
  <text x="150" y="65" font-family="Arial" font-size="14" font-weight="bold" fill="#31a354">y = λ₁x¹ + λ₂x² + λ₃x³</text>
  
  <defs>
    <marker id="arrow4" markerWidth="10" markerHeight="10" refX="0" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#000" />
    </marker>
    <marker id="arrow_vec2" markerWidth="10" markerHeight="10" refX="5" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#e6550d" />
    </marker>
  </defs>
</svg>
---
## Teroema di "_Weyl_" | Rappresentazione dei poliedri

> [!important] Teorema di Weyl (Rappresentazione dei poliedri)
> Dato un poliedro $P$, esistono sempre un insieme di $k$ vertici $V = \{v^1, \dots, v^k\} \subset P$ e un insieme di $p$ direzioni $E = \{e^1, \dots, e^p\}$ tali che $P$ può essere espresso come la somma di Minkowski del loro inviluppo convesso e del loro inviluppo conico:
> 
> $$ P = \text{conv}(V) + \text{cono}(E) $$
> 
>> **Definizioni dei termini:**
>> *   **$\text{conv}(V)$** è l'insieme di tutte le possibili **combinazioni convesse** dei punti in $V$:
>>    $$ \text{conv}(V) = \left\{ \sum_{i=1}^{k} \lambda_i v^i \ \Bigg| \ \sum_{i=1}^{k} \lambda_i = 1, \ \lambda_i \ge 0 \ \forall i \right\} $$
>> *   **$\text{cono}(E)$** è l'insieme di tutte le possibili **combinazioni coniche** delle direzioni in $E$:
>>     $$ \text{cono}(E) = \left\{ \sum_{j=1}^{p} \mu_j e^j \ \Bigg| \ \mu_j \ge 0 \ \forall j \right\} $$
> 
> *Nota: Il simbolo $+$ indica la somma vettoriale tra i due insiemi di punti (nota anche come somma di Minkowski, talvolta indicata con il simbolo $\oplus$).*

<svg width="600" height="350" xmlns="http://www.w3.org/2000/svg">
  <!-- Definizioni per le frecce -->
  <defs>
    <marker id="arrow" markerWidth="10" markerHeight="10" refX="0" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#000" />
    </marker>
    <marker id="arrow_dir" markerWidth="10" markerHeight="10" refX="5" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#31a354" />
    </marker>
    <marker id="arrow_dashed" markerWidth="10" markerHeight="10" refX="5" refY="3" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L0,6 L9,3 z" fill="#756bb1" />
    </marker>
  </defs>

  <!-- Area del poliedro P -->
  <polygon points="50,40 50,150 150,250 550,250 550,40" fill="#deebf7" />

  <!-- Griglia di riferimento (scala: 1 unità = 50px) -->
  <line x1="100" y1="250" x2="100" y2="40" stroke="#ccc" stroke-dasharray="3,3"/>
  <line x1="150" y1="250" x2="150" y2="40" stroke="#ccc" stroke-dasharray="3,3"/>
  <line x1="200" y1="250" x2="200" y2="40" stroke="#ccc" stroke-dasharray="3,3"/>
  <line x1="250" y1="250" x2="250" y2="40" stroke="#ccc" stroke-dasharray="3,3"/>
  
  <line x1="50" y1="200" x2="550" y2="200" stroke="#ccc" stroke-dasharray="3,3"/>
  <line x1="50" y1="150" x2="550" y2="150" stroke="#ccc" stroke-dasharray="3,3"/>
  <line x1="50" y1="100" x2="550" y2="100" stroke="#ccc" stroke-dasharray="3,3"/>

  <!-- Assi Cartesiani -->
  <line x1="50" y1="250" x2="550" y2="250" stroke="black" marker-end="url(#arrow)" />
  <line x1="50" y1="250" x2="50" y2="40" stroke="black" marker-end="url(#arrow)" />
  
  <!-- Numeri sugli assi -->
  <text x="40" y="265" font-family="Arial" font-size="12">0</text>
  <text x="145" y="268" font-family="Arial" font-size="12" font-weight="bold">2</text>
  <text x="245" y="268" font-family="Arial" font-size="12" font-weight="bold">4</text>
  
  <text x="35" y="155" font-family="Arial" font-size="12" font-weight="bold">2</text>
  <text x="35" y="105" font-family="Arial" font-size="12" font-weight="bold">3</text>

  <text x="560" y="245" font-family="Arial" font-size="14" font-style="italic">x₁</text>
  <text x="30" y="30" font-family="Arial" font-size="14" font-style="italic">x₂</text>

  <!-- Segmento conv(V) (Inviluppo convesso) -->
  <line x1="50" y1="150" x2="150" y2="250" stroke="#3182bd" stroke-width="4" />
  
  <g transform="translate(60, 235) rotate(-45)">
    <text x="0" y="0" font-family="Arial" font-size="14" font-weight="bold" fill="#3182bd">conv(V)</text>
  </g>

  <!-- Direzioni di base del cono(E) -->
  <line x1="150" y1="250" x2="230" y2="250" stroke="#31a354" stroke-width="3" marker-end="url(#arrow_dir)" />
  <text x="160" y="235" font-family="Arial" font-size="14" font-weight="bold" fill="#31a354">e¹ = (1,0)</text>

  <line x1="50" y1="150" x2="50" y2="70" stroke="#31a354" stroke-width="3" marker-end="url(#arrow_dir)" />
  <text x="60" y="90" font-family="Arial" font-size="14" font-weight="bold" fill="#31a354">e² = (0,1)</text>

  <!-- I due vertici V -->
  <circle cx="50" cy="150" r="6" fill="#e6550d" />
  <text x="10" y="140" font-family="Arial" font-size="14" font-weight="bold" fill="#e6550d">v² (0,2)</text>

  <circle cx="150" cy="250" r="6" fill="#e6550d" />
  <text x="125" y="275" font-family="Arial" font-size="14" font-weight="bold" fill="#e6550d">v¹ (2,0)</text>

  <!-- Punto BASE scelto nel conv(V) -->
  <circle cx="100" cy="200" r="5" fill="#3182bd" />
  <text x="110" y="215" font-family="Arial" font-size="12" font-weight="bold" fill="#3182bd">Punto Base (1,1)</text>

  <!-- Spostamento calcolato col cono(E) -->
  <line x1="100" y1="200" x2="250" y2="200" stroke="#756bb1" stroke-width="2" stroke-dasharray="5,5" marker-end="url(#arrow_dashed)" />
  <text x="135" y="190" font-family="Arial" font-size="12" font-weight="bold" fill="#756bb1">+ 3e¹ (verso destra)</text>

  <line x1="250" y1="200" x2="250" y2="100" stroke="#756bb1" stroke-width="2" stroke-dasharray="5,5" marker-end="url(#arrow_dashed)" />
  <text x="260" y="150" font-family="Arial" font-size="12" font-weight="bold" fill="#756bb1">+ 2e² (verso l'alto)</text>

  <!-- Punto FINALE nel poliedro -->
  <circle cx="250" cy="100" r="6" fill="#756bb1" />
  <text x="265" y="95" font-family="Arial" font-size="16" font-weight="bold" fill="#756bb1">y (4,3)</text>
  
  <!-- Riepilogo Formula -->
  <text x="320" y="70" font-family="Arial" font-size="14" font-weight="bold" fill="#333">y = (1,1) + (3,0) + (0,2)</text>
  <text x="320" y="90" font-family="Arial" font-size="12" font-weight="bold" fill="#3182bd">└─ da conv(V)</text>
  <text x="320" y="110" font-family="Arial" font-size="12" font-weight="bold" fill="#756bb1">└─ da cono(E)</text>
</svg>
