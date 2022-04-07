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
	void updateBoard(int x, int y, int whichPlayer) {
		switch (whichPlayer) {
		case 1:
			board[y][x] = 'x';
			break;
		case 2:
			board[y][x] = 'y';
			break;
		default:
			std::cout << "Pick a valid option\n";
		}
		printToConsole();
	}
};

class PlayerCreator {
int8_t wins = 0; 
public:
	void checkWinner(std::vector < std::vector<char> > boardLocal) {
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
};

int8_t whichPlayerGlobal = 1;
boardConstructor GameBoard;
PlayerCreator Player1;
PlayerCreator Player2;

void chooseWhichOption();

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

int main() {
	GameBoard.printToConsole();
	chooseWhichOption();
	std::cout << "Tic tac toe";
}
