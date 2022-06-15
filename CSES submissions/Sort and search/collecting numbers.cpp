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
map<string,string> mp;

char in[maxN],out[maxN];
int main()
{
    fast;
    //setIO();
    ll n,l=1;
    cin>>n;
    vector<ll> v(n);
    ll ind[n+1];
    for(ll i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        ind[x]=i;
    }
    ll c=1;
    for(ll i=1;i<=n;i++)
    {
        if(l>ind[i]) {c++;}
        l=ind[i];
    }

    cout<<c<<endl;
    return ghost;
}
