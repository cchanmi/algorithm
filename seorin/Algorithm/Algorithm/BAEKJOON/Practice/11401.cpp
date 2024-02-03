#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 4000000

long num[MAX][MAX];

int main() {
    FAST;
    long n, k;
    cin >> n >> k;
    for(int i=0; i<=n; i++) {
        num[i][0] = 1;
        num[i][i] = 1;
        for(int j=1; j<i; j++) {
            num[i][j] = (num[i-1][j-1] + num[i-1][j]) % 1000000007;
        }
    }
    
    cout  << num [n][k]  << "\n";
}
