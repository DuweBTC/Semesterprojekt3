# ReadMe
## Brew System
Brew system is a part of the project. Brew system has the overall task of brewing/mixing the drinks, that the user is requesting.
Brew System is made up of modules. These modules and their overall functions is as following;

| Module name | Funcionality |
|----------------|----------------|
| ActuatorDriver | ActuatorDrivers function is to open and close the valves in the system |
| LiquidSensor   | LiquidSensor's purpos is to see if there still is liquid in the containers. |
| WeightSensor   | WeightSensor's purpos is to see if there is a glass placed, so that the machine dosn't start to pour a drink without a glass to pour into. |

## ActuatorDriver
### Functions
#### Public Function
| Function name | Return type | Parameters | Function decription |
|---------------|------------|------------|------------------|
| Pour | void | | This function is the function that controlls the pouring of a drink. It looks for if there is a glass placed and if there is liquid in the containers. if there is. it calculates how much time it the valves needs to be open, and then opens them for that amount of time using a timer component. |
| setIngredient| void | int container, int amount | This function assings a value to two global variabels, the first for the container number that liquid needs to come out of, the second for the amount of liquid needed. |

#### Static Functions
| Function name | Return type | Parameters | Function decription |
|---------------|------------|------------|------------------|
| openValveNr | void | int valveNumber | The purpos of this function is to open a valve, specified in the parameter. |
| CloseValves | void | | The purpos of this function is to close all the valves. |

### Hardware
The hardware used for ActuatorDriver is 4 x WPM422 - Water Valve, 8mm, 8bar, 12V, Velleman. This is valves, that you can open if you give them 12V and 0.4A. When power is applied to them, they open, so that liquid can flow though them. When power is not applied they are closed, therefore they are what's called normally closed.

## LiquidSensor
### Functions
#### Public Functions
| Function name | Return type | Parameters | Function decription |
|---------------|------------|------------|------------------|
| checkAllLiquid | bool |w | The purpos of this function is to look for whetere or not there is liquid in all the containers at once. | 
| checkLiquid_1 | bool | | The purpos of this function is to look for whetere or not there is liquid in container 1. | 
| checkLiquid_2 | bool | | The purpos of this function is to look for whetere or not there is liquid in container 2. | 
| checkLiquid_3 | bool | | The purpos of this function is to look for whetere or not there is liquid in container 3. | 
| checkLiquid_4 | bool | | The purpos of this function is to look for whetere or not there is liquid in container 4. | 
#### Static Functions
| Function name | Return type | Parameters | Function decription |
|---------------|------------|------------|------------------|
|||||

### Hardware
The hardware used for Liquid sensor is a Non-contact Liquid Level Sensor XKC Y25-T12V SKU SEN0204. For 4 containers there should be used 4 of those sensors (for the project, there is used one, as they are pricy, and you can prove the concept for testing purpos with only one).

## WeightSensor
### Functions
#### Public Functions
| Function name | Return type | Parameters | Function decription |
|---------------|------------|------------|------------------|
| checkForGlass | bool | | this function uses the weight hardware component to messure wether or not there is a glass placed on it. If there is a glass it returns true, of there isn't it returns false |

#### Static Functions
| Function name | Return type | Parameters | Function decription |
|---------------|------------|------------|------------------|

### Hardware
The hardware for WeightSensor is a 1 kg load cell (the one from GFV on 2. semester). This loadcell also needs an amplifier circuit (Also from GFV 2. Semester). The load cell is used to see if there is a glass placed.
