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
    ll n,q;
    cin>>n>>q;
    vector<ll> values(n+1);
    vector<ll> positionof(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin>>values[i];
        positionof[values[i]]=i;
    }
    ll ans=1;
    for(ll i=1;i<n;i++)
    {
        ans+=(positionof[i]>positionof[i+1]);

    }
    ll l,r;
    set<pair<ll,ll>>updatedpairs;
    while(q--)
    {
        cin>>l>>r;
        if(values[l]+1<=n){
            updatedpairs.insert({values[l],values[l]+1});
        }
         if(values[l]-1>=1){
            updatedpairs.insert({values[l]-1,values[l]});
        }
        if(values[r]+1<=n){
            updatedpairs.insert({values[r],values[r]+1});
        }
        if(values[r]-1>=1){
            updatedpairs.insert({values[r]-1,values[r]});
        }
        for(pair<ll,ll> swapped:updatedpairs)
        {
            ans-=positionof[swapped.first]>positionof[swapped.second];
        }
        swap(values[l],values[r]);
        positionof[values[l]]=l;
         positionof[values[r]]=r;

        for(pair<ll,ll> swapped:updatedpairs)
        {
            ans+=positionof[swapped.first]>positionof[swapped.second];
        }
        cout<<ans<<endl;
        updatedpairs.clear();
    }
    return ghost;
}


