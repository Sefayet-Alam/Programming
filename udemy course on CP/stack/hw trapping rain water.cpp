 /*42. Trapping Rain Water
Hard

16639

235

Add to List

Share
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.



Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9


Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105*/
 class Solution {
public:
   int trap(vector<int>& height) {

    int n = height.size();

    vector<int> leftMax(n);
    leftMax[0] = height[0];
    int maxi = height[0];

    for(int i=1;i<n;i++)
    {
        if(height[i]>maxi)
            maxi = height[i];
        leftMax[i] = maxi;
    }

    vector<int> rightMax(n);
    rightMax[n-1] = height[n-1];
    maxi = height[n-1];

    for(int i=n-2;i>=0;i--)
    {
        if(height[i]>maxi)
            maxi = height[i];
        rightMax[i] = maxi;

    }

    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += min(leftMax[i],rightMax[i]) - height[i];
    }
    return sum;
}
};
