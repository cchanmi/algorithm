#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100001

priority_queue<int> spq;
priority_queue<int, vector<int>, greater<int>> bpq;

void setSameQueueSize() {
    if(spq.size() > bpq.size()+1) {
        bpq.push(spq.top());
        spq.pop();
    } else if ( bpq.size() > spq.size()+1) {
        spq.push(bpq.top());
        bpq.pop();
    }
}

int solve(int num) {
    if (spq.top() >= num) {
        spq.push(num);
    } else if (bpq.top()  <= num ) {
        bpq.push(num);
    } else {
        spq.push(num);
    }
    setSameQueueSize();
    if ( spq.size() >= bpq.size()) {
        return spq.top();
    } else {
        return bpq.top();
    }
}


int main() {
    FAST;
    int n;
    cin >> n;
    spq.push(-10000);
    bpq.push(10000);
    while (n--) {
        int num;
        cin >> num;
        cout << solve(num) << "\n";
    }
}

