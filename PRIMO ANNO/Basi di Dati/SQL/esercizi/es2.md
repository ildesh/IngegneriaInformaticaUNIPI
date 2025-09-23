## Esercizio 2:

>[!NOTE]
> Indicare nome e cognome dei pazienti che sono stati visitati non meno di due volte dalla dottoressa Gialli Rita.

Risolviamo in SQL questo esercizio, utilizzando una tabella 'Paziente'.

---

- **_MEDICO_**(<u>matricola</u>, nomeMedico, cognomeMedico, specializzazione, parcella, città)
- **_VISITA_**(<u>Medico</u>, <u>Paziente</u>, <u>Data</u>)
- **_PAZIENTE_**(<u>codice_fiscale</u>, nomePaziente, cognomePaziente, DataNascita, Reddito)

MEDICO:
| <u>matricola</u> | nome  | cognome | specializzazione | parcella | città  |
| ---------------- | ----- | ------- | ---------------- | -------- | ------ |
| 123456           | Mario | Rossi   | Cardiologo       | 100      | Roma   |
| 123457           | Rita  | Gialli  | Dentista         | 200      | Milano |
| 123458           | Anna  | Verdi   | Cardiologo       | 150      | Roma   |
| 123459           | Marco | Neri    | Dentista         | 250      | Napoli |


VISITA:
| Medico | Paziente | Data       |
| ------ | -------- | ---------- |
| 123456 | 1        | 2026-01-01 |
| 123457 | 2        | 2024-02-01 |
| 123458 | 3        | 2022-03-01 |
| 123459 | 4        | 2025-04-01 |
| 123456 | 5        | 2024-01-01 |
| 123457 | 6        | 2023-02-01 |

PAZIENTE:
| <u>codice\_fiscale</u> | nome  | cognome | DataNascita | Reddito |
| ---------------------- | ----- | ------- | ----------- | ------- |
| 1                      | Mario | Rossi   | 1990-01-01  | 30000   |
| 2                      | Luca  | Bianchi | 1985-02-01  | 40000   |
| 3                      | Anna  | Verdi   | 1992-03-01  | 35000   |
| 4                      | Marco | Neri    | 1988-04-01  | 45000   |
| 5                      | Rita  | Gialli  | 1995-05-01  | 50000   |
| 6                      | Sara  | Bianchi | 1991-06-01  | 60000   |


```sql
Select P.nome, P.cognome
FROM VISITA V
    INNER JOIN
    MEDICO M ON V.Medico = M.matricola
    INNER JOIN
    PAZIENTE P ON V.Paziente = P.codice_fiscale
WHERE M.nome = 'Rita' AND M.cognome = 'Gialli'
GROUP BY V.paziente, P.nome, P.cognome
HAVING COUNT(V.Paziente) >= 2;
```

Passo dopo passo:

1. **`SELECT`**: Selezioniamo le colonne `nomePaziente` e `cognomePaziente` dalla tabella `PAZIENTE`.
2. **`FROM`**: Indichiamo le tabelle `VISITA`, `MEDICO` e `PAZIENTE` da cui prelevare i dati.
3. **`INNER JOIN`**: Uniamo le tabelle `VISITA`, `MEDICO` e `PAZIENTE` sulle colonne `Medico` e `Paziente` per ottenere i dati del medico associati a ciascuna visita e i dati del paziente.

| Matricola | Paziente | Data       | nomeMedico | cognomeMedico | nomePaziente | cognomePaziente |
| --------- | -------- | ---------- | ---------- | ------------- | ------------ | --------------- |
| 123456    | 1        | 2026-01-01 | Mario      | Rossi         | Mario        | Rossi           |
| 123457    | 2        | 2024-02-01 | Luca       | Bianchi       | Luca         | Bianchi         |
| 123458    | 3        | 2022-03-01 | Anna       | Verdi         | Anna         | Verdi           |
| 123459    | 4        | 2025-04-01 | Marco      | Neri          | Marco        | Neri            |
| 123456    | 5        | 2024-01-01 | Rita       | Gialli        | Rita         | Gialli          |
| 123457    | 6        | 2023-02-01 | Sara       | Bianchi       | Sara         | Bianchi         |


4. **`WHERE`**: Filtriamo i risultati per includere solo le visite effettuate dalla dottoressa Gialli Rita, utilizzando `M.nome = 'Rita' AND M.cognome = 'Gialli'`.

| Matricola | Paziente | Data       | nomeMedico | cognomeMedico | nomePaziente | cognomePaziente |
| --------- | -------- | ---------- | ---------- | ------------- | ------------ | --------------- |
| 123457    | 2        | 2024-02-01 | Rita       | Gialli        | Luca         | Bianchi         |
| 123457    | 6        | 2023-02-01 | Rita       | Gialli        | Sara         | Bianchi         |


5. **`GROUP BY`**: Raggruppiamo i risultati per `Paziente`, `nomePaziente` e `cognomePaziente` per calcolare il numero di visite per ciascun paziente.

| Paziente | nomePaziente | cognomePaziente | numero\_visite |
| -------- | ------------ | --------------- | -------------- |
| 2        | Luca         | Bianchi         | 1              |
| 6        | Sara         | Bianchi         | 1              |

6. **`HAVING`**: Filtriamo i risultati per includere solo i pazienti che sono stati visitati almeno due volte, utilizzando `HAVING COUNT(V.Paziente) >= 2`.

    - In questo caso, non ci sono pazienti che soddisfano questa condizione, quindi la query restituirà un risultato vuoto.
    - Nel caso avessimo avuto per esempio 'Luca Bianchi' visitato 3 volte, il risultato sarebbe stato:

        | nomePaziente | cognomePaziente |
        | ------------ | --------------- |
        | Luca         | Bianchi         |

>[!TIP]
> L'utilizzo di `DISTINCT` non è necessario in questo caso, poiché stiamo già raggruppando i risultati per `Paziente`, `nomePaziente` e `cognomePaziente`.