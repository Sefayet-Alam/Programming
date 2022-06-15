#include <bits/stdc++.h>
#define ll long long
#define ghost 0
#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1011
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;

const ll md = 1000000007;
void setIO(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
map<string,string> mp;

char in[maxN],out[maxN];
int main()
{
    fast;
    //setIO();
   ll n,k;
   cin>>n>>k;
   ordered_set<ll>children;
   for(ll i=1;i<=n;i++)
   {
       children.insert(i);
   }
   ll startposition=0;
   while(children.size()>0)
   {
       startposition%=children.size();
       ll positiontoremove=(startposition+k)%children.size();
       startposition=positiontoremove;
       auto t=children.find_by_order(positiontoremove);
       cout<<*t<<" ";
       children.erase(t);
   }
    return ghost;
}

