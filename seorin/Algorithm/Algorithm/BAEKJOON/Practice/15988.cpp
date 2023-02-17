#include <iostream>

using namespace std;

int main() {
    int t;
    cin>> t;
    int n;
    long long num[1000001];
    num[0] = 1;
    num[1] = 2;
    num[2] = 4;
    
    for(int i=3; i<1000001;i++)
        num[i] = ( num[i-1] + num[i-2] + num[i-3] )%1000000009;
    for(int i=0; i<t; i++) {
        cin>>n;
        cout<< num[n-1] << "\n";
    }
}
