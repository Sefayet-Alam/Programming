/*32. Longest Valid Parentheses
Hard

7057

242

Add to List

Share
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.



Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0*/
class Solution {
public:
    int longestValidParentheses(string s) {
        size_t n = s.length();
        int ret = 0;
        int ob = 0;
        int cb = 0;
        for(size_t i = 0; i < n; ++i) {
            if(s[i] == '(')
                ob++;
            else
                cb++;
            if(cb == ob) {
                ret = max(ret,2*cb);
            }
            if(cb > ob) {
                cb = ob = 0;
            }
        }
        ob = cb = 0;
        for(size_t i = n; i > 0; --i) {
            if(s[i-1] == '(')
                ob++;
            else
                cb++;
            if(cb == ob) {
                ret = max(ret,2*cb);
            }
            if(cb < ob) {
                cb = ob = 0;
            }
        }
        return ret;
    }
};
