class Solution {
public:
    int minSrairsCost(int n,vector <int> & cost,vector<int> &dp){

        if(n <=1) return 0;

        if(dp[n] != -1) return dp[n];

        return dp[n] = min(cost[n-2]+ minSrairsCost(n-2,cost,dp),cost[n-1]+ minSrairsCost(n-1,cost,dp));
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // if(n <=1) return 0;
        // int prev1 = 0;
        // int prev2 = 
        vector<int>dp(n+1,-1);
        return minSrairsCost(n,cost,dp);
    }
};