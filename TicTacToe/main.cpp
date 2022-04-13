#include<iostream>


int8_t whichPlayer = 1;


enum Symbol {
EMPTY = 0,
CIRCLE,
CROSS
};


enum Result {
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
void checkWinner(Result a);
void clearGrid();


Result move(int x, int y, Symbol symbol) {
int squaresNo = 0 ;

if (x < 3 && x >= 0 && y < 3 && y >= 0 && grid[y][x] == Symbol::EMPTY && grid[y][x] == EMPTY) {
grid[y][x] = symbol;

/* 
for (int i = 0; i < 3; i++)
if ((grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]) ||
(grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i]) ||
(grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) ||
(grid[2][0] == grid[1][1] && grid[2][0] == grid[0][2]))return Result::WON;
*/

for (int i = 0; i < 3; i++)
for (int j = 0; j < 3; j++)
if (grid[i][j] == Symbol::EMPTY) return Result::LEGIT;
else (grid[i][j] != Symbol::EMPTY); squaresNo++;
std::cout << "balls" <<squaresNo;

if (squaresNo == 9) return Result::LEGIT;
}
else return Result::WRONG;
}


void print() {
std::cout << " 0 1 2 \n" << " -------\n";
for (int i = 0; i < 3; i++) {
if (i == 0) {
std::cout << "0" << "|";
}
else {
std::cout << i << "|";
}
for (int j = 0; j < 3; j++) {
if (grid[i][j] == Symbol::CIRCLE) std::cout << 'O' << "|";
else if (grid[i][j] == Symbol::CROSS) std::cout << 'X' << "|";
else if (grid[i][j] == Symbol::EMPTY) std::cout << ' ' << "|";
}
std::cout << "\n";
}
std::cout << " -------\n";


}


void getInput() {
//system("CLS");
print();


int xAxis;
int yAxis;


std::cout << "What x axis do you choose";
std::cin >> xAxis;
std::cout << "What y axis do you choose";
std::cin >> yAxis;


switch (whichPlayer) {
Result a;
case 1:
whichPlayer = 2;
a = move(xAxis, yAxis, Symbol::CROSS);
checkWinner(a);
break;
case 2:
whichPlayer = 1;
a = move(xAxis, yAxis, Symbol::CIRCLE);
checkWinner(a);
break;
 }
}


void checkWinner(Result a) {
switch (a) {
case Result::WON:
std::cout << "You win\n";
break;
case Result::TIE:
std::cout << "Tie";
break;
case Result::WRONG:
std::cout << "Wrong input";

default:
std::cout << "Next players turn\n";
getInput();
}
}


void clearGrid() {
for (int i = 0; i < 3; i++)
for (int j = 0; j < 3; j++)
grid[i][j] = Symbol::EMPTY;
}


int main() {
getInput();
return 0;
}