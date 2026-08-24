class Solution {
public:
    // int minDiff(int sum1,vector<int>& stones,int totalSum,int n,vector<vector<int>>&dp){
    //     if(n == 0){
    //         int sum2 = totalSum - sum1;
    //         return abs(sum1-sum2);
    //     }

    //     if(dp[n][sum1] != -1) return dp[n][sum1];

    //     return dp[n][sum1] = min(minDiff(sum1+stones[n-1],stones,totalSum,n-1,dp), minDiff(sum1,stones,totalSum,n-1,dp));
    // }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int totalSum = 0;

        for(int i = 0; i < n;i++) totalSum += stones[i];

        int target = totalSum/2;

        vector <int> dp(target+1,0);
       
        dp[0] = 1;

        for(int i : stones){
            for(int j = target; j >= i ;j--){
                dp[j] = dp[j] || dp[j-i];
            }
        }

        int best = 0;

        for(int j = target; j >= 0;j--){
            if(dp[j]) {
                best = j ;
                break;
            }
        }

        return totalSum - 2 * best;
    }

};