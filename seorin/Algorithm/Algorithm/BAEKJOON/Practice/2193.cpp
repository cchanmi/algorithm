#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    
    long long oneNum[n+1], zeroNum[n+1];
    
    oneNum[1] = 1;
    zeroNum[1] = 0;
    
    oneNum[2] = 0;
    zeroNum[2] = 1;
    for(int i=3; i<=n; i++) {
        oneNum[i] = zeroNum[i-1];
        zeroNum[i] = oneNum[i-1] + zeroNum[i-1];
    }
    cout<< oneNum[n] + zeroNum[n];
}
