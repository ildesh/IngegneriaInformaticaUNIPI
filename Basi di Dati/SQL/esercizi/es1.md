## Riassuntino prima degli esercizi

- **Costrutti SQL principali**

  * **`SELECT`** → per selezionare le colonne da visualizzare.
  * **`FROM`** → per specificare le tabelle da cui prelevare i dati.
  * **`WHERE`** → per filtrare le righe in base a condizioni specifiche.
  * **`GROUP BY`** → per raggruppare i risultati in base a una o più colonne.
  * **`HAVING`** → per filtrare i gruppi creati da `GROUP BY` in base a condizioni aggregate.
  * **`ORDER BY`** → per ordinare i risultati in base a una o più colonne.
  * **`JOIN`** → per unire più tabelle in base a condizioni specifiche.
  * **`DISTINCT`** → per eliminare i duplicati e ottenere solo valori unici.
  * **`EXISTS`** → per verificare l'esistenza di righe in una sottoquery (usato spesso con `NOT EXISTS` per divisione/differenza).

---

-  **Parole chiave → Tecniche SQL**

   - **Per ogni / ciascuno** → `'GROUP BY'` in SQL
      *(Esempio: numero di studenti per corso)*

   - **Solo / solamente / esclusivamente** → **'Differenza'**
      *(Si usa con `EXCEPT`, `NOT EXISTS` o `LEFT JOIN ... WHERE ... IS NULL`)*

   - **Tutti / tutte / ogni** → **'Divisione'**
      *(Si risolve con `NOT EXISTS` annidato; esempio tipico: "chi ha superato *tutti* gli esami")*

   - **Condizioni aggregate** (quelle con funzioni tipo `COUNT`, `SUM`, `AVG`) →
      **NON VANNO MESSE NEL `WHERE`, MA NEL `HAVING`.**
      *(Es: `HAVING COUNT(*) > 5`)*

---

- **Nuove dritte rapide**

  * **`DISTINCT`** ➔ quando nella traccia leggi: *"diversi"*, *"unici"*, *"senza ripetizioni"*
    *(Es: `SELECT DISTINCT corso FROM studenti`)*

  * **`EXISTS` / `NOT EXISTS`** ➔ usato quando leggi: *"se esiste almeno uno"*, *"solo chi ha fatto"*

    * **`NOT EXISTS`** ➔ chi *non* ha fatto qualcosa → usato per **differenza** o **divisione**
      *(Es: studenti che NON hanno sostenuto un certo esame)*

---

| **Parola nella traccia**                      | **Cosa usare in SQL**                                         |
| ------------------------------------------------ | ---------------------------------------------------------------- |
| Per ogni / Ciascuno                      | `GROUP BY`                                                       |
| Solo / Solamente                         | **Differenza** ➔ `NOT EXISTS`, `EXCEPT`, `LEFT JOIN ... IS NULL` |
| Tutti / Tutte / Ogni                 | **Divisione** ➔ `NOT EXISTS` doppio                              |
| Condizioni aggregate (`COUNT`, `SUM`, `AVG`) | ➔ **nel** `HAVING` **(non** `WHERE` **)**                        |
| Diversi / Unici                          | `DISTINCT`                                                       |
| Se esiste almeno uno                         | `EXISTS`                                                         |
| Non esiste / Nessuno ha fatto            | `NOT EXISTS`                                                     |


## Esercizio 1:

>[!NOTE]
> Considerata ogni specializzazione, indicarne il nome e l'incasso totale degli ultimi due anni di ciascusa specializzazione.

Risolviamo in SQL questo esercizio, utilizzando una tabella 'Medico'.

---

- **_MEDICO_**(<u>matricola</u>, nome, cognome, specializzazione, parcella, città)
- **_VISITA_**(<u>Medico</u>, <u>Paziente</u>, <u>Data</u>)

MEDICO:
| <u>matricola</u> | nome | cognome | specializzazione | parcella | città |
| ---------------- | ---- | ------- | ---------------- | -------- | ----- |
| 123456           | Mario | Rossi   | Cardiologo       | 100      | Roma  |
| 123457           | Luca  | Bianchi | Dentista         | 200      | Milano|
| 123458           | Anna  | Verdi   | Cardiologo       | 150      | Roma  |
| 123459           | Marco | Neri    | Dentista         | 250      | Napoli|

VISITA:
| Medico | Paziente | Data |
| ----------------- | -------- | ---------- |
| 123456            | 1        | 2026-01-01 |
| 123457            | 2        | 2024-02-01 |
| 123458            | 3        | 2022-03-01 |
| 123459            | 4        | 2025-04-01 |
| 123456            | 5        | 2024-01-01 |
| 123457            | 6        | 2023-02-01 |


```sql
SELECT M.specializzazione, SUM(V.parcella) AS incasso_totale
    FROM VISITA V
    INNER JOIN 
    MEDICO M ON V.matricola = M.matricola
WHERE year(V.data) >= YEAR(current_date()) - 1
GROUP BY M.specializzazione;
```

Passo dopo passo:

1. **`SELECT`**: Selezioniamo le colonne `specializzazione`, `nome` e la somma delle parcelle (`SUM(V.parcella)`) come `incasso_totale`.

| specializzazione | incasso_totale |
| ---------------- | -------------- |
| Cardiologo       | 100            |
| Dentista         | 200            |
| Cardiologo       | 150            |
| Dentista         | 250            |


1. **`FROM`**: Indichiamo le tabelle `VISITA` e `MEDICO` da cui prelevare i dati.
2. **`INNER JOIN`**: Uniamo le tabelle `VISITA` e `MEDICO` sulla colonna `matricola` per ottenere i dati del medico associati a ciascuna visita.

| Matricola | Paziente | Data       | specializzazione | nome  | parcella |
| ---------- | -------- | ---------- | ---------------- | ----- | -------- |
| 123456     | 1        | 2026-01-01 | Cardiologo       | Mario | 100      |
| 123457     | 2        | 2024-02-01 | Dentista         | Luca  | 200      |
| 123458     | 3        | 2022-03-01 | Cardiologo       | Anna  | 150      |
| 123459     | 4        | 2025-04-01 | Dentista         | Marco | 250      |

4. **`WHERE`**: Filtriamo le righe per considerare solo quelle degli ultimi due anni, utilizzando `year(V.data) >= YEAR(current_date()) - 1`.
5. **`GROUP BY`**: Raggruppiamo i risultati per `specializzazione` e `nome` per calcolare l'incasso totale per ciascuna specializzazione.
6. **`SUM`**: Calcoliamo la somma delle parcelle per ciascun gruppo di specializzazione.

| specializzazione | incasso_totale |
| ---------------- | -------------- |
| Cardiologo       | 250            |
| Dentista         | 450            |

---