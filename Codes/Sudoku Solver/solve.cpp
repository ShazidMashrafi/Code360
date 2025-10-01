#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int val) 
{
    for(int i = 0; i < 9; ++i) {
        if(board[row][i] == val)    return false;
        if(board[i][col] == val)    return false;
    }

    int x = 3 * (row / 3);
    int y = 3 * (col / 3);
    for(int i = x; i < x + 3; ++i) {
        for(int j = y; j < y + 3; ++j) {
            if(board[i][j] == val) return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &board)
{
    for(int row = 0; row < 9; ++row) {
        for(int col = 0; col < 9; ++col) {
            if(board[row][col]) continue;

            for(int val = 1; val <= 9; val++) {
                if(isSafe(row, col, board, val)) {
                    board[row][col] = val;
                    if(solve(board)) return true;
                    board[row][col] = 0;
                }
            }
            return false;
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}