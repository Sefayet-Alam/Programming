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
    vector<ll> children(n);
    for(ll i=0;i<n;i++)
        {children[i]=i+1;}


    while(children.size()>1)
    {
        vector<ll> survivors;
        for(ll i=0;i<children.size();i++)
        {
            if(i%2==1) cout<<children[i]<<" ";
            else{survivors.push_back(children[i]);}
        }
        if(children.size()%2==0){children=survivors;}
        else{
            ll starter=survivors.back();
            survivors.pop_back();
            children.clear();
            children.push_back(starter);
            for(ll z: survivors)
            {
                children.push_back(z);
            }
        }
    }
    cout<<children[0];
    return ghost;
}

