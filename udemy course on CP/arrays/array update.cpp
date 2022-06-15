#include <iostream>

using namespace std;

const int Nmax = 100005;

int n, a[Nmax], b[Nmax], s[Nmax];

void Update(int x, int y, int val) {
    b[x] += val;
    b[y + 1] -= val;
}

void buildFinalArray() {
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + b[i];
        a[i] += s[i];
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    while(m--) {
        int x, y, val;
        cin >> x >> y >> val;
        Update(x, y, val);
    }
    buildFinalArray();
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}
