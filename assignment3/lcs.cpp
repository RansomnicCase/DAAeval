#include<bits/stdc++.h>
using namespace std;


int lcs(string s, string t, int i, int j, vector<vector<int>> &dp){
    if(i==0||j==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];


    if(s[i-1]==t[j-1]){
        return dp[i][j] = 1 + lcs(s,t,i-1,j-1, &dp);
    }

    else{
        return dp[i][j] = max(lcs(s,t,i-1,j, &dp), lcs(s,t,i,j-1, &dp));
    }
}


int main(){
    string s = "abcdbcd";
    string t = "abed";


    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    return lcs(s,t,n,m,dp);
}