# Lezione 3 - 05/03/2025

## | Algebra Relazionale

>[!TIP] Che cos'è l'algebra relazionale ?
> L'algebra relazionale è un insieme di operazioni matematiche che definiscono le manipolazioni di dati in un database relazionale. Ogni operazione agisce su una o più relazioni (tabelle) e restituisce un'altra relazione come risultato. L'algebra relazionale è la base teorica dei linguaggi di query, come SQL, ed è fondamentale per la gestione delle basi di dati relazionali.

### Linguaggi per le basi di dati:

Esistono due tipi di categorie di operazioni:
1. Operazioni sullo **schema**
   1. **_Data Definition Language_** (DDL);
2. Operazioni sui **dati**
   1. **_Data Manipulation Language_** (DML)
      1. Interrogazione (query)
      2. Aggironamento (update)

### Linguaggi di interrogazione per le basi di dati
1. >[!TIP] Cosa si intende per interrogazione?
    > L'interrogazione è un'**_operazione di lettura_** sulla base di dati che può richiedere l'accesso a **più di una tabella**.
2. >[!TIP] Cosa è necessario fare per specificare il significato di una interrogazione?
    > Due formalismi
    > 1. **_Modo dichiarativo_**: si specificano le proprietà del risultato ("che cosa");
    > 2. **_Modo procedurale_**: si specificano le modalità di generazione del risultato ("come").

Si definisce il **comportamento** delle interrogazioni in **modo preocedurale** utilizzando le espressioni dell'algebra relazionale.

Si definisce qual è il risultato di un'interrogazione in **modo dichiarativo** utilizzando le espressioni del calcolo relazionale

- Il calcolo relazionale è l'effettiva semantica del linguaggio
    - Le interrogazioni sono esprese ad alto livello
        - **_NESSUN concetto di costo_**

- Con l'algebra relazionale si può invece **introdurre il concetto di costo**.

1. **Algebra = _dati_ + _operatori_**

2. **Algebra relazionale**:
   - _Dati_: relazioni
   - _Operazioni_:
     - su relazioni,
     - che producono relazioni,
     - e che possono essere scomposti

### Operatori dell'Algebra Relazionale:

Esistono due tipologie di opeartori:
1. **_Operatori su insiemi_**:
   1. Unione, Intersezione, Differenza
2. **_Operatori su relazioni_**:
   1. Ridenominazione, Selezione, Proiezione, Join
>[!NOTE]
>(_Riguardo al join_) --> naturale, prodotto cartesiano, theta.

#### Notazione:

- R, R<sub>1</sub>,R<sub>2</sub>,... indicano nomi di relazioni
- A,B,C,A<sub>1</sub>,A<sub>2</sub>,... indicanon nomi di attributo
- X,Y,X<sub>1</sub>,X<sub>2</sub>... indicano insiemi di attributi
- XY è un'abbreviazione di X U Y
- Una relazione con n-uple t<sub>1</sub>, t<sub>2</sub>,...,t<sub>n</sub> è indicata con l'insieme { t<sub>1</sub>, t<sub>2</sub>,...,t<sub>n</sub> }
- t<sub>i</sub>[A<sub>j</sub>] indica il valore dell'attributo A<sub>j</sub> nella n-upla t<sub>i</sub>
- t[X] indica l'n-upla ottenuta da t considerando solo gli attributi in X

##### Esempio:

| ID  | Nome     | Età | Corso      |
| --- | -------- | --- | ---------- |
| 1   | Maria    | 22  | Ingegneria |
| 2   | Luigi    | 23  | Matematica |
| 3   | Sara     | 21  | Informatica |

- t<sub>2</sub>[Nome] = "Luigi"
- t<sub>1</sub>[Corso] = "Ingegneria"
- t<sub>3</sub>[X] = {21} (se X = {Età})
- t<sub>2</sub>[X] = {Luigi, Matematica} (se X = {Nome, Corso})

### Opeartori su insiemi (con esempi):

- _**Unione**_
  - **L'operazione di unione** permette di combinare i dati di due relazioni (tabelle) che hanno lo stesso schema, ossia le stesse colonne (attributi). L'unione restituisce tutte le righe che appaiono in entrambe le relazioni, eliminando i duplicati. (**R1 ∪ R2**)
  - #### Esempio:
    
    Tabella Studenti_Corso_A

    | ID  | Nome     |
    | --- | -------- |
    | 1   | Maria    |
    | 2   | Luigi    |

    Tabella Studenti_Corso_B

    | ID  | Nome     |
    | --- | -------- |
    | 2   | Luigi    |
    | 3   | Sara     |

    Tabella Studenti_Corso_A ∪ Studenti_Corso_B (Unione)

    | ID  | Nome     |
    | --- | -------- |
    | 1   | Maria    |
    | 2   | Luigi    |
    | 3   | Sara     |

