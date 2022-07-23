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
const ll maxN=1e3+10;//for graph
const ll INF=1e9+10;
#define M 10000



//when edges dont have same weight...0 and 1 weights..use 0-1 bfs
 ll n,m;

 ll val[maxN][maxN];
 ll vis[maxN][maxN];
 ll lev[maxN][maxN];


 void reset(){

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            vis[i][j]=0;
            lev[i][j]=INF;
        }
    }

 }
 bool isvalid(ll i,ll j){
    return i>=0 &&  j>=0 && i< n && j<m;

 }
  vector<pair<ll,ll> >movements={
 {0,1},{0,-1},{1,0},{-1,0},
 {1,1},{1,-1},{-1,1},{-1,-1}

 };
 ll bfs(){
     ll mx=0;
     for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
          mx=max(mx,val[i][j]);
        }
    }
    queue< pair<ll,ll> >q;

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
        if(mx==val[i][j]){
            q.push({i,j});
            lev[i][j]=0;
            vis[i][j]=1;
        }
        }
    }
    ll ans=0;
    while(!q.empty()){
        auto v=q.front();
        ll v_x=v.first;
        ll v_y=v.second;
        q.pop();
        for(auto movement : movements){
            ll child_x=movement.first+v_x;
            ll child_y=movement.second+v_y;
            if(!isvalid(child_x,child_y)) continue;
            if(vis[child_x][child_y]) continue;

            q.push({child_x,child_y});
            lev[child_x][child_y]=lev[v_x][v_y]+1;
            vis[child_x][child_y]=1;
            ans=max(ans,lev[child_x][child_y]);
        }

    }
    return ans;
 }
int main()
{
    fast;
     ll t;
     //ll tno=1;;
     //t=1;
    cin>>t;
   while(t--){

    cin>>n>>m;
    reset();
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>val[i][j];
        }
    }
   cout<< bfs()<<endl;


   }


    return 0;
}
// codechef link:https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/
/*Input
3
2 2
1 1
1 1
2 2
1 1
1 2
3 4
1 2 1 2
1 1 1 2
1 1 2 2*/
