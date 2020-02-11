# Simulator for tilpdat-heislab

Forket fra [erlendb/TTK4235-tipdat-simulatorheis](https://github.com/erlendb/TTK4235-tilpdat-simulatorheis), og oppdatert til utleverte drivere fra 2020.

Heissimulator og kode for å kjøre din egen heis i simulator. For heislab i TTK4235 Tilpassede datasystemer.

Med denne greia kan du altså teste heiskoden din i simulator, så du slipper å sitte på sal med den fysiske heisen.

Testet og funker på Linux. Kan ikke garantere noe på Windows. Alt som står her er beregnet på Linux.

## Hvordan bruke simulatoren
1. Last ned simulatoren (Linux: [*SimElevatorServer*](https://github.com/erlendb/TTK4235-tilpdat-simulatorheis/raw/master/SimElevatorServer). Windows: [*SimElevatorServer.exe*](https://github.com/erlendb/TTK4235-tilpdat-simulatorheis/raw/master/SimElevatorServer.exe))

2. Åpne terminalen i mappen der du lagret *SimElevatorServer*. Kjør kommandoen `chmod +x SimElevatorServer` for å gjøre det mulig å kjøre simulatoren som et program. Dette trenger du bare å gjøre én gang.

3. Kjør kommandoen `./SimElevatorServer` i terminalen for å starte simulatoren.

4. Bytt ut `source`-mappen og makefilen i skjelettprosjektet med disse.


5. Kompiler heisprogrammet ditt med de nye filene (`make`) og kjør det (`./elevator`). Hvis heisprogrammet kjører som det skal og alt funker, så skal det nå stå "Connected" i simulatorvinduet. Bruk tastene **qwe, sdf og zxcv** på tastaturet for å "trykke" på bestillingsknappene i heisen.

6. Wooho, kjør heis og vær glad.

## Hvordan bytte mellom simulator og heisen på sal

For å bygge heisen **for simulator** må det stå følgende øverst i makefilen: 
~~~make
SIM := true
~~~
Detsom det ikke står vil heisen bygges for sal.

## Litt mer info om simulatoren

Inne i simulatoren kan du "trykke" på bestillingsknapper med qwe (opp), sdf (ned), zxcv (inni heisen).

Teknisk info og bedre bruksanvisning for simulatoren finner du på https://github.com/TTK4145/Simulator-v2

For å avslutte simulatoren kan du trykke `ctrl+c`.

## Takk til

Dette repoet tar utgangspunkt i simulatoren og driveren fra TTK4145:
* https://github.com/TTK4145/Simulator-v2
* https://github.com/TTK4145/driver-c

*SimElevatorServer* og *SimElevatorServer.exe* som er lagt med i dette repoet er versjon v1.5 fra TTK4145/Simulator-v2.
