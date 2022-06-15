/*321. Create Maximum Number
Hard

1234

302

Add to List

Share
You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.

Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.

Return an array of the k digits representing the answer.



Example 1:

Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
Output: [9,8,6,5,3]
Example 2:

Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
Output: [6,7,6,0,4]
Example 3:

Input: nums1 = [3,9], nums2 = [8,9], k = 3
Output: [9,8,9]


Constraints:

m == nums1.length
n == nums2.length
1 <= m, n <= 500
0 <= nums1[i], nums2[i] <= 9
1 <= k <= m + n*/
class Solution {
public:
    std::deque<int> getMax(const std::vector<int> &nums, int k)
    {
        if(k == 0){
            return {};
        }

        std::deque<int> result;
        const int drop = std::max<int>(0, nums.size() - k);

        for(int d = 0; const auto e: nums){
            while(!result.empty() && result.back() < e && d < drop){
                result.pop_back();
                d++;
            }
            result.push_back(e);
        }

        while(result.size() > k){
            result.resize(k);
        }
        return result;
    }

    std::vector<int> merge(std::deque<int> p, std::deque<int> q)
    {
        std::vector<int> result;
        while(!(p.empty() && q.empty())){
            if(p > q){
                result.push_back(p.front());
                p.pop_front();
            }
            else{
                result.push_back(q.front());
                q.pop_front();
            }
        }
        return result;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
    {
        std::vector<int> result;
        for(int i = 0; i <= k && i <= nums1.size(); ++i){
            if(int j = k - i; j <= nums2.size()){
                result = std::max(result, merge(getMax(nums1, i), getMax(nums2, j)));
            }
        }
        return result;
    }
};
