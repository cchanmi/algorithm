#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[8];

int gap(int a, int b) {
    if (a>b) return a-b;
    else return b-a;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> num[i];
    sort(num, num+n, greater<>());
    int sum = 0;
    if (n  % 2 == 0) {
        for(int i=0; i<n/2-1; i++)
            sum += 2*num[i];
        for(int i=n/2+1; i<n; i++)
            sum -= 2*num[i];
        sum += gap(num[n/2-1], num[n/2]);
    } else {
        for(int i=0; i<n/2-1; i++)
            sum += 2*num[i];
        for(int i=n/2+2; i<n; i++)
            sum -= 2*num[i];
        sum += max(gap(num[n/2-1], num[n/2]), gap(num[n/2+1], num[n/2]));
        sum += gap(num[n/2+1], num[n/2-1]);
    }
    
    cout<<sum << "\n";
}
