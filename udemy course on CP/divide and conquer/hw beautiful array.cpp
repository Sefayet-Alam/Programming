/*932. Beautiful Array
Medium

775

1156

Add to List

Share
An array nums of length n is beautiful if:

nums is a permutation of the integers in the range [1, n].
For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.



Example 1:

Input: n = 4
Output: [2,1,4,3]
Example 2:

Input: n = 5
Output: [3,1,2,5,4]*/
class Solution {
public:
    vector<int> beautifulArray(int n)
    {
        int a[n*2];
        int b[n*2];
        a[0] = 0;
        int *r =  a;
        int *r1 = b;
        for(int i = 1; i<=n; i*=2)
        {
            int *t = r;
            r = r1;
            r1 = t;
            for (int j=0,l=0; j<i; j++,l+=2)
            {
                r[l] = r1[j];
                r[l+1] = r1[j]+i;
                // cout  << ", " << r[l] << ", " << r[l+1];
            }
            // cout << endl;
        }
        vector<int> ans(n);
        for(int i = 1, j = 0; j<n; i++)
        {
            if (r[i] <= n)
                ans[j++] = r[i];
        }
        return ans;

    }
};
