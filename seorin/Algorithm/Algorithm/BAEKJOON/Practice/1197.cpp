#include <iostream>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100001

using namespace std;

int v, e;
vector<pair<int, int>> edge;
vector<int> dist;
int parent[MAX];
int answer = 0;

void quickSort(vector<int>& dist, int left, int right) {
    int i = left, j = right;
    int pivot = dist[(left + right) / 2];

    while (i <= j) {
        while (dist[i] < pivot) i++;

        while (dist[j] > pivot) j--;

        if (i <= j) {
            swap(dist[i], dist[j]);
            swap(edge[i], edge[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(dist, left, j);
    if (i < right) quickSort(dist, i, right);
}

int getParent(int num) {
    if (parent[num] == num) return num;
    parent[num] = getParent(parent[num]);
    return parent[num];
}

void unionParent(int startNum, int endNum) {
    if (startNum < endNum) {
        parent[endNum] = startNum;
    } else {
        parent[startNum] = endNum;
    }
}

void mst() {
    for(int i=0; i<e; i++) {
        int startNum = edge[i].first;
        int endNum = edge[i].second;
        if (getParent(startNum) != getParent(endNum)) {
            unionParent(getParent(startNum), getParent(endNum));
            answer += dist[i];
        }
    }
}

int main() {
    FAST;
    cin >> v >> e;
    for(int i=0; i<=v; i++) parent[i] = i;
    for(int i=0; i<e; i++) {
        pair<int, int> tempEdge;
        int tempDistance;
        cin >>tempEdge.first >> tempEdge.second >> tempDistance;
        edge.push_back(tempEdge);
        dist.push_back(tempDistance);
    }
    quickSort(dist, 0, dist.size()-1);
    mst();
    cout << answer << "\n";
    
}
