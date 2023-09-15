#include <iostream>
#include <algorithm>
#include <queue>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
#define MAX 100

char area[MAX][MAX];
int result[MAX][MAX];
int w, h;
pair<int, int> start;
queue<pair<int, int>> q;

void input() {
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char temp;
            cin >> temp;
            area[i][j] = temp;
            if (temp == 'C') {
                start = make_pair(i, j);
            }
        }
    }
}

int solve() {
    q.push(make_pair(start.first, start.second));
    result[start.first][start.second] = -1;
    area[start.first][start.second] = '-';
    while (!q.empty()) {
        int x;
        int y;
        x = q.front().first - 1;
        y = q.front().second;
        while (x >= 0) {
            if (area[x][y] == '*') break;
            else if (area[x][y] == 'C'){
                return result[q.front().first][q.front().second] + 1;
            }
            else if (area[x][y] == '.') {
                area[x][y] = '-';
                result[x][y] = result[q.front().first][q.front().second] + 1;
                q.push(make_pair(x, y));
            }
            x--;
        }
        x = q.front().first + 1;
        y = q.front().second;
        while (x < h) {
            if (area[x][y] == '*') break;
            else if (area[x][y] == 'C'){
                return result[q.front().first][q.front().second] + 1;
            }
            else if (area[x][y] == '.'){
                area[x][y] = '-';
                result[x][y] = result[q.front().first][q.front().second] + 1;
                q.push(make_pair(x, y));
            }
            x++;
        }
        x = q.front().first;
        y = q.front().second-1;
        while (y >= 0) {
            if (area[x][y] == '*') break;
            else if (area[x][y] == 'C'){
                return result[q.front().first][q.front().second] + 1;
            }
            else if (area[x][y] == '.'){
                area[x][y] = '-';
                result[x][y] = result[q.front().first][q.front().second] + 1;
                q.push(make_pair(x, y));
            }
            y--;
        }
        x = q.front().first;
        y = q.front().second+1;
        while (y < w) {
            if (area[x][y] == '*') break;
            else if (area[x][y] == 'C'){
                return result[q.front().first][q.front().second] + 1;
            }
            else if (area[x][y] == '.'){
                area[x][y] = '-';
                result[x][y] = result[q.front().first][q.front().second] + 1;
                q.push(make_pair(x, y));
            }
            y++;
        }
        q.pop();
    }
    return 0;
}

int main()
{
    input();
    cout << solve();
}
