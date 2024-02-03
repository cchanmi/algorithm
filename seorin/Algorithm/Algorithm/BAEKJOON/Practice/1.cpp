#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

priority_queue<pair<int, int>> delPq;
priority_queue<pair<int, int>> pickPq;

long long solution(
    int cap, 
    int n,
    vector<int> deliveries, 
    vector<int> pickups) {
    long long answer = 0;
    for (int i=0; i<n; i++) {
        if (deliveries[i] > 0) 
            delPq.push(make_pair(i, deliveries[i]));
        if (pickups[i] > 0)
            pickPq.push(make_pair(i, pickups[i]));
    }
    while(!delPq.empty() || !pickPq.empty()) {
        int dist = 0;
        int delStore = cap;
        int pickStore = cap;
        while (!delPq.empty() && delStore>0) {
            if (delStore == cap)
                dist = max(dist, delPq.top().first);
            delStore--;
            int tempI = delPq.top().first;
            int temp = delPq.top().second-1;
            delPq.pop();
            delPq.push(make_pair(tempI, temp));
            if (delPq.top().second == 0)
                delPq.pop();
        }
        while (!pickPq.empty() && pickStore>0) {
            if (pickStore == cap)
                dist = max(dist, pickPq.top().first);
            pickStore--;
            int tempI = pickPq.top().first;
            int temp = pickPq.top().second-1;
            pickPq.pop();
            pickPq.push(make_pair(tempI, temp));
            
            if (pickPq.top().second == 0)
                pickPq.pop();
        }
        cout << dist << "\n";
        answer += dist*2;
    }    
    return answer;
}

int main() {
    int cap = 4;
    int n = 5;
    vector<int> deliveries;
    vector<int> pickups;
    deliveries.push_back(1);
    deliveries.push_back(0);
    deliveries.push_back(3);
    deliveries.push_back(1);
    deliveries.push_back(2);
    pickups.push_back(0);
    pickups.push_back(3);
    pickups.push_back(0);
    pickups.push_back(4);
    pickups.push_back(0);
    cout << solution(cap, n,deliveries, pickups) << "\n\n";
}