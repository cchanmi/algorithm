#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 61

int n, m;
int scv[3];
int result[61][61][61];

int attack[6][3] = {
    {9, 3, 1},
    {3, 9, 1},
    {9, 1, 3},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9},
};

void input() {
    memset(result, -1, sizeof(result));
    memset(scv, 0, sizeof(scv));
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> scv[i];
    }
}

int attactScv(int scv1, int scv2, int scv3) {
    scv1 = scv1 < 0 ? 0 : scv1;
    scv2 = scv2 < 0 ? 0 : scv2;
    scv3 = scv3 < 0 ? 0 : scv3;
    if (scv1==0 && scv2==0 && scv3==0) return 0;
    
    int& ret = result[scv1][scv2][scv3];
    
    if (ret!=-1) return ret;
    ret = MAX;
        
    for(int i=0; i<6; i++) {
        ret = min(ret, attactScv(scv1 - attack[i][0], scv2-attack[i][1], scv3-attack[i][2])+1);
    }
    return ret;
}

int main() {
    FAST;
    input();
    cout << attactScv(scv[0], scv[1], scv[2]) << "\n";
}

