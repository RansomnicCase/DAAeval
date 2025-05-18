#include<bits/stdc++.h>
using namespace std;


int knapsackutil(int idx, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
    if(idx==0){
        return val[0];
    }

    if(dp[idx][W]!=-1){
        return dp[idx][W];
    }

    int nottake = knapsackutil(idx-1, W, val, wt, dp);

    int take = INT_MIN;
    if(wt[idx]<=W){
        take = val[idx] + knapsackutil(idx-1, W-wt[idx], val, wt, dp);
    }
    return dp[idx][W] = max(take,nottake); 
}

int knapsack(vector<int> &val, vector<int> &wt, int W){
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W+1,-1));
    return knapsackutil(n-1,W,val,wt,dp);
}


int main(){
    vector<int> val = {60,100,120};
    vector<int> wt = {10,20,30};
    int W = 50;
    cout<<knapsack(val,wt,W);
}