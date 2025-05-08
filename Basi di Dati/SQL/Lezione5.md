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

Un parametro in ingresso può essere letto, ma non modificato

- i parametri sono in ingresso per default
- equivalente al passaggio per valores

(da pagina 5 a 25 manca LEZIONE 5).