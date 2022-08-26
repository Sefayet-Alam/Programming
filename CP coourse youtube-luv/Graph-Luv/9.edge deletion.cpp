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

const int N=1e5+10;
const int M=1e9+7;

vector<ll> g[N];
ll subtree_sum[N];

void dfs(ll v,ll par){

    for(ll child : g[v]){
        if(child==par) continue;

        dfs(child,v);
        subtree_sum[v]+=subtree_sum[child];
    }
}
int main()
{
    fast;
     ll t;
     //ll tno=1;;
    t=1;
    //cin>>t;
    while(t--){
     ll n;
     cin>>n;
     ll x,y;
    for(ll i=0;i<n-1;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
   ll ans=0;
   dfs(1,0);
   for(ll i=2;i<=n;i++){
    ll part1=subtree_sum[i];
    ll part2=subtree_sum[1]-part1;
    ans=max(ans,(part1*part2)%M);
   }
    cout<<ans<<endl;

   }


    return 0;
}
/*
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11

*/

//https://www.interviewbit.com/problems/delete-edge/
