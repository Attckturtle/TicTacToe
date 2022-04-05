#include <iostream>
#include<vector>
#include<cctype>
struct boardConstructor {
private:
    const int height = 3;
    const int width = 3;
public:
    std::vector<std::vector<bool>> board
    {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
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

    void updateBoard(int8_t x, int8_t y) {
        printToConsole();
    }
};

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
    std::cin >> chosenSquare;
    GameBoard.updateBoard(chosenX, chosenY);
}


int main() {
    GameBoard.printToConsole();
    chooseWhichOption();
    std::cout << "Tic tac toe";
}