#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin>> n;
    int num[n];
    queue<int> seq[n];

    for(int i=0; i<n; i++) {
        cin>> num[i];
        seq[i].push(num[i]);
    }
    long max=1, maxNum=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++)
            if(num[i] > num[j])
                if(seq[i].size() < seq[j].size()+1) {
                    seq[i] = seq[j];
                    seq[i].push(num[i]);
                }
        if(max < seq[i].size()) {
            max = seq[i].size();
            maxNum = i;
        }
    }
    cout<<max<<"\n";
    while( !seq[maxNum].empty()) {
        cout<< seq[maxNum].front() << " ";
        seq[maxNum].pop();
    }
}
