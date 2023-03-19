#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int paper[4][4];
int ans = 0;

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            char c;
            cin >> c;
            paper[i][j] = c - '0';
        }
    
    int sum =0, temp=0;
    for(int s=0; s< (1<<(n*m)); s++) {
        sum = 0;
        for(int i=0; i<n; i++) {
            temp = 0;
            for(int j=0; j<m; j++) {
                int k = 1<<((m*i)+j);
                if((s&k)!=0) { // 1이라면  -> 가로라면
                    temp *= 10;
                    temp += paper[i][j];
                } else {
                    sum += temp;
                    temp = 0;
                }
            }
            sum += temp;
        }
        for(int j=0; j<m; j++) {
            temp = 0;
            for(int i=0; i<n; i++) {
                int k = 1<<((m*i)+j);
                if((s&k)==0) { //0이라면  -> 세로라면
                    temp *= 10;
                    temp += paper[i][j];
                } else {
                    sum += temp;
                    temp = 0;
                }
            }
            sum += temp;
        }
        ans = max(ans, sum);
    }
    
    cout << ans << "\n";
}
