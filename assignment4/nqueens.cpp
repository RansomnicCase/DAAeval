#include<bits/stdc++.h>
using namespace std;


bool printBoard(vector<string> &board){
    for(auto row:board){
        cout<<row<<endl;
    }
    cout<<endl;
    return true;
}


bool isSafe(vector<string> &board, int row, int col, int n){
    //check col
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q') return false;
    }

    //check left diagonal
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q') return false;
    }

    //check right diagonal
    for(int i=row,j=col;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q') return false;
    }
    return true;
}


void solve(vector<string> board, int n, int row, vector<vector<string>> &solutions){
    if(row==n){
        solutions.push_back(board);
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(board,row,col,n)){
            board[row][col] = "q";
            solve(board,n,row+1,solutions);
            board[row][col] = ".";
        }
    }
}

vector<vector<string>> solvequeens(int n){
    vector<vector<string>> solutions;
    vector<string> board(n,string(n,"."));

    solve(board,n,0,solutions);
    return solutions;
}


int main() {
    int n = 4;
    vector<vector<string>> solutions = solvequeens(n);

    cout << "Total Solutions: " << solutions.size() << "\n";
    for (auto &sol : solutions) {
        printBoard(sol);
    }

    return 0;
}