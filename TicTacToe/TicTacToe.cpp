#include<iostream>

int8_t whichPlayer = 1;

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

Symbol grid[3][3]{
	{Symbol::EMPTY, Symbol::EMPTY, Symbol::EMPTY},
	{Symbol::EMPTY, Symbol::EMPTY, Symbol::EMPTY},
	{Symbol::EMPTY, Symbol::EMPTY, Symbol::EMPTY}
};

Result move(int x, int y, Symbol symbol);
void print();
void getInput();
void orderOfFunctions();

Result move(int x, int y, Symbol symbol) {
	
	if (x < 3 && x >= 0 && y < 3 && y >= 0) {
		if (grid[y][x] != EMPTY) return Result::WRONG;

		grid[y][x] = symbol;

		for (int i = 0; i < 3; i++)
			if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]) return Result::WON;

		for (int i = 0; i < 3; i++)
			if (grid[0][i] == grid[1][i] && grid[i][0] == grid[2][i]) return Result::WON;

		if ((grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) ||
		 	(grid[2][0] == grid[1][1] && grid[2][0] == grid[0][2])) return Result::WON;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (grid[i][j] != Symbol::EMPTY) return Result::LEGIT;
		
		return Result::TIE;
	} 
	else return Result::WRONG;
}

void print() {
	std::cout << " 0 1 2 \n" << "-------\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] == Symbol::CIRCLE) std::cout << 'O';
			else if (grid[i][j] == Symbol::CROSS) std::cout << 'X';
			else if (grid[i][j] == Symbol::EMPTY) std::cout << ' ';
		}
		std::cout << "\n";
	}
	getInput();
	/*std::cout << " 0 1 2 \n" <<"-------\n" ;
	for (int i = 0; i < 3; i++) 
		std::cout << i << "|" << grid[i][0] << "|" << grid[i][1] << "|" << grid[i][2] << "|"
			<< "-------\n";*/
}

void getInput() {
	int xAxis;
	int yAxis;

	std::cout << "What x axis do you choose";
	std::cin >> xAxis;
	std::cout << "What y axis do you choose";
	std::cin >> yAxis;

	switch (whichPlayer) {
	case 1:
		move(xAxis, yAxis, Symbol::CROSS);
		whichPlayer = 2;
		break;
	case 2:
		move(xAxis, yAxis, Symbol::CIRCLE);
		whichPlayer = 1;
		break;
	}
}

void orderOfFunctions() {
	getInput();
	print();
}

int main() {
	orderOfFunctions();
	return 0;
}

/*
will will print 2 for CROSS and 1 for CIRCLE
we need to print X and O
this is why we might have needed to do a for inside a for so only one grid[][] to care about
lets do that


ok


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