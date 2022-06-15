#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> myMap;

void add(string &s) {
    myMap[s]++;
}

int find(string &s) {
    if(myMap.find(s) != myMap.end()) {
        return myMap[s];
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
