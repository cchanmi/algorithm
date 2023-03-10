#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>> n;
    int num[n+1];
    num[0] = 0;
    for(int i=1; i<=n; i++)
        cin >>num[i];
    int idx = n;
    while (num[idx-1] > num[idx])
        idx--;
    if(idx == 1) {
        cout<< -1;
        return 0;
    }
    int minNum = 10001, minIdx =0;
    for(int i=idx; i<=n; i++)
        if (minNum > num[i] &&  num[i] > num[idx-1]) {
            minNum = num[i];
            minIdx = i;
        }
    swap(num[idx-1], num[minIdx]);
    sort(num+idx, num+n+1);
    for(int i=1; i<=n; i++)
        cout<<num[i] << " ";
    cout<<"\n";
}
