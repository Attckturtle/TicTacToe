#include <iostream>
#include<vector>
#include<cctype>

struct boardConstructor {
private:
	const int height = 3;
	const int width = 3;
public:
	char board[3][3] = {
		{'o','o','o'},
		{'o','o','o'},
		{'o','o','o'}
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

	void updateBoard(int x, int y, int whichPlayer) {
		x--;
		y--;
		if (x <= width && y <= height) {
			switch (whichPlayer) {
			case 1:
				board[y][x] = 'x';
				break;
			case 2:
				board[y][x] = 'y';
				break;
			}
		}
		else if (x > width || y > height) {
			std::cout << "Pick a valid option\n";
			Player1.chooseWhichOption();
		}
		printToConsole();
	}
};

class PlayerCreator {
int8_t wins = 0; 
public:
	void checkWinner(char boardLocal[3][3]) {
		int8_t howManyX = 0;
		int8_t howManyY = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 3; j < 3; j++) {
				if (boardLocal[i][j] == 'x') {
					howManyX++;
				} 
				if (boardLocal[i][j] == 'y') {
					howManyY++;
				}
			}
		}
		if (howManyX >= 3) {
			
		}

		if (howManyY >= 3) {

		}
	}

	void chooseWhichOption() {
		std::string chosenSquare;
		int8_t chosenX;
		int8_t chosenY;
		std::cout << "What square do you want to pick\n";
		std::cout << "X axis\n";
		std::cin >> chosenX;
		std::cout << "Y axis\n";
		std::cin >> chosenY;
		GameBoard.updateBoard(chosenX, chosenY, whichPlayerGlobal);

	}
};

int8_t whichPlayerGlobal = 1;
boardConstructor GameBoard;
PlayerCreator Player1;
PlayerCreator Player2;

int main() {
	GameBoard.printToConsole();
	Player1.chooseWhichOption();
	std::cout << "Tic tac toe";
}
