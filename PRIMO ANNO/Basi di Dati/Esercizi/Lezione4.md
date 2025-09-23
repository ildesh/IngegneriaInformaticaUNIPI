# Esercizi Lezione 4 - 19-03-2025

## Esercizio 1

- Città(Nome, Regione, Abitanti)
- Fiumi(Fiume, Lunghezza)
- Attraversa(Città, Fiume)

 

<div style="display: flex; justify-content: center; margin-top: 20px;">
  <div style="display: flex; flex-direction: row; gap: 15px; transform: scale(0.95);">  
    <table>
      <caption><b>Relazione "Città"</b></caption>
      <thead>
        <tr>
          <th>Nome</th>
          <th>Regione</th>
          <th>Abitanti</th>
        </tr>
      </thead>
      <tbody>
        <tr><td>Roma</td><td>L</td><td>100k</td></tr>
        <tr><td>Pisa</td><td>T</td><td>100k</td></tr>
        <tr><td>Firenze</td><td>T</td><td>300k</td></tr>
      </tbody>
    </table>
-->
    <table>
      <caption><b>Relazione "Fiumi"</b></caption>
      <thead>
        <tr>
          <th>Fiume</th>
          <th>Lunghezza</th>
        </tr>
      </thead>
      <tbody>
        <tr><td>A</td><td>160</td></tr>
        <tr><td>G</td><td>10</td></tr>
        <tr><td>T</td><td>400</td></tr>
        <tr><td>C</td><td>36</td></tr>
        <tr><td>M</td><td>14</td></tr>
      </tbody>
    </table>
-->
    <table>
      <caption><b>Relazione "Attraversa"</b></caption>
      <thead>
        <tr>
          <th>Città</th>
          <th>Fiume</th>
        </tr>
      </thead>
      <tbody>
        <tr><td>P</td><td>A</td></tr>
        <tr><td>F</td><td>A</td></tr>
        <tr><td>F</td><td>G</td></tr>
        <tr><td>R</td><td>T</td></tr>
        <tr><td>R</td><td>C</td></tr>
        <tr><td>R</td><td>M</td></tr>
      </tbody>
    </table>
  </div>
</div>



- Trovare nome, regione e abitanti della citàt con più di 50k abitanti attraversate dal Po o dall'Adige:

Per risolverlo dobbiamo:

1. Selezionare degli elementi di "attraversa" che hanno all'interno come fiume o Po oppure Adige e la denominiamo come R<sub>1</sub>:
$$
R_1 = \sigma_\text{fiume = Po OR fiume = Adige}(Attraversa)
$$

1. Creare una relazione R<sub>2</sub> in cui utilizziamo l'equi-join della relazione città in cui andiamo a prendere il nome delle città di R<sub>1</sub>:
$$
R_2 = R_1 \bowtie_\text{Città = Nome}(Città)
$$

1. Creare una relazione R<sub>3</sub> in cui si fa la selezione della relazione R2 degli abitanti che hanno più di 50k abitanti

$$
R_3 =  \sigma_\text{Abitanti>50k}(R2)
$$

4. Creare una relazione R<sub>4</sub> in cui si fa la proiezione di R<sub>3</sub> per selezionare gli attributi che ci vengono chiesti nel problema in quest'ultima relazione

$$
R_4 = \pi\text{Nome,Regione,Abitanti}(R_3)
$$

- Trovare le città attraversate da almeno 2 fiumi visualizzando come risultato il nome della città e il più lungo tra detti fiumi:

Per risolverlo dobbiamo:

1. **_Ridenominiamo la relazione "Attraversa" per poter fare un join con sé stessa:_** 
   1. Creiamo una nuova relazione Attraversa₁, dove rinominiamo l'attributo Fiume in Fiume₁ per evitare ambiguità nel successivo join:

$$
Attraversa_1 = \rho_\text{x1<-x}(Attraversa)
$$

2.
$$
R_1 = Attrav \bowtie_\text{città = città1}(Attraversa_1)
$$

3.
$$
R_2 = \sigma_{\text{Fiume} \neq \text{Fiume1}}(R_1)
$$

---

## Esercizio 2

FARMACI (Codice, Nome farmaco, P.A., Produttore, Prezzo)

PRODUTTORI (Cod. Prod., Nome, Nazione)

SOSTANZE (Id, Nome Sostanza, Categoria)

- Trovare, per i farmaci di produzione italiana, il nome del farmaco e quello del suo principio attivo.

$$
R_1 = \sigma_\text{Nazione = Italia}(Produttori)
$$

$$
R_2 = \text{Farmaci} \bowtie_\text{Produttore = Cod. Prod.}(R_1)
$$

$$
R_3 = R_2 \bowtie_\text{P.A. = Id}(\text{Sostanze})
$$

