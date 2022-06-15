#include <iostream>
#include <vector>

using namespace std;

const int Nmax = 100005;

int maxHeap[Nmax], n;

void upHeap(int pos) {
    while(pos > 1 && maxHeap[pos] > maxHeap[pos / 2]) {
        swap(maxHeap[pos], maxHeap[pos / 2]);
        pos /= 2;
    }
}

void insert(int x) {
    maxHeap[++n] = x;
    upHeap(n);
}

void downHeap(int pos) {
    int largest = pos;
    int lSon = 2 * pos, rSon = 2* pos + 1;
    if(lSon <= n && maxHeap[lSon] > maxHeap[largest]) {
        largest = lSon;
    }
    if(rSon <= n && maxHeap[rSon] > maxHeap[largest]) {
        largest = rSon;
    }
    if(pos != largest) {
        swap(maxHeap[pos], maxHeap[largest]);
        downHeap(largest);
    }
}

int getMax() {
    return maxHeap[1];
}

void removeMax() {
    maxHeap[1] = maxHeap[n--];
    downHeap(1);
}

int main() {
    insert(10);
    insert(5);
    cout << getMax() << "\n";
    removeMax();
    cout << getMax() << "\n";
    insert(2);
    insert(7);
    cout << getMax() << "\n";
    removeMax();
    cout << getMax() << "\n";
    return 0;
}
