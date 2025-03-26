## Lezione 5-6-7 - Esercizi

### Esercizio:

- Stabilimento(<u>codice</u>,dimensione,Ubicazione)
- Articolo(<u>nome</u>,tipo,prezzo)
- Produzione(<u>NomeArticolo</u>,<u>CodiceStabilimento</u>,Data,Quantità)

1. Trovare codice e dimensione di tutti gli stabilimenti in cui si producono articoli di nome "sedia" e di nome "tavolo".
2. Trovare il codice degli stabilimenti che producono almeno due articoli diversi.

#### Soluzione punto 1:
$$
\pi_\text{codiceStabilimento}(\sigma_\text{nomeArticolo = "sedia" \text{AND} nomeArticolo = "tavolo"}(\text{PRODUZIONE}))
$$

#### Soluzione punto 2:

$$ 
\text{PROD1} = \rho_{\text{x1} \leftarrow X} \, \text{(PROD)} 
$$

$$
\pi_\text{codiceStabilimento}(PROD \bowtie_\text{NomeArticolo != NomeArticolo1 AND CodiceStabilimento = CodiceStabilimento1}PROD1)
$$
