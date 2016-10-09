class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        return DP(dp,1,n);
    }
    int DP(vector<vector<int>> &dp,int b,int e){
        if(b>=e) return 0;
        if(dp[b][e]) return dp[b][e];
        int result = INT_MAX;
        for(int i=b;i<=e;++i){
            result = min(result,max(DP(dp,b,i-1),DP(dp,i+1,e))+i);
        }
        dp[b][e] = result;
        return result;
    }
};