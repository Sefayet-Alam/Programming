#include <bits/stdc++.h>

#include <string>
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

int numDigits(int result)
{
    int ans=0;
    while(result>0)
    {
        ans++;
        result/=10;
    }
    return ans;
}
char in[maxN],out[maxN];
int main()
{
    fast;
    //setIO();
    string s="12345678910111213141516171819202122232425";
    vector<ll>powers(19,1);
    for(int i=1;i<19;i++)
    {
        powers[i]=powers[i-1]*10;
    }

    ll  t;
    cin>>t;
    while(t--)
    {
       ll k;
       cin>>k;
       ll numDig=0,digitslen=0,prevDig=0;

       for(int i=1;i<19;i++)
       {
           digitslen+=(powers[i]-powers[i-1])*i;
           if(digitslen>=k)
           {
               numDig=i;
               break;
           }
           prevDig=digitslen;
       }
       ll low=powers[numDig-1];
       ll high=powers[numDig]-1;
       ll ans=0;
       ll startPosans=0;
       while(low<=high)
       {
           ll mid=(low+high)/2;
           ll startpos =(mid-powers[numDig-1])*numDig+prevDig+1;
           if(startpos<=k)
                {
           if(mid>ans)
           {
               ans=mid;
               startPosans=startpos;

           }
           low=mid+1;
        }
            else{high=mid-1;}



        }
      string num=to_string(ans);
        cout<<num[k-startPosans]<<endl;


     }
     return ghost;

}
