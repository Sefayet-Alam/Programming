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

map<string,string> mp;

char in[maxN],out[maxN];
int main()
{
    fast;

    ll n,tot=0;
    cin>>n;
    vector<ll>v(n+1);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
        tot+=v[i];
    }
    ll ans=1e18;
    for(ll i = 0;i< 1<<n;i++) {
		ll s = 0;
		for(ll j = 0; j < n; j++) {
			if(i & 1<<j) s += v[j];
		}
		ll curr = abs((tot-s)-s);
		ans = min(ans, curr);
	}
	cout<<ans<<endl;


    return ghost;
}
