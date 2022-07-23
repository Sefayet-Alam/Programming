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
const ll INF=1e9+10;//for graph
#define M 10000


vector<ll>g[maxN];
bool vis[8][8];
ll level[8][8];

//bfs=breadth first search
//according to level traversal

ll getX(string s){
    return s[0]-'a';

}
ll getY(string s){
    return s[1]-'1';
}

bool isValid(ll x,ll y){
    return x>=0 && y>=0 && x<8 && y<8;
}
vector<pair<ll,ll> >movements={
{-1,2},{1,2},
{-1,-2},{1,-2},
{2,-1},{2,1},
{-2,-1},{-2,1}
};
ll bfs(string source,string dest){
    ll sourcex=getX(source);
    ll sourcey=getY(source);
    ll destx=getX(dest);
    ll desty=getY(dest);

    queue<pair<ll,ll> >q;
    q.push({sourcex,sourcey});
    vis[sourcex][sourcey]=1;
    level[sourcex][sourcey]=0;
    while(!q.empty()){
        pair<ll,ll> v =q.front();
        ll x=v.first;
        ll y=v.second;
        q.pop();
       for(auto movement:movements){
        ll childX=movement.first+x;
        ll childY=movement.second+y;
        if(!isValid(childX,childY)) continue;
        if(!vis[childX][childY]){
            q.push({childX,childY});
            level[childX][childY]=level[x][y]+1;
            vis[childX][childY]=1;
        }
       }
       if(level[destx][desty]!=INF) break;
    }
    return level[destx][desty];
}

void reset(){
    for(ll i=0;i<8;i++){
        for(ll j=0;j<8;j++){
            vis[i][j]=0;
            level[i][j]=INF;
        }
    }

}
int main()
{
    fast;
     ll t;
     //ll tno=1;;
     //t=1;
    cin>>t;
   while(t--){
        reset();
    //ll n;
    //cin>>n;
   // ll v1,v2;
 // while(n--)
    string s1,s2;
    cin>>s1>>s2;
    cout<< bfs(s1,s2) <<endl;
  }



    return 0;
}
/*
3
a1 h8
a1 c2
h8 c3

*/
//spoj problem:https://www.spoj.com/problems/NAKANJ/
