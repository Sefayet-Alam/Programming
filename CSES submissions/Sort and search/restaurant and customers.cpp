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
    ll n;
    cin>>n;
    vector<pair<ll,ll>>events(n);
    for(ll i=1;i<=n;i++)
    {
        int start,end;
        cin>>start>>end;
        events.push_back({start,1});
        events.push_back({end,-1});
    }

    sort(events.begin(),events.end());
    ll actualcustomers=0,maxcustomers=0;
    for(ll i=0;i<events.size();i++)
    {
        actualcustomers+=events[i].second;
        maxcustomers=max(maxcustomers,actualcustomers);
    }
   cout<<maxcustomers<<endl;
    return ghost;
}

