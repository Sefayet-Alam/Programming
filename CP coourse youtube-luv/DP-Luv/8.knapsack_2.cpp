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


ll dp[105][100005];

ll wt[105],val[105];
//func(-1,amount)
//func(ind,0)
ll func(ll ind,ll value_left){
    if(value_left==0) return 0;
    if(ind<0) return 1e15;

    if(dp[ind][value_left]!=-1) return dp[ind][value_left];
    //Dont choose item at ind
    ll ans=func(ind-1,value_left);
    //Choose
    if(value_left-val[ind]>=0) ans=min(ans,func(ind-1,value_left-val[ind])+wt[ind]);
    return dp[ind][value_left]=ans;

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
    ll max_val=1e5;
    for(ll i=max_val;i>=0;i--){
        if(func(n-1,i)<=w){
            cout<<i<<endl;
            break;
        }
    }
    }



    return 0;
}
