#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int num[100001] = {0};
    long firstSeq[100001] = {0};
    long secondSeq[100001] = {0};
    for(int i=1; i<=n; i++)
        cin>> num[i];
    firstSeq[1] = num[1];
    secondSeq[1] = num[1];
    long max=num[1];
    for(int i=2; i<=n; i++) {
        if(firstSeq[i-1] + num[i] > num[i])
            firstSeq[i] = firstSeq[i-1] + num[i];
        else
            firstSeq[i] = num[i];
        
        if(firstSeq[i-1] > secondSeq[i-1] + num[i])
            secondSeq[i] = firstSeq[i-1];
        else
            secondSeq[i] = secondSeq[i-1] + num[i];
        if(max < firstSeq[i])
            max = firstSeq[i];
        if(max < secondSeq[i])
            max = secondSeq[i];
    }
    
    cout<<max<<"\n";
}
