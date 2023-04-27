#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 1001

int r, c;
char area[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> jQueue;
queue<pair<int, int>> fQueue;


int bfs() {
    int answer = 0;
    while (!jQueue.empty()) {
        answer++;
        int fireSize = fQueue.size();
        while (fireSize--) {
            pair<int, int> cur = fQueue.front();
            fQueue.pop();
            for(int i=0; i<4; i++) {
                int nextX = cur.first + dx[i];
                int nextY = cur.second + dy[i];
//                cout << " ( " << nextX << " , " << nextY << " ) \n";
                if (nextX>=0 && nextX<r && nextY>=0 && nextY<c) {
                    if (area[nextX][nextY] == '.' || area[nextX][nextY] == 'J') {
                        area[nextX][nextY] = 'F';
                        fQueue.push(make_pair(nextX, nextY));
                    }
                }
            }
        }
        int jSize = jQueue.size();
        while (jSize--) {
            pair<int, int> cur = jQueue.front();
            jQueue.pop();
            for(int i=0; i<4; i++) {
                int nextX = cur.first + dx[i];
                int nextY = cur.second + dy[i];
                if (nextX>=0 && nextX<r && nextY>=0 && nextY<c) {
                    if (area[nextX][nextY] == '.') {
                        area[nextX][nextY] = 'J';
                        jQueue.push(make_pair(nextX, nextY));
                    }
                } else return answer;
            }
        }
    }
    return 0;
}

int main() {
    FAST;
    cin >> r >> c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++) {
            cin >> area[i][j];
            if (area[i][j] == 'J') jQueue.push(make_pair(i, j));
            else if (area[i][j] == 'F') fQueue.push(make_pair(i, j));
        }
    int result = bfs();
    if (result == 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << result << "\n";
    }
}

