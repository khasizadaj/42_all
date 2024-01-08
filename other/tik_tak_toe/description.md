# Subject

**Program name:** tiktaktoe
**Arguments:** [difficulty] [which player starts]
**Turn in files:** Makefile and all the necessary files
**Allowed functions:** read, write, exit, malloc, free
**Description:** Write a program with which you can play Tik Tak Toe.

- The aim of this project is to play Tik Tak Toe
- Your program will be compiled as follows:

```sh
$ make fclean
$ make
```

- Your program will be run as follows: `./tiktaktoe`
	- Optionally it needs to support following arguments:
		- Difficulty: easy, normal, impossible
		- Which player starts: computer, human
		- An invalid argument causes an error
	- On start it needs to print the current mode
	- Before each game it needs to print the current amount of wins for both players
	- You should understand how the game works by the example below.

---

Here is an example of how it should work:

```
./tiktaktoe
Computer starts. Difficulty: normal
Current wins: Computer: 0 You: 0
| X |   |   |         |   | 2 | 3 |
|   |   |   |         | 4 | 5 | 6 |
|   |   |   |         | 7 | 8 | 9 |
What's your move (enter the number of the cell you want to place in)?
5
| X |   |   |         |   | 2 | 3 |
| X | O |   |         |   |   | 6 |
|   |   |   |         | 7 | 8 | 9 |
What's your move (enter the number of the cell you want to place in)?
1
This is not a valid move. Try again:
3
| X |   | O |
| X | O |   |
| X |   |   |
Computer wins! 1-0 for the Computer!
Do you want to play again? [y/n] n
```

# Bonus

- Add a mode to play against another human.
- Give feedback when the player decided on a move.
- Add an option to change the grid's size. What?

# Submission and peer-evaluation

Turn in your program in the desired Git repository. Only files in the Git repository will be graded.
After two peer evaluations your program will also be graded by Moulinette, because why not?

