/*402. Remove K Digits
Medium

4414

184

Add to List

Share
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.



Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.


Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.*/
// Monotonic Stack Solution
class Solution {
public:
    string removeKdigits(string &num, int k) {
        int len = num.size();
        if (k == len) {
            return "0";
        }

        stack<int> monoIncStack;
        for (int i = 0; i < num.size() && k > 0; i++) {
            while (!monoIncStack.empty() && num[i] < num[monoIncStack.top()] && k > 0) {
                num[monoIncStack.top()] = '*';
                monoIncStack.pop();
                k--;
            }
            monoIncStack.push(i);
        }

        while (k > 0 && !monoIncStack.empty()) {
            num[monoIncStack.top()] = '*';
            monoIncStack.pop();
            k--;
        }

        string result;
        for (char c : num) {
            if (c != '*') {
                result += c;
            }
        }

        int i = 0;
        for (; i < result.size() && result[i] == '0'; i++) {}

        string cleanRes(begin(result) + i, end(result));
        return cleanRes == "" ? "0" : cleanRes;
    }
};
