# ChessAI

A chess game CLI and engine AI made from scratch. Everything was handmade in c++17 standard.

## Video Demonstration (AI vs AI; until Turn 30)
https://github.com/seokholim/Chess/assets/59181749/c125598d-ed37-4d02-a1c8-396e0e731267

## Overview

A brief overview using **ClassName**:   

**Chess** is the main class that runs to create **Board** and make **Piece**s on it.        
**Piece**s look at **Board** and make candidate **Position**s, but **Chess** passes **Piece**s to **Engine** to generate **Move**s for **Piece**s.     
**Engine** validates and evaluates each **Move** by running the **Move**'s **Scenario**. **Scenario** first copy constructs **Board** and **Piece**s from the current **Board** and **Piece**s, perform the given **Move**, and then recursivly calls **Engine** to run next **Scenario**s for opponent's next candidate **Move**s. The best performance so far was achieved when the depth of the recursion was 2, excluding the root layer.                 
After candidate **Move**s are evaluated, they are added to **Player**s.      
Finally, **Player** plays a **Move** in their turn. If **Player** is AI, it plays the **Move** with the highest value.  
When a **Move** is played, **Piece**s are notified to make new candidate **Position**s, which are again passed to **Engine** to generate new **Move**s for their turn.     

IMPORTANT NOTE:     
The reason why I designed **Scenario** to copy construct **Board** and **Piece**s was so that **Engine** could have multiple threads to run **Scenario**s concurrently for a given **Piece**'s candidate **Move**s, *without sharing data between threads*.    
When evaluating base cases for **Scenario**s, *multithreading did not yield an improved result*. Therefore, a single thread was used for base cases.    
Moreover, for the sake of brevity, interface classes **ChessBoard** and **ChessPiece** were not introduced in this overview.   

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
