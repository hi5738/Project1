/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   board.h
 * Author: Brandon
 *
 * Created on January 9, 2018, 12:03 PM
 */

#include <iostream>
#include <string>
using namespace std;

#ifndef BOARD_H
#define BOARD_H

class Board{
    
private:
    
    int board[4][4];
    int xDim; //x dimensions
    int yDim; //y dimensions
    bool filled; //bool variable to determine if user input anything into board
    
public:
    Board();
    Board(int pattern[], int dimension);
    void emptyBoard();
    void printBoard();
    void printEntire(char entire[]);
    bool compare(const Board& board);
	int Board::missCount(const Board& board);
    void fillSpot(int row, int col);
    void fillRow(int row, int col1, int col2);
    void fillCol(int col, int row1, int row2);
    
};

#endif /* BOARD_H */

