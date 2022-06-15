/*Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.



Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
Example 2:

Input: arr = [1,1]
Output: 1*/

class Solution {

public:
    int findSpecialInteger(vector<int>& arr) {
        int window_size = arr.size() / 4;

        for (int i = 0; i < arr.size() - window_size; i++) {
            if (arr[i] == arr[i + window_size]) {
                return arr[i];
            }
        }

        return -1;
    }
};
