#include <string>
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

//Array constants
enum { EMPTY, CURRENT, HISTORY, JEWEL };
const int Nboard = 6;

//GUI Functions
void clearConsole();
void pauseConsole();
void splashScreen();
void displayGameState(int[Nboard][Nboard], string, bool);
void displayGameDone(int[Nboard][Nboard], int, int, string);
char getAction();

//Engine Functions
void initGame(int[Nboard][Nboard], int&, int&, int&, int&);
void changeGameState(char, int[Nboard][Nboard], int&, int&, bool&);
bool gameIsDone(int, int, int, int);

string studentName = "Your name here (2020)";

int main () {
	//the game board
	int board[Nboard][Nboard];

	//State variables
	int currentRow, currentCol, secretRow, secretCol;
	bool history = true;

	//Splash Screen
	clearConsole();
	splashScreen();

	initGame(board, currentRow, currentCol, secretRow, secretCol);

	do {
		//Display Game State
		clearConsole();
		displayGameState(board, "Current Search History", history);

		//Update Game State
		changeGameState(getAction(), board, currentRow, currentCol, history);

		//Check Game Termination
	} while (!gameIsDone(currentRow, currentCol, secretRow, secretCol));

	//Display Termination Game State
	displayGameDone(board, secretRow, secretCol, "YOU FOUND THE HIDDEN JEWEL!");

	return 0;
}

void clearConsole () {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	system("cls");
#else
    system("clear");
#endif
}

void pauseConsole () {
    std::string temp;
    std::cout << "Enter to continue... ";
    std::getline(std::cin, temp);
}

void splashScreen () {
	cout << "HIDDEN JEWEL!" << endl;
	cout << endl;
	cout << studentName << endl;
	cout << "CPSC 2376, Programming II, Quest 0" << endl;
	cout << "UALR, Computer Science Dept." << endl;
	cout << endl;
	cout << "INSTRUCTIONS:" << endl;
	cout << endl;
	cout << "Find the hidden jewel to win the game!" << endl;
	cout << endl;
	cout << "        (North)          " << endl;
	cout << "           w             " << endl;
	cout << "           |             " << endl;
	cout << "(West) a --+-- d (East)  " << endl;
	cout << "           |             " << endl;
	cout << "           s             " << endl;
	cout << "        (South)          " << endl;
	cout << endl;
	cout << "Select 'h' to toggle history." << endl;
	cout << endl;

	pauseConsole();
}

void displayGameState (int board[Nboard][Nboard], string message, bool history) {
	//Implement here

}

void displayGameDone (int board[Nboard][Nboard], int secretRow, int secretCol, string message) {
	//Implement here

}

char getAction () {
	//Implement here

	return('n'); //This is a placeholder to make the program compile!

}

void initGame (int board[Nboard][Nboard], int& currentRow, int& currentCol, int& secretRow, int& secretCol) {
	//this code given to you because we have not covered random number generation yet;
	//You will still need to add more code to this function.
	random_device seed;
	default_random_engine e(seed());
	uniform_int_distribution<int> d(0, Nboard-1);

	//generates random location.
	secretRow = d(e);
	secretCol = d(e);

	// Implement here
}

void changeGameState (char action, int board[Nboard][Nboard], int& currentRow, int& currentCol, bool& history) {
	//Implement here

}


bool gameIsDone (int currentRow, int currentCol, int secretRow, int secretCol) {
	//Implement here

	return false; //This is a placehold to make the program compile!

}
