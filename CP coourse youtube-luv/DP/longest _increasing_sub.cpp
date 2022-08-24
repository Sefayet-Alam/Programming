#include<bits/stdc++.h>

using namespace std;


#define ll                  long long
#define scl(n)              scanf("%lld", &n)
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)
#define pfl(x)              printf("%lld\n",x)
#define endl 	            "\n"
#define pb                  push_back
#define asort(a)            sort(a,a+n)
#define dsort(a)            sort(a,a+n,greater<int>())
#define vasort(v)         sort(v.begin(), v.end());
#define vdsort(v)         sort(v.begin(), v.end(),greater<ll>());
#define pn                  printf("\n")
#define md                  10000007
#define debug               printf("I am here\n")

#define l(s)                      s.size()
#define tcas(i,t)             for(ll i=1;i<=t;i++)
#define pcas(i)                printf("Case %lld: ",i)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define M 10000
const ll maxN=1e5+10;

vector<ll>v(maxN);
/// 0 1 1 2 3 5 8
ll dp[maxN];
//TOP DOWN approach
ll lis(ll i){
    if(dp[i]!=-1) return dp[i];
    ll ans=1;
  for(ll j=0;j<i;j++){
    if(v[i]>v[j]){
        ans=max(ans,lis(j)+1);
    }
  }
  return dp[i]=ans;
}
//O(N^2)
int main()
{
    fast;
     ll t;


     //t=1;
    cin>>t;
   while(t--){
    memset(dp,-1,sizeof(dp));
    ll n;
    cin>>n;

    fr(i,n) cin>>v[i];
    ll ans=0;
    for(ll i=0;i<n;i++){
        ans=max(ans,lis(i));
    }
    cout<<ans<<endl;
    }



    return 0;
}
//ques link:https://leetcode.com/problems/longest-increasing-subsequence/
/*Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.*/
