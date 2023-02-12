#include <iostream>
#include <stack>

using namespace std;

int main() {
    int num;
    cin >> num;
    int seqSum[num+1];
    seqSum[0] = 0;
    for(int i=1; i<=num; i++) {
        int minSumNum = 100000;
        for(int j=1; j*j<=i; j++) {
            if (j*j == i){
                minSumNum = 1;
            } else if( minSumNum > seqSum[i-j*j] + seqSum[j*j])
                minSumNum = seqSum[i-j*j] + seqSum[j*j];
        }
        seqSum[i] = minSumNum;
    }
    cout<< seqSum[num] << "\n";
}
