#include <bits/stdc++.h>
#define ll long long
#define ghost 0
#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1011
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
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
    ll n;
    cin>>n;
    vector<ll> v(n+1);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }

    ll total=0,m=v[0];
    for(ll i=0;i<n;i++)
    {
        total+=max(0LL,m-v[i]);
        m=max(m,v[i]);
    }
    cout<<total<<endl;
    return ghost;
}

