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

ll wt[105],val[105];

ll dp[105][100005];
/*In knapsack problem, we are given n items we have to choose some items and to choose those there should be a condition and we must choose optimally
*/
/*bounded(general bag and stealing items prooblem or 0-1 knpsk) and unbounded knapsack(rod cutting)*/
/*fractional knapsack-similar to 0-1 knapsack but we can pick 0.1 part of an item)...not a prob of dp...rather a prob of greedy*/
///BOUNDED KNAPSACK
ll func(ll ind,ll wt_left){
    if(wt_left==0) return 0;
    if(ind<0) return 0;
    if(dp[ind][wt_left]!=-1) return dp[ind][wt_left];
    ll ans=func(ind-1,wt_left);
   if(wt_left-wt[ind] >=0) ans=max(ans,func(ind-1,wt_left-wt[ind])+val[ind]);

    return dp[ind][wt_left]=ans;

}

int main()
{
    fast;
     ll t;


     t=1;
    //cin>>t;
   while(t--){
    memset(dp,-1,sizeof(dp));
    ll n,w;
    cin>>n>>w;
    for(ll i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    cout<<func(n-1,w)<<endl;
    }



    return 0;
}
//ques link:https://atcoder.jp/contests/dp/tasks/dp_d
//time complexity= O(n*w)
