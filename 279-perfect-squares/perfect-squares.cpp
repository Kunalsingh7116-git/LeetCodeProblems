class Solution {
public:
    void getperfectSquare(int n,vector <int>& perfectSquare){
        for(int i = 1; i <= sqrt(n);i++){
            perfectSquare.push_back(i*i);
        }
    }
    // int minSum(vector<int>& perfectSquare,int m,int n,vector<vector<int>>&dp){
    //     if(n == 0) return 0;
    //     if(m == 0 || n < 0) return 1e9;
    //     if(dp[m][n] != -1) return dp[m][n];
    //     return dp[m][n] = min(minSum(perfectSquare,m-1,n,dp),1 + minSum(perfectSquare,m,n - perfectSquare[m-1],dp));
    // }
    int numSquares(int n) {
        vector<int> perfectSquare;
        getperfectSquare(n,perfectSquare);
        int m = perfectSquare.size();
        // vector <vector<int>>dp(m+1,vector<int>(n+1,-1));
        // vector <vector<int>>dp(m+1,vector<int>(n+1,0))
        // vector <int> prev(n+1,0);
        // for(int j = 0; j <= n; j++) prev[j] = 1e9;
        // for(int i = 0 ; i <= m;i++) dp[i][0] = 0;
        vector <int> prev(n+1,1e9);
        prev[0]= 0;
        for(int i = 0; i < m; i++){
            for(int j = perfectSquare[i]; j <= n;j++){
                prev[j] = min(prev[j], 1 + prev[j-perfectSquare[i]]);
            }
        }
        return prev[n];
        // return minSum(perfectSquare,m,n,dp);
    }
};