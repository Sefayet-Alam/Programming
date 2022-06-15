#include <iostream>
#include <algorithm>

using namespace std;

const int Nmax = 100005;

int n, a[Nmax], dp[Nmax], minLast[Nmax], len;

int findLIS(int a[], int n) {
    dp[1] = 1;
    minLast[1] = a[1];
    len = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] > minLast[len]) {
            len++;
            dp[i] = len;
            minLast[len] = a[i];
        }
        else {
            int p = upper_bound(minLast + 1, minLast + len + 1, a[i]) - minLast;
            if(minLast[p - 1] == a[i]) {
                p--;
            }
            dp[i] = p;
            minLast[p] = a[i];
        }
    }
    return len;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << findLIS(a, n);
    return 0;
}
