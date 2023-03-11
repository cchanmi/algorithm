#include <iostream>
#include <algorithm>

using namespace std;

int n;
int seq[8];
bool visitNum[9] = { false };


void dfs(int depth) {
    if (depth == n) {
        for(int i=0; i<n; i++)
            cout<< seq[i] << " ";
        cout<<"\n";
        return;
    } else {
        for(int i=1; i<=n; i++) {
            if (visitNum[i] == true) continue;
            else {
                visitNum[i] = true;
                seq[depth] = i;
                dfs(depth+1);
                visitNum[i] = false;
            }
        }
    }
}
int main() {
    cin>>n;
    dfs(0);
}
