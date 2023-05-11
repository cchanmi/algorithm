#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100001

int parent[201];
bool road [201][201];
int n, m;
int trip[1001];


int getParent(int num) {
    if (parent[num] == num) return num;
    else return parent[num] = getParent(parent[num]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a < b) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

void intput() {
    cin >> n >> m;
    for(int i=0; i<=n; i++) {
        parent[i] = i;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> road[i][j];
            if (road[i][j]) {
                unionParent(i, j);
            }
        }
    }
}

void unionFind() {
    for(int i=0; i<m; i++)
        cin >> trip[i];
    int dest = getParent(trip[0]);
    for(int i=0; i<m; i++) {
        if (dest != getParent(trip[i])) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    FAST;
    intput();
    unionFind();
}

