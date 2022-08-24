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
ll dp[maxN];
ll h[maxN];
ll k;
ll func(ll i){
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];

    ll cost=INT_MAX;
    for(ll j=1;j<=k;j++){
    if(i-j>=0) cost=min(cost,func(i-j)+abs(h[i]-h[i-j]));
    }

    return dp[i]=cost;
}


int main()
{
    fast;
     ll t;


     t=1;
    //cin>>t;
   while(t--){
    memset(dp,-1,sizeof(dp));
    ll n;
    cin>>n>>k;
    fr(i,n) cin>>h[i];
    cout<<func(n-1)<<endl;
    }



    return 0;
}

//ques link:https:atcoder.jp/contests/dp/tasks/dp_a
//time complexity for bruteforce recursion=O(n^k)
//time complexity for dp=O(n*k)

