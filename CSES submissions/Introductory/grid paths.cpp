#include <bits/stdc++.h>
#define ll long long
#define ghost 0
#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1011
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define isValid(a,b,c) (a>=b && a<c ? 1:0)
const ll md = 1000000007;
void setIO(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

#define RIGHT 0
#define LEFT 1
#define DOWN 2
#define UP 3

string str;
int vis[7][7];

int countPaths(int x,int y,int pos)
{
    if(pos==(int)str.length()){return (x==6 && y==0);}
    if(x==6 && y==0) {return 0;}
    if(vis[x][y]){return 0;}
    vector<bool>visited(4,-1);
    for(int k=0;k<4;k++)
    {
        if(isValid(x+dx[k],0,7) && isValid(y+dy[k],0,7)){visited[k]=vis[x+dx[k]][y+dy[k]];}


    }
    if(!visited[DOWN] && !visited[UP] && visited[RIGHT] && visited[LEFT]) {return 0;}
    if(visited[DOWN] && visited[UP] && !visited[RIGHT] && !visited[LEFT]) {return 0;}
    if(isValid(x-1,0,7) && isValid(y+1,0,7) && vis[x-1][y+1]==1){
            if(!visited[RIGHT] && !visited[UP]){return 0;}

        }
    if(isValid(x+1,0,7) && isValid(y+1,0,7) && vis[x+1][y+1]==1){
            if(!visited[RIGHT] && !visited[DOWN]){return 0;}

        }
    if(isValid(x-1,0,7) && isValid(y-1,0,7) && vis[x-1][y-1]==1){
            if(!visited[LEFT] && !visited[UP]){return 0;}

        }
    if(isValid(x+1,0,7) && isValid(y-1,0,7) && vis[x+1][y-1]==1){
            if(!visited[LEFT] && !visited[DOWN]){return 0;}

        }
    vis[x][y]=1;
    int numofPaths=0;
    if(str[pos]=='?')
    {
        for(int k=0;k<4;k++)
        {
            if(isValid(x+dx[k],0,7) && isValid(y+dy[k],0,7))
                numofPaths+=countPaths(x+dx[k],y+dy[k],pos+1);
        }
    }
    else if(str[pos]=='R' && y+1<7)
            {
                numofPaths+=countPaths(x,y+1,pos+1);
            }
    else if(str[pos]=='L' && y-1>=0)
            {
                numofPaths+=countPaths(x,y-1,pos+1);
            }
    else if(str[pos]=='U' && x-1>=0)
            {
                numofPaths+=countPaths(x-1,y,pos+1);
            }
    else if(str[pos]=='D' && x+1<7)
            {
                numofPaths+=countPaths(x+1,y,pos+1);
            }
    vis[x][y]=0;
    return numofPaths;

}
int main()
{
    fast;
    //setIO();
    cin>>str;
    cout<<countPaths(0,0,0)<<endl;

    return ghost;
}
