# Connect 4

## 1. Files
 This repo contains the readme that you're reading, a Makefile, and five source code files: 
 - main.c just calls the menu of the game ; 
 - fonctions.h and fonctions.c implement the funcitons used for the actual game, as long as a pvp game ; 
 - AI.c and AI.h implement the menu of the game, as long as the functions used by the AIs, and the games against the computer. 
 

## 2. How to use
 If you are using ubuntu, simply use the "make" command, and it will recompile and run automatically.
 If you're using another OS, you'll have to recompile the source code for yourself.
 Once you rune the program, a menu will open and ask you if you want to play player v. player, or against an AI. If you choose AI, you'll (soon) get to choose how smart you want the computer to be, then which turn you play, or let the computer decide randomly the turn for you.
 For now, there is only one difficulty: the AI plays randomly.

## 3. Future improvements
- I'll code an AI that uses a min-max algorithm to play smart moves, and ask the player how deep they want the computer to think.
- In the long term, I'll make a simple GUI