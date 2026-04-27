# CSCI-271-project

# Dice Dash

## Team Members

* Emmanue1 White (EMPLID: 24491798) — GitHub: @EmmanuelW123
* Alassane Camara (EMPLID: 23957039) — GitHub: @Alassane427
* Name 3 (EMPLID: XXXXXX) — GitHub: @username

---

## Game Description

Dice Dash is a multiplayer game played in the console where up to four players compete to reach the finish line. Each player is assigned a character and starts at the same starting position on a linear track. The objective of the game is to move across the board by rolling a dice and advancing based on the number rolled.

The track has a fixed length (for example, 50 spaces), and players must reach or pass this distance to finish. On each turn, a player rolls a virtual dice (generating a number between 1 and 6), and their character moves forward that number of spaces. The game continues in turns for each player until the required number of winners is reached, depending on the number of players in the game. The program displays messages showing each player’s roll, position, and progress throughout the game.

---

## Rules

* The game supports 2 to 4 players
* Each player starts at position 0 (starting line)
* Players take turns rolling a dice (random number from 1 to 6)
* The number rolled determines how many spaces the player moves forward
* A player is considered a winner once they reach or pass the finish line
* If there are **2 players**, the game ends immediately after the first player wins
* If there are **3 players**, the game continues until the **2nd player wins**
* If there are **4 players**, the game continues until the **3rd player wins**

---

## Scoring

This game is based on placement rather than points.

* Players are ranked based on the order in which they reach the finish line
* First player to finish gets 1st place, second gets 2nd place, and so on
* The last remaining player is automatically placed last

---

## User Interface / Messages

The game will display messages in the console to guide players throughout the game. Examples include:

* "Player 1 rolls a 4 and moves to position 12"
* "Player 2 rolls a 6 and moves to position 18"
* "Player 3 rolls a 2 and moves to position 10"
* "Player 1 has reached the finish line!"
* "Player 2 finishes in 2nd place"

The game continuously updates player positions after each turn so users can track progress.

---

## Game Flow

1. The program asks for the number of players (2–4)
2. All players start at position 0
3. Players take turns rolling the dice
4. Their positions update based on the dice roll
5. When a player reaches the finish line, they are ranked
6. The game ends when the required number of winners is reached

---

## Who's Doing What

| Team Member | Responsible for                                                                                                              |
| ----------- | ---------------------------------------------------------------------------------------------------------------------------- |
| Alassane    | Game setup (handling number of players, input validation, initializing variables like positions and finish line)             |
| Emmanuel White| Dice rolling and turn system (creating the game loop, generating random dice values, and updating player movement each turn) |
| Name 3      | Output display and winner tracking (printing messages, tracking finished players, assigning rankings, and ending the game)   |
