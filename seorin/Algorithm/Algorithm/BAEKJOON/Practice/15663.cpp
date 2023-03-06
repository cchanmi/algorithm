#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int seq[8];
int num[8];
bool visitSeq[8] = { false };
bool isUniqueSeq;

void dfs(int depth) {
    if (depth == m) {
        for(int i=0; i<m; i++)
            cout <<num[i] << " ";
        cout<<"\n";
        return;
    } else {
        for(int i=0; i<n; i++) {
            if(visitSeq[i] == true) continue;
            isUniqueSeq = true;
            for(int j=0; j<i; j++)
                if(seq[i] == seq[j] && visitSeq[j] == false) isUniqueSeq = false;
            if (isUniqueSeq) {
                visitSeq[i] = true;
                num[depth] = seq[i];
                dfs(depth+1);
                visitSeq[i] = false;
            }
        }
    }
    return;
}

int main() {
    cin>> n >> m;
    for(int i=0; i<n; i++)
        cin >> seq[i];
    sort(seq, seq+n);
    dfs(0);
}
