#include <iostream>

using namespace std;

int main() {
    int t;
    cin>> t;
    int n;
    int num[11];
    num[0] = 1;
    num[1] = 2;
    num[2] = 4;
    for(int i=3; i<11;i++)
        num[i] = num[i-1] + num[i-2] + num[i-3];
    for(int i=0; i<t; i++) {
        cin>>n;
        cout<< num[n-1] << "\n";
    }
}
