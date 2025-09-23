## Lezione 5-6-7 - Esercizi

### Esercizio 1:

- Stabilimento(<u>codice</u>,dimensione,Ubicazione)
- Articolo(<u>nome</u>,tipo,prezzo)
- Produzione(<u>NomeArticolo</u>,<u>CodiceStabilimento</u>,Data,Quantità)

1. Trovare codice e dimensione di tutti gli stabilimenti in cui si producono articoli di nome "sedia" e di nome "tavolo".
2. Trovare il codice degli stabilimenti che producono almeno due articoli diversi.

#### Soluzione punto 1:
$$
\pi_\text{codiceStabilimento}(\sigma_\text{nomeArticolo = "sedia" \text{OR} nomeArticolo = "tavolo"}(\text{PRODUZIONE}))
$$

#### Soluzione punto 2:

$$ 
\text{PROD1} = \rho_{\text{x1} \leftarrow X} \, \text{(PROD)} 
$$

$$
\pi_\text{codiceStabilimento}(PROD \bowtie_\text{NomeArticolo != NomeArticolo1 AND CodiceStabilimento = CodiceStabilimento1}PROD1)
$$

---

### Esercizio 2:

- GRUPPO : (NomeGruppo, DataConsegna, VotoProgetto)
- STUDENTE : (Matricola, N, C, AnnoGruppo, NomeGruppo)
- ESAMEBD : (Matrciola, VotoScritto, VotoOrale)

1. Trovare il nome dei GRUPPI per i quali tutti i membri hanno ottenuto un gruppo superiore a 28 e non inferiore inferiore a 25 nell'orale:

$$
\text{GruppiNonValidi} = \pi_{\text{NomeGruppo}} (\sigma_{\text{VotoScritto} \leq 28 \lor \text{VotoOrale} < 25} (STUDENTE \bowtie ESAMEBD))
$$

$$
\text{GruppiValidi = Gruppo - GruppiNonValidi}
$$


$$
\pi_\text{Nome}(\text{GruppiValidi})
$$

