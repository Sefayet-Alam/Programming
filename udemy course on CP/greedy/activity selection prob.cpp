#include <iostream>
#include <algorithm>

using namespace std;

const int Nmax = 100005;

struct Activity {
    int start, finish;
    bool operator < (const Activity &x) const {
        return finish < x.finish;
    }
};
Activity act[Nmax];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> act[i].start >> act[i].finish;
    }
    sort(act + 1, act + n + 1);
    int ans = 0, currFinish = -1;
    for(int i = 1; i <= n; i++) {
        if(currFinish < act[i].start) {
            ans++;
            currFinish = act[i].finish;
        }
    }
    cout << ans << "\n";
    return 0;
}
