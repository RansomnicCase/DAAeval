#include<bits/stdc++.h>
using namespace std;


bool isSafe(int board[9][9], int row, int col, int num){
    for(int x=0;x<9;x++){
        if(board[x][col]==num||board[row][x]==num){
            return false;
        }
    }

    int starrow = row - row%3;
    int startcol = col - col%3;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i+startrow][j+startcol]==num){
                return false;
            }
        }
    }
    return true;
}


bool solve(int board[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                for(int num=1;num<=9;num++){
                    if(isSafe(board,i,j,num)){
                        board[i][j] = num;

                        if(solve(board)){
                            return true;
                        }
                        board[i][j] = 0;//backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},

        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},

        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board)) {
        cout << "Solved Sudoku:\n";
        printBoard(board);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}