#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100001

using namespace std;

int n, k;
queue<long> findPlace;
bool visited[MAX] = {false};
long preNum[MAX] = {-1};

void bfs() {
    while (!findPlace.empty()) {
        if (findPlace.front() == k) break;
        int curPlace = findPlace.front()-1;
        if (curPlace>=0 && curPlace < 100001)
            if (!visited[curPlace]) {
                visited[curPlace] = true;
                preNum[curPlace] = findPlace.front();
                findPlace.push(curPlace);
            }
        curPlace = findPlace.front()+1;
        if (curPlace>=0 && curPlace<=100000)
            if (!visited[curPlace] ) {
                visited[curPlace] = true;
                preNum[curPlace] = findPlace.front();
                findPlace.push(curPlace);
            }
        curPlace = findPlace.front()*2;
        if (curPlace>=0 && curPlace<=100000)
            if (!visited[curPlace]) {
                visited[curPlace] = true;
                preNum[curPlace] = findPlace.front();
                findPlace.push(curPlace);
            }
        findPlace.pop();
    }
}

int main() {
    FAST;
    cin >> n >> k;
    if (n==k) {
        cout << 0 << "\n" << n;
        return 0;
    }
    
    findPlace.push(n);
    preNum[n] = n;
    visited[n] = true;
    bfs();
    int num = k;
    stack<int> resultStack;
    while (num!=n) {
        resultStack.push(num);
        num = preNum[num];
    }
    cout << resultStack.size() << "\n";
    resultStack.push(n);
    while (!resultStack.empty()) {
        cout << resultStack.top() << " ";
        resultStack.pop();
    }
}
