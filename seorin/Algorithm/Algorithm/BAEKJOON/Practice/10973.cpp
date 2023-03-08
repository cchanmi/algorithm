#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>> n;
    int num[n+1];
    num[0] = 10001;
    for(int i=1; i<=n; i++)
        cin >>num[i];
    int idx = n;
    while (num[idx-1] < num[idx])
        idx--;
    if(idx == 1) {
        cout<< -1;
        return 0;
    }
    int maxNum = 0, maxIdx =0;
    for(int i=idx; i<=n; i++)
        if (maxNum < num[i] &&  num[i] < num[idx-1]) {
            maxNum = num[i];
            maxIdx = i;
        }
    swap(num[idx-1], num[maxIdx]);
    sort(num+idx, num+n+1, greater<>());
    for(int i=1; i<=n; i++)
        cout<<num[i] << " ";
    cout<<"\n";
}

