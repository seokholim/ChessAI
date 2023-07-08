# Chess

A chess game & AI made from scratch.

## Overview

Here is a brief overview of how this Chess game is structured, using **ClassName**.  

**Chess** is the main class that runs to create **Board** and make **Piece**s on it.    
**Piece**s can make candidate **Position**s, but ultimately **Engine** makes the valid **Move**s for **Player**s.   
**Move**s are evaluated by building a **Scenario** tree. If **Move**s are valid, they are added to **Player**s.    
Finally, **Player** plays a **Move** in their turn. If **Player** is AI, it plays the **Move** with the highest value.    

## How to run

Run inside ***src*** directory:

```bash
make
./chess
```  

## Directory Structure  

```
├── Makefile
├── board
│   ├── board.cc
│   ├── board.h
│   ├── cell.cc
│   ├── cell.h
│   ├── chess_board.cc
│   └── chess_board.h
├── chess.cc
├── chess.h
├── engine
│   ├── engine.cc
│   ├── engine.h
│   ├── move.cc
│   ├── move.h
│   ├── scenario.cc
│   └── scenario.h
├── main.cc
├── pieces
│   ├── bishop.cc
│   ├── bishop.h
│   ├── chess_piece.cc
│   ├── chess_piece.h
│   ├── king.cc
│   ├── king.h
│   ├── knight.cc
│   ├── knight.h
│   ├── observer.cc
│   ├── observer.h
│   ├── pawn.cc
│   ├── pawn.h
│   ├── piece.cc
│   ├── piece.h
│   ├── queen.cc
│   ├── queen.h
│   ├── rook.cc
│   ├── rook.h
│   ├── subject.cc
│   └── subject.h
├── player
│   ├── player.cc
│   └── player.h
└── utility
    ├── info.cc
    └── info.h
```