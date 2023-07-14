# ChessAI

A chess game CLI and chess AI made from scratch. Everything was handmade in c++17 standard.

## Video Demonstration (AI vs AI; until Turn 30)
https://github.com/seokholim/ChessAI/assets/59181749/00299020-8f3e-44c6-a15b-929a40de1d44

## Video Demonstration (Human vs AI; until Turn 11)
https://github.com/seokholim/chess/assets/59181749/92077b27-9ee6-418e-849f-58554d3ba8fa


## Why I worked on this project
I wanted to create an AI that can make intellectual decisions. So, after making a chess game in OOP with design patterns, I created an AI with the following reasoning.    
For each move, AI considers the next scenarios that can be played out by an opponent after making the move. For example, if AI has a move from a2 to a3, AI supposes that it made such move, and then considers the next moves that the opponent can play. If the opponent happens to have a move that can capture the AI's piece on a3, then the move from a2 to a3 is potentially dangerous, or strategic, depending on whether or not AI has a different move that can go to a3. So, again, AI supposes that the opponent made a capturing move to a3, and then sees if AI has moves that can capture the opponent's piece on a3 in turn. If AI has no such move, then the original move from a2 to a3 was dangerous. Otherwise, the original move can be strategic. If the recursion level is 2, AI stops considering the next depth of scenarios.          

The result is surprising. Moves that are made by AI look intellectual; please check out the demo videos above.    

NOTE: One of the rule of Chess is that one can't make a move that will put their King in check. Therefore, by implementing this recursive scenarios, one can make sure that each move is valid by checking if opponent has no move that can capture their King in the next scenario.    

## How moves are evaluated
In recursion, there must be a base case. In other words, in Chess, one can't always consider the next scenarios.     
That's why I have a simple way to evaluate a base value of a move at the end of the recursive scenarios.   
A pawn capturing a bishop, should be more advantageous than a bishop capturing a pawn. Of course, this is not always the case; but as a base case, it is a sufficient assumption. Therefore, at the end of the scenario tree, "leaf" moves are evaluated simply by what kind of moves they are; for example, if they are capturing moves, their values are X, and X can vary depending on what kind of a capture it is; if they are neutral moves with no capture, their values are Y, and Y can vary depending on what kind of a neutral move it is.  
Moves that are not at the base case scenario are evaluated by averaging out the next scenarios, and subtracting it from the move's base value.     

Example: consider that White Player has a move from a2 to a3. Supposing the move was made, it has next scenarios that can be played out by Black Player's moves. If the recursion level is 1, then Black Player's moves are "leaf" moves, and they are evaluated with base values; a pawn capturing a bishop is more advantageous than a bishop capturing a pawn. Then, the averaged value is subtracted from the original White Player move's base value. The reasoning of subtraction is that Black Player's good moves are bad moves for White player. If the recursion level is 2, then Black Player's move are not "leaf" moves, so they could again create the next scenarios which are White Player's "leaf" moves.   s

## Technical Overview of the Design

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
