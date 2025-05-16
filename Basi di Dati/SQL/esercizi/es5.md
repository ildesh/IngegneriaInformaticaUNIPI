>[!TIP]
> Nome e cognome dei pazienti di Roma e Napoli visitati al più cinque volte in almeno due specializzazioni
>
> ```SQL
> SELECT P.Nome, P.Cognome
> FROM Visita V
> INNER JOIN Paziente P ON V.Paziente = P.CodFiscale
> INNER JOIN Medico M ON V.Medico = M.Matricola
> WHERE (P.Citta = 'Pisa' OR P.Citta = 'Napoli') 
> GROUP BY V.Paziente
> HAVING COUNT(DISTINCT M.Specializzazione) >= 2 AND  COUNT(*) <= 5;
> ```

>[!WARNING]
> Ma la query sopra è sbagliata perché fa la sorta di *pappone*—mischia filtri e condizioni di WHERE, GROUP BY, e HAVING senza la dovuta chiarezza, e il risultato può essere scorretto.

>[!TIP]
>La query corretta è la seguente:
> ```SQL
> WITH coppie_target AS(
>	SELECT V.Paziente, M.Specializzazione, P.Nome, P.Cognome
>	FROM Visita V
>	INNER JOIN Paziente P ON V.Paziente = P.CodFiscale
>	INNER JOIN Medico M ON V.Medico = M.Matricola
>	WHERE (P.Citta = 'Pisa' OR P.Citta = 'Napoli')
>	GROUP BY V.Paziente, M.Specializzazione
>	HAVING COUNT(*) <= 5
>)
>
>SELECT CT.Nome, CT.Cognome
>FROM coppie_target CT
>GROUP BY CT.Paziente
>HAVING COUNT(*) >= 2;


> [!NOTE]
>
> ### Spiegazione:
>
> La query utilizza una CTE (`coppie_target`) per selezionare tutte le **coppie paziente-specializzazione** in cui:
>
> * Il paziente è di Roma o Napoli
> * Il numero di visite in quella specifica specializzazione è al più 5
>
> Successivamente, nel `SELECT` finale, si raggruppano le coppie per paziente e si verifica che ci siano **almeno 2 specializzazioni diverse** (cioè almeno due righe nel gruppo), soddisfacendo così la condizione richiesta.


> [!IMPORTANT]
> Il ***DISTINCT*** non serve perché la `GROUP BY` nella CTE già restituisce **una sola riga per ogni coppia paziente-specializzazione**:
>
> * Se un paziente ha 3 visite con cardiologi e 2 con ortopedici, avremo **una riga per ciascuna specializzazione** (se ognuna ha al massimo 5 visite).
> * Quindi, nel conteggio finale non ci sono duplicati da eliminare: ogni riga rappresenta una specializzazione distinta già filtrata.

---
