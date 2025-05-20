# Controllo della Concorrenza: Concetti Chiave e Definizioni

---

## 1. Transazioni e Proprietà ACID
> [!IMPORTANT]  
> **Definizione di Transazione**  
> Sequenza di operazioni (letture/scritture) che inizia con `begin`, termina con `commit` o `abort`, e garantisce le proprietà ACID:  
> - **Atomicità**: Effetti visibili solo se commit.  
> - **Isolamento**: Esecuzione concorrente equivalente a seriale.  
> - **Durabilità**: Modifiche commit sono permanenti.  
> - **Consistenza**: DB rimane valido prima/dopo la transazione.

> [!NOTE]  
> **Ipotesi Semplicative**  
> - Ogni transazione legge/scrive un oggetto **al massimo una volta**.  
> - Nessun abort (solo commit).  
> - Operazioni di inserimento/cancellazione ignorate.

---

## 2. Anomalie in Esecuzione Concorrente
> [!WARNING]  
> **Problemi senza Controllo della Concorrenza**  
> 1. **Perdita di Aggiornamento**  
>    - Esempio:  
>      ```  
>      T1: r(x) → x+1 → w(x)  
>      T2: r(x) → x+1 → w(x)  
>      ```  
>      Risultato finale: 3 invece di 4 (se x iniziale = 2).  
> 2. **Lettura Sporca**  
>    - Leggere dati non commitati (es. `T2` legge da `T1` prima di abort).  
> 3. **Letture Inconsistenti**  
>    - Transazione legge valori diversi dello stesso oggetto.  
> 4. **Aggiornamenti Fantasma**  
>    - Violazione vincoli di integrità (es. `y + z = 1000` non mantenuto).

---

## 3. Schedule e Serializzabilità
> [!IMPORTANT]  
> **Definizioni Fondamentali**  
> - **Schedule**: Sequenza di operazioni di transazioni concorrenti che preserva l’ordine interno.  
> - **Schedule Serializzabile**: Equivalente a un esecuzione seriale.  

### 3.1 View Serializzabilità (VSR)
> [!NOTE]  
> **View-Equivalenza**  
> Due schedule sono equivalenti se:  
> - Stessa relazione **"legge-da"** (`LeggeDa(S)`).  
> - Stesse **scritture finali** (`Finali(S)`).  
> - **VSR** = Insieme di schedule view-equivalenti a uno seriale.  
> - **NP-completo** da verificare.

### 3.2 Conflict Serializzabilità (CSR)
> [!TIP]  
> **Conflict-Equivalenza**  
> Due schedule sono conflict-equivalenti se preservano l’ordine delle **operazioni in conflitto**:  
> - Lettura-scrittura (`r_i(x)`, `w_j(x)`).  
> - Scrittura-scrittura (`w_i(x)`, `w_j(x)`).  
> - **CSR** = Schedule conflict-equivalenti a uno seriale.  
> - Verifica tramite **grafo dei conflitti aciclico** (complessità lineare).

> [!IMPORTANT]  
> **Teorema: CSR ⊂ VSR**  
> - Ogni CSR è VSR, ma non viceversa.  
> - Esempio di VSR non CSR:  
>   `r1(x) w2(x) w1(x) w3(x)` è view-equivalente a seriale ma non conflict-serializzabile.

---

## 4. Locking e Two-Phase Locking (2PL)
> [!WARNING]  
> **Tipi di Lock**  
> - **Lock condiviso (RL)**: Per letture (`rl_i(x)`).  
> - **Lock esclusivo (WL)**: Per scritture (`wl_i(x)`).  

> [!IMPORTANT]  
> **Two-Phase Locking (2PL)**  
> 1. **Fase Crescente**: Acquisizione lock (nessun rilascio).  
> 2. **Fase Calante**: Rilascio lock (nessuna acquisizione).  
> - **2PL stretto**: Lock rilasciati solo al commit/abort.  

> [!WARNING]  
> **Deadlock**  
> - Situazione ciclica di attesa (es. `T1` attende `T2`, `T2` attende `T1`).  
> - **Soluzioni**:  
>   - **Timeout**: Abort dopo tempo prefissato.  
>   - **Grafo delle attese**: Rilevazione cicli e abort selettivo.

---

## 5. Grafo dei Conflitti e Serializzabilità
> [!TIP]  
> **Struttura del Grafo**  
> - **Nodi**: Transazioni.  
> - **Archi**: `T_i → T_j` se operazioni in conflitto di `T_i` precedono `T_j`.  
> - **Condizione**: Schedule è CSR ⇨ Grafo aciclico.

**Esempio Pratico**:  
Per lo schedule:  