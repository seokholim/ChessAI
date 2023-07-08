# Chess

A chess game & AI made from scratch.

## Overview

Here is a brief overview of how this Chess game is structured, using "**\<ClassName\>**".  
**\<Chess\>** is the main class that runs to create **\<Board\>** and make **\<Pieces\>** on it.    
**\<Pieces\>** can make candidate **\<Positions\>**, but ultimately **\<Engine\>** makes the valid **\<Moves\>** for **\<Players\>**.   
**\<Moves\>** are evaluated by building a **\<Scenario\>** tree. If **\<Moves\>** are valid, they are added to **\<Players\>**.    
Finally, **\<Players\>** plays the **\<Moves\>** each turn. If **\<Player\>** is AI, it plays the **\<Move\>** with the highest value.    