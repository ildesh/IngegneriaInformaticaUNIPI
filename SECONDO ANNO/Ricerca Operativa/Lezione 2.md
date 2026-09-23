## 1. Condizioni esistenza elementi funzione
Rivediamo il primo problema della lezione 1: 
$$
\begin{cases}
\max \ 300x_1 + 200x_2 \\
20x_1 + 10x_2 \le 950 & \\
2x_1 + 3x_2 \le 120 &  \\
x_1 + 2x_2 \le 70 &  \\
x_1 \ge 0, x_2 \ge 0 & 
\end{cases}
\begin{cases}
\max (\text{o } \min) \ Z = c^T x \\
Ax \le b \\
x \ge 0
\end{cases}
$$
Le condizioni di esistenza dei vari elementi che descrivono la nostra funzione sono i seguenti:
1. $A \in \mathbb{R}^{m x n}$
2. $b \in \mathbb{R}^m$
3. $c \in \mathbb{R}^n$
4. $x \in \mathbb{R}^n$
---
## 2. Trasformazioni equivalenti di problemi di PL: 
### Primale e standard: Cosa significa _formato standard_
Nella forma standard:
1.  il min si trasforma in max e max in min: $min \longleftrightarrow max$
2. il $\le$ si trasforma in $\ge$ e viceversa: $\le \ \longleftrightarrow \ \ge$ 
3. Un vincolo di uguaglianza si trasforma in una coppia di vincoli
	- $2x_1 + 4x_2 = 7 \ \rightarrow \begin{cases}2x_1 + 4x_2 \le 7 \\2x_1 + 4x_2 \ge 7\end{cases}$
4. E invece da $\le$ a $=$ ?? 
---
## 3. Risoluzione geometrica di un problema di PL in formato primale standard in due variabili

$$
\begin{cases}
\max \ 300x_1 + 200x_2 \\
20x_1 + 10x_2 \le 950 & \\
2x_1 + 3x_2 \le 120 &  \\
x_1 + 2x_2 \le 70 &  \\
-x_1 \le 0 \\
-x_2 \le 0 & 
\end{cases}
$$
<svg viewBox="0 0 700 550" width="100%" height="auto" xmlns="http://www.w3.org/2000/svg" style="background:#ffffff; border-radius:8px; font-family: 'Comic Sans MS', 'Chalkboard SE', sans-serif;">
  <defs>
    <!-- Motivo a quadretti per lo sfondo -->
    <pattern id="grid" width="20" height="20" patternUnits="userSpaceOnUse">
      <path d="M 20 0 L 0 0 0 20" fill="none" stroke="#e2e8f0" stroke-width="1"/>
    </pattern>
    <!-- Tratteggio a mano per la regione ammissibile -->
    <pattern id="hatch" width="8" height="8" patternTransform="rotate(45 0 0)" patternUnits="userSpaceOnUse">
      <line x1="0" y1="0" x2="0" y2="8" stroke="#475569" stroke-width="1" />
    </pattern>
    <!-- Freccia -->
    <marker id="arrow" viewBox="0 0 10 10" refX="5" refY="5" markerWidth="5" markerHeight="5" orient="auto-start-reverse">
      <path d="M 0 1.5 L 10 5 L 0 8.5 z" fill="#0f172a"/>
    </marker>
  </defs>

  <!-- Sfondo a quadretti -->
  <rect width="100%" height="100%" fill="url(#grid)" />

  <!-- Assi cartesiani -->
  <line x1="80" y1="450" x2="600" y2="450" stroke="#0f172a" stroke-width="2" marker-end="url(#arrow)"/>
  <line x1="120" y1="480" x2="120" y2="50" stroke="#0f172a" stroke-width="2" marker-end="url(#arrow)"/>
  
  <text x="590" y="475" font-size="16" fill="#0f172a">x₁</text>
  <text x="90" y="60" font-size="16" fill="#0f172a">x₂</text>

  <!-- Regione Ammissibile (Poligono con tratteggio) -->
  <polygon points="120,450 310,450 285,400 240,370 120,310" fill="url(#hatch)" stroke="#1e293b" stroke-width="1.5"/>

  <!-- Etichetta interna alla Regione Ammissibile con sfondo semitrasparente per leggibilità -->
  <rect x="135" y="415" width="165" height="22" fill="#ffffff" fill-opacity="0.85" rx="4"/>
  <text x="142" y="431" font-size="13" font-weight="bold" fill="#0f172a">REGIONE AMMISSIBILE</text>

  <!-- Rette dei vincoli -->
  <line x1="120" y1="70" x2="330" y2="490" stroke="#0f172a" stroke-width="1.5"/>
  <line x1="100" y1="276" x2="410" y2="483" stroke="#0f172a" stroke-width="1.5"/>
  <line x1="100" y1="300" x2="450" y2="475" stroke="#0f172a" stroke-width="1.5"/>

  <!-- Punti notevoli e coordinate -->
  <circle cx="310" cy="450" r="3" fill="#0f172a"/>
  <text x="290" y="475" font-size="14">(47.5, 0)</text>

  <circle cx="360" cy="450" r="3" fill="#0f172a"/>
  <text x="345" y="475" font-size="14">(60, 0)</text>

  <circle cx="400" cy="450" r="3" fill="#0f172a"/>
  <text x="385" y="475" font-size="14">(70, 0)</text>

  <circle cx="120" cy="310" r="3" fill="#0f172a"/>
  <text x="50" y="315" font-size="14">(0, 35)</text>

  <circle cx="120" cy="290" r="3" fill="#0f172a"/>
  <text x="50" y="275" font-size="14">(0, 40)</text>

  <circle cx="120" cy="70" r="3" fill="#0f172a"/>
  <text x="50" y="75" font-size="14">(0, 95)</text>
  
  <circle cx="285" cy="400" r="4" fill="#0f172a"/>
  <text x="295" y="395" font-size="14">(41.25, 12.5)</text>

  <circle cx="120" cy="450" r="3" fill="#0f172a"/>
  <text x="95" y="475" font-size="14">O</text>
</svg>



Prendiamo $\begin{cases}2x_1 + x2 = 95 \\ 2x1 + 3x2 = 120\end{cases}$  e attraverso questo troviamo l'intersezione tra il primo e il secondo vincolo: 
- Moltiplichiamo per $-1$ la seconda equazione: $\begin{cases}2x_1 + x2 = 95 \\ -2x1 - 3x2 = -120\end{cases}$
- Viene fuori un unica equazione: $0 - 2x_2 = -25$ e il risultato che viene fuori è $x_2 = \frac{25}{2}$
- Ora risolviamo la prima equazione sostituendo $x_2$ appena trovato: $2x_1 + \frac{25}{2} = 95$
- $4x_1 + 25 = 190 \ \rightarrow \ x_1 = \frac{165}{4}$
- Quindi la soluzione finale è: $\overline{x} = (\frac{165}{4}, \frac{25}{2})$

Se avessi un vincolo con $<$ stretto sarebbe "bucherellato".   

>[!IMPORTANT] Definizione di poliedro:
>- Definizione geometrica: Dicesi poliedro, l'intersezione di un numero finito di semispazi chiusi
>- Definizione algebrica: Dicesi poliedro, le soluzioni di questo sistema di disequazioni: $Ax \le b$

>[!IMPORTANT] RICORDARE SEMPRE CHE LA SOLUZIONE OTTIMA SI TROVA SEMPRE SUL BORDO DEL POLIEDRO

---
## 4. Esercizio
$$
\begin{cases}
\text{max } x_1 + x_2 \\
2x_1 + x_2 \leq 7 \\
x_1 + 3x_2 \leq 8 \\
-x_1 \leq 0 \\
-x_2 \leq 0
\end{cases}
$$
La funzione obiettivo parte con questa idea: $x_1 + x_2 = 0 = c^Tx$
Ora scriviamolo in funzione come se fosse un fascio di rette: $x_1 + x_2 = k,\ k \in \mathbb{R}$ e da qua possiamo introdurre il concetto di **_retta di isoguadagno_**

