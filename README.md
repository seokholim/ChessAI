# Chess

A chess game CLI and AI made from scratch.

## Overview

Using **ClassName**: 

**Chess** is the main class that runs to create **Board** and make **Piece**s on it.        
**Piece**s look at **Board** and make candidate **Position**s, but **Chess** passes **Piece**s to **Engine** to make valid **Move**s for **Piece**s.     
In **Engine**, each **Move** is validated and evaluated by building a **Scenario** tree. **Scenario** first copy constructs **Board** and **Piece**s, perform the given **Move**, and then recursivly constructs next **Scenario**s by considering opponent's **Move**s.     
Valid **Move**s are evaluated by their parent **Scenario**, and then added to **Player**s.     
Finally, **Player** plays a **Move** in their turn. If **Player** is AI, it plays the **Move** with the highest value.   

For the sake of brevity, interface classes were not introduced in this overview.

## How to run

Run inside **src** directory:

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