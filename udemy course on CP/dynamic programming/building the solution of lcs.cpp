#include <iostream>

using namespace std;

const int Nmax = 1005;

int dp[Nmax][Nmax];
int a[Nmax], b[Nmax], n, m;

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

void reconstruct(int i, int j) {
    if(i == 0 || j == 0) {
        return;
    }
    if(a[i] == b[j]) {
        reconstruct(i - 1, j - 1);
        cout << a[i];
    }
    else {
        if(dp[i - 1][j] > dp[i][j - 1]) {
            reconstruct(i - 1, j);
        }
        else {
            reconstruct(i, j - 1);
        }
    }
}

int main () {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    reconstruct(n, m);
}
