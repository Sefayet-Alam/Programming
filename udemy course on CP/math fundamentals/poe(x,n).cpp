#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        long a = n;
        double ans = 1.0;
        if(a<0) a = -1*a;       //if power is negative make it positive, for simplicity
        while(a>0){
            if(a%2==0){     //checking if power is even
                x = x*x;    //if even, suppose 2^4, do (2*2)^2, diving problem in simpler steps.
                a = a/2;        //divide power by 2
            }
            else{           //if power is odd
                ans = ans*x;    //if odd, suppose 2^5, do (2^4)*2, to break it down into even power
                a = a-1;        //decrease n
            }
        }
        if(n<0)    ans = (double)(1.0)/(double)(ans);    //the reason for doing (-1*a), if n is negative power, simply move the answer in denominator
        return ans;
    }
};
int main()
{
    int m,g;
    cin>>m>>g;

    cout<<Solution().myPow(m,g);
}
