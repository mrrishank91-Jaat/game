Existing Game Analysis (Simple English):-

This repository contains a simple console-based C game where the player moves 
left and right to avoid falling obstacles. Below is the analysis of the game logic.

 1. Game Objective:-
The goal of the game is to avoid the obstacle that falls from the top.  
If the obstacle reaches the bottom and matches the player’s lane, the game ends.

 2. Player Controls:-
 Player can move LEFT using the left arrow key.
 Player can move RIGHT using the right arrow key.
 Player position values:  
   0 = Left lane  
   1 = Middle lane  
   2 = Right lane  

 3. Important Variables:-
 `x` → current player lane (0–2)
 `step` → how far the obstacle has moved downward
 `obstaclePos` → lane in which the obstacle appears
 `rand() % 3` → picks a random lane for obstacle

 4. Game Loop Explanation:-
The game runs inside a *while(1)* infinite loop.  
In each loop:

 A. Input Handling:-
`_kbhit()` checks if a key is pressed.  
`getch()` reads the key:  
 75 = left arrow  
 77 = right arrow  

 B. Screen Drawing:-
`clear_screen_fast()` moves cursor to top-left to reduce flicker.  
Game prints:
 Game border
 Obstacle in its current lane
 Player in bottom row

 C. Obstacle Movement:-
`step` increases each loop, so the obstacle moves downward.  
If `step > 10`, it resets and a new random obstacle is created.

 D. Collision Detection:-
If:
 `step == 10`  (means obstacle reached last row)  
 and `x == obstaclePos` (player & obstacle in same lane)

 Game Over message appears  
 Background sound stops  
 Impact sound plays  

 5. Sounds Used:-
`bg.wav` → background looping sound  
`impact.wav` → collision sound  

 6. Summary:-
This is a simple obstacle-avoidance console game in C.  
The game uses:
 Keyboard input
 Random lane generation
 Collision logic
 Screen refresh technique
 Sound effects

This analysis completes Objective 1 of the assignment.
