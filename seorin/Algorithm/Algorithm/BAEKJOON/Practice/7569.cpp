#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int m, n, h;
int tomato[100][100][100];
int dx[8] = {1, -1, 0, 0, 0, 0};
int dy[8] = {0, 0, 1, -1, 0, 0};
int dz[8] = {0, 0, 0, 0, 1, -1};
queue<tuple<int, int, int>> ripedTomato;

int cal() {
    int ripeDay = 0;
    while (!ripedTomato.empty()) {
        int tomatoNum = ripedTomato.size();
        while (tomatoNum--) {
            int tomatoX = get<0>(ripedTomato.front());
            int tomatoY = get<1>(ripedTomato.front());
            int tomatoZ = get<2>(ripedTomato.front());
            ripedTomato.pop();
            for(int i=0; i<8; i++) {
                int x = tomatoX + dx[i];
                int y = tomatoY + dy[i];
                int z = tomatoZ + dz[i];
                if (x<0 || x>=h || y<0 || y>=n || z<0 || z>=m) continue;
                if (tomato[x][y][z]==0) {
                    tomato[x][y][z] = 1;
                    ripedTomato.push(make_tuple(x, y, z));
                }
            }
        }
        ripeDay++;
    }
    return --ripeDay;
}
                     
int main() {
    cin >> m >> n >> h;
    for(int i=0; i<h; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<m; k++) {
                cin>> tomato[i][j][k];
                if(tomato[i][j][k] == 1) ripedTomato.push(make_tuple(i, j, k));
            }
    int day = cal();
    
    for(int i=0; i<h; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<m; k++)
                if(tomato[i][j][k] == 0)
                    day = -1;
    cout << day << "\n";
}
