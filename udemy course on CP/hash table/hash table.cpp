#include <iostream>
#include <vector>

using namespace std;

const int N = 666013, X = 13;

vector<pair<string, int>> H[N];

int h_func(string &s) {
    int key = 0;
    for(char c : s) {
        key = (1LL * key * X + c) % N;
    }
    return key;
}

void add(string &s) {
    int key = h_func(s);
    for(auto &x : H[key]) {
        if(x.first == s) {
            x.second++;
            return;
        }
    }
    H[key].push_back({s, 1});
}

int find(string &s) {
    int key = h_func(s);
    for(auto x : H[key]) {
        if(x.first == s) {
            return x.second;
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        int type;
        string s;
        cin >> type >> s;
        if(type == 0) { // add
            add(s);
        }
        else { // find
            cout << find(s) << "\n";
        }
    }
    return 0;
}
