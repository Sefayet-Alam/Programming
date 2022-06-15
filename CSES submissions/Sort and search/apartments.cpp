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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n),b(m );
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
     for(ll i=0;i<m;i++)
    {
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans=0,r=0,f=0;
    while(r<n && f<m)
    {
        if(abs(a[r]-b[f])<=k)
        {
            ans++;
            r++;
            f++;
        }
        else if(a[r]<b[f])
        {
            r++;
        }
        else{
            f++;
        }
    }
    cout<<ans<<endl;


    return ghost;
}

