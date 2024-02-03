#include <iostream>
#include <algorithm>
#include <queue>
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAXNUM 3001
using namespace std;

int n;
int lotationDist[MAXNUM];
bool visited[MAXNUM];
int subway[MAXNUM][MAXNUM];
int subwayArray[MAXNUM];

void inputNum() {
    int a, b;
    cin >> n;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) subway[i][j] = 0;
        visited[i] = false;
        lotationDist[i] = MAXNUM;
    }
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        subway[a][b] = 1;
        subway[b][a] = 1;
    }
}

void lotation(int depth, int startLotation) {
    lotationDist[startLotation] = 0;
    while (depth >= 0)
        if (subwayArray[depth] != startLotation) {
            lotationDist[subwayArray[depth]] = 0;
            depth--;
        } else return;
}

void bfs(int depth, int curNum, int preNum) {
//    cout << preNum << "  ---- > "  << curNum << "\n";
    for(int i=1; i<=n; i++) {
        if (subway[curNum][i] && i != preNum) {
            if (visited[i]) {
                lotation(depth-1, i);
            } else {
                visited[i] = true;
                subwayArray[depth] = i;
                bfs(depth+1, i, curNum);
                visited[i] = false;
            }
        }
    }
}

void bfsCalDist(int curNum, int preNum) {
//    cout << preNum << "  ---- > "  << curNum << "\n";
    for(int i=1; i<=n; i++) {
        if (subway[curNum][i] && i!=preNum && !visited[i]) {
            lotationDist[i] = min(lotationDist[i], lotationDist[curNum]+1);
            visited[i] = true;
            bfsCalDist(i, curNum);
            visited[i] = false;
        }
    }
}

int main() {
    FAST;
    inputNum();
    for(int i=1; i<=n; i++) {
        visited[i] = true;
        subwayArray[0] = i;
        bfs(1, i, i);
        visited[i] = false;
    }
    for(int i=0; i<n; i++)
        visited[i] = false;
    for(int i=1; i<=n; i++) {
        if (lotationDist[i]==0) {
            visited[i] = true;
            bfsCalDist(i, 0);
            visited[i] = false;
        }
    }
    for(int i=1; i<=n; i++)
        cout << lotationDist[i] << " ";
    cout << "\n";
}
