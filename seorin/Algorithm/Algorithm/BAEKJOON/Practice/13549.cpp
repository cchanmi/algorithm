#include <iostream>
#include <algorithm>
#include <queue>
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAXNUM 100001

using namespace std;

int n, k;
bool visited[MAXNUM] = {false};
int answer[MAXNUM] = {MAXNUM};
queue<int> findQueue;

void bfs() {
    while (!findQueue.empty()) {
        int curPlace = findQueue.front();
        findQueue.pop();
        visited[curPlace] = false;
        if (curPlace+1 < MAXNUM && answer[curPlace+1] > answer[curPlace]+1 && curPlace <= k) {
            answer[curPlace+1] = answer[curPlace] + 1;
            if (!visited[curPlace+1])
                findQueue.push(curPlace+1);
            visited[curPlace+1] = true;
        }
        if (curPlace-1 >= 0 && answer[curPlace-1] > answer[curPlace]+1) {
            answer[curPlace-1] = answer[curPlace] + 1;
            if (!visited[curPlace-1])
                findQueue.push(curPlace-1);
            visited[curPlace-1] = true;
        }
        if (curPlace*2 < MAXNUM && answer[curPlace*2] > answer[curPlace] && curPlace <= k) {
            answer[curPlace*2] = answer[curPlace];
            if (!visited[curPlace*2])
                findQueue.push(curPlace*2);
            visited[curPlace*2] = true;
        }
    }
}

int main() {
    FAST;
    for(int i=0; i<MAXNUM; i++) answer[i] = MAXNUM;
    cin >> n >> k;
    answer[n] = 0;
    findQueue.push(n);
    visited[n] = true;
    if (n==k) {
        cout << answer[n] << "\n";
        return 0;
    }
    bfs();
    cout << answer[k] << "\n";
    
}
