class Solution {
public:
    // int findcombination(int n,int target,vector<int>& nums,vector <int> &dp){
    //     if(target == 0) return 1;
    //     if(target < 0) return 0;

    //     int result = 0;

    //     if(dp[target] != -1) return dp[target];
    //     for(int j = 0;j<n;j++){
    //         result += findcombination(n,target-nums[j],nums,dp);
    //     }
    //     return dp[target] = result;
    // }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned int> dp(target+1,-1);
        dp[0] = 1;
        for(int i = 1;i <=target;i++){
            int result = 0;
            for(int j = 0; j < n;j++){
                if(i-nums[j] >= 0) result += dp[i-nums[j]];
            }
            dp[i] = result;
        }
        return (int)dp[target];
    }
};