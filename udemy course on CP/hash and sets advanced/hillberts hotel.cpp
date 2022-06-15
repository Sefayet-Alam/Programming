#include<bits/stdc++.h>
#include<fstream>>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long

using namespace std;

const int Nmax=1000005;
const int INF=1000000000;
const int MOD=9998852536;

int a[Nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll f,t;
    cin>>t;

    for(f=0;f<t;f++)
    {
        int n;
        cin>>n;
        vector<bool> rest(n+1,false);
        for(int i=0;i<n;i++)
            {cin>>a[i];}
        int i;
        for(i=0;i<n;i++)
        {
            int x=a[i];
            if(x<0) {
                x=(1LL*INF*n+x)%n;
            }
            if(rest[(i+x)%n]==true)
                {
                cout<<"NO"<<endl;
                break;
                }
           rest[(i+x)%n]=true;
        }
           if(i==n) cout<<"YES"<<endl;
    }


}
