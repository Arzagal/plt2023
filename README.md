# PLT

[![Actions Status](https://github.com/Arzagal/plt2023/workflows/PLT%20build/badge.svg)](https://github.com/Arzagal/plt2023/actions)[![codecov](https://codecov.io/gh/Arzagal/plt2023/graph/badge.svg?token=1MESYSIBL5)](https://codecov.io/gh/Arzagal/plt2023)

## Introduction
This project goal is to recreate the game "Shadow hunter" in C++, as a final study project.
It is conducted by 3 third-year enginnering students :
- [VINCKEL François](https://github.com/Voldelol)
- [FAY Louis](https://github.com/Arzagal)
- [FUSSELIER Thomas](https://github.com/Krustybe)

## The game
[Shadow Hunter](https://cdn.1j1ju.com/medias/bf/1f/fa-shadow-hunters-regle.pdf) is a hidden role game, where two teams (the shadows and the hunters) attempt to kill each other. Depending of the number of players, there can be a third team (the neuutrals), that can have variety of different win conditions. Each player play as a different character with unique abilities. 
Each turn, a player move his pawn, draw and play card, etc. The game ends when one of the team have fullfilled its win condition. 

## Compiling the project
To run this project you will need to have CMake installed. Then, simply execute [this file](config.sh) to compile the project.
The executable can be found in the bin directory, for example : 
```console
./bin/client DemoAI
```
will run the client with the AI demo.
