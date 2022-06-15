/*368. Largest Divisible Subset
Medium

3000

137

Add to List

Share
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.



Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //for pair to be valid -> larger must be multiple of smaller
        //pick largest stream of multiples
        //given nums[i] are positive
        //al integers are unique

        // dynamic programming to explore every pair
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<pair<int,int>> dp(n,make_pair(1,n));  //also keep record of next element to pick
        //next index is n
        int maxlen=1;
        int start_from=n-1;

        for(int i=n-1;i>=0;i--)  //nums[i] as divisor
        {
            //check for dividend>divisor
            for(int j=i+1;j<n;j++) //nums[j] as dividend
            {
                if(nums[j]%nums[i]==0)
                {
                    if(dp[j].first+1>dp[i].first)
                    {
                        dp[i].first=dp[j].first+1;
                        dp[i].second=j;

                    }
                }
            }

            if(dp[i].first>maxlen)
            {
                maxlen=dp[i].first;
                start_from=i;  //maximum numbers are dividing nums[i] perfectly
            }
        }

        vector<int> ans;
        //all divisors of biggest
        for(int i=start_from;i<n;i=dp[i].second)
        {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
