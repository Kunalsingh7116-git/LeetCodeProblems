class Solution {
public:
    int minDiff(int sum1,vector<int>& stones,int totalSum,int n,vector<vector<int>>&dp){
        if(n == 0){
            int sum2 = totalSum - sum1;
            return abs(sum1-sum2);
        }

        if(dp[n][sum1] != -1) return dp[n][sum1];

        return dp[n][sum1] = min(minDiff(sum1+stones[n-1],stones,totalSum,n-1,dp), minDiff(sum1,stones,totalSum,n-1,dp));
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int sum1 = 0;

        int totalSum = 0;

        for(int i = 0; i < n;i++) totalSum += stones[i];

        vector<vector <int>> dp(n+1,vector<int>(totalSum+1,-1));

        return minDiff(sum1,stones,totalSum,n,dp);
    }

};