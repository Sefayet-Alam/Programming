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
void solve(int a, int b, int c, int n) {
	if (n == 0)
		return;
	solve(a, c, b, n-1);
	cout<<a<<' '<<c<<endl;
	solve(b, a, c, n-1);
}
char in[maxN],out[maxN];
int main()
{
    fast;
    //setIO();
    int n; cin>>n;
    cout<< (1<<n) - 1<<endl;
    solve(1, 2, 3, n);
    return ghost;
}
