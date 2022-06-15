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
int a[6]={1,2,3,4,5};

int subset[6];

int n=5;
void gen_subset(int pos, int cnt){
  if(pos==n){
    // print values of subset[0...cnt]
    for(int i=0;i<cnt;i++) cout<<subset[i]<<" ";
    cout<<endl;
    return;
  }

  gen_subset(pos+1, cnt);
  subset[cnt] = a[pos];
  gen_subset(pos+1, cnt+1);
}
char in[maxN],out[maxN];
int main(){
    fast;
    //setIO();
      gen_subset(0,0);

    return ghost;
}
