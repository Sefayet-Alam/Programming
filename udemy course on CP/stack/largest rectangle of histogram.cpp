/*84. Largest Rectangle in Histogram
Hard

9030

136

Add to List

Share
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.



Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4


Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104*/
class Solution {
private:
    vector<int> nextSmaller(vector<int>arr,int n)
    {
        stack<int> s;
        vector<int> v(n);
        s.push(-1);
        for(int i = n-1;i>=0;i--)
        {
            while(s.top()!=-1 && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }
    vector<int> prevSmaller(vector<int>arr,int n)
    {
        stack<int> s;
        vector<int> v(n);
        s.push(-1);
        for(int i = 0;i<n;i++)
        {
            while(s.top()!=-1 && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        vector<int> next(n);
        vector<int> prev(n);
        next = nextSmaller(heights,n);
        prev = prevSmaller(heights,n);
        int area = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            int l = heights[i];

            if(next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i]-prev[i]-1;
            int newArea = l*b;
            area = max(area,newArea);
        }
        return area;

    }
};