- _**Intersezione**_
  - **L'operazione di intersezione** restituisce le righe che sono comuni a entrambe le relazioni. A differenza dell'unione, l'intersezione mantiene solo gli elementi che si trovano in entrambe le tabelle. (**R1 ∩ R2**)

  - #### Esempio:

    Tabella Studenti_Corso_A

    | ID  | Nome     |
    | --- | -------- |
    | 1   | Maria    |
    | 2   | Luigi    |

    Tabella Studenti_Corso_B

    | ID  | Nome     |
    | --- | -------- |
    | 2   | Luigi    |
    | 3   | Sara     |

    Tabella Studenti_Corso_A ∩ Studenti_Corso_B (Intersezione)

    | ID  | Nome     |
    | --- | -------- |
    | 2   | Luigi    |

- _**Differenza**_
  - **L'operazione di differenza** restituisce le righe che sono presenti in una relazione ma non nell'altra. In altre parole, restituisce gli elementi che appartengono alla prima relazione ma non alla seconda. (**R1 - R2**)
  - #### Esempio:

    Tabella Studenti_Corso_A

    | ID  | Nome     |
    | --- | -------- |
    | 1   | Maria    |
    | 2   | Luigi    |

    Tabella Studenti_Corso_B

    | ID  | Nome     |
    | --- | -------- |
    | 2   | Luigi    |
    | 3   | Sara     |

    Tabella Studenti_Corso_A ∩ Studenti_Corso_B (Intersezione)

    | ID  | Nome     |
    | --- | -------- |
    | 1   | Maria    |

- (_**Unione Impossibile?**_) (esempio con Paternità e Meternità (attributi Padre figlio e Madre figlio))
  - L'operazione di unione è possibile **SOLO se le due relazioni hanno lo stesso schema** (cioè lo stesso numero di colonne e gli stessi nomi di attributi). 
  
    Quindi, se le due tabelle hanno attributi diversi, l'unione non è possibile.

  - #### Esempio:

    Tabella Paternità

    | Padre   | Figlio  |
    | ------- | ------- |
    | Marco   | Luca    |
    | Giovanni| Sara    |

    Tabella Maternità

    | Madre   | Figlio  |
    | ------- | ------- |
    | Laura   | Luca    |
    | Maria   | Sara    |

- Se provi a fare un'unione tra queste due tabelle, non sarebbe possibile perché hanno lo stesso attributo (Figlio), ma l'altro attributo è diverso: Padre nella prima tabella e Madre nella seconda. Quindi, l'unione tra queste due tabelle non è valida senza una trasformazione, come rinominare gli attributi o aggiungere un attributo che rappresenti la relazione in modo uniforme.

Per risolvere questa unione entra in gioco la  **_Ridenominazione_**:
  - Operatore con un solo opearando ("monadico");
  - Modifica lo schema dell' operando, lasciandone inalterata l'istanza
  - Data una relazione R, in genereale, questo operatore si scrive come:

<strong>

$$
\rho_{B_1, B_2, \dots, B_n \leftarrow A_1, A_2, \dots, A_m}(R)
$$

</strong>

da leggersi:
1. L'attributo A<sub>1</sub>, viene sostituido dall'attributo B<sub>1</sub>
2. L'attributo A<sub>2</sub>, viene sostituido dall'attributo B<sub>2</sub>
3. e così via...

#### Esempio
_riprendendo l'esempio delle due tabelle maternità & paternità..._

Tabella Paternità (modificata)

| Genitore | Figlio |
| -------- | ------ |
| Marco    | Luca   |
| Giovanni | Sara   |

Tabella Maternità (modificata)

| Genitore | Figlio |
| -------- | ------ |
| Laura    | Luca   |
| Maria    | Sara   |

Tabella Unione (Paternità ∪ Maternità)

| Genitore | Figlio |
| -------- | ------ |
| Marco    | Luca   |
| Giovanni | Sara   |
| Laura    | Luca   |
| Maria    | Sara   |

