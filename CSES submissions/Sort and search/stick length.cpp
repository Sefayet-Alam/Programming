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
    ll n,tot=0;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];

    }
    sort(v.begin(),v.end());

    ll x=v[n/2],sum=0;
    for(ll i=0;i<n;i++)
    {
       sum+=abs(v[i]-x);
    }
    if(n%2==0)
    {
        ll sum2=0;
        x=v[(n-1)/2];
         for(ll i=0;i<n;i++)
        {
        sum2+=abs(v[i]-x);
        }
        sum=min(sum,sum2);
    }
    cout<<sum<<endl;
    return ghost;
}
