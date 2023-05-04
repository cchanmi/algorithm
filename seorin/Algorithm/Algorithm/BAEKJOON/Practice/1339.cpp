#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100001
#include <algorithm>

int cNum[10];

vector<pair<char, long>> wordSeq;
priority_queue<long> pq;

int n;

void input() {
    cin >> n;
    string temp;
    for(int i=0; i<n; i++) {
        cin >> temp;
        long digit = 1;
        while (!temp.empty()) {
            wordSeq.push_back({temp.back(), digit});
            temp.pop_back();
            digit *= 10;
        }
    }
}

long greedy() {
    sort(wordSeq.begin(), wordSeq.end());
    long wordSum = wordSeq[0].second;
    for(int i=1; i<wordSeq.size(); i++) {
        if (wordSeq[i-1].first != wordSeq[i].first) {
            pq.push(wordSum);
            wordSum = 0;
        }
        wordSum += wordSeq[i].second;
    }
    pq.push(wordSum);
    
    long result = 0;
    int alphaNum = 9;
    while (!pq.empty()) {
        result += pq.top()*alphaNum;
        alphaNum--;
        pq.pop();
    }
    return result;
}

int main() {
    FAST;
    input();
    cout << greedy() << "\n";
}

