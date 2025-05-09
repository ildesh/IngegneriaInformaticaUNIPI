<h1> Lezione 2 - </h1>

<h1> Indice </h1>

- [Join](#join)
  - [A cosa serve?](#a-cosa-serve)
    - [1. Inner Join (⨝)](#1-inner-join-)
      - [Esempio dell'Inner Join](#esempio-dellinner-join)
    - [2. Natural Join](#2-natural-join)
      - [Esempio del natural join](#esempio-del-natural-join)
    - [3. Cross Join](#3-cross-join)
      - [Esempio di un Cross Join](#esempio-di-un-cross-join)
    - [4. Join Esterni](#4-join-esterni)
      - [4.1 Join esterno sinistro (⟕):](#41-join-esterno-sinistro-)
      - [4.2 Join esterno destro (⟖):](#42-join-esterno-destro-)


---

# Join
## A cosa serve?

Il join dà la possibilità di **combinare i dati di più tabelle**

Esistono più tipi di JOIN:
1. natural join
2. inner join 
3. left outer join
4. cross join
5. right outer join
6. self join

---

### 1. Inner Join (⨝)

Date due tabelle, combina ogni record della prima con tutti i record della seconda **che verificano una determinata condizione**.

- Affianca i due record per formarne uno solo
- Predicato del Join

#### Esempio dell'Inner Join

>[!TIP]
> Indicare nome e cognome dei medice che hanno effettuato almeno una visita

```SQL
SELECT DISTINCT M.Nome, M.Cognome -- M = alias per la tabella Medico
FROM Visita V -- V = alias per la tabella Visita
    INNER JOIN
    Medico M ON V.Medico = M.Matricola;
```

---

### 2. Natural Join

Combina i record della prima tabella con i record della seconda tabella aventi valori uguali sugli attributi omonimi (TUTTI).

#### Esempio del natural join

>[!TIP]
>Indicare nome e cognome dei medici che hanno effettuato almeno una visita

```SQL
SELECT DISTINCT M.Nome, M.cognome
FROM Visita V
    NATURAL JOIN
    Medico M;
```

>[!WARNING]
> Nel databasae Clinica questo join naturale non è fattibile, gli attributi hanno nome diverso!!!
> Il predicato è implicito: 
> - V.ID_Medico = M.ID_Medico (sono gli unici attributi)
> - Gli attributi omonimi devono rappresentare lo stesso concetto!!!

---

### 3. Cross Join

Restituisce tutte le possibili combinazioni di ciascun record della prima tabella con tutti i record della seconda tabella.

- il Join può essere pensato come un prodotto cartesiano con condizione

#### Esempio di un Cross Join

>[!TIP]
> Indicare il numero di pazienti aventi nome uguale ad almeno un medico della clinica

```SQL
SELECT COUNT(DISTINCT P.CodFiscale)
FROM Paziente P
    CROSS JOIN
    Medico M
WHERE P.Nome = M.Nome;
```

>[!WARNING]
> ### ATTENZIONE: 
> serve distinct perché un paziente può avere il nome uguale a più di un medico.

---

### 4. Join Esterni

Date due tabelle, combinano ogni record della prima con tutti i record della seconda che soddisfano una condizione, mantenendo tutti i record di una delle due tabelle
- diverso da inner join che invece scarta i record che non fanno join

#### 4.1 Join esterno sinistro (⟕):
Combina ogni record della tabella sinistra con i record della tabella destra che soddisfano una condizione, mantenendo tutti i record della tabella di sinistra

#### 4.2 Join esterno destro (⟖):
Combina ogni record della tabella destra con i record della tabella sinistra che soddisfano una condizione, mantenendo tutti i record della tabella di destra