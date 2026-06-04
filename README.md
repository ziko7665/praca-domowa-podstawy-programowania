# Basic Programming Course Project - C++ Console Games and SVG Generator

This repository contains a C++ project created for the **Basic Programming** course. The main goal of the assignment was to practice procedural programming, file handling, input validation and generating simple vector graphics in the SVG format.

The program is a console application with a menu that combines several smaller modules into one project: a basic SVG generator, tic-tac-toe and checkers.

## Features

### SVG generator

The project includes two SVG-related modes:

- generating an empty SVG file,
- generating an SVG file with basic shapes such as a circle, rectangle and line,
- choosing coordinates, sizes and colors from the console,
- simple validation that prevents generated shapes from overlapping,
- opening the generated SVG file in the browser from the program level.

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

## Technologies

- C++
- Standard Library
- File streams
- SVG/XML text generation
- Console input and output
- MSYS2/MinGW g++
- Visual Studio Code configuration

## Project structure

```text
.
├── main.cpp          # Main menu and application entry point
├── funkcje.cpp/.h    # Shared helper functions, input handling and help menu
├── svg.cpp/.h        # SVG file generation module
├── XO.cpp/.h         # Tic-tac-toe game logic
├── warcaby.cpp/.h    # Checkers game logic, save/load system and SVG board
├── POP2025_domowe_v2.pdf
├── Raport_PP_PD.pdf
└── .vscode/          # VS Code build and debug configuration
```

## How to build and run

The project was prepared for Windows and uses a few Windows-specific functions such as `windows.h`, `cls` and `start`.

With MSYS2/MinGW g++ installed, the project can be built from the project directory using:

```bash
g++ *.cpp -o program.exe
```

Then run:

```bash
./program.exe
```

In Windows Command Prompt you can also run:

```cmd
program.exe
```

The repository also contains a VS Code configuration that uses MSYS2 g++ from:

```text
C:/msys64/ucrt64/bin/g++.exe
```

## Generated files

During program execution, additional files can be created, for example:

- SVG files with generated graphics or board previews,
- checkers save files such as `war_slot1.txt`, `war_slot2.txt`, etc.,
- compiled `.exe` files.

These files are runtime/build outputs and do not have to be stored in the repository.

## What I practiced

While working on this project I practiced:

- splitting a larger program into multiple `.cpp` and `.h` files,
- using functions instead of writing everything in `main`,
- working with 2D arrays for board games,
- validating user input,
- saving and loading program state from files,
- generating SVG files manually as text,
- basic game logic and turn-based program flow,
- keeping project history in Git.

## Course context

This project was created as a homework assignment for the **Basic Programming** course. It focuses more on core programming fundamentals than on graphics libraries or advanced game engines.
