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
  ll n;
  cin>>n;
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
        cin>>dist[i][j];
    }
  }
  vector<ll>del_oder(n);
    for(ll i=0;i<n;i++){
   cin>>del_oder[i];
  }
  reverse(del_oder.begin(),del_oder.end());
  vector<ll>ans;
  for(ll k=0;k<n;k++){
    ll k_v=del_oder[k];
     for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
       dist[i][j]=min(dist[i][j],dist[i][k_v]+dist[k_v][j]);
        }
    }
    ll sum=0;
    for(ll i=0;i<=k;i++){
         for(ll j=0;j<=k;j++){
           sum+=dist[del_oder[i]][del_oder[j]];
        }

    }
    ans.push_back(sum);



  }
    reverse(ans.begin(),ans.end());
   for(auto it:ans){
        cout<<it<<" ";
    }
  cout<<endl;
   }
    return 0;
}
/*
4
0 3 1 1
6 0 400 1
2 4 0 1
1 1 1 0
4 1 2 3
*/
//link:https://codeforces.com/problemset/problem/295/B
