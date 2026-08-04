class Solution {
public:
    void getperfectSquare(int n,vector <int>& perfectSquare){
        for(int i = 1; i <= sqrt(n);i++){
            perfectSquare.push_back(i*i);
        }
    }
    int minSum(vector<int>& perfectSquare,int m,int n,vector<vector<int>>&dp){
        if(n == 0) return 0;
        if(m == 0 || n < 0) return 1e9;
        if(dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = min(minSum(perfectSquare,m-1,n,dp),1 + minSum(perfectSquare,m,n - perfectSquare[m-1],dp));
    }
    int numSquares(int n) {
        vector<int> perfectSquare;
        getperfectSquare(n,perfectSquare);
        int m = perfectSquare.size();
        vector <vector<int>>dp(m+1,vector<int>(n+1,-1));
        return minSum(perfectSquare,m,n,dp);
    }
};