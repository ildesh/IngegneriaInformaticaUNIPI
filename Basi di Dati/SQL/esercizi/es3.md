## Esercizio 3:

Si consideri la realtà medica descritta dalla base di dati relazionale definita dal seguente schema:

- **_Paziente_**(<u>codice_fiscale</u>, nomePaziente, cognomePaziente, DataNascita, Reddito, Sesso, Città)
- **_Medico_**(<u>matricola</u>, nomeMedico, cognomeMedico, specializzazione, parcella, città)
- **_Visita_**(<u>Medico</u>, <u>Paziente</u>, <u>Data</u>, Mutuata)

>[!NOTE]
> Scrivere una query che, per ogni specializazione, restituisca il numero di medici che, dopo aver visitato la prima volta un paziente, lo hanno visitato una volta all'anno, in almeno la metà degli anni successivi.

---

Risolviamo tramite SQL però prima ragioniamolo:

1. Per ogni medico e paziente, trovare k (anno in cui il paziente e il medico si sono visti la prima volta).
2. Contare in quanti anni successivi N<sub>anniP</sub> a k c'è stata una visita tra i due.
3. Selezionare i medici M tale che N<sub>anniP</sub> > 1/2.anni_successiviK
4. Selezionare le specializzazioni.
5. Contiamo i medici validi.


```SQL
-- 1. Calcoliamo per ogni coppia Medico-Paziente l'anno della prima visita
WITH PrimaVisita AS (
    SELECT 
        V.Medico, 
        V.Paziente, 
        MIN(YEAR(V.Data)) AS AnnoPrimaVisita
    FROM Visita V
    GROUP BY V.Medico, V.Paziente
),

-- 2. Contiamo in quanti anni successivi c'è stata almeno una visita
VisitePerAnno AS (
    SELECT 
        V.Medico, 
        V.Paziente, 
        YEAR(V.Data) AS AnnoVisita
    FROM Visita V
    GROUP BY V.Medico, V.Paziente, YEAR(V.Data)
),

-- 3. Per ogni medico-paziente calcoliamo:
-- - il numero di anni in cui si sono visti (AnniVisitati)
-- - il numero di anni totali dal primo incontro (AnniSuccessivi)
ContaAnni AS (
    SELECT 
        P.Medico,
        P.Paziente,
        P.AnnoPrimaVisita,
        COUNT(*) AS AnniVisitati,
        MAX(V.AnnoVisita) - P.AnnoPrimaVisita + 1 AS AnniSuccessivi
    FROM PrimaVisita P
    JOIN VisitePerAnno V 
        ON P.Medico = V.Medico AND P.Paziente = V.Paziente
    GROUP BY P.Medico, P.Paziente, P.AnnoPrimaVisita
),

-- 4. Selezioniamo i medici che hanno visto almeno la metà degli anni successivi
MediciValidi AS (
    SELECT 
        C.Medico
    FROM ContaAnni C
    WHERE C.AnniVisitati >= (C.AnniSuccessivi / 2.0)  -- /2.0 per forza floating point
    GROUP BY C.Medico
)

-- 5. Per ogni specializzazione, contiamo i medici validi
SELECT 
    M.specializzazione, 
    COUNT(DISTINCT M.matricola) AS NumMedici
FROM Medico M
JOIN MediciValidi MV ON M.matricola = MV.Medico
GROUP BY M.specializzazione;


```