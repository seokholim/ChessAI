# Chess

A chess game & AI made from scratch.

## Overview

Here is a brief overview of how this Chess game is structured, using **ClassName**.  

**Chess** is the main class that runs to create **Board** and make **Piece**s on it.    
**Piece**s can make candidate **Position**s, but ultimately **Engine** makes the valid **Move**s for **Player**s.   
**Move**s are evaluated by building a **Scenario** tree. If **Move**s are valid, they are added to **Player**s.    
Finally, **Player** plays a **Move** in their turn. If **Player** is AI, it plays the **Move** with the highest value.    