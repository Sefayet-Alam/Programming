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

/// 0 1 1 2 3 5 8
int dp[10010];
//TOP DOWN approach

int func(int amount,vector<int> &coins){
    if(amount==0) return 0;
    if(dp[amount]!=-1) return dp[amount];
    int ans=INT_MAX;
    for(int coin:coins){
    if(amount-coin>=0)ans=min(ans+0LL,func(amount-coin,coins)+1LL);
    }
    return dp[amount]=ans;

}
int coinChange(vector<int>& coins, int amount) {
     memset(dp,-1,sizeof(dp));
        int ans=func(amount,coins);
        return ans==INT_MAX? -1:ans;
}

int main()
{
    fast;
     ll t;


     //t=1;
    cin>>t;
   while(t--){

    vector<int> coins={1,2,5};
    cout<<coinChange(coins,11)<<endl;

    }



    return 0;
}
//ques link:https://leetcode.com/problems/coin-change/
