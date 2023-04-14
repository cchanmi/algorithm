#include <iostream>
#include <algorithm>
#include <queue>
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

queue<int> screen;
queue<int> clipBoard;
bool visited[1001][1001] = {false};
int answer[1001][1001];

int s;

void bfs() {
    bool find = false;
    while (!find) {
        int sNum = screen.front();
        int cbNum = clipBoard.front();
        screen.pop();
        clipBoard.pop();
        if (sNum>0 && cbNum>=0 && sNum<1001 && cbNum<1001 && sNum+cbNum < 1001) {
            if (!visited[sNum+cbNum][cbNum]) {
                if (sNum+cbNum == s) find = true;
                visited[sNum+cbNum][cbNum] = true;
                screen.push(sNum+cbNum);
                clipBoard.push(cbNum);
                answer[sNum+cbNum][cbNum] = min(answer[sNum+cbNum][cbNum], answer[sNum][cbNum]+1);
            }
        }
        if (sNum>0 && cbNum>=0 && sNum<1001 && cbNum<1001) {
            if (!visited[sNum-1][cbNum]) {
                if (sNum-1 == s) find = true;
                visited[sNum-1][cbNum] = true;
                screen.push(sNum-1);
                clipBoard.push(cbNum);
                answer[sNum-1][cbNum] = min(answer[sNum-1][cbNum], answer[sNum][cbNum]+1);
            }
        }
        if (sNum>0 && cbNum>=0 && sNum<1001 && cbNum<1001) {
            if (!visited[sNum][sNum]) {
                if (sNum == s) find = true;
                visited[sNum][sNum] = true;
                screen.push(sNum);
                clipBoard.push(sNum);
                answer[sNum][sNum] = min(answer[sNum][sNum], answer[sNum][cbNum]+1);
            }
        }
    }
}

int main() {
    FAST;
    cin >> s;
    screen.push(1);
    clipBoard.push(0);
    for(int i=0; i<1001; i++) for(int j=0; j<1001; j++) answer[i][j] = 1001;
    answer[1][0] = 0;
    visited[1][0] = true;
    bfs();
    int result = 1001;
    for(int i=0; i<1001; i++) result = min(result, answer[s][i]);
    cout << result << "\n";
}
