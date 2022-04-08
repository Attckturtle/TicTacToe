#include<iostream>

enum Symbol{
	EMPTY = 0,
	CIRCLE,
	CROSS
};

enum Result{
	LEGIT,
	WRONG,
	WON,
	TIE
};

struct Position {
	int x, y;
};

Symbol grid[3][3]{};

Result move(int x, int y, Symbol symbol) {
	int numOfEmptySquares = 0;
	if (x < 3 && x >= 0 && y < 3 && y >= 0) {
		if (grid[y][x] != EMPTY) {
			return Result::WRONG;
		} else
		
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (grid[i][j] == Symbol::EMPTY) {
						numOfEmptySquares++;
					}
				}
			}

		if (numOfEmptySquares == 0) {
			return Result::TIE;
		}

		if (grid[0][0] == CIRCLE || grid[0][0] == CROSS && grid[0][1] == CIRCLE)

		return Result::LEGIT;
	}
	else {
		return Result::WRONG;
	}
}

int main() {

	


	return 0;
}

/*
we could just make a table of them and check for every case
like you have the position of the last move and you check if the move is present 
it is always present in the table
in the configuration where its found present we check the configuration with the grid 
alright so
how do we represent a configuration???
i dont know
you have already an algorithm you are copying?
no i was finishing the thing that checks for a tie

sry i gtg its getting late where i live.
bye
bye we can see it tomorrow
yeah ok
bye
bye
    0   1   2          0   1   2           0   1   2
  -------------      -------------       -------------   
0 | X | X | X |      |   |   |   |       |   |   |   |
  -------------      -------------       -------------
1 |   |   |   |   Or | X | X | X |   Or  |   |   |   | 
  -------------      -------------       -------------
2 |   |   |   |      |   |   |   |       | X | X | X |
  -------------      -------------       -------------
   0   1   2          0   1   2           0   1   2
  -------------      -------------       -------------   
0 | X |   |   |      |   | X |   |       |   |   | X |
  -------------      -------------       -------------
1 | X |   |   |   Or |   | X |   |   Or  |   |   | X | 
  -------------      -------------       -------------
2 | X |   |   |      |   | X |   |       |   |   | X |
  -------------      -------------       -------------
    0   1   2         
  -------------      
0 | X |   |   |     
  -------------   
1 |   | X |   |   
  -------------   
2 |   |   | X |   
  ------------- 
    0   1   2         
  -------------      
0 |   |   | X |     
  -------------   
1 |   | X |   |   
  -------------   
2 | X |   |   |   
  ------------- 
*/