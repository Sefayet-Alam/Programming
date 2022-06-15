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
map<char,ll> mp;


int main()
{
    fast;
    //setIO();
    string s;
    cin>>s;
    for(auto it:s)
    {
        mp[it]++;
    }
    char x='-'; int c=0;
	for (auto it: mp){
		if (it.second%2==1) {c++;x = it.first;}
	}

    if(c>1) {cout<<"NO SOLUTION"<<endl; return ghost;}


        string ans;
        for (auto it: mp){
		if (it.first==x) {continue;}
		for(ll j=0;j<(it.second)/2;j++) {ans+=it.first;}
        }
	if (x!='-') {for(ll i=0;i<mp[x];i++) {ans+=x;}}
	for (auto it=mp.rbegin();it!=mp.rend();it++){
		if ((*it).first==x) continue;
		for(ll j=0;j<(*it).second/2;j++) ans+=(*it).first;
	}

    cout<<ans<<endl;

    return ghost;
}
