#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 1001

int result[MAX];
int resultIdx[MAX];
string strA;
string strB;

void input() {
    cin >> strA;
    cin >> strB;
    memset(result, 0, sizeof(result));
    memset(resultIdx, -1, sizeof(resultIdx));
}

void solve() {
    for(int i=0; i<strA.size(); i++) {
        int maxNum = 0;
        int maxIdx = -1;
        for(int j=0; j<strB.size(); j++) {
            if (strA[i] == strB[j]) {
                result[j] = maxNum+1;
                
            }
            if ( maxNum<result[j] ) {
                maxNum = result[j];
                maxIdx = j;
            }
        }
    }
}

int main() {
    FAST;
    input();
//    solve();
}

