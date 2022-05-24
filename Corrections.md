# Dokumentation rettelser
## (alt + c) giveer flueben [x] 


## Probleformuleringen
* [ ] Forklaring til rigtbillede mangler en for for database
* [ ] Systemskitse udformet som rigt billede
  * [ ] Task, hvis er det?
  * [ ] Måske manger der en Bartender der på 
  * [ ] Vi mangler en database af en form

* [ ] Det er indda skrevet ind i teksten understående rigtbillede, at vi bruger en server

* [ ] MoSCoW
  * [ ] Must have
    * [ ] touch interface? er det for specifikt?
    * [ ] Automaten skal kunne hente drinksopskrifter ved brug af en SQL database. Er det for specifikt?


## Risikoanalyse
* [x] Indledning 
 ### Personlige risici
  * [x] Indledning 
  * [x] Tabel 
  * [x] Beskrivelse til risici matrix
  * [x] risici matrix
  * [ ] Beskrivelse af scrum
### Teknisk ricisi
  * [x] Indledning
  * [x] Tabel
  * [x] Beskrivelse til risici matrix
  * [x] risici matrix
###  Teknisk Risici Nedbringelse
  * [ ] Client hvad har I lavet i forsøg?
  * [ ] Client Argument for/imod giver ikke menning
  * [ ] Server Arduino er ikke bygget til Server
  * [ ] Server test at kan modtage hvad? Ping
  * [ ] PSoC hvordan tester det nogen form for kommunikation? Det er have noget der kan kommunikerere med clienten
  * [ ] Sensor? Mangler vi ikke en liqued senser. 
    * [ ] Lave en simpel test, og ser giver ikke menning, Skriv tester hvpr lang tid det tager for hver at registrer et glas eller hvad end I ønsker at teste
  * [ ] Akuator - Forsøg: Teste hvilken af de forskellige akkuator der virker bedst - Skal skrives om
  * [ ] beholderen, hvordan vil I teste det?
  * [ ] RFID - hvordan testes der for hvor hurtigt? Vel bare en test om vi kan modtag et studiekort eller RFID-kort
* [ ] Der skal skrives ind i vurderingen at vi ikke ordenligt fik udfyldt disse test, hvormed overblikket faldt hurtigt fra hinanden


## Kravspecifikation
* [ ] Mangler introduktion kravspecifiktaionen 
### Aktør-kontekst diagram
* [ ] Aktør beskrivelse
  * [ ] Kunde Fjern den primære aktør i beskrivelse
* [ ] Måske test til AC 
### Funktionelle Krav
* [x] Beskrivelse
* [x] User Stories
  * [ ] Som kunde vil jeg kunne blande min egen drink, så jeg kan f˚a en drink, som jeg kan lide. - Skal den fjernes?

### Ikke funktionelle krav
* [ ] Functionality
  * [ ] F.2 Automaten skal kunne scanne et kort på under et sekund
    * [ ] Hvordan tester vi det?'
  * [ ] F.3 Skal testes
* [ ] Usability
  * [ ] U.1 Hvordan tester vi det?
  * [ ] U.2 testes
* [ ] Reliability
  * [ ] R.1 testes
  * [ ] R.2 testes
* [ ] Performance
  * [ ] P.1 testes
  * [ ] p.2 testes - 
    * [ ] Automaten skal have en beholder på minimum 250 ml til opsamling af spild. på hvor lang tid eller på hvor mange opfyldninger
  * [ ] P.3 testes
* [ ] Supportability
  * [ ] S.1 Dette når vi ikke
  * [ ] S.2 Er de? 
  * [ ] S.3 Testes

### Use case 
  * [ ] Hvordan skal vi skrive use case? Use Case eller use case? det står blandet
  * [ ] En læser alle use case igennem og godkender, mærkes med flueben

## Accepttestspecifikation 
* [ ] Indledningen er for tynd her
* [x] UC1 
* [x] UC1 exception
* [x] UC2 er det ikke prækodition der står overstånde
* [ ] UC2 Hvordan godkendes opdateringen af penge? Bartender står ikke på testen
* [x] UC2 - exception
* [x] UC3
* [x] UC4 
* [x] UC5
* [x] UC5 exception
* [x] UC6
* [x] UC6 exception
  
## Systemarkitektur
* [x] Indledning
### Hardware arkitektur
* [ ] Overordnet Blokbeskrivelse
  * [ ] Mangler 
    * [ ] Motor beskrivelse se kommentar
    * [ ] Brew Unit
    * [ ] Mircocontroller
    * [ ] Aktuatoren
* [ ] Journal
  * [ ] De kan findes henholdvis i bilagene:Bilag-X-Motor - HVor findes de og list dem alle
  * [ ] Motor
    * [ ] Bruger vi "Vi" i en rapport? hvis vi gør så okay ellers ret
    * [ ] Hvorfor kunnne vi ikke bruger en mindre stærk? Kunne den så ikke rotererer med flaskerne. Det er et tomt argumment
  * [ ] RFID hvor er den??????
  * [ ] Vægt sensor hvor er konklusion for den?????


