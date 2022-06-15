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

ll ans=0;

vector<bool> leftDiagonal(15);
vector<bool> rightDiagonal(15);
vector<bool> placedRows(7);
char arr[8][8];
void solved(int currentColumn)
{
    if(currentColumn==8)
    {
        ans++;
        return;
    }
    for(ll row=0;row<8;row++)
        {
            if(arr[row][currentColumn]=='.' && leftDiagonal[row-currentColumn+7]==false && rightDiagonal[row+currentColumn]==false && placedRows[row]==false)
            {

                leftDiagonal[row-currentColumn+7]=true;
                rightDiagonal[row+currentColumn]=true;
                placedRows[row]=true;

                solved(currentColumn+1);

                leftDiagonal[row-currentColumn+7]=false;
                rightDiagonal[row+currentColumn]=false;
                placedRows[row]=false;

            }
        }
}
char in[maxN],out[maxN];
int main()
{
    fast;
    //setIO();
    ans=0;
    for(ll i=0;i<8;i++)
    {
       for(ll j=0;j<8;j++)
        {
        cin>>arr[i][j];
        }
    }
    solved(0);
    cout<<ans<<endl;
    return ghost;
}
