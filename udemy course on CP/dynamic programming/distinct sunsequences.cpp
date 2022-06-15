
/*115. Distinct Subsequences
Hard

3074

136

Add to List

Share
Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

The test cases are generated so that the answer fits on a 32-bit signed integer.



Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag
 */


class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length();
        int n = s.length();
        vector<vector<unsigned long long >>DP(m,vector<unsigned long long>(n,0));
        DP[0][0] = (s[0] == t[0]);
        for(int j = 1; j < n; j++)
        {
            DP[0][j] = DP[0][j - 1] + (t[0] == s[j]);
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = i; j < n; j++)
            {
                DP[i][j] = DP[i][j - 1];
                if(t[i] == s[j])
                    DP[i][j] += DP[i - 1][j - 1];
            }
        }
        return DP[m - 1][n - 1];

    }
};
