#include <bits/stdc++.h>
#define ll long long
#define ghost 0
#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1011
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void setIO(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
map<string,string> mp;

char in[maxN],out[maxN];
bool nextPermutation(std::string &s, int n)
{
    // Find the largest index `i` such that `s[i-1]` is less than `s[i]`
    int i = n-1;
    while (s[i-1] >= s[i])
    {
        // if `i` is the first index of the string, we are already at the last
        // possible permutation (string is sorted in reverse order)
        if (--i == 0) {
            return false;
        }
    }

    // If we reach here, substring `s[i…n-1]` is sorted in reverse order.
    // Find the highest index `j` to the right of index `i` such that `s[j] > s[i-1]`.
    int j = n-1;
    while (j > i && s[j] <= s[i-1]) {
        j--;
    }

    // swap character at index `i-1` with index `j`
    std::swap(s[i-1], s[j]);

    // Reverse substring `s[i…n-1]`and return true
    std::reverse (s.begin() + i, s.end());

    return true;
}
int main()
{
    fast;
    //setIO();
      int n;
    cin >> n;

    if(n == 1) cout << 1 << endl;
    else if (n < 4) cout << "NO SOLUTION" << endl;
    else if (n == 4) cout << "2 4 1 3\n";
    else {
        for (int i = 1; i <= n; i += 2) cout << i << " ";
        for (int i = 2; i <= n; i += 2) {
            cout << i;
            if (i + 2 <= n) cout << " ";
            else cout << endl;
        }
    }
    return ghost;
}

