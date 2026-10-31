//my last step could be 1 or either 2 to get reached that level
//eg. no of ways for 7 stairs : 
//        (no of ways for 6 stairs + 1 step) && (no of ways for 5 stairs + 2 step)

// base case would be : 
//              (1) no. of ways to climb 1 step = 1 
//              (2) no. of ways to climb 2 step = 2(by taking 1 and 1 || 2 steps directly)

class Solution {
public:
    int climb(int n,vector<int>&dp){
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n]= climb(n-1,dp)+climb(n-2,dp);

    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return climb(n,dp);
    }
};
