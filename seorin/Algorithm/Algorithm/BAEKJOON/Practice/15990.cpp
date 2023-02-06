#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int num[n];
    int max=0;
    for(int i=0; i<n; i++) {
        cin>>num[i];
        if(max<num[i]) max = num[i];
    }
    long long oneNum[max], twoNum[max], threeNum[max];
    oneNum[0] = 1;
    twoNum[0] = 0;
    threeNum[0] = 0;
    oneNum[1] = 0;
    twoNum[1] = 1;
    threeNum[1] = 0;
    oneNum[2] = 1;
    twoNum[2] = 1;
    threeNum[2] = 1;
    for(int i=3; i<max; i++) {
        oneNum[i] = (twoNum[i-1] + threeNum[i-1]) % 1000000009;
        twoNum[i] = (oneNum[i-2] + threeNum[i-2]) % 1000000009;
        threeNum[i] = (oneNum[i-3] + twoNum[i-3]) % 1000000009;
    }
    for(int i=0; i<n; i++) {
        cout<< (oneNum[num[i]-1] + twoNum[num[i]-1] + threeNum[num[i]-1]) % 1000000009 << "\n";
    }
}
