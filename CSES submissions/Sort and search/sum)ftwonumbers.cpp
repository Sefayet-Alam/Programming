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
    ll n,sum;
    cin>>n>>sum;
    vector<pair<ll,ll>>v;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        v.push_back({x,i+1});
    }
    sort(v.begin(),v.end());
    ll i=0,j=n-1;

    while(i<j)
    {
        if(v[i].first+v[j].first>sum){j--;}
        else if(v[i].first+v[j].first<sum){i++;}
        else{
            cout<<v[i].second<<" "<<v[j].second<<endl;
            return 0;
        }

    }
    cout<<"IMPOSSIBLE"<<endl;

    return ghost;
}

