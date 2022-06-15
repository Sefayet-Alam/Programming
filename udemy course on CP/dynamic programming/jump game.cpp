/*45. Jump Game II
Medium

7206

267

Add to List

Share
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000*/
class Solution {
public:

        int jump(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n, 0);

    for (int i = n - 2; i >= 0; --i)
    {
        int steps = 10010;

        for (int j = 1; j <= nums[i]; ++j)
        {
            if (i + j >= n)
                break;

            if (!dp[i + j] and i + j != n - 1)
                continue;

            steps = min(steps, dp[i + j] + 1);
        }

        if (steps == 10010)
            steps = 0;

        dp[i] = steps;
    }

    return dp[0];
}
    };
