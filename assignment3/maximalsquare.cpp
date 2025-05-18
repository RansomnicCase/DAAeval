#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int solve(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp, int &maxside) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (i >= rows || j >= cols) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int right_val = solve(matrix, i, j + 1, dp, maxside);
    int down_val = solve(matrix, i + 1, j, dp, maxside);
    int diag_val = solve(matrix, i + 1, j + 1, dp, maxside);

    if (matrix[i][j] == 1) {
        dp[i][j] = 1 + min({right_val, down_val, diag_val});
        maxside = max(maxside, dp[i][j]);
    } else {
        dp[i][j] = 0;
    }
    
    return dp[i][j];
}

int maximalsquare(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    if (rows == 0) {
        return 0;
    }
    int cols = matrix[0].size();
    if (cols == 0) {
        return 0;
    }

    
    vector<vector<int>> dp(rows, vector<int>(cols, -1));
    int maxside = 0; 

    
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            solve(matrix, r, c, dp, maxside);
        }
    }

    return maxside * maxside;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    cout << "Maximum Square Area: " << maximalsquare(matrix) << endl; 
    
    vector<vector<int>> matrix2 = {
        {0,1},{1,0}
    };
    cout << "Maximum Square Area: " << maximalsquare(matrix2) << endl;

    vector<vector<int>> matrix3 = {
        {0}
    };
    cout << "Maximum Square Area: " << maximalsquare(matrix3) << endl;      

    vector<vector<int>> matrix4 = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };
    cout << "Maximum Square Area: " << maximalsquare(matrix4) << endl; 


    return 0;
}
