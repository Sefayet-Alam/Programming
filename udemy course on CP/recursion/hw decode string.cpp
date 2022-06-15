/*394. Decode String
Medium

7458

317

Add to List

Share
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].



Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"*/
class Solution {
public:

    string repeat(string s, int n)
    {
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            ans += s;
        }
        return ans;
    }

    string function(string s, int &idx)
    {
        string substr = "";
        while(s[idx] >= 'a' && s[idx] <= 'z')
        {
            substr.push_back(s[idx]);
            idx++;
        }
        string digit = "";
        while(s[idx] >= '0' && s[idx] <= '9')
        {
            digit.push_back(s[idx]);
            idx++;
        }
        int num = 0;
        if(digit != "") num = stoi(digit);

        if(s[idx] == '[')
        {
            idx++;
            substr +=  repeat(function(s, idx), num);
        }
        else if(s[idx] == ']')
        {
            idx++;
            return substr;
        }
        while(idx < s.length() && s[idx] >= 'a' && s[idx] <= 'z')
        {
            substr.push_back(s[idx]);
            idx++;
        }
        if(idx >= s.length())
        {return substr;}
        else{
            substr += function(s, idx);
        }
        return substr;
    }

    string decodeString(string s) {

        int i = 0;
        return function(s, i);

    }
};
