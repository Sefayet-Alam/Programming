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


const int N=1e5+10;//for graph
const int INF=1e9+10;




//in graph first element is node and  second element is weight

//diijkstra
//similar to bfs

int dijkstra(int source,int n,vector< pair<int,int> > g[n]){
    vector<int> vis(N,0);
    vector<int> dist(N,INF);
    set<pair <int,int> > st;
    ///in set<ll,ll>= <weight,node>

    st.insert({0,source});
    dist[source]=0;
    while(st.size()>0){
        auto node=*st.begin();
        int v=node.second;
        int v_dist=node.first;
        st.erase(st.begin());
        if(vis[v]==1) continue;
        vis[v]=1;
        for(auto child :g[v]){
            int child_v=child.first;
            int wt=child.second;
            if(dist[v]+wt<dist[child_v]){
                dist[child_v]=dist[v]+wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(dist[i]==INF) return -1;
        ans=max(ans,dist[i]);
    }
    return ans;
}
 int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int> >g[N];
        for(auto vec:times){
            g[vec[0]].push_back({vec[1],vec[2]});
        }
        return dijkstra(k,n,g);
    }
///leetcode link:https://leetcode.com/problems/network-delay-time/
///TIME O(V+E*log(V)
