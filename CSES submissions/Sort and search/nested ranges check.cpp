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
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
map<string,string> mp;
ll pow1(ll n, ll p)
{
    if (p == 0)
        return 1;
    ll x = pow1(n, p / 2);
    x = (x * x) % md;
    if (p % 2 == 0)
        return x;
    else
        return (x * n) % md;
}

struct range
{
    ll l,r,index;
    bool operator < (const range &other) const
    {
     if(l==other.l) return r>other.r;
     return l<other.l;

    }


};
char in[maxN],out[maxN];
int main()
{
    fast;
    //setIO();
    ll n;
    cin>>n;
    vector<range> ranges(n);
    vector<bool> contained(n);
    vector<bool> contains(n);
    for(int i=0;i<n;i++){
        cin>>ranges[i].l;
        cin>>ranges[i].r;
        ranges[i].index=i;

    }
    sort(ranges.begin(),ranges.end());
    ll maxEnd=0;
    for(int i=0;i<n;i++){
       if(ranges[i].r<=maxEnd)
            contained[ranges[i].index]=true;
        maxEnd=max(maxEnd,ranges[i].r);
    }
    ll minEnd=1e17;
     for(int i=n-1;i>=0;i--){
       if(ranges[i].r>=minEnd)
            contains[ranges[i].index]=true;
        minEnd=min(minEnd,ranges[i].r);
    }
    for(ll i=0;i<n;i++){cout<<contains[i]<<" ";}
    cout<<endl;
    for(ll i=0;i<n;i++){cout<<contained[i]<<" ";}
    cout<<endl;
    return ghost;
}