$$
R_4 = \pi_\text{Nome farmaco, Nome Sostanza}(R_3)
$$

- Trovare, per i farmaci il cui principio attivo è "sulfamidico", il nome del farmaco e del suo produttore.



$$
R_1 = \sigma_\text{Nome Sostanza = "sulfamidico"}(\text{Sostanze})
$$

$$
R_2 = \text{Farmaci} \bowtie_\text{P.A. = Id}(R_1)
$$

$$
R_3 = R_2 \bowtie_\text{Produttore = Cod. Prod.}(\text{Produttori})
$$

$$
R_4 = \pi_\text{Nome farmaco, Nome}(R_3)
$$

Nel primo quesito, il nostro obiettivo è trovare il nome del farmaco e del suo principio attivo (P.A.) per i farmaci prodotti da produttori italiani. 

### Passaggi per risolvere il primo quesito:

#### Passo 1: Selezionare i produttori italiani

Iniziamo con la selezione dei produttori italiani dalla relazione **PRODUTTORI**. Utilizziamo la selezione per filtrare solo i produttori con **Nazione = Italia**:

$$
R_1 = \sigma_{\text{Nazione = Italia}}(\text{PRODUTTORI})
$$

#### Passo 2: Eseguire l'Inner Join tra FARMACI e la selezione dei produttori italiani

Ora, eseguiamo un **inner join** tra la relazione **FARMACI** e la relazione **R_1** (che contiene i produttori italiani), unendo i dati sulla colonna **Produttore** (da **FARMACI**) e **Cod. Prod.** (da **R_1**):

$$
R_2 = \text{FARMACI} \bowtie_{\text{Produttore = Cod. Prod.}}(R_1)
$$

#### Passo 3: Eseguire l'Inner Join tra FARMACI e SOSTANZE per ottenere il principio attivo

A questo punto, facciamo un altro **inner join** tra **R_2** (che contiene le informazioni sui farmaci dei produttori italiani) e la relazione **SOSTANZE** per associare il principio attivo **P.A.** al farmaco. Usiamo la colonna **P.A.** (da **FARMACI**) e la colonna **Id** (da **SOSTANZE**):

$$
R_3 = R_2 \bowtie_{\text{P.A. = Id}}(\text{SOSTANZE})
$$

#### Passo 4: Proiezione dei dati desiderati

Infine, proiettiamo solo le colonne **Nome farmaco** e **Nome Sostanza** (il principio attivo), per ottenere il risultato richiesto:

$$
R_4 = \pi_{\text{Nome farmaco, Nome Sostanza}}(R_3)
$$

### Risultato per il primo quesito:

La relazione finale **R_4** contiene il **Nome farmaco** e il **Nome Sostanza** (principio attivo) per tutti i farmaci prodotti da produttori italiani.

---

Nel secondo quesito, dobbiamo trovare il nome del farmaco e del produttore per i farmaci il cui principio attivo è "sulfamidico".

### Passaggi per risolvere il secondo quesito:

#### Passo 1: Selezionare i farmaci con principio attivo "sulfamidico"

Iniziamo con la selezione dei farmaci il cui principio attivo è "sulfamidico" dalla relazione **SOSTANZE**. Usiamo la selezione per filtrare la colonna **Nome Sostanza**:

$$
R_1 = \sigma_{\text{Nome Sostanza = "sulfamidico"}}(\text{SOSTANZE})
$$

#### Passo 2: Eseguire l'Inner Join tra FARMACI e la selezione dei farmaci "sulfamidici"

Successivamente, eseguiamo un **inner join** tra la relazione **FARMACI** e la relazione **R_1** (contenente i farmaci con principio attivo "sulfamidico") usando la colonna **P.A.** di **FARMACI** e la colonna **Id** di **SOSTANZE**:

$$
R_2 = \text{FARMACI} \bowtie_{\text{P.A. = Id}}(R_1)
$$

#### Passo 3: Eseguire l'Inner Join tra i farmaci "sulfamidici" e i produttori

Ora, uniamo **R_2** con la relazione **PRODUTTORI** per ottenere i nomi dei produttori. Eseguiamo un **inner join** usando la colonna **Produttore** di **R_2** e la colonna **Cod. Prod.** di **PRODUTTORI**:

$$
R_3 = R_2 \bowtie_{\text{Produttore = Cod. Prod.}}(\text{PRODUTTORI})
$$

#### Passo 4: Proiezione dei dati desiderati

Infine, proiettiamo solo le colonne **Nome farmaco** e **Nome** (che rappresenta il produttore) per ottenere il risultato finale:

$$
R_4 = \pi_{\text{Nome farmaco, Nome}}(R_3)
$$

