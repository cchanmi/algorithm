#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int num[8];


void dfs(int depth, int leastNum) {
    if (depth == m) {
        for(int i=0; i<m; i++) {
            cout<< num[i] << " ";
        }
        cout << "\n";
    } else {
        for(int i=leastNum; i<=n; i++) {
            num[depth] = i;
            dfs(depth+1, i);
        }
    }
}

int main() {
    cin>> n >> m;
    dfs(0, 1);
}
