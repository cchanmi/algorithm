#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

char field[1000][1000];
int h, w;
bool isImpossible;
queue<pair<int, int>> sang;
queue<pair<int, int>> fire;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


void inputCase() {
    while (!sang.empty()) sang.pop();
    while (!fire.empty()) fire.pop();
    cin>> w >> h;
    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++) {
            cin >> field[i][j];
            if (field[i][j] == '*') fire.push(make_pair(i, j));
            else if (field[i][j] == '@') sang.push(make_pair(i, j));
        }
}

int escape() {
    int move = 0;
    while (!sang.empty()) {
        move++;
        int sangSize = sang.size();
        int fireSize = fire.size();
        while (fireSize--) {
            for(int i=0; i<4; i++) {
                int x = fire.front().first + dx[i];
                int y = fire.front().second + dy[i];
                if (x<0 || x>=h || y<0 || y>=w) continue;
                if (field[x][y] == '.' || field[x][y] == '@') {
                    field[x][y] = '*';
                    fire.push(make_pair(x, y));
                }
            }
            fire.pop();
        }
        while (sangSize--) {
            for(int i=0; i<4; i++) {
                int x = sang.front().first + dx[i];
                int y = sang.front().second + dy[i];
                if (x<0 || x>=h || y<0 || y>=w) return move;
                if (field[x][y] == '.') {
                    field[x][y] = '@';
                    sang.push(make_pair(x, y));
                }
            }
            sang.pop();
        }
    }
    isImpossible = true;
    return move;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, result;
    cin >> t;
    while (t--) {
        isImpossible = false;
        inputCase();
        result = escape();
        if (isImpossible) cout << "IMPOSSIBLE\n";
        else cout << result <<"\n";
    }
    
}
