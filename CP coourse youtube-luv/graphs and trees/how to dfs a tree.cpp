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
ll depth[maxN],height[maxN];

void dfs(ll vertex,ll par){
    //take action on vertex after entering the vertex


    for(ll child:g[vertex]){
        //cout<<"par:"<<vertex<<" "<<"child:"<<child<<endl;
        if(child==par) continue;
        depth[child]=depth[vertex]+1;
        //take action on the node before entering the child node

        dfs(child,vertex);
        //take action on the node after exiting the child node
        height[vertex]=max(height[vertex],height[child]+1);
    }
    //take action on the vertex after exiting the node
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
        //as each tree has n-1 edges so i=0 -> i<n-1
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1,0);


    for(ll i=1;i<=n;i++){
        cout<<depth[i]<<" "<<height[i]<<endl;;
    }
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


