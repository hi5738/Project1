/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <sstream>
#include <algorithm>
#include "board.h"

int main() {
	cout << "Welcome to Nonogram Game" <<endl;
	cout << "Fill or unfill the board with your cordinate to match the hidden pattern." << endl;
	int pattern[100] = { 0,1,1,0,
						1,0,0,1,
						1,1,1,1,
						1,0,0,1 };

	//whole board; Z represents the pattern needed from the pattern array
	char entire[300] = { ' ', ' ', ' ', ' ', ' ', ' ', '1', ' ', '1', ' ', ' ', ' ',
						 ' ', ' ', ' ', ' ', '3', ' ', '1', ' ', '1', ' ', '3', ' ',
						 ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-',
						 ' ', ' ', '2', '|', 'Z', '|', 'Z', '|', 'Z', '|', 'Z', '|',
						 ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-',
						 '1', ' ', '1', '|', 'Z', '|', 'Z', '|', 'Z', '|', 'Z', '|',
						 ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-',
						 ' ', ' ', '4', '|', 'Z', '|', 'Z', '|', 'Z', '|', 'Z', '|',
						 ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-',
						 '1', ' ', '1', '|', 'Z', '|', 'Z', '|', 'Z', '|', 'Z', '|',
						 ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-' };

	//int response = 0;

	Board userBoard;
	Board board(pattern, 4);
	userBoard.printEntire(entire);
	cout << endl;
	string userInput;
	int k = 0;
	string token;
	string arr2[2];

		while (1) {
			cout << "What would you like to fill? ie. 1,2 or Quit" << endl;
			getline(cin, userInput);
			if (userInput == "Quit" || userInput == "quit")
				break;
			//replaces the "-" character to become a " "
			replace(userInput.begin(), userInput.end(), ',', ' ');

				
					istringstream ss(userInput);


					while (getline(ss, token, ' ')) {

						arr2[k] = token;
						k++;
					}
				


				k = 0;
				userBoard.fillSpot(stoi(arr2[0]), stoi(arr2[1]));
				userBoard.printEntire(entire);
		
		}

		if (userBoard.compare(board))
			cout << "Congratulations! It is correct!";
		else {
			cout << "Missing: " << userBoard.missCount(board) << endl;
		}
	cout << "Entire Board Game Pattern" << endl;
	board.printEntire(entire);
	system("pause");
	return 0;
    
}