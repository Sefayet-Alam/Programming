#include <iostream>

using namespace std;

const int Nmax = 1005;

int dp[Nmax][Nmax];

int findLCS(int a[], int n, int b[], int m) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main () {
    int a[Nmax], b[Nmax], n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    cout << findLCS(a, n, b, m);
}
