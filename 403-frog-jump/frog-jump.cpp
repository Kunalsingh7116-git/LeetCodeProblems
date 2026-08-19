class Solution {
public:
    int n;
    unordered_map <int,int>mpp;
    bool solve(vector<int>& stones,int curr_stone_idx, int prevJump,vector<vector<int>>&dp){
        if(curr_stone_idx == n - 1) return true ;

        int result = false;

        if(dp[curr_stone_idx][prevJump] != -1) return dp[curr_stone_idx][prevJump];
        for(int nextJump = prevJump - 1; nextJump <= prevJump + 1;  nextJump++){
            if(nextJump > 0){
                int nextStone = stones[curr_stone_idx] + nextJump;
                if(mpp.find(nextStone) != mpp.end()){
                    result = result || solve(stones,mpp[nextStone], nextJump,dp);
                }
            }
        }
        return dp[curr_stone_idx][prevJump] = result;
    }
    bool canCross(vector<int>& stones) {

        n = stones.size();

        if(stones[1] != 1) return false;


        for(int i = 0; i < n;i++){
            mpp[stones[i]] = i;
        }

        vector<vector<int>>dp(2001,vector<int>(2001,-1));
        return solve(stones,mpp[0],0,dp);
        
    }
};