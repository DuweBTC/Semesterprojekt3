# ReadMe
## Brew System
Brew System er den del af projektet som står for at brygge de forskellige drinks, som brugeren beder som.
Brew System består af nogle delsystem disse delsystemer og deres overordnet funktionalitet er følgende;

| Delsystem navn | Funktionalitet |
|----------------|----------------|
| ActuatorDriver | ActuatorDriver har til formål at åbne og lukke for vores ventiler. |
| LiquidSensor | LiquidSensors formål er at holde øje med om der er væske i alkohol/blanding beholderne. |
| WeightSensor | WeightSensor har til formål at se om der er blevet placeret et glas af brugeren, sådan vi ikke starter med at blande en drink uden der er et glas |

## ActuatorDriver
### Funktioner
#### Public Funktioner
|Funktions navn | Retur Type | Parametere | Funktions formål |
|---------------|------------|------------|------------------|
| openValveNr | void | int valveNumber | formålet med denne funktion er at kunne åbne for en bestemt ventil |
| CloseValve | void | | Formålet med denne funktion er at lukke alle valves |
#### Private funktioner
|Funktions navn | Retur Type | Parametere | Funktions formål |
|---------------|------------|------------|------------------|

### Hardware
Hardwareen der skal bruges til ActuatorDriver delen, 4 x WPM422 - Water Valve, 8mm, 8bar, 12V, Velleman. Dette er nogle ventiler, som man kan åbne ved at tilføre spædning og strøm. Når der bliver tilført strøm til dem åbner de, når der ikke er noget strøm lukker de, altså er de normal closed. Disse skal der som nævnt bruges 4 af (Når man bruger 4 beholdere).

## LiquidSensor
### Funktioner
#### Public Funktioner
|Funktions navn | Retur Type | Parametere | Funktions formål |
|---------------|------------|------------|------------------|
| checkLiquid | bool | | Formålet med denne funktion er at kontrollere om der er væske i beholderne. | 
#### Private funktioner
|Funktions navn | Retur Type | Parametere | Funktions formål |
|---------------|------------|------------|------------------|

### Hardware
Hardwaren til LiquidSensor er Non-contact Liquid Level Sensor XKC Y25-T12V SKU SEN0204. Dem skal der bruges 4 af (I forbindellse med udarbejdelsen af projekt bliver der kun brugt 1, da de er små dyre, og derfor bruger vi en til at implemtere og teste, og derefter ville det være let at tilføjde de sidste 3 sensore).

## WeightSensor
### Funktioner
#### Public Funktioner
|Funktions navn | Retur Type | Parametere | Funktions formål |
|---------------|------------|------------|------------------|
#### Private funktioner
|Funktions navn | Retur Type | Parametere | Funktions formål |
|---------------|------------|------------|------------------|

### Hardware
Hardwaren til WeightSensor er en 1 kg load cell (fra GFV på 2. semester). Denne load cell, skal brgues til at registere om der står et glas til at blande drink i eller ej. Til load cell'en skal der også bruges et amplifier circuit (igen fra GFV på 2. semester).