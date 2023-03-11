#include <iostream>
#include <algorithm>

using namespace std;


int ans = 10000000;
bool visitCountry[11] = {false};
int n, w[11][11] = {0};
int seq[11];

void dfs(int depth, int curCountry) {
    if (depth == n) {
        if (w[seq[n-1]][seq[0]] == 0)
            return;
        int sum = 0;
        for(int i=0; i<n-1; i++)
            sum += w[seq[i]][seq[i+1]];
        sum += w[seq[n-1]][seq[0]];
        ans = min(ans, sum);
    } else {
        for(int i=0; i<n; i++) {
            if (visitCountry[i] == true) continue;
            if (w[curCountry][i] == 0) continue;
            if (curCountry == i) continue;
            seq[depth] = i;
            visitCountry[i] = true;
            dfs(depth+1, i);
            visitCountry[i] = false;
        }
    }
}

int main() {
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>> w[i][j];
    for(int i=0; i<n; i++) {
        seq[0] = i;
        visitCountry[i] = true;
        dfs(1, i); // 다음 1번째 지역으로 갈 건데 현재 i 에 있음
        visitCountry[i] = false;
    }
    
    cout << ans << "\n";
}
