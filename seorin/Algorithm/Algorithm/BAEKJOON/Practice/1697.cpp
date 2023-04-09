#include <iostream>
#include <algorithm>
#include <queue>
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

long long n, k;
queue<long long> findPlace;
bool visited[1000000] = {false};

bool findK() {
    int findSize = findPlace.size(), tryPlace;
    while (findSize--) {
        tryPlace = findPlace.front();
        findPlace.pop();
        if (tryPlace+1==k || tryPlace-1==k || tryPlace*2==k) return true;
        else {
            if (tryPlace-1>=0&&tryPlace-1<=100000&&!visited[tryPlace-1]) {
                visited[tryPlace-1] = true;
                findPlace.push(tryPlace-1);
            }
            if (tryPlace+1>=0&&tryPlace+1<=100000&&!visited[tryPlace+1]) {
                visited[tryPlace+1] = true;
                findPlace.push(tryPlace+1);
            }
            if (tryPlace*2>=0&&tryPlace*2<=100000&&!visited[tryPlace*2]) {
                visited[tryPlace*2] = true;
                findPlace.push(tryPlace*2);
            }
        }
    }
    return false;
}

int main() {
    FAST;
    int tryNum = 1;
    cin>> n >> k;
    if (n!=k) findPlace.push(n);
    else {
        cout << 0;
        return 0;
    }
    
    while (!findK()) tryNum++;
    cout << tryNum;
}
