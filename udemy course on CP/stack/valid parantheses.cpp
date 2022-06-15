#include<bits/stdc++.h>
#include<stack>
#define ll long long
using namespace std;

int typeOf(char c){
    if(c=='(' || c==')') return 0;
    if(c=='{' || c=='}') return 1;
    else return 2;

}
bool ispalindrome(string r)
{
    ll f=r.size();
    for(int j=0;j<=f/2;j++)
    {
        if(r[j]!=r[f-j]) return false;
    }
    return true;
}

bool validParantheses(string s){
    stack <char> S;
    for(int i=0;i<s.size();i++){
    if(s[i]=='{' || s[i]=='[' || s[i]=='(')
        S.push(s[i]);
    else
        if(!S.empty() && typeOf(S.top())==typeOf(s[i]))
            S.pop();}
    return S.empty();

}


int main()
{
    ll t;
    cin>>t;
    while(t--)
    {

     string s;
    ll k;
    cin>>k;
     cin>>s;
    ll cnt=0;
    ll n=2;
    ll g=0;
    flag:
    string r=s.substr(0,n);

    //cout<<r<<endl;
    if(validParantheses(r) || ispalindrome(r))
     {
        cnt++;
        s.erase(0,r.length());
        n++;
        g+=r.size();
        goto flag;
     }
    else cout<<cnt<<" "<<k-g<<endl;

    }
    return 0;
}
