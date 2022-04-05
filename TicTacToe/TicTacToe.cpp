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
            std::cout << std::endl;
        }
    }
};

boardConstructor GameBoard;

//void renderNewFrame(std::string a);
void chooseWhichOption();

void chooseWhichOption() {
    std::string chosenSquare;
    std::cout << "What square do you want to pick";
    std::cin >> chosenSquare;
    //chosenSquare = tolower(chosenSquare);
    //renderNewFrame(chosenSquare);
}

/*
void renderNewFrame(std::string a) {
    char b = a[0];
    if (b == "a") {
    }
    switch (a) {
    case "a1":
        GameBoard.board[0][0] = "x";
        break;
    case "a2":
        GameBoard.board[0][1] = "x";
        break;
    case "a3":
        GameBoard.board[0][2] = "x";
        break;
    case "b1":
        GameBoard.board[1][0] = "x";
        break;
    case "b2":
        GameBoard.board[1][1] = "x";
        break;
    case "b3":
        GameBoard.board[1][2] = "x";
        break;
    case "c1":
        GameBoard.board[2][0] = "x";
        break;
    case "c2":
        GameBoard.board[2][1] = "x";
        break;
    case "c3":
        GameBoard.board[2][2] = "x";
        break;
    }
    GameBoard.printToConsole();
}
*/

int main() {
    GameBoard.printToConsole();
    chooseWhichOption();
    std::cout << "Tic tac toe";
}