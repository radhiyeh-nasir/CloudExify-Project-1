# Number Guessing Game

CloudExify Summer Internship 2026
Intern Id: CX-INT-2026-CPP-0295

Name:Radhiyeh Nasir

## Description

It is a console-based Number Guessing Game built in C++. The computer picks a random secret number within a range chosen by the player, and the player has a limited number of attempts to guess it correctly, guided by high/low and warmer/colder hints.

## Features

- **Difficulty selection** — Easy (1–30), Medium (1–100), Hard (1–500)
- **Input validation** — invalid difficulty choices default safely to Medium with a warning; guesses outside the valid range don't count as an attempt
- **High/Low feedback** — tells the player whether to guess higher or lower
- **Warmer/Colder hints (bonus)** — compares each guess's distance from the secret number to the previous guess, letting the player know if they're getting closer or farther away
- **Attempt limit (bonus)** — player has 10 attempts per round; the game ends and reveals the number if all attempts are used without a correct guess
- **Best score tracking** — the lowest number of attempts taken to win is saved to `best_score.txt` and persists across program runs; only updates when beaten
- **Replay loop** — play multiple rounds in one session without restarting the program

## How to Run

### Requirements
- A C++ compiler (e.g. g++, or Code::Blocks with MinGW)

### Compile and run (command line)
```bash
g++ guessinggame.cpp -o guessinggame
./guessinggame        
guessinggame.exe     
```

### Or using Code::Blocks
1. Open `guessinggame.cpp` in Code::Blocks
2. Build: `Ctrl + F9`
3. Run: `Ctrl + F10`

## How to Play

1. Choose a difficulty level (1, 2, or 3)
2. Enter your guess when prompted
3. Use the Too High / Too Low and Getting Warmer / Getting Colder hints to narrow down the number
4. Guess correctly within 10 attempts to win
5. Try to beat your best score, saved automatically between sessions
6. Choose to play again or exit at the end of each round

## Sample Output

```
===== WELCOME TO NUMBER GUESSING GAME =====
Current best score: 4 attempts

Choose your difficulty:
1) Easy   (1-30)
2) Medium (1-100)
3) Hard   (1-500)
Enter your choice: 2

I'm thinking of a number between 1 and 100.
You have 10 attempts. Good luck!

Attempt 1/10 - Enter your guess: 50
Too HIGH! 

Attempt 2/10 - Enter your guess: 25
Too LOW! (Getting warmer)

Attempt 3/10 - Enter your guess: 37
Correct! You guessed it in 3 tries!
New best score: 3 attempts!

Play again? (y/n): n

Thanks for playing! Goodbye!
```

