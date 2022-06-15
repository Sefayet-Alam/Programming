/*You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.



Example 1:

Input: n = 1
Output: true
Example 2:

Input: n = 10
Output: false*/

class Solution {
public:
   bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        do{
            if(s[0] == '0') continue;
            int m = stoi(s);
            if(__builtin_popcount(m) == 1) return true;
        }while(next_permutation(s.begin(), s.end()));
        return false;
    }
};
