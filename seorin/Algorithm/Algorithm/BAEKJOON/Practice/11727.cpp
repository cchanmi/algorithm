#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int num[n+1];
    num[0] = 1;
    num[1] = 1;
    for(int i=2; i<=n; i++) {
        num[i] = (num[i-1] + 2*num[i-2]) % 10007;
        
    }
    cout<<num[n];
}
