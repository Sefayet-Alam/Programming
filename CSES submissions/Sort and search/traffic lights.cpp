#include <bits/stdc++.h>
#define ll long long
#define ghost 0
#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1011
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const ll md = 1000000007;
void setIO(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
map<ll,ll> mp;
ll x,n;
vector<ll>p(2e5);
char in[maxN],out[maxN];
int main()
{
    fast;
    //setIO();
    ll n;
    cin>>x>>n;
    set<ll>s;
    s.insert(0);
    s.insert(x);
    mp[x]=1;

    for(ll i=0;i<n;++i)
    {
        cin>>p[i];
        auto it=s.lower_bound(p[i]);
        ll r=*it;
        --it;
        ll l=*it;
        --mp[r-l];
        if(!mp[r-l]){mp.erase(r-l);}
        s.insert(p[i]);
        ++mp[r-p[i]];
        ++mp[p[i]-l];
        cout<<(--mp.end())->first<<endl;
    }



    return ghost;
}

