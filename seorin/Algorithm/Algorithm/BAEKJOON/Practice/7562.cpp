#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 301

int board[MAX][MAX];
bool visited[MAX][MAX];
int boardSize;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
queue<pair<int, int>> visitedPlace;
pair<int, int> night;
pair<int, int> dest;

void bfs() {
    while (!visitedPlace.empty()) {
        int curX = visitedPlace.front().first;
        int curY = visitedPlace.front().second;
        visitedPlace.pop();
        for(int i=0; i<8; i++) {
            int preX = curX+dx[i];
            int preY = curY+dy[i];
            if(preX>=0 && preX<boardSize && preY>=0 && preY<boardSize) {
                if (!visited[preX][preY]) {
                    visited[preX][preY] = true;
                    board[preX][preY] = board[curX][curY] + 1;
                    visitedPlace.push(make_pair(preX, preY));
                }
            }
        }
    }
}

int main() {
    FAST;
    int t;
    cin >> t;
    while (t--) {
        memset(board, 10, sizeof(board));
        memset(visited, false, sizeof(visited));
        cin >> boardSize;
        cin >> night.first >> night.second;
        board[night.first][night.second] = 0;
        visited[night.first][night.second] = true;
        visitedPlace.push(make_pair(night.first, night.second));
        cin >> dest.first >> dest.second;
        bfs();
        cout << board[dest.first][dest.second] << "\n";
    }
}

