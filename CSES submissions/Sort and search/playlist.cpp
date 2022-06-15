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
    ll x,ans=0,currans=0;
    map<ll,ll>mp;
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        v[i]=x;

    }

    ll i=0,j=0,maxlen=0,curlen=0;
    while (j < n)
	{
		if (mp.find(v[j])==mp.end() || mp[v[j]]==0)
		{
			mp[v[j]]++;
			curlen++;
			maxlen = max(maxlen, curlen);
			j++;
		}
		else
		{
			curlen--;
			mp[v[i]]--;
			i++;
		}
	}
    cout<<maxlen<<endl;
    return ghost;
}
