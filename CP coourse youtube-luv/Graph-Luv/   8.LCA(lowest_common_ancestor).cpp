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
const ll maxN=1e5+10;//for graph
#define M 10000


vector<ll>g[maxN];
bool vis[maxN];
ll par[maxN];

void dfs(ll v,ll p=-1){
    par[v]=p;
    for(ll child:g[v]){
        if(child==p) continue;
        dfs(child,v);
    }

}

vector<ll> path(ll v){
    vector<ll> ans;
    while(v!=-1){
        ans.push_back(v);
        v=par[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
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
    ll v1,v2;
    for(ll i=0;i<n-1;i++){
        //n-1 edges for n nodes in trees
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
    ll x,y;
    cin>>x>>y;
    vector<ll> path_x=path(x);
    vector<ll> path_y=path(y);

    ll mn_ln=min(path_x.size(),path_y.size());
    ll lca=-1;
    for(ll i=0;i<n;i++){
        if(path_x[i]==path_y[i]){
            lca=path_x[i];
        }
        else{
            break;
        }
    }
    cout<<lca<<endl;
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

7 2
*/
//ans=2
