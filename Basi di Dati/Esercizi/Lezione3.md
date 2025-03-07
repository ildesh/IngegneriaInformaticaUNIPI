## Lezione 3 - Esercizi

### Esercizio 1:

>[!TIP] Testo domanda:
>Si consideri il seguente schema di base di dati
> - Film(<u>CodiceFilm</u>, Titolo, CodiceRegista, Anno)
> - Produzione(<u>CasaProduzione</u>, Nazionalità, <u>CodiceFilm</u>, Costo, Incasso1annoSala)
> - Artista(<u>CodiceAttore</u>, Cognome, Nome, Sesso, DataDiNascita, Nazionalità)
> - Interpretazione(<u>CodiceFilm</u>, <u>CodiceAttore</u>, Personaggio, SessoPersonaggio)
> - Regista(<u>CodiceRegista</u>, Cognome, Nome, Sesso, DataDiNascita, Nazionalità)
> - Noleggio(<u>CodiceFilm</u>, Incasso1annoVideo, Incasso1annoDVD)
> 
> Formulare in algebra relazionale la seguente interrogazione:
> - Nomi e cognomi dei registi che hanno diretto film che hanno incassato il primo anno di uscita meno nelle sale che per il noleggio di DVD

1. Cosa ci serve???
   1. nome e cognome regista --> REGISTA
   2. registi e film diretti --> FILM
   3. film e incassi DVD     --> NOLEGGIO
   4. film e incasso sala    --> PROD

2. **Approccio BOTTOM-UP** (_dal particolare al generale_)

   1. Accorpare IncassoSALA e incassoDVD:
      1. R<sub>1</sub> = NOLEGGIO ⋈ PROD = CodiceFilm,IncassoDVD, CasaProf,IncassoSALA.
   2. Selezioniamo solo i film richiesti:
      1. R<sub>2</sub> = σ<sub>IncassoDVD>IncassoSala</sub>(R<sub>1</sub>).
   3. Accorpiamo REGISTA e FILM:
      1. R<sub>3</sub> = REGISTA ⋈ FILM = CodiceRegista, Cognome, Nome, CodiceFilm, Titolo.
   4. Accorpiamo R<sub>2</sub> e R<sub>3</sub>:
      1. R<sub>4</sub> = R<sub>2</sub> ⋈ R<sub>3</sub> 
   5. Proiettiamo su quanto richiesto:
      1. R = π<sub>Nome,Cognome</sub>(R<sub>4</sub>)

---

### Esercizio 2:

>[!TIP] Testo Domanda
> - CLIENTI(Codice,Nome,Indirizzo,Città)
> - NOLEGGI(Cliente,Auto,DPrelievo,DRest)
> - AUTO(Targa,Modello)
>
> Trovare:
> 1. I dati dei clienti che hanno noleggiato almeno un auto nel 2006
> 2. I cienti che hanno noleggiato più di un auto
> 3. I clienti che jhanno noleggiato auto di un solo modello

Eseguiamo i seguenti passaggi:

1. R<sub>1</sub> = σ<sub>DP>=01/01/2006 AND DP<=31/12/2006</sub>(NOLEGGI) <br> R<sub>2</sub> = CLIENTI ⋈<sub>CODICE = Cliente</sub>(R<sub>1</sub>) <br> R<sub>3</sub> = π<sub>Codice,Nome,Indirizzo,Città</sub>(R<sub>2</sub>)
2. NOLEGGI X NOLEGGI - SINTATTICAMENTE IL COMPILATORE DA' ERRORE ED E' SBAGLIATO!!! <br> però possiamo dire NOLEGGI X P<sub>X<sub>1</sub> <- X </sub>(NOLEGGI).
   1. Possiamo in seguito applicare una selazione nella relazione R1 creata per trovare gli elementi che ci interessano e poi fare una proiezione: R<sub>2</sub> = σ<sub>A!=A<sub>1</sub></sub>(R<sub>1</sub>) e R3 = π<sub>Cliente</sub>(R<sub>2</sub>)
3. Unire NOLEGGI con AUTO per ottenere il modello dell'auto noleggiata: R₁ = NOLEGGI ⋈<sub>Auto = Targa</sub>(AUTO) <br> R = π<sub>C</sub>(NOLEGGI) - X (dove X è una relazione che contiene le persone che hanno comprato più macchine diverse). <br> R<sub>2</sub> = R<sub>1</sub> ⋈<sub>C = C1</sub> ρ<sub>X1<--X</sub>(R<sub>1</sub>) <br> R<sub>3</sub> = σ<sub>M != M1 </sub>(R<sub>1</sub>). <br> R4 =  π<sub>Cliente</sub>(R<sub>3</sub>)
