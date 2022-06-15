#include <bits/stdc++.h>
#define ll long long
#define ghost 0
#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1011
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

map<string,string> mp;

char in[maxN],out[maxN];
int main()
{
    fast;
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=1;i<=n-1;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
     for(ll i=1;i<=n;i++)
    {
        if(v[i]!=i) {cout<<i<<endl; break;}
    }
    return ghost;
}
