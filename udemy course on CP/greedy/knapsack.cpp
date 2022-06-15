#include <iostream>
#include <algorithm>

using namespace std;

const int Nmax = 100005;

struct Object {
    int w;
    double vpu;
    bool operator < (const Object &x) const {
        return vpu > x.vpu;
    }
};
Object a[Nmax];

int main() {
    int n, G;
    cin >> n >> G;
    for(int i = 1; i <= n; i++) {
        int v, w;
        cin >> v >> w;
        a[i].w = w;
        a[i].vpu = (double) v / w;
    }
    sort(a + 1, a + n + 1);
    double ans = 0;
    for(int i = 1; i <= n; i++) {
        int q = min(a[i].w, G);
        ans += q * a[i].vpu;
        G -= q;
    }
    cout << ans << "\n";
    return 0;
}
