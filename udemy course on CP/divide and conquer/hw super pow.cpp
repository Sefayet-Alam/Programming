/*372. Super Pow
Medium

438

1036

Add to List

Share
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.



Example 1:

Input: a = 2, b = [3]
Output: 8
Example 2:

Input: a = 2, b = [1,0]
Output: 1024
Example 3:

Input: a = 1, b = [4,3,3,8,5,2]
Output: 1*/

class Solution {
public:
    int power(int a,int b,int M){
        a %= M;
        int ans = 1;
        if(a == 0) return 0;
        while (b)
        {
            if (b & 1) ans = (ans * a) % M;
            a = (a * a) % M, b >>= 1;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
         int res = 0;
		 for (int i = 0; i < b.size(); i++) res = (res * 10 + b[i]) % 1140;
		 return power(a,res,1337);
    }
};
