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


ll dist[N][N];



int main()
{
    fast;
     ll t;
     //ll tno=1;;
     t=1;
    //cin>>t;
   while(t--){
   for(ll i=0;i<N;i++){
    for(ll j=0;j<N;j++){
        if(i==j) dist[i][j]=0;
        dist[i][j]=INF;
    }
   }
   ll n,m;
   cin>>n>>m;
   ll x,y,wt;
   for(ll i=0;i<m;i++){
    cin>>x>>y>>wt;
    dist[x][y]=wt;
   }
   for(ll k=1;k<=n;k++){
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
        if(dist[i][k]!=INF && dist[k][j]!=INF )
            dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
   }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(dist[i][j]==INF){
                cout<<"I"<<" ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
   }
    return 0;
}
///link:https://codeforces.com/problemset/problem/295/B
