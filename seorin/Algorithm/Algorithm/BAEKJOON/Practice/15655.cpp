#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int seq[8];
int num[8];

void printNum(int depth, int leastSeq) {
    if (depth == m) {
        for(int i=0; i<m; i++)
            cout <<num[i] << " ";
        cout<<"\n";
        return;
    } else {
        for(int i=leastSeq; i<n; i++) {
            num[depth] = seq[i];
            printNum(depth+1, i+1);
        }
    }
    return;
}

int main() {
    cin>> n >> m;
    for(int i=0; i<n; i++)
        cin >> seq[i];
    sort(seq, seq+n);
    printNum(0, 0);
}
