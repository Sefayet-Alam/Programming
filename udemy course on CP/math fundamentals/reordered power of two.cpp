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
