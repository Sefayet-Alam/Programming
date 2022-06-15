/*327. Count of Range Sum
Hard

1422

155

Add to List

Share
Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.

Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.



Example 1:

Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.
Example 2:

Input: nums = [0], lower = 0, upper = 0
Output: 1*/
class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {

		if (nums.size() == 0)
			return 0;

		// build cumulative summation array
		vector<long long> cums(nums.size(), 0);
		cums[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i)
			cums[i] = cums[i - 1] + nums[i];

		// run divide and conquer
		vector<long long> tmp(nums.size());
		return recursive_count(cums, 0, nums.size() - 1, tmp, lower, upper);
	}

	int recursive_count(vector<long long>& cums, int i, int j, vector<long long>& tmp, int lower, int upper) {

		if (i == j)
			return cums[i] >= lower && cums[i] <= upper;
		if (i > j)
			return 0;

		int mid = (i + j) / 2;
		int left = recursive_count(cums, i, mid, tmp, lower, upper);
		int right = recursive_count(cums, mid + 1, j, tmp, lower, upper);

		// compute the cross-boundary case in O(n)
		// based on the assumption that both left and right array are sorted
		int p = i, q = i, k = mid + 1;
		int cross = 0;
		for (k = mid + 1; k <= j; ++k) {
			while (p <= mid && cums[k] - cums[p] > upper)
				++p;
			while (q <= mid && cums[k] - cums[q] >= lower)
				++q;
			cross += q - p;
		}

		// merge sort in O(n)
		p = i; q = mid + 1; int o = i;
		while (p <= mid || q <= j) {
			long long v1 = (p <= mid ? cums[p] : LONG_MAX);
			long long v2 = (q <= j ? cums[q] : LONG_MAX);
			if (v1 < v2)
				tmp[o++] = cums[p++];
			else
				tmp[o++] = cums[q++];
		}
		copy(tmp.begin() + i, tmp.begin() + j + 1, cums.begin() + i);

		return left + right + cross;
	}
};
