	vector<vector<int>> pre_cal(vector<vector<int>> &a)
    {
        int n = a.size(), m = a[0].size();

        vector<vector<int>> ans(n, vector<int>(m,0));

        for(int i = 0; i < n; i++)
        {
            ans[i][m - 1] = a[i][m - 1];
            for(int j = m - 2; j >= 0; j--)
            {
                if(a[i][j]) ans[i][j] = ans[i][j + 1] + 1;
                else ans[i][j] = 0;
            }
        }

        return ans;
    }

    int numSubmat(vector<vector<int>>& a)
    {
        vector<vector<int>> pre = pre_cal(a);

        int n  = a.size(), m = a[0].size();

        int ans = 0;

        for(int i  = 0; i < n; i++)
        {
            for(int j  = 0; j < m; j++)
            {
                if(!a[i][j]) continue;

                //fix this corner (i, j)
                int cnt = pre[i][j];
                int mn = pre[i][j];
                for(int k = i + 1; k < n; k++)
                {
                    if(!a[k][j]) break;
                    mn = min(mn,pre[k][j]);
                    cnt += mn;
                }

                ans += cnt;
            }
        }

        return ans;
    }