### Operatori su UN SOLO insieme:
- Operatore di Selezione:
  - 
    - L'operatore di selezione è un operatore monadico che permette di estrarre un sottoinsieme di tuple che soddisfano una determinata condizione (predicato).
    
        L'operatore di selezione viene scritto come:

        $$
        \sigma_{\text{condizione}}(𝑅)
        $$

      - **𝜎** è _l'operatore di selezione_.
      - **condizione** è un _predicato che definisce le tuple da selezionare (ad esempio, "Età > 21")_.
      - **𝑅** è la _relazione su cui l'operatore di selezione viene applicato_.

    - Esempio:
    
        Immagina di avere una relazione Studenti con gli attributi ID, Nome ed Età:

        | ID  | Nome  | Età |
        | --- | ----- | --- |
        | 1   | Maria | 22  |
        | 2   | Luigi | 23  |
        | 3   | Sara  | 21  |

        L'operatore di selezione per ottenere tutti gli studenti con Età > 21 sarebbe:

        $$
        \sigma_{\text{Età > 21}}(Studenti)
        $$

        Il risultato sarebbe:

        | ID  | Nome  | Età |
        | --- | ----- | --- |
        | 1   | Maria | 22  |
        | 2   | Luigi | 23  |

        L'operatore di selezione estrae solo le tuple che soddisfano la condizione specificata.


- Operatore di Proiezione
  - 
  - L'operatore di proiezione è un operatore monadico che seleziona un sottoinsieme di attributi (colonne) da una relazione, eliminando gli altri attributi. La proiezione restituisce una nuova relazione che contiene solo gli attributi specificati.

    L'operatore di proiezione viene scritto come:

    $$
    \pi_{A_1, A_2, \dots, A_n}(R)
    $$

    - 𝜋 è l'operatore di proiezione.
    - 𝐴₁, 𝐴₂, …, 𝐴ₙ sono gli attributi da selezionare dalla relazione.
    - 𝑅 è la relazione da cui si estraggono gli attributi.
  - Esempio:

    Immagina di avere una relazione Studenti con gli attributi ID, Nome, ed Età:

    |ID|Nome |Età|
    |--|-----|---|
    |1 |Maria|22 |
    |2 |Luigi|23 |
    |3 |Sara |21 |

    L'operatore di proiezione per selezionare solo gli attributi Nome e Età sarebbe:

    $$
    \pi_{Nome,Età}(Studenti)
    $$

    Il risultato sarebbe:

    |Nome |Età|
    |-----|---|
    |Maria|22 |
    |Luigi|23 |
    |Sara |21 |
    
    <br>

    >[!TIP] Cardinalità delle Proiezioni
    > Una proiezione può contenere al più tante n-uple quante ne ha l'operando e contenerne di meno
    > Se X è una superchiave di R allora 𝜋<sub>X</sub>(R) contiene esattamente tante tuple quante ne ha R. 

    >[!IMPORTANT] RICORDA!
    >I valori degli altributi di quella tupla la identificano univocamente!
    
    >COSA CAZZO VUOL DIRE cit. prof

### Proiezione e Selezione:

- Selezione **_σ_** : decomposizione **orizzontale**
- Proiezione **_𝜋_**: decompozione **verticale**

#### Esempio:
>[!TIP]Calcola matricola e cognome degli iimpiegati che guadagnano più di 50000:
>
>| Matricola | Cognome | Filiale  | Stipendio |
>|-----------|---------|----------|-----------|
>| 1001      | Rossi   | Milano   | 60000     |
>| 1002      | Bianchi | Roma     | 45000     |
>| 1003      | Verdi   | Milano   | 55000     |
>| 1004      | Neri    | Torino   | 70000     |

>[!WARNING] Eseguiamo prima una selezione per la condizione "stipendio > 50000" e poi in seguito una proiezione per estrarre solo le colonne "Matricola" e "Cognome".


### Passo 1. Selezione

La selezione per gli impiegati che guadagnano più di 50.000 è espressa come:

$$
\sigma_{\text{Stipendio} > 50000}(\text{Impiegati})
$$

Possiamo scrivere sotto l'espressione:

$$

$$

e rappresentarla con la seguente tabella:

| Matricola | Cognome | Filiale  | Stipendio |
|-----------|---------|----------|-----------|
| 1001      | Rossi   | Milano   | 60000     |
| 1003      | Verdi   | Milano   | 55000     |
| 1004      | Neri    | Torino   | 70000     |

### Passo 2: Proiezione

Dopo aver effettuato la selezione, applichiamo la proiezione per estrarre solo le colonne "Matricola" e "Cognome". L'operazione di proiezione è espressa come:

$$
\pi_{\text{Matricola}, \text{Cognome}}(\sigma_{\text{Stipendio} > 50000}(\text{Impiegati}))
$$

Il risultato della proiezione sarà:

| Matricola | Cognome |
|-----------|---------|
| 1001      | Rossi   |
| 1003      | Verdi   |
| 1004      | Neri    |



>[!NOTE] Note - Possiamo dunque dire che... 
> - Combinando selezione e proiezione possiao estrarre informazioni da **una sola** relazione
> - **NON** possiamo **combinare informazioni** presenti in **relazioni diverse**
> - **NON** possiamo combinare informazioni presenti in **n-uple diverse della stessa relazione**

