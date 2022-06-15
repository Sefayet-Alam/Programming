#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPlatforms(vector<pair<double, double>> trains) {
    vector<pair<double, int>> events;
    for(pair<double, double> tr : trains) {
        events.push_back({tr.first, 1});
        events.push_back({tr.second, 0});
    }
    sort(events.begin(), events.end());
    int ans = 0, free_plat = 0;
    for(pair<double, int> ev : events) {
        if(ev.second == 0) {
            free_plat++;
        }
        else {
            if(free_plat == 0) {
                ans++;
            }
            else {
                free_plat--;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    double t1, t2;
    cin >> n;
    vector<pair<double, double>> trains;
    for(int i = 1; i <= n; i++) {
        cin >> t1 >> t2;
        trains.push_back({t1, t2});
    }
    cout << minPlatforms(trains);
    return 0;
}
