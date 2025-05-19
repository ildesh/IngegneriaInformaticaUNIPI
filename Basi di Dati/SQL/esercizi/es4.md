## Esercizio 4:

```SQL
SELECT M.Specializzazzione
FROM Medico M
GROUP BY M.specializzazione
HAVING COUNT (DISTINCT M.Città) = 1;
```

>[!TIP]
> ### Che cosa fa questa parte di SQL?
> Seleziona le specializzazioni in cui i medici risultano associati a una sola città nel database.

---

```SQL
SELECT M.Specializzazzione
FROM Medico M
GROUP BY M.specializzazione
HAVING COUNT (*) = 1;
```

>[!TIP]
> ### Che cosa fa questa parte di SQL?
> Seleziona le specializzazioni che hanno esattamente un solo medico registrato nel database.

---

Complichiamo un po':

```SQL
SELECT DISTINCT M.Matricola
FROM Medico M
WHERE NOT EXISTS (
    SELECT *
    FROM Medico M2
    WHERE M2.Specializzazione <> M.Specializzazione;
    -- <> significa diverso
)
```

>[!TIP]
> ### Che cosa fa questa parte di SQL?
> Seleziona la matricola dei medici solo se tutti i medici del database hanno la stessa specializzazione.