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
const ll INF=1e9+10;
#define M 10000


vector<pair<ll,ll> >g[maxN];
vector<ll> lev(maxN,INF);
//when edges dont have same weight...0 and 1 weights..use 0-1 bfs
 ll n,m;

ll bfs(){

    deque<ll> q;
    q.push_back(1);

    lev[1]=0;
    while(!q.empty()){
        ll curr_v=q.front();
        q.pop_front();
        for(auto &child : g[curr_v]){
            ll child_v=child.first;
            ll weight=child.second;
            if(lev[curr_v]+weight<lev[child_v]){
                lev[child_v]=lev[curr_v]+weight;
                if(weight==1){
                    q.push_back(child_v);
                }
                else{
                    q.push_front(child_v);
                }
            }
        }
    }
    return lev[n]==INF? -1:lev[n];


}

int main()
{
    fast;
     ll t;
     //ll tno=1;;
     t=1;
    //cin>>t;
   while(t--){

    cin>>n>>m;
    ll v1,v2;
    for(ll i=0;i<m;i++){
        cin>>v1>>v2;
        if(v1==v2) continue; //for loops
        g[v1].push_back({v2,0});
        //normal weight=0
        g[v2].push_back({v1,1});
        //reverse-> weight =1

    }
   cout<< bfs()<<endl;


   }


    return 0;
}
//codechef prob link:https://www.codechef.com/problems/REVERSE
/*
7 7
1 2
3 2
3 4
7 4
6 2
5 6
7 5
*/
