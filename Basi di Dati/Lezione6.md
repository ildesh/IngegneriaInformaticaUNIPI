<h1> Lezione 6 - 20-03-2025 </h1>

<h1>📚 Indice</h1>

- [Progettazione Concettuale](#progettazione-concettuale)
  - [Design Pattern](#design-pattern)
  - [Reificazione di attributo di entità](#reificazione-di-attributo-di-entità)
  - [Reificazione di relationship binaria](#reificazione-di-relationship-binaria)
  - [Reificazione di attributo di relationship](#reificazione-di-attributo-di-relationship)
    - [Caso particolare di entità](#caso-particolare-di-entità)
  - [Relationship ternaria](#relationship-ternaria)
    - [Reificazione di relationship ternaria](#reificazione-di-relationship-ternaria)
  - [Strategie di progetto](#strategie-di-progetto)
    - [Strategia top-down](#strategia-top-down)
    - [Strategia bottom-up](#strategia-bottom-up)
      - [Nella pratica…](#nella-pratica)
  - [Una metodologia](#una-metodologia)
  - [Qualità di uno schema concettuale](#qualità-di-uno-schema-concettuale)

# Progettazione Concettuale
>[!WARNING]
>#### Quale costrutto E-R va utilizzato per rappresentare un concetto presente nelle specifiche?
> 1. Bisogna basarsi sulle definizioni dei costrutti del
modello E-R
>       - se ha proprietà significative e descrive oggetti con esistenza autonoma
>           - entità
>       - se è semplice e non ha proprietà
>           - attributo
>       - se correla due o più concetti
>           - relationship
>       - se è caso particolare di un altro
>           - generalizzazione
## Design Pattern

I Design Pattern rappresentano soluzioni progettuali a problemi comuni, fungendo da modelli riutilizzabili per affrontare sfide ricorrenti nello sviluppo software. 

**_Caratteristiche Fondamentali_**: 
1. Soluzioni progettuali a problemi comuni
2. Largamente usati nell'ingegneria del software
3. Vediamo alcuni pattern comuni nella progettazione concettuale di basi di dati

## Reificazione di attributo di entità

- Reificazione di attributo di entità
- Parte-di
- Istanza-di

## Reificazione di relationship binaria

## Reificazione di attributo di relationship

### Caso particolare di entità

## Relationship ternaria


### Reificazione di relationship ternaria


## Strategie di progetto
>[!WARNING]
>#### Come procediamo con tante specifiche anche dettagliate? Come ci orientiamo?
>- Strategie:
>   - _**top-down**_
>   - _**bottom-up**_
>   - _**inside-out**_

### Strategia top-down

Per questa strategia si parte da uno schema iniziale che viene successivamente raffinato e integrato per mezzo di primitive che lo trasformano in una serie di schemi intermedi per arrivare allo schema E-R finale.
- Primitive di raffinamento:
    - Da entità a associazione tra entità
    - Da entità a generalizzazione
    - Da associazione a insiemi di associazioni
    - Da associazione a entità con associazioni
    - Introduzione di attributi su entità e associazioni

### Strategia bottom-up

Invece per quest'altra strategia si parte dalle specifiche iniziali e si suddividono fino a dare specifica ad una componente minima di cui si dà lo schema E-R. Gli schemi prodotti vengono fusi e integrati fino ad
ottenere lo schema finale. 
- Primitive di trasformazione:
    - Generazione di entità
    - Generazione di associazione
    - Generazione di generalizzazione

#### Nella pratica…

Si procede di solito con una strategia mista:
  - si individuano i **_concetti principali_** e si realizza uno **_schema scheletro_**;
  - sulla base di questo si può **_decomporre_**;
  - poi si **_raffina_**, si **_espande_**, si **_integra_**;
Definizione dello **_schema scheletro_**: Si individuano i **_concetti più importanti_**, ad esempio perché più citati o perché indicati esplicitamente come cruciali e li si organizza in un **_semplice schema concettuale_**.

## Una metodologia

Il metodo si divide in quattro passaggi:
1. **_Analisi dei requisiti_**:
   1. Analizzare i requisiti ed eliminare le ambiguità
   2. Costruire un glossario dei termini
   3. Raggruppare i requisiti in insiemi omogenei 

2. **_Passo base_**:
   1. Definire uno schema scheletro con i concetti più rilevanti

3. **_Passo iterativo_**:
   1. Raffinare i concetti presenti sulla base delle loro specifiche
   2. Aggiungere concetti per descrivere specifiche non descritte 

4. **_Analisi di qualità_**:
   1. Verificare le qualità dello schema e modificarlo

## Qualità di uno schema concettuale

Lo schema concettuale deve avere al suo interno:
1. **_Correttezza_**;
2. **_Completezza_**;
3. **_Leggibilità_**;
4. e soprattutto... **_minimalità_**;