#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int num[n];
    long maxSum[n][3];
    num[0] = 0;
    for (int i=0; i<n; i++) {
        cin >>num[i];
    }
    
    maxSum[0][0] = 0;
    maxSum[0][1] = num[0];
    maxSum[0][2] = num[0];
    for(int i=1; i<n; i++) {
        maxSum[i][0] = max(max(maxSum[i-1][0], maxSum[i-1][1]), maxSum[i-1][2]);
        maxSum[i][1] = maxSum[i-1][0] + num[i];
        maxSum[i][2] = maxSum[i-1][1] + num[i];
    }
    
    cout<< max(max(maxSum[n-1][0], maxSum[n-1][1]), maxSum[n-1][2]) << "\n";
}
