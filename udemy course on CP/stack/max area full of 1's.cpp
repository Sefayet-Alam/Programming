#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int Nmax = 1005;

int a[Nmax][Nmax], tower[Nmax][Nmax];

long long maxRectArea(vector<int> &h) {
    int n = h.size();
    vector<int> Left(n, -1), Right(n, n);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && h[i] < h[st.top()]) {
            Right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // st.clear() does not exist but we can clear it another way
    while(!st.empty()) {
        st.pop();
    }

    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && h[i] < h[st.top()]) {
            Left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    long long ans = 0;
    for(int k = 0; k < n; k++) {
        ans = max(ans, 1LL * h[k] * (Right[k] - Left[k] - 1));
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) {
                tower[i][j] = 0;
            }
            else {
                tower[i][j] = tower[i - 1][j] + 1;
            }
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        vector<int> h;
        for(int j = 1; j <= m; j++) {
            h.push_back(tower[i][j]);
        }
        ans = max(ans, maxRectArea(h));
    }
    cout << ans;
    return 0;
}
