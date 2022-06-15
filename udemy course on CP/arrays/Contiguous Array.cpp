/*Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.



Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp; mp[0]=-1;
        int sum = 0,longest_subarray = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 0 ? - 1 : 1;
            if(mp.find(sum) != mp.end())
            {
                if(longest_subarray < i - mp[sum])
                {
                    longest_subarray = i - mp[sum];
                }
            }
            else
            {
                mp[sum] = i;
            }
        }
        return longest_subarray;
    }
};