>[!WARNING] Retta di isoguadagno:
> La retta di isoguadagno è la rappresentazione grafica delle combinazioni di due o più variabili e permette di trovare la soluzione ottima spostando graficamente la funzione obiettivo sul piano cartesiano.

- **Traccia la regione ammissibile:**
    Disegna le rette dei vincoli $2x_1 + x_2 = 7$ e $x_1 + 3x_2 = 8$. I vincoli $-x_1 \le 0$ e $-x_2 \le 0$ si traducono in $x_1 \ge 0$ e $x_2 \ge 0$, limitando l'area al primo quadrante. L'intersezione dei semipiani forma un poligono chiuso.
    
- **Disegna la retta di isoguadagno base ($k=0$):**
    Traccia la retta $x_1 + x_2 = 0$, che passa esattamente per l'origine. Tutti i punti situati su questa retta generano un profitto pari a zero.
    
- **Individua la direzione di crescita (Vettore Gradiente):**
    I coefficienti della funzione obiettivo ($c_1=1, c_2=1$) indicano la direzione in cui il valore di $k$ aumenta. Il vettore $c = (1, 1)$ punta verso l'alto a destra. Spostando la retta perpendicolarmente a questo vettore, otterrai rette parallele con valori di $k$ progressivamente maggiori (es. $x_1 + x_2 = 2$).
    
- **Trasla la retta fino al punto estremo:**
    Fai scorrere un righello parallelamente alla retta $x_1 + x_2 = 0$ muovendoti verso l'alto a destra. Continua a traslare finché non tocchi l'**ultimo punto** (o vertice) della regione ammissibile prima di uscire definitivamente dall'area.
    
- **Calcola le coordinate dell'ottimo:**
    Dal grafico si nota che l'ultimo punto toccato dalla retta traslata è l'intersezione tra i due vincoli strutturali:
$$\begin{cases} 2x_1 + x_2 = 7 \\ x_1 + 3x_2 = 8 \end{cases}$$
    Risolvendo il sistema, si ottiene $x_1 = 2.6$ (oppure $\frac{13}{5}$) e $x_2 = 1.8$ (oppure $\frac{9}{5}$).
    
- **Verifica il valore massimo ($k$ ottimo):**
    Sostituisci le coordinate trovate nella funzione obiettivo originale per trovare il valore di massimo profitto: $k = 2.6 + 1.8 = 4.4$.

>[!WARNING]
> - Matematicamente esistono problemi di PL che hanno soluzione $+\infty$  
>- Se sono presenti troppi vincoli all'interno del sistema, potrebbe essere che non esiste una soluzione ammissibile e quindi, pari all'insieme vuoto

---
## 5. Problema di assegnamento di costo minimo
### Risoluzione problema

| Risorsa / Attività | 1   | 2   | 3   | 4   |
| ------------------ | --- | --- | --- | --- |
| 1                  | 8   | 7   | 9   | 5   |
| 2                  | 12  | 13  | 15  | 16  |
| 3                  | 9   | 14  | 6   | 10  |
| 4                  | 7   | 8   | 11  | 9   |
>[!NOTE]
>Il valore in ogni cella rappresenta il costo associato all'assegnazione della risorsa della riga corrispondente all'attività della colonna corrispondente.

**Numero di soluzioni**
- Il numero totale di soluzioni ammissibili per una matrice di assegnamento è pari a $n!$.
- Nel caso della matrice presentata, essendo $n = 4$, il numero di assegnamenti completi possibili è $4! = 24$.
- Poiché $n!$ ha una crescita di tipo fattoriale, valutare tutte le combinazioni possibili (approccio per enumerazione o "forza bruta") diventa un metodo computazionalmente intrattabile anche per valori di $n$ relativamente piccoli.