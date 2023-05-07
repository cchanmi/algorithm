#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100001

int n, m;
int parent[500001];

int getParent(int num) {
    if(parent[num] == num) return num;
    else return parent[num] = getParent(parent[num]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a<b) parent[b] = a;
    else parent[a] = b;
}

void input() {
    cin >> n >> m;
}

int main() {
    FAST;
    input();
    int a, b, result = 0;
    for(int i=0; i<=n; i++)
        parent[i] = i;
    for(int i=1; i<=m; i++) {
        cin >> a >> b;
        if (getParent(a) != getParent(b)) unionParent(a, b);
        else {
            if (result == 0)
                result = i;
        }
    }
    cout << result << "\n";
}
