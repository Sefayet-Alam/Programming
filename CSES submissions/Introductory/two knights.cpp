#include <bits/stdc++.h>
#define ll long long
#define ghost 0
#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1011
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
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

    ll k;
    cin >> k;

    for (ll n = 1; n <= k; n++)
    {
        ll totalpositions=(n*n)*(n*n-1)/2;
        ll attackpositions =4*(n-1)*(n-2);

        cout <<totalpositions-attackpositions<< endl;
    }
    return ghost;
}
