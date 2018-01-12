/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <sstream>
#include <algorithm>
#include "board.h"

int main(){
    
    int pattern[100] = {0,1,1,0,
                        1,0,0,1,
                        1,1,1,1,
                        1,0,0,1};
    
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
                         ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-'};
    
    bool compared;
    
    Board userBoard;
    Board board(pattern, 4);
    
    cout << "User Board\n";
    userBoard.printBoard();
    cout << endl;
    cout << "Pattern Board\n";
    board.printBoard();
    cout << endl;
    
    userBoard.printEntire(entire);
    cout << endl;
    board.printEntire(entire);
    
    compared = board.compare(userBoard);
    if(compared == 0)
        cout << "Comparable: FALSE" << endl;
    else
        cout << "Comparable: TRUE" << endl;
    
    board.emptyBoard();
    cout << "Pattern Board\n";
    board.printBoard();
    cout << endl;
    board.printEntire(entire);
    cout << endl;
    compared = board.compare(userBoard);
    if(compared == 0)
        cout << "Comparable: FALSE" << endl;
    else
        cout << "Comparable: TRUE" << endl;
    
    //board.fillSpot(0,0);
    //board.printEntire(entire);
    string userInput;
    cout << "What would you like to fill? ie. fillRow 1 0-2" << endl;
    //user must write exactly like the example or the fill function fails
    //can make it possible to check if user entered the line correctly before attempting to fill board; but did not try
    //string length should be 13
    //for single fill inputs, ie. 1,3, length is 3; same procedure as fillRow sentence
    
    getline(cin, userInput);
    string arr[4];
    int k = 0;
    //replaces the "-" character to become a " "
    replace(userInput.begin(), userInput.end(), '-', ' ');
    cout << userInput << endl;
    string token;
    if(true){
    istringstream ss(userInput);
    //creates tokens and inputting tokens into a string array
    //tested to see if separation worked on string
    while(getline(ss, token, ' ')){
        cout << token << endl;
        arr[k] = token;
        k++;
    }
    }
    k = 0;
    
    //tests to see if token placed in 3rd element went in
    cout << arr[3] << endl;
    
    //if arr[0] is fillRow; do the following
    if(arr[0] == "fillRow"){
        cout << "Filling Row" << endl;
        //converted the string array into the numbers that the user desired for input into board
        //fillRow function takes in int parameters
        userBoard.fillRow(stoi(arr[1]), stoi(arr[2]), stoi(arr[3]));
    }
    userBoard.printEntire(entire);
    
    cout << "What would you like to fill? ie. 1,2" << endl;
    getline(cin, userInput);
    string arr2[2];
    //replaces the "-" character to become a " "
    replace(userInput.begin(), userInput.end(), ',', ' ');
    cout << userInput << endl;
    if(true){ //if confused with if statement, its just for making the istringstream object
              //will be changing the if into a while loop
    istringstream ss(userInput);
    //creates tokens and inputting tokens into a string array
    //tested to see if separation worked on string
    while(getline(ss, token, ' ')){
        cout << token << endl;
        arr2[k] = token;
        k++;
    }
    }
    k = 0;
    userBoard.fillSpot(stoi(arr2[0]), stoi(arr2[1]));
    userBoard.printEntire(entire);
    //userBoard.fillSpot(1,2);
    //userBoard.printEntire(entire);
    //userBoard.fillRow(1, 0, 2);
    //userBoard.printEntire(entire);
    userBoard.fillCol(0, 1, 2);
    userBoard.printEntire(entire);
    
	system("pause");
	return 0;
    
}