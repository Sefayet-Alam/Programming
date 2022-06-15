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
    long long int n,x;
    cin>>n>>x;
    int j=0,k=n-1;
    int f;
    deque <long long int> m;
    for(int i=0;i<n;i++)
    {
        cin>>f;
        m.push_back(f);
    }
    sort(m.begin(),m.end());
    int c=0;

   while(j<=k)
    {


            if(m[j]+m[k]<=x) {c++; j++;k--;}
            else {c++;k--;}



    }


    if(n!=1) cout<<c<<endl;
    else cout<<1<<endl;

    return ghost;
}


