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
    ll n;
    cin>>n;
    cout<<n<<" ";
    while(n>1)
    {
        if(n==1) {cout<<1<<endl; break;}
        if(n%2==0) {n/=2;}
        else {n=n*3+1;}
        cout<<n<<" ";
    }

    return ghost;
}


