<h1> Lezione 5 SQL - 08/05/2025 </h1>

<h1> Indice </h1>

- [Stored procedure](#stored-procedure)
  - [Che cosa sono le stored procedure](#che-cosa-sono-le-stored-procedure)
    - [Accesso diretto ai dati](#accesso-diretto-ai-dati)
  - [Sicurezza](#sicurezza)
      - [Esempio:](#esempio)
- [Variabili Locali](#variabili-locali)
  - [Che cosa sono le variabili locali](#che-cosa-sono-le-variabili-locali)
  - [Sintassi:](#sintassi)
- [Assegnamento](#assegnamento)
  - [Su cosa si basa l'assegnamento?](#su-cosa-si-basa-lassegnamento)
    - [1. Assegnamento statico con SET (esempio):](#1-assegnamento-statico-con-set-esempio)
    - [2. Assegnamento calcolato con SELECT+INTO](#2-assegnamento-calcolato-con-selectinto)
- [Variabili user-defined:](#variabili-user-defined)
  - [Che cosa sono?](#che-cosa-sono)
- [Tipologie di parametro](#tipologie-di-parametro)
  - [Che cosa sono?](#che-cosa-sono-1)
    - [1. Ingresso](#1-ingresso)
      - [Esempio dell'ingresso:](#esempio-dellingresso)
    - [2. Uscita](#2-uscita)
      - [Esempio di Uscita](#esempio-di-uscita)
- [Istruzioni condizionali](#istruzioni-condizionali)
  - [Che cosa sono?](#che-cosa-sono-2)
    - [1. Esempio `IF`:](#1-esempio-if)
    - [2. Esempio `CASE`](#2-esempio-case)
- [Istruzioni iterative](#istruzioni-iterative)
  - [Che cosa sono:](#che-cosa-sono-3)
    - [1. While](#1-while)
    - [2. Repeat](#2-repeat)

---

# Stored procedure

## Che cosa sono le stored procedure

Le stored procedure sono programmi dichiarativo-procedurali _(invocate tramite chiamata e possono ricevere e/o restituire valori)_ memorizzati nel DBMS _(supportate dalla versione 5.0 di MySQL)_.

Queste possono essere considerate come un servizio che gli utenti delle applicazioni che usano il database possono **utilizzare senza scrivere codice**.

### Accesso diretto ai dati

COMPUTER --- SELECT FROM WHERE... ----> DBMS

I dati devono essere accessibili e si deve padroneggiare l'uso di SQL

## Sicurezza
Le applicazioni possono essere autorizzate a eseguire stored procedure, ma **avere accesso vietato alle tabelle**

>[!NOTE]
> - Il codice può essere mascherato
> - Restrizioni impostate con opportuni grant
> - I dati grezzi non sono visibili

#### Esempio:

>[!TIP]
>Scrivere una stored procedure che restituisca le specializzazioni mediche offerte dalla clinica

```SQL
DROP PROCEDURE IF EXISTS mostra_specializzazioni;

DELIMITER $$

CREATE PROCEDURE mostra_specializzazioni( )
    BEGIN
        SELECT DISTINCT Specializzazione
        FROM Medico;
    END $$

DELIMITER;
```

- Esecuzione

```terminal
QUERY                                            | Message |
-------------------------------------------------|---------|
DROP PROCEDURE IF EXIST mostra_specializzazioni  |  OK     |
CREATE PROCEDURE mostra_specializzazioni()       |  OK     |
```

>[!NOTE]
> ### Storing...
>Eseguire questo codice effettua la compilazione e lo stoccaggio nel DBMS
> ### Chiamata
> ```SQL
> CALL mostra_specializzazioni( );
> ```
> La chiamata esegue la stored procedure e ottiene
il risultato restituito dall’esecuzione del body

---

# Variabili Locali

## Che cosa sono le variabili locali

Sono usate all’interno di una stored procedure,
per memorizzare informazioni intermedie di ausilio

>[!WARNING]
> DEVONO ESSERE DICHIARATE TUTTE INSIEME ALL'INIZIO DEL BODY!

## Sintassi:

```SQL
DECLARE nom>e_variabile tipo(size) DEFAULT valore_default
```

- **`DECLARE nome_variabile tipo(size)`**: viene dichiarato un int,double,char,varchar,date,datetime (tipizzazione forte, non si possono dichiarare senza specificare il tipo)
- **`(size)`**: capacità della variabile (se non settata, è il valore default del tipo di dato)
- **`DEFAULT valore_default`**: senza default value, il valore iniziale è `NULL`

---

# Assegnamento
## Su cosa si basa l'assegnamento?

È possibile assegnare un valore a una variabile in due modalità:
- **`istruzione SET`**
- **`istruzione SELECT+INTO`**

### 1. Assegnamento statico con SET (esempio):

Supporre di essere nel body di una stored procedure e creare una variabile contenente il minimo numero di visite mensili da effettuare, impostato a 20.

```SQL
DECLARE min_visite_mensili INT DEFAULT 0;
-- .
-- .
-- .
SET min_visite_mensili = 20;
```

>[!WARNING]
> la sintassi imporrebbe l'uso di :=, ma i due punti si possono essere omessi se si usa l'istruzione SET.

### 2. Assegnamento calcolato con SELECT+INTO

Supporre di essere nel body di una stored procedure e creare una variabile contenente il numero di visite effettuate nel mese in corso

```SQL
DECLARE visite_mese_attuale INT DEFAULT 0;
-- .
-- .
-- .
SELECT COUNT(*) INTO visite_mese_attuale
FROM Visita V
WHERE MONTH(V.Data) = MONTH(CURRENT_DATE)
    AND YEAR(V.Data) = YEAR(CURRENT_DATE);


```
SELECT COUNT(*)
FROM Visita V
WHERE MONTH(V.Data) = MONTH(CURRENT_DATE)
    AND YEAR(V.Data) = YEAR(CURRENT_DATE)
INTO visite_mese_attuale;

>[!WARNING]
> ```SQL
> DECLARE visite_mese_attuale VARCHAR(255);
> 
> SELECT * INTO visite_mese_attuale
> FROM Visita
> WHERE MONTH(Data) = MONTH(CURRENT_DATE)
> AND YEAR(V.Data) = YEAR(CURRENT_DATE);
> ```
>
> Nel DECLARE una variabile non può contenere un result set.

---

# Variabili user-defined:
## Che cosa sono?

Sono inizializzate dall’utente senza necessità di dichiarazione, e il loro ciclo di vita equivale alla durata della connection a MySQL server.

- il contenuto è visibile ovunque, ma solo all’utente che
le ha inizializzate, sono case insensitive e il loro identificatore deve iniziare con ‘@’

- tipizzazione debole
  - (non si specifica il tipo della variabile, può contenere qualsiasi
tipo di dato, e tipi di dato diversi in istanti diversi).

>[!WARNING]
> Una variabile locale o user-defined (@) è sempre scalare, non può contenere un result set.

---

# Tipologie di parametro
## Che cosa sono?

Una stored procedure MySQL accetta parametri di tipo

- **ingresso**
- **uscita**
- **ingresso-uscita**

### 1. Ingresso

Un parametro in ingresso **_può essere letto_**, ma non modificato

- i parametri sono in ingresso per default
- equivalente al passaggio per valore

#### Esempio dell'ingresso:

```SQL
DROP PROCEDURE IF EXISTS parcella_media_spec;

DELIMITER $$
CREATE PROCEDURE parcella_media_spec(IN _specializzazione VARCHAR(100))
BEGIN
  SELECT AVG(M.Parcella)
  FROM Medico M
  WHERE M.specializzazione = _specializzazione;
END $$
DELIMITER;

-- Chiamata della stored procedure
CALL parcella_media_spec('Ortopedia'); --chiamata
```

>[!NOTE]
>## Esecuzione
>```terminal
>|AVG(Parcella)|
>|-------------|
>|  170.0000   |

---

### 2. Uscita

Un parametro di uscita **_può essere modificato_** per assumere il valore del risultato della stored procedure

- nella chiamata si possono usare variabili user-defined(quelle che iniziano con '@').

#### Esempio di Uscita
```SQL
DROP PROCEDURE IF EXISTS tot_pazienti_visitati_spec;

DELIMITER $$
CREATE PROCEDURE tot_pazienti_visitati_spect(
                 IN _specializzazione VARCHAR(100)
                 OUT totale_pazienti_ INT)
  BEGIN
    SELECT COUNT(DISTINCT V.Paziente) INTO totale_pazienti_
    FROM Visita V
      INNER JOIN
      Medico M ON V.Medico = M.Matricola
    WHERE M.Specializzazione = _specializzazione;
  END $$
DELIMITER;

CALL tot_pazienti_visitati_spect('Neurologia', @quantiPazienti);

SELECT @quantiPazienti;
```

>[!NOTE]
>## Esecuzione
>```terminal
>|@quantiPazienti|
>|---------------|
>|      18       |

---

# Istruzioni condizionali

## Che cosa sono?

Le istruzioni condizionali permettono di esprimere conizioni modificando il flusso di esecuzione

1. istruzione `IF`
2. istruzione `CASE`

- possono contenere letterali, variabili e funzioni

### 1. Esempio `IF`:

La dicitura per l'`IF` è la seguente:

```SQL
IF --condizione
-- blocco istruzione
ELSE --/ELSEIF
-- blocco istruzione
ENDIF
```


>[!TIP]
>Scrivere una stored procedure che riceva come parametro un inter t e una specializzazione s e restituisca in uscita true se il numero di visite della psecializzazione s nel mese in corso p superiore a t, false se è inferiore, e NULL se è uguale
```SQL
DROP PROCEDURE IF EXISTS visite_sopra_soglia

DELIMITER $$
CREATE PROCEDURE visite_sopra_sogla(IN _t INT, IN _s VARCHAR(100), OUT passed BOOLEAN)
BEGIN
  DECLARE visite_mese_attuale INT DEFAULT 0;
  SET visite_mese_attuale = (
      SELECT COUNT (*)
      FROM VISITA V
        INNER JOIN
        Medico M ON V.Medico = M.Matricola
      WHERE M.Specializzazione = _s
        AND MONTH(V.'Data') = MONTH(CURRENT_DATE)
        AND YEAR(V.'Data') = YEAR(CURRENT_DATE)
  );

  IF visite_mese_attuale > _t THEN
    SET passed = TRUE;
  ELSEIF visite_mese_attuale < _t THEN
    SET passed = FALSE;
  ELSE
    SET passed = NULL;
  END IF;
END $$
DELIMITER;

CALL visite_sopra_soglia(10,'Otorinolaringoiatria', @controllo);
```

### 2. Esempio `CASE`

La dicitura in SQL del `CASE` è la seguente:

```SQL
CASE
  WHEN --condizione
   THEN
    -- blocco istruzione
  WHEN --condizione 
   THEN
    -- blocco istruzione
  ELSE
    -- blocco istruzione
END CASE
```

>[!TIP]
>Scrivere una stored procedure che riceva come parametro un intero t e una specializzazione s e restituisca in uscita una stringa che indichi "Sopra soglia" se il numero di visite della specializzazione s nel mese in corso è superiore a t, "Sotto soglia" se è inferiore, e "Uguale alla soglia" se è uguale.

```SQL
DROP PROCEDURE IF EXISTS verifica_visite_soglia;

DELIMITER $$

CREATE PROCEDURE verifica_visite_soglia(IN _t INT, IN _s VARCHAR(100), OUT risultato VARCHAR(50))
BEGIN
  DECLARE visite_mese_attuale INT DEFAULT 0;
  SET visite_mese_attuale = (
      SELECT COUNT(*)
      FROM Visita V
        INNER JOIN
        Medico M ON V.Medico = M.Matricola
      WHERE M.Specializzazione = _s
        AND MONTH(V.Data) = MONTH(CURRENT_DATE)
        AND YEAR(V.Data) = YEAR(CURRENT_DATE)
  );

  CASE
    WHEN visite_mese_attuale > _t THEN
      SET risultato = 'Sopra soglia';
    WHEN visite_mese_attuale < _t THEN
      SET risultato = 'Sotto soglia';
    ELSE
      SET risultato = 'Uguale alla soglia';
  END CASE;
END $$

DELIMITER;

CALL verifica_visite_soglia(10, 'Cardiologia', @esito);

SELECT @esito;
```

---

# Istruzioni iterative

## Che cosa sono:

Le istruzioni iterative permettono di ripetere blocchi di codice, dipendentemente dalla veridicità di una condizione

1. Istruzioni `WHILE`
2. Istruzioni `REPEAT`
3. Istruzioni `LOOP`

- La condizione può valutare anche delle funzioni

### 1. While

La dicitura in SQL per il WHILE è la seguente:

```SQL

WHILE -- condizione
  DO
    -- blocco istruzioni
END WHILE

-- ovviamente il blocco viene eseguito fino a che la condizione del WHILE non diventa FALSE

```

### 2. Repeat

La dicitura in SQL per il REPEAT è la seguente:

```SQL

REPEAT
  -- blocco istruzioni
UNTIL -- condition
END REPEAT;

-- il REPEAT viene eseguito fintantochè non si verifica la condizione
-- (UNTIL contiene una condizione d'uscita)
```

>[!NOTE]
> ## NOTA BENE: 
> Il `REPEAT` in SQL corrisponde al `DO WHILE` negli altri linguaggi di programmazione.