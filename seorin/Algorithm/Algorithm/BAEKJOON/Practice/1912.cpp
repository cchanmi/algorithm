#include <iostream>

using namespace std;

int main() {
    int n;
    cin>> n;
    int num[n+1], sumSeq[n+1];
    num[0] = 0;
    sumSeq[0] = 0;
    for(int i=1; i<=n; i++) {
        cin>>num[i];
        if(sumSeq[i-1] + num[i] < num[i])
            sumSeq[i] = num[i];
        else
            sumSeq[i] = sumSeq[i-1] + num[i];
    }
    int max = -1000;
    for(int i=1; i<=n; i++)
        if(max < sumSeq[i])
            max = sumSeq[i];
    cout<<max;
}
