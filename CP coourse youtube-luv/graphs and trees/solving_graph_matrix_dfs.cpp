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
const ll maxN=1e5+10;//for graph
#define M 10000


class Solution {
public:
void dfs(int i,int j,int initialColor,int newColor,vector<vector<int>>& image){
    int n=image.size();
    int m=image[0].size();
    if(i<0 || j<0) return;
    if(i>=n || j>=m) return;
    if(image[i][j]!=initialColor) return;
    image[i][j]=newColor;
    dfs(i-1,j,initialColor,newColor,image);
    dfs(i+1,j,initialColor,newColor,image);
    dfs(i,j-1,initialColor,newColor,image);
    dfs(i,j+1,initialColor,newColor,image);

}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor=image[sr][sc];

        if(initialColor!=color) dfs(sr,sc,initialColor,color,image);
        return image;
    }
};