>[!TIP]
> #### Matricola e cognome dei medici che hanno visitato solo pazienti con reddito superiore al reddito medio dei pazienti della loro stessa città.

>[!WARNING]
> Stiamo attenti alla parola "SOLO" perché 

>[!NOTE]
> SOLO di un certo tipo --> MAI di un altro tipo
>
>                           -> NON ESISTE ALTRO TIPO PORTA A FARE UNA SUBQUERY CON **_NOT EXISTS_**

>[!TIP]
> ### E' giusta?
> ```SQL
> WITH A AS(
>     SELECT P.CodFiscale as Paziente
>     FROM Paziente P
>     WHERE P.Reddito > (
>         SELECT AVG(P2.Reddito) as Reddito Medio
>         FROM Paziente P2
>         WHERE P2.Citta = P.Citta
>     )
> )
> 
> SELECT M.Matricola, M.Cognome
> FROM A
> NATURAL JOIN Visita V 
> INNER JOIN Medico M ON V.Medico = M.Matricola;
> ```

>[!WARNING]
> Avendo scritto però questa cosa
> ```SQL
> SELECT M.Matricola, M.Cognome
>FROM A
>NATURAL JOIN Visita V 
>INNER JOIN Medico M ON V.Medico = M.Matricola;
>```
> Sarebbe sbagliata perché non trova **`SOLO`** solo quelli che hanno XXX ma trovi quelli che **`ANCHE`** hanno XXX.

>[!TIP]
> ### E' Giusta?
>
> ```SQL
>WITH PazientiRicchi AS (
>    SELECT P.CodFiscale
>    FROM Paziente P
>    WHERE P.Reddito > (
>        SELECT AVG(P2.Reddito)
>        FROM Paziente P2
>        WHERE P2.Citta = P.Citta
>    )
>),
>VisiteANonRicchi AS (
>    SELECT V.Medico
>    FROM Visita V
>    WHERE V.Paziente NOT IN (
>        SELECT CodFiscale FROM PazientiRicchi
>    )
>)
>
>SELECT DISTINCT M.Matricola, M.Cognome
>FROM Medico M
>JOIN Visita V ON M.Matricola = V.Medico
>LEFT JOIN VisiteANonRicchi VR ON M.Matricola = VR.Medico
>WHERE VR.Medico IS NULL;
>```


---


>[!TIP]
> Matricola dei medici che negli ultimi 5 anni, hanno effettuato un numero di visite annue crescente per almeno un biennio (due anni consecutivi).

> ### 1. Contare le visite annue (per ogni anno) di ogni medico negli ultimi 5 anni
>```SQL
> WITH Visite_annue_med AS(
>   SELECT V.Medico, YEAR(V.Data), count(*) as NVisite
>   FROM Visite V
>   WHERE YEAR(V.Data) > YEAR(current_date - interval 5 year)
>   GROUP BY V.Medico, YEAR(V.Data);
>)

Ecco come puoi **continuare il ragionamento e la scrittura SQL** per completare l’esercizio:

---

> ### 2. Ordinare le visite annue per medico e anno, e confrontare l'anno corrente con quello precedente

```sql
, Visite_confronto AS (
  SELECT 
    V1.Medico,
    YEAR(V1.Data) AS Anno,
    COUNT(*) AS NVisite
  FROM Visite V1
  WHERE YEAR(V1.Data) > YEAR(CURRENT_DATE - INTERVAL 5 YEAR)
  GROUP BY V1.Medico, YEAR(V1.Data)
),
Incrementi AS (
  SELECT 
    V1.Medico,
    V1.Anno AS AnnoCorrente,
    V2.Anno AS AnnoPrecedente,
    V1.NVisite,
    V2.NVisite AS NVisitePrecedente
  FROM Visite_confronto V1
  JOIN Visite_confronto V2 
    ON V1.Medico = V2.Medico 
    AND V1.Anno = V2.Anno + 1
  WHERE V1.NVisite > V2.NVisite
)
```

> ### 3. Trovare i medici che hanno avuto almeno **due incrementi consecutivi** → un biennio crescente

```sql
, BienniCrescenti AS (
  SELECT 
    I1.Medico
  FROM Incrementi I1
  JOIN Incrementi I2 
    ON I1.Medico = I2.Medico 
    AND I1.AnnoCorrente = I2.AnnoPrecedente
  GROUP BY I1.Medico
)

SELECT DISTINCT Medico
FROM BienniCrescenti;
```

---