<h1> Lezione 2 </h1>

---

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
    - [5. Join con Condizioni sui Record](#5-join-con-condizioni-sui-record)
      - [Esempio di Join con Condizione](#esempio-di-join-con-condizione)
    - [6. Join Multipli](#6-join-multipli)
      - [Esempio di Join Multiplo](#esempio-di-join-multiplo)
    - [7. Ambiguità e Alias](#7-ambiguità-e-alias)
      - [Esempio con Alias](#esempio-con-alias)
    - [8. Self Join](#8-self-join)
      - [Esempio di Self Join](#esempio-di-self-join)
    - [9. Derived Table](#9-derived-table)
      - [Esempio di Derived Table](#esempio-di-derived-table)
  - [✅ Riepilogo Tipi di JOIN](#-riepilogo-tipi-di-join)

---

# Join

## A cosa serve?

Il join dà la possibilità di **combinare i dati di più tabelle**.

Esistono più tipi di JOIN:

1. natural join
2. inner join
3. left outer join
4. cross join
5. right outer join
6. self join

---

### 1. Inner Join (⨝)

Combina record della prima tabella con quelli della seconda **che verificano una condizione**.

#### Esempio dell'Inner Join

```SQL
SELECT DISTINCT M.Nome, M.Cognome
FROM Visita V 
    INNER JOIN Medico M ON V.Medico = M.Matricola;
```

---

### 2. Natural Join

Combina record con **valori uguali su tutti gli attributi omonimi**.

#### Esempio del natural join

```SQL
SELECT DISTINCT M.Nome, M.cognome
FROM Visita V
    NATURAL JOIN Medico M;
```

> [!WARNING]
> Nel database Clinica questo join naturale non è fattibile: gli attributi hanno nome diverso!

---

### 3. Cross Join

Restituisce tutte le possibili combinazioni tra i record delle due tabelle.

#### Esempio di un Cross Join

```SQL
SELECT COUNT(DISTINCT P.CodFiscale)
FROM Paziente P
    CROSS JOIN Medico M
WHERE P.Nome = M.Nome;
```

> [!WARNING]
> Serve `DISTINCT` perché un paziente può avere il nome uguale a più medici.

---

### 4. Join Esterni

Mantenendo **tutti** i record da una tabella, anche se non trovano corrispondenza.

#### 4.1 Join esterno sinistro (⟕):

```SQL
SELECT V.*
FROM Visita V 
    LEFT OUTER JOIN Medico M ON V.Medico = M.Matricola
WHERE M.Matricola IS NULL;
```

#### 4.2 Join esterno destro (⟖):

```SQL
SELECT M.Matricola, M.Cognome, M.Specializzazione
FROM Visita V 
    RIGHT OUTER JOIN Medico M ON V.Medico = M.Matricola
WHERE V.Medico IS NULL;
```

---

### 5. Join con Condizioni sui Record

La clausola `WHERE` filtra **dopo** il join per selezionare solo i record di interesse.

#### Esempio di Join con Condizione

Indicare matricola, cognome e specializzazione dei medici che hanno visitato il 1° Marzo 2013:

```SQL
SELECT DISTINCT M.Matricola, M.Cognome, M.Specializzazione
FROM Medico M 
    INNER JOIN Visita V ON M.Matricola = V.Medico
WHERE V.Data = '2013-03-01';
```

---

### 6. Join Multipli

È possibile fare il join di **più di due tabelle**.

#### Esempio di Join Multiplo

Indicare nome e cognome dei pazienti visitati dal dott. Rino Neri:

```SQL
SELECT DISTINCT P.Nome, P.Cognome
FROM Paziente P 
    INNER JOIN Visita V ON P.CodFiscale = V.Paziente
    INNER JOIN Medico M ON V.Medico = M.Matricola
WHERE M.Nome = 'Rino' AND M.Cognome = 'Neri';
```

---

### 7. Ambiguità e Alias

Quando più tabelle hanno attributi con lo stesso nome (**Nome**, **Cognome**), servono alias per evitare ambiguità.

#### Esempio con Alias

Indicare nome e cognome dei pazienti visitati nel Dicembre 2013, e nome e cognome dei medici:

```SQL
SELECT DISTINCT 
    P.Nome AS NomePaziente, P.Cognome AS CognomePaziente,
    M.Nome AS NomeMedico, M.Cognome AS CognomeMedico
FROM Paziente P 
    INNER JOIN Visita V ON P.CodFiscale = V.Paziente
    INNER JOIN Medico M ON V.Medico = M.Matricola
WHERE YEAR(V.Data) = 2013 AND MONTH(V.Data) = 12;
```

---

### 8. Self Join

Combina una tabella con sé stessa, utile per confronti tra righe.

#### Esempio di Self Join

Indicare i pazienti visitati **più di una volta** dallo stesso medico nel mese corrente:

```SQL
SELECT DISTINCT V1.Paziente
FROM Visita V1  
    INNER JOIN Visita V2 
        ON V2.Medico = V1.Medico 
           AND V2.Paziente = V1.Paziente 
           AND V2.Data <> V1.Data 
WHERE MONTH(V1.Data) = MONTH(CURRENT_DATE)        
  AND YEAR(V1.Data) = YEAR(CURRENT_DATE)
  AND MONTH(V2.Data) = MONTH(CURRENT_DATE)
  AND YEAR(V2.Data) = YEAR(CURRENT_DATE);
```

---

### 9. Derived Table

Sono **sottoquery nel FROM** che creano tabelle temporanee.

#### Esempio di Derived Table

Indicare la matricola dei medici che **non hanno mai visitato** di giovedì:

```SQL
SELECT DISTINCT V1.Medico
FROM Visita V1 
    LEFT OUTER JOIN (
        SELECT V2.Medico
        FROM Visita V2
        WHERE DAYOFWEEK(V2.Data) = 4 -- Giovedì
    ) AS D ON V1.Medico = D.Medico
WHERE D.Medico IS NULL;
```

> [!WARNING]
> L'alias `AS D` è **obbligatorio** nella derived table.

---

## ✅ Riepilogo Tipi di JOIN

| Tipo di JOIN             | Restituisce...                                             |
| ------------------------ | ---------------------------------------------------------- |
| **Inner Join (⨝)**       | Solo i record **con corrispondenza** tra le due tabelle    |
| **Natural Join**         | Come inner join, ma su **tutti gli attributi omonimi**     |
| **Cross Join**           | Il prodotto cartesiano (tutte le combinazioni possibili)   |
| **Left Outer Join (⟕)**  | Tutti i record della tabella sinistra + match dalla destra |
| **Right Outer Join (⟖)** | Tutti i record della tabella destra + match dalla sinistra |
| **Full Outer Join (⟗)**  | Tutti i record di entrambe le tabelle (match + non match)  |
| **Self Join**            | Join della tabella con sé stessa                           |

---
