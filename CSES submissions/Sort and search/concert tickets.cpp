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


    ll n,m,x;
    cin>>n>>m;
    vector<ll>v(n),u(m);
    multiset<ll,greater<ll>>s;
    for(ll i=0;i<n;i++)
    {
       cin>>v[i];
    }
    for(ll i=0;i<m;i++)
    {
        cin>>u[i];
    }
    for(ll i=0;i<n;i++)
    {
      s.insert(v[i]);
    }
    for(ll i=0;i<m;i++)
    {
        auto it=s.lower_bound(u[i]);
		if(it==s.end())cout<<-1<<endl;
		else
		{
			cout<<*it<<endl;
			s.erase(it);
		}
    }

    return ghost;
}

