class Solution {
public:
    // int findMinCoins(vector<int>& coins,int amount,int n,vector <vector<int>>&dp){
    //     if(amount == 0) return 0;
    //     if(n == 0 || amount < 0) return 1e9;
    //     if(dp[n][amount] != -1) return dp[n][amount];

    //     return dp[n][amount] = min(findMinCoins(coins,amount,n-1,dp),1 + findMinCoins(coins,amount-coins[n-1],n,dp));

    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector <vector<int>>dp(n+1,vector<int>(amount+1,0));
        //intialize row by 1e9
        //intialize col by 0
        for(int j = 0 ; j <= amount ;j++) dp[0][j] = 1e9;
        for(int i = 0 ; i <= n ;i++) dp[i][0] = 0;
        

        for(int i = 1;i <= n;i++){
            for(int j = 1; j <= amount;j++){
                if(j-coins[i-1] >= 0) dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
                else dp[i][j] = dp[i-1][j];   
            }
        }
        return dp[n][amount] >= 1e9 ? -1 : dp[n][amount];
        // return findMinCoins(coins,amount,n,dp) >= 1e9 ? -1 : findMinCoins(coins,amount,n,dp);
    }
};