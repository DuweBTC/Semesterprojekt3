# ReadMe
## Brew System
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

## LiquidSensor
### Funktioner
#### Public Funktioner
|Funktions navn | Retur Type | Parametere | Funktions formål |
|---------------|------------|------------|------------------|
| checkLiquid | bool | | Formålet med denne funktion er at kontrollere om der er væske i beholderne. | 
#### Private funktioner
|Funktions navn | Retur Type | Parametere | Funktions formål |
|---------------|------------|------------|------------------|

## WeightSensor
### Funktioner
#### Public Funktioner
|Funktions navn | Retur Type | Parametere | Funktions formål |
|---------------|------------|------------|------------------|
#### Private funktioner
|Funktions navn | Retur Type | Parametere | Funktions formål |
|---------------|------------|------------|------------------|
