class Solution {
public:
    int findMinCoins(vector<int>& coins,int amount,int n,vector <vector<int>>&dp){
        if(amount == 0) return 0;
        if(n == 0 || amount < 0) return 1e9;
        if(dp[n][amount] != -1) return dp[n][amount];

        return dp[n][amount] = min(findMinCoins(coins,amount,n-1,dp),1 + findMinCoins(coins,amount-coins[n-1],n,dp));

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector <vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return findMinCoins(coins,amount,n,dp) >= 1e9 ? -1 : findMinCoins(coins,amount,n,dp);
    }
};