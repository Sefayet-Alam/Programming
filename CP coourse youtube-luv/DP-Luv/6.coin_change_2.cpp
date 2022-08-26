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


int dp[300][10010];
//coins length<=300
//TOP DOWN approach


int func1(int ind,int amount,vector<int> &coins){
    if(amount==0) return 1;
    if(ind<0) return 0;
    if(dp[ind][amount]!=-1) return dp[ind][amount];
    int ans=0;
    for(int coin_amount=0;coin_amount<=amount;coin_amount+=coins[ind]){
        ans+=func1(ind-1,amount-coin_amount,coins);
    }

    return dp[ind][amount]=ans;

}
int coinChange(vector<int>& coins, int amount) {
     memset(dp,-1,sizeof(dp));
        int ans=func1(coins.size()-1,amount,coins);
        return ans;
}

int main()
{
    fast;
     ll t;


     t=1;
    //cin>>t;
   while(t--){

    vector<int> coins={1,2,5};
    cout<<coinChange(coins,5)<<endl;

    }



    return 0;
}
//ques link:https://leetcode.com/problems/coin-change/
/*class Solution {
public:

int dp[310][10010];
//coins length<=300
//TOP DOWN approach


int func1(int ind,int amount,vector<int> &coins){
    if(amount==0) return 1;
    if(ind < 0) return 0;
    if(dp[ind][amount]!=-1) return dp[ind][amount];
    int ans=0;
    for(int coin_amount=0;coin_amount<=amount;coin_amount+=coins[ind]){
        ans+=func1(ind-1,amount-coin_amount,coins);
    }

    return dp[ind][amount]=ans;

}
int change(int amount, vector<int>& coins) {
     memset(dp,-1,sizeof(dp));
        return func1(coins.size()-1,amount,coins);

}
};*/