* [ ] bdd fully opdateres
* [ ] Skrive blokbeskrivelse 
  * [ ] Alle navne skal stemme overens med bdd
  * [ ] Motor
    * [ ] Common GND med microcon-troller i signal giver ikke menning. Det er en kommentar
* [ ] Indledning til ibd. Hvad er et ibd. Hvordan er det delt op
* [ ] ibd opdateres
* [ ] ibd skal navne passe med signalnavne fra bloksignal.........
* [ ] Intro til Signalbeskrivlese
* [ ] Signalbeskrivlese mangler

### Software arkitektur
* [ ] Indledning. Hvad er Software arkitektur? hvad bruges det til
* [ ] Domænemodel indledning er for tynd
* [ ] Domædemodel opdateres og recipe tilføjes

#### Konceptuel klasse diagram 
  * [ ] Indledning skal skrives om da vi ikke gør det på denne måde længere, men vi har tre systemer
  * [ ] Mangler revipe på conceptual klassediagram
  * [ ] Client - Fjern server og skriv dens reele navn, samme med brew system på UARTDriver eller noget
  * [ ] Server - hvordan vil det virker og samme rettelser som før 
  * [ ] Breswystem - navn som overstående. Har I drinks eller kun container?
#### System sekvens diagram'
* [x] UC1
* [x] UC2
* [ ] UC3 Fjern Mircocontroller og sensor og lav det omtil Brew System. Black box
* [x] UC4
* [x] UC5
* [x] UC6

#### Protokobeskrivelse
* [ ] Indledning mangler
* [ ] UART protokol
* [ ] HTTP protokol

### Deploiyment view
* [ ] Der mangler ibd med softwarepackage på

## Design
* [x] Indledning
### Hardware design
* [ ] Indledning er for tynd ogHAr er der brugt? 
* [ ] Lav en liste, dan overblik for jer selv og andre
* [ ] Brew System  
  * [ ] Hvordan er sammenhængene mellem delene?
  * [ ] Hvad for nogle porte I bruger PSoC og går det til ventil eller hvad
  * [ ] Skriver I bruger 4 sensore (Derudover skal der bruges 4 stk sensore der kan teste om der er væske i beholderne)
    * [ ] Hvor er det i forhold til arkitekturen
* [ ] Client
  * [ ] Alt mangler her
* [ ] Server
  * [ ] Er der strøm til den? skal der angives noget her?

### Software design
* [ ] Indledningen 
#### Server
* [ ] Indledningen 
* [ ] Skriv at vi har lavet en uddybende domain model, der beskriver relationerne og deres type for databasen
* [ ] Opdaterer class diagram   
* [ ] Applikationssekvensdiagram for Program fjern UseHtttpsRedirectiuon()
* [x] Sekvens diagrams
  * [x] Program
  * [x] Account get
  * [x] Account post
  * [x] Account put
  * [x] Account delelete
  * [x] Container get
  * [x] Container post
  * [x] Container put
  * [x] Container delelete
  * [x] Drink get
  * [x] Drink post
  * [x] Drink put
  * [x] Drink delelete
  * [x] Ingredient get
  * [x] Ingredient post
  * [x] Ingredient put
  * [x] Ingredient delelete
  * [x] Recipe get
  * [x] Recipe post
  * [x] Recipe put
  * [x] Recipe delelete
* [ ] Klasse diagram opdateres
* [ ] Metodebeskrivelse mangler der resten aaf funktionerne
* [ ] Metodebeskivelse er vedhæftet hvor (Det færdige mockup er vedhæftet som bilag)

#### Client
* [x] Indledning
##### Applikationsmodel 
* [x] Indledning
* [ ] Klasse diagram opdateres til de respektive navne
* [ ] Sekvens diagram
  * [ ] Indledning for tynd og giver ikke menning, derudover brug ref{fig:name} (Her ses det hvordan Client vil fungerer sammen med Use case 1. Dette ses på nedenstående billede)
  * [ ] Sekvensdiagrammerne opdateres navne på
  * [ ] UC1 - opdater til at være respektiv til vores kode
  * [ ] UC2 - opdater til at være respektiv til vores kode
  * [ ] UC3 - opdater til at være respektiv til vores kode
  * [ ] UC4 - opdater til at være respektiv til vores kode
  * [ ] UC5 - opdater til at være respektiv til vores kode
  * [ ] UC5 gør billedet mindre, så det passer på siden
  * [ ] UC6 - mangler
  * [ ] Det hedder fully dressed class diagram
* [ ] Opdateret klasse diagram går i bilag og kun bruger det sidste i dokumentationen - Michael ORD
* [ ] Afsnit 6.4 og 6.5 og 6.5.1 giver ikke menning opdel det på en ordenligt måde
* [ ] Afsnit 6.5.2 giver proxy main menu menning?
###### Flowchart
* [ ] Flowchart for IDLE state get
  * [ ]  I ikke fra Server inden i creater new account? ID-vaild, menes der ikke Id-Card is user. ID-vaild lyder saom kortet ikke er den rigtige type
* [ ] Flowchart for Main Menu state
  * [ ] Hvordan hænger det sammen med det forrige flowchart? Svar det gør det ikke

#### Brew System
* [ ] Indledning 
##### Applikationssekvensdiagram
* [ ] 

