#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ghost 0
#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1011
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

using namespace __gnu_pbds;

template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll md = 1000000007;
void setIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
map<string,string> mp;
ll pow1(ll n, ll p)
{
    if (p == 0)
        return 1;
    ll x = pow1(n, p / 2);
    x = (x * x) % md;
    if (p % 2 == 0)
        return x;
    else
        return (x * n) % md;
}

struct range
{
    ll l,r,index;
    bool operator < (const range &other) const
    {
     if(l==other.l) return r>other.r;
     return l<other.l;

    }


};
char in[maxN],out[maxN];
int main()
{
    fast;
    //setIO();
    ll n;
    cin>>n;
    vector<range> ranges(n);
    vector<bool> contained(n);
    vector<bool> contains(n);
    ordered_set<pair<ll,ll>> rightBoundaries;
    for(int i=0;i<n;i++){
        cin>>ranges[i].l;
        cin>>ranges[i].r;
        ranges[i].index=i;

    }
    sort(ranges.begin(),ranges.end());

    for(int i=0;i<n;i++){
     rightBoundaries.insert({ranges[i].r,-1*i});
    contained[ranges[i].index]=rightBoundaries.size()-rightBoundaries.order_of_key({ranges[i].r,-1*i})-1;

    }
    rightBoundaries.clear();

    for(int i=n-1;i>=0;i--){
      rightBoundaries.insert({ranges[i].r,-1*i});
      contains[ranges[i].index]=rightBoundaries.order_of_key({ranges[i].r,-1*i});
    }
    for(ll i=0;i<n;i++){cout<<contains[i]<<" ";}
    cout<<endl;
    for(ll i=0;i<n;i++){cout<<contained[i]<<" ";}
    cout<<endl;
    return ghost;
}


