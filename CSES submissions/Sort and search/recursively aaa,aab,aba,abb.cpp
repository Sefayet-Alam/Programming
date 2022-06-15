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
string str="abcdef";
string toprint="";
void printstr(ll k,ll n,ll j){

    if(j==k){
    for(ll i=0;i<k;i++){
    cout<<toprint[i];
    }
    cout<<"\n";
    return;
    }
    for(ll i=0;i<n;i++){
    toprint[j]=str[i];
    printstr(k,n,j+1);
    }
}

ll power(ll x,ll y) {
  ll ans = 1;
  while(y) {
    if(y%2==1){
    ans=ans*x;
    y--;}
    else{
        x=x*x;
        y=y/2;
    }
  }
  return ans;
}

int main()
{
    fast;
    //setIO();
    ll k,n;
    cin>>k>>n;//3 2
    cout<<power(n,k)<<"\n";

    printstr(k,n,0);

    return ghost;

}

/*output
aaa
aab
aba
abb
baa
bab
bba
bbb
*/
