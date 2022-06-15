/*Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.



Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].*/
class Solution {
public:
    int kSubCounter(vector<int> nums,int k){
        //the approach is hashing along with sliding window.
        // on each iteration we will count no. of subarrays with atmost k diff elements in it .
        int subCount=0;
        unordered_map<int,int> mp;
        int l=0;
        int n=nums.size();
        int diff=0;//to count diff ele in the subarray (we can also use mp.size() to determine that.)

        for(int r=0;r<n;r++){
            //if the ele is not in the map(new element)
            if(mp[nums[r]]==0)diff++;

            //otherwise we will simply increment its count in map.
            mp[nums[r]]++;

            //if the subarray already has less than k diff integers we will not remove the elements and                     just simply calculate the total subarrays at last.

            //else we will remove the elements from the window(increment the left pointer.)
            //as well as decreasing the count of the element in map.
            // and whenever count of this integer in the map becomes zero then it means the total number of
               // diff elements in the window is decreased by one.
            while(l<n and l<=r and diff>k){
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0)diff--;

                    l++;
               }
            //here we calculated the total subarrays with atmost k diff elements in it.
            subCount+=(r-l+1);

        }
        return subCount;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return kSubCounter(nums,k)-kSubCounter(nums,k-1);
        //main idea is if I count subarrays with atmost k diff ele and subarray with k-1 atmost diff ele                then i can determine subarray with exactly k diff elements by substracting them.

    }
};
