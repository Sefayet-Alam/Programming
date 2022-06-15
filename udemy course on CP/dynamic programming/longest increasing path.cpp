/*329. Longest Increasing Path in a Matrix
Hard

4827

82

Add to List

Share
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).



Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
 */
class Solution {
public:
    int m,n;
    int dir[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    int dfs(vector<vector<int>>& matrix,int x,int y,vector<vector<int>> &dp){
        if(dp[x][y]!=-1) return dp[x][y];
        int res=0;
        for(int i=0;i<4;i++){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(nx>=0 and ny>=0 and nx<m and ny<n and matrix[nx][ny]<matrix[x][y]){
                res=max(res,1+dfs(matrix,nx,ny,dp));
            }
        }
        return dp[x][y]=res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res=max(res,1+dfs(matrix,i,j,dp));
            }
        }
        return res;
    }
};
