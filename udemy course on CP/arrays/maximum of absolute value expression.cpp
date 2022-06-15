/*Given two arrays of integers with equal lengths, return the maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

where the maximum is taken over all 0 <= i, j < arr1.length.



Example 1:

Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
Output: 13
Example 2:

Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
Output: 20*/

class Solution {
public:

int get_result(vector<int>&nums){

    int n=nums.size();

    int max1=INT_MIN;
    int max2=INT_MIN;
    int min1=INT_MAX;
    int min2=INT_MAX;

    int temp1,temp2;

    for(int i=0;i<n;i++){

        temp1=nums[i]+i;
        temp2=nums[i]-i;

        max1=max(max1,temp1);
        min1=min(min1,temp1);
        max2=max(max2,temp2);
        min2=min(min2,temp2);

    }

    return max((max1-min1),(max2-min2));

}

int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
    int n=arr1.size();

    vector<int>add;
    vector<int>sub;

    for(int i=0;i<n;i++){
        add.push_back(arr1[i]+arr2[i]);
    }

    for(int i=0;i<n;i++){
        sub.push_back(arr1[i]-arr2[i]);
    }

    return max(get_result(add),get_result(sub));

}
};
