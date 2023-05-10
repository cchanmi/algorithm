#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100001

int n;
double probability[4];
bool visited[30][30];
double resultProb;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input() {
    cin >> n;
    for(int i=0; i<4; i++) {
        cin >> probability[i];
        probability[i] /= 100;
    }
    memset(visited, false, sizeof(visited));
    resultProb = 0;
}

void solve(int x, int y, int depth, double prob) {
    if (depth == n) {
        return;
    } else {
        for(int i=0; i<4; i++) {
            int curX = x+dx[i];
            int curY = y+dy[i];
            if (visited[curX][curY]) {
                resultProb += prob*probability[i];
            } else {
                visited[curX][curY] = true;
                solve(curX, curY, depth+1, prob*probability[i]);
                visited[curX][curY] = false;
            }
        }
    }
}
int main() {
    FAST;
    cout.precision(20);
    input();
    visited[15][15] = true;
    solve(15, 15, 0, 1);
    cout << 1 - resultProb << "\n\n";
}

