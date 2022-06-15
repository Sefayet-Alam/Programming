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
    vector<ll>cubes(n);
    for(ll i=0;i<n;i++)
    {
        cin>>cubes[i];
    }
    multiset<ll>towers;
    for(ll i=0;i<n;i++)
    {
        if(towers.size()==0){towers.insert(cubes[i]);}
        else{
            auto base=towers.upper_bound(cubes[i]);
            if(base==towers.end()){towers.insert(cubes[i]);}
            else{towers.insert(cubes[i]);
            towers.erase(base);}
        }
    }
    cout<<towers.size()<<endl;
    return ghost;
}

