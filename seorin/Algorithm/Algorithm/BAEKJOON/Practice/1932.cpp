#include <iostream>

using namespace std;

int main() {
    int n;
    long num[501][501] = {0};
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++) {
            cin >>num[i][j];
            num[i][j] += max(num[i-1][j-1], num[i-1][j]);
        }
    int max = 0;
    for(int i=1; i<=n; i++)
        if (max < num[n][i])
            max = num[n][i];
    
    cout<< max << "\n";
}
