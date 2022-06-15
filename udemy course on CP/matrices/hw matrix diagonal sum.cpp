class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat)
    {
        int ans= 0;
        int j= 0;
        int k= mat.size()-1;
        for(int i=0; i<mat.size(); i++)
        {
            if(j==k)
            {
                ans+=mat[i][j];
            }
            else
            {
                ans+=(mat[i][j] + mat[i][k]);
            }
            j++;
            k--;
        }
        return ans;
    }
};
