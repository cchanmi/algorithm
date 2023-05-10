#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100001

long n;
vector<pair<long, long>> confer;

void input() {
    cin >>n;
    int a, b;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        confer.push_back({b, a});
    }
    sort(confer.begin(), confer.end());
}

long greedy() {
    long result = 0;
    long endTime = 0;
    for(int i=0; i<n; i++) {
        if (endTime<=confer[i].second) {
            endTime = confer[i].first;
            result++;
        }
    }
    return result;
}

int main() {
    FAST;
    input();
    cout<< greedy() << "\n";
}
