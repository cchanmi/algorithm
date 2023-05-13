#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int n;
long long populationSum = 0;
vector<pair<long long, long long>> cityLocation;

void input() {
    cin >> n;
    for(int i=0; i<n; i++) {
        long long city, cityPopulation;
        cin >> city >> cityPopulation;
        cityLocation.push_back({city, cityPopulation});
        populationSum += cityPopulation;
    }
    sort(cityLocation.begin(), cityLocation.end());
}

long long greedy() {
    long long centerIdx;
    long long centerPopulation;
    long long curPopulation;
    centerPopulation = populationSum/2;
    if (populationSum%2 == 1) centerPopulation++;
    int i=-1;
    curPopulation = 0;
    while (centerPopulation>curPopulation) {
        i++;
        curPopulation += cityLocation[i].second;
    }
    centerIdx = cityLocation[i].first;
    return centerIdx;
}

int main() {
    FAST;
    input();
    cout << greedy() << "\n";
    
}
