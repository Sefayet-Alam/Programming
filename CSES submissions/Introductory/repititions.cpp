#include <bits/stdc++.h>
#define ll long long
#define ghost 0
#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1011
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

map<string,string> mp;

char in[maxN],out[maxN];
int main()
{
    fast;
    string s;
    cin>>s;

    ll cnt=1,mx=1;
    ll n=s.size();

    for(ll i=0;i<n-1;i++)
    {

        if(s[i]==s[i+1]) {cnt++;}
        else{cnt=1;}
        mx=max(mx,cnt);

    }
    cout<<mx<<endl;
    return ghost;
}
