#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> res;
        for(int i = left ; i <= right ; i ++)
            if(selfDividing(i))
                res.push_back(i);
        return res;
    }

private:
    bool selfDividing(int num){
        int t = num;
        while(t){
            int x = t % 10;
            t /= 10;
            if(x == 0 || num % x != 0)
                return false;
        }
        return true;
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {
    int m,n;
    cin>>m>>n;

    printVec(Solution().selfDividingNumbers(m,n));

    return 0;
}
