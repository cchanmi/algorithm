#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 1500002

long n;
long revenue[MAX];
vector<int> t;
vector<int> p;

void input() {
    cin >> n;
    int a, b;
    t.push_back(0);
    p.push_back(0);
    for(int i=0; i<n; i++) {
        cin >>a >> b;
        t.push_back(a);
        p.push_back(b);
    }
    memset(revenue, 0, sizeof(int)*(n+2));
}

void solved() {
    for(int i=1; i<=n; i++) {
        revenue[i] = max(revenue[i], revenue[i-1]);
        if (i+t[i]>n+1) continue;
        revenue[i+t[i]] = max(revenue[i+t[i]], revenue[i]+p[i]);
    }
    revenue[n+1] = max(revenue[n+1], revenue[n]);
}

int main() {
    FAST;
    input();
    solved();
    cout << revenue[n+1] << "\n";
}

