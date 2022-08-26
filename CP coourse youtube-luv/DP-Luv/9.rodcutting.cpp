#include<bits/stdc++.h>

using namespace std;


#define ll                  long long
#define scl(n)              scanf("%lld", &n)
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)
#define pfl(x)              printf("%lld\n",x)
#define endl 	            "\n"
#define pb                  push_back
#define asort(a)            sort(a,a+n)
#define dsort(a)            sort(a,a+n,greater<int>())
#define vasort(v)         sort(v.begin(), v.end());
#define vdsort(v)         sort(v.begin(), v.end(),greater<ll>());
#define pn                  printf("\n")
#define md                  10000007
#define debug               printf("I am here\n")

#define l(s)                      s.size()
#define tcas(i,t)             for(ll i=1;i<=t;i++)
#define pcas(i)                printf("Case %lld: ",i)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define M 10000
const ll maxN=1e5+10;
///unbounded knapsack
class Solution{
  public:
      int dp[1005];
int func(int len,vector<int> &prices){
    if(len==0) return 0;
    if(dp[len]!=-1) return dp[len];
    int ans=0;
    for(int len_to_cut=1;len_to_cut<=prices.size();len_to_cut++){
        if(len-len_to_cut>=0){
            ans=max(ans,func(len-len_to_cut,prices)+prices[len_to_cut-1]);
        }

    }
    return dp[len]=ans;

}
int cutRod(int price[], int n) {
    memset(dp,-1,sizeof(dp));
      vector<int> prices(price,price+n);
        return func(n,prices);
    }

};
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
//ques link:https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
/*
input
N=8
Price[] = {3, 5, 8, 9, 10, 17, 17, 20}*/
//Time complexity:O(N^2)
