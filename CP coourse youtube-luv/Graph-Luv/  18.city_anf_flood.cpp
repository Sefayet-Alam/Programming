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
const ll N=510;//for graph
const ll INF=1e9+10;
#define M 10000

///DSU
ll dist[N][N];
ll size[N];
int parent[N];
void make(int v){
    parent[v]=v;
    size[v]=1;

}

int find(int v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(size[a]<size[b]) swap(a,b);///connecting the smaller tree to the bigger one
        parent[b]=a;
    size[a]+=size[b];
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
    ll n;//nodes
    ll k;//edges
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        make(i);
    }

    while(k--){
        ll u,v;
        cin>>u>>v;
        Union(u,v);

    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i){cnt++;}
    }

    cout<<cnt<<endl;
   }
    return 0;
}
//time comp:O(alpha(n))
//reverse ackerman function  alpha(n)

