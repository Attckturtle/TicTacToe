#include <iostream>
#include<vector>
#include<cctype>


struct boardConstructor {
private:
	const int height = 3;
	const int width = 3;
public:
	std::vector<std::vector<char>> board
	{
	{'a', 'a', 'a'},
	{'a', 'a', 'a'},
	{'a', 'a', 'a'}
	};


	void printToConsole() {
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				std::cout << board[i][j] << "";
			}
			std::cout << "\n";
		}
	}


	void updateBoard(int8_t x, int8_t y, int8_t whichPlayer) {
		switch (whichPlayer) {
		case 1:
			board[y][x] = 'x';
			break;
		case 2:
			board[y][x] = 'y';
			break;
		default:
			std::cout << "Pick a valid option";
		}
		printToConsole();
	}
};


int8_t whichPlayerGlobal = 1;
boardConstructor GameBoard;


void chooseWhichOption();


void chooseWhichOption() {
	std::string chosenSquare;
	int8_t chosenX;
	int8_t chosenY;
	std::cout << "What square do you want to pick";
	std::cout << "X axis";
	std::cin >> chosenX;
	std::cout << "Y axis";
	std::cin >> chosenY;
	GameBoard.updateBoard(chosenX, chosenY, whichPlayerGlobal);
}



int main() {
	GameBoard.printToConsole();
	chooseWhichOption();
	std::cout << "Tic tac toe";
}