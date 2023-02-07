#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int n;
    cin>> n;
    int num[n], seq[n];
    for(int i=0; i<n; i++) {
        cin>>num[i];
        seq[i] = 1;
    }
    int max = 1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++)
            if (num[i] > num[j])
                if(seq[i] < seq[j]+1)
                    seq[i] = seq[j]+1;
        if (max < seq[i]) max = seq[i];
    }
    cout<< max;
}
