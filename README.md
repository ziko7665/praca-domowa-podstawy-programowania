# Basic Programming Course Project  
## C++ Console Games and SVG Generator

This repository contains a C++ project created for the Basic Programming course.  
The main goal of the assignment was to practice procedural programming, file handling, input validation and generating simple vector graphics in the SVG format.

The program is a Windows console application with a menu that combines several smaller modules into one project: an SVG generator, tic-tac-toe and checkers.

## Features

### SVG generator

The SVG module allows the user to:

- generate an empty SVG file,
- generate SVG files with basic shapes such as a circle, rectangle and line,
- choose coordinates, sizes and colors from the console,
- use simple validation to prevent generated shapes from overlapping,
- open the generated SVG file in a browser from the program level.

### Tic-tac-toe

The tic-tac-toe module includes:

- player vs player mode,
- player vs computer mode,
- ASCII board displayed in the console,
- optional SVG board generated after each move,
- simple computer move logic based on blocking, choosing nearby fields and random fallback,
- optional time limit for players,
- win and draw detection.

### Checkers

The checkers module includes:

- 8x8 board displayed in the console,
- player vs player gameplay,
- initial setup with 12 pieces per player,
- move validation,
- mandatory captures,
- king promotion,
- win condition checking,
- optional SVG representation of the board,
- saving and loading game state from text files.

## Technologies and concepts used

- C++
- Procedural programming
- Standard Library
- File streams
- Console input and output
- Input validation
- 2D arrays
- SVG/XML text generation
- MSYS2/MinGW g++

## Project structure

```text
.
├── main.cpp              # Main menu and application entry point
├── funkcje.cpp           # Shared helper functions, input handling and help menu
├── funkcje.h
├── svg.cpp               # SVG file generation module
├── svg.h
├── XO.cpp                # Tic-tac-toe game logic
├── XO.h
├── warcaby.cpp           # Checkers game logic, save/load system and SVG board
├── warcaby.h
├── POP2025_domowe_v2.pdf # Original assignment description
└── Raport_PP_PD.pdf      # Project report
