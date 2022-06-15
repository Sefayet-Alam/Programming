#include <bits/stdc++.h>
#define ll long long
#define ghost 0
#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1011
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
set<string> perms;
const ll md = 1000000007;
void setIO(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
map<string,string> mp;
void permutations(string prefix, string suffix)
{
    if (suffix.length() == 0)
    {
        perms.insert(prefix);
        return;
    }
    for (int i = 0; i < suffix.length(); i++)
    {
        permutations(prefix + suffix[i], suffix.substr(0, i) + suffix.substr(i + 1));
    }
}
char in[maxN],out[maxN];
int main()
{
    fast;
    //setIO();
   string s;
    cin >> s;
    permutations("", s);
    cout << perms.size() << endl;
    for (auto ele : perms)
    {
        cout << ele << endl;
    }
    return ghost;
}

