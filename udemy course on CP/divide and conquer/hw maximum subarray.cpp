/*53. Maximum Subarray
Easy

18299

871

Add to List

Share
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.



Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23*/
class Solution {
    struct value
    {
        int startLeft; // maxSum that must include left
        int endRight; // maxSum that must include right
        int totalSum; // total sum
        int maxSum; // result of current region
        value(int s, int e, int t, int m):startLeft(s), endRight(e), totalSum(t), maxSum(m){}
    };

    value divideAndConquer(vector<int> const& nums, int l, int r)
    {
        if (l==r)
        {
            return {nums[l], nums[l],nums[l],nums[l]};
        }

        int m = l + (r-l)/2;

        auto fromLeft=divideAndConquer(nums, l, m);
        auto fromRight=divideAndConquer(nums, m+1, r);

        int s = max(fromLeft.startLeft, fromLeft.totalSum+fromRight.startLeft);
        int e = max(fromRight.endRight, fromRight.totalSum+fromLeft.endRight);
        int t = fromLeft.totalSum + fromRight.totalSum;
        int ma = max(max(fromLeft.endRight+fromRight.startLeft, fromLeft.maxSum), fromRight.maxSum);

        return {s,e,t,ma};

    }
public:
    int maxSubArray(vector<int>& nums) {
        auto v = divideAndConquer(nums, 0, nums.size()-1);

        return v.maxSum;
    }
};

