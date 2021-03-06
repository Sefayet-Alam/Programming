int maximalSquare(vector<vector<char>>& matrix) {
    int n=matrix.size(),m=matrix[0].size();
    int dp[n+1][m+1]; int ans=0;
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(matrix[i-1][j-1]=='1'){
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                ans=max(ans,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    return ans*ans;
}
