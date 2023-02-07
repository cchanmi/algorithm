#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long num[n][10];
    num[0][0] = 0;
    for(int i=1; i<10; i++)
        num[0][i] = 1;
    
    for(int i=1; i<n; i++) {
        num[i][0] = num[i-1][1];
        num[i][9] = num[i-1][8];
        for(int j=1; j<9; j++){
            num[i][j] = (num[i-1][j-1] + num[i-1][j+1])%1000000000;
        }
    }
    
    long long sum=0;
    for(int i=0; i<10; i++) {
        sum += (num[n-1][i]);
        sum %= 1000000000;
    }
    cout<<sum<<"\n";
}
