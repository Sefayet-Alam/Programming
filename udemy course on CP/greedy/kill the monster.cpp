#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int killMonsters(int Hp, int k, vector<int> &dmg) {
    priority_queue<int> kills;
    for(int i = 0; i < dmg.size(); i++) {
        if(dmg[i] <= 0) {
            Hp += -dmg[i];
            continue;
        }
        Hp -= dmg[i];
        kills.push(dmg[i]);
        while(Hp <= 0 && k > 0 && !kills.empty()) {
            Hp += kills.top();
            kills.pop();
            k--;
        }
        if(Hp < 0) {
            return i;
        }
        if(Hp == 0) {
            return i + 1;
        }
    }
    return dmg.size();
}

int main() {
    int n, k, Hp;
    vector<int> dmg;
    cin >> n >> k >> Hp;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        dmg.push_back(x);
    }
    cout << killMonsters(Hp, k, dmg);
    return 0;
}
