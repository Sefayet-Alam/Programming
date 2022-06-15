#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

vector<int> lis[20009];
int vis[20009];
bool node_type[20009];
long long int lykan=0,vampire=0;
int tempHigh=0;


void clr()
{
  for(int i=0;i<20009;i++)
{
    vis[i]=false;
    node_type[i]=0;
    lis[i].clear();
}
}



void DFS (int source, int current, int team) {
    if(vis[source]==1) {
        vis[current]=2;
        vampire++;
    }
    else {
        vis[current]=1;
        lykan++;
    }

    int temp= lis[current].size();
    for(int i=0; i<temp; i++) {
        if(vis[lis[current][i]]==0) {
            DFS(current, lis[current][i], vis[current]);
        }
    }
}
int main()
{
   int f,T,u,v,n,sum=0;
   cin>>T;
   for(f=1;f<=T;f++)
   {
       clr();
      //int u,v,n,sum=0;
      cin>>n;
      while(n--)
      {
          cin>>u>>v;
          lis[u].push_back(v);
          lis[v].push_back(u);
      }
      int result=0;
       for(int i=0;i<20001;i++)
       {

          if(vis[i]==0 && lis[i].size()>0)
           {
               lykan=1,vampire=0;
                vis[i]=1;
                int temp= lis[i].size();
                for(int j=0; j<temp; j++) {
                    if(vis[lis[i][j]]==0) DFS(i ,lis[i][j] , 1);
                }

                if(lykan>vampire) result+=lykan;
                else result+=vampire;

                lykan=0;
                vampire=0;
           }


       }

       cout<<"Case "<<f<<":"<<result<<endl;

    }
return 0;
}
