#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long num[n];
    long long sum[n];
    for(int i=0; i<n;i++) {
        cin >> num[i];
        sum[i] = num[i];
    }
    sum[0] = num[0];
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if (num[i] > num[j]) {
                if (sum[i] < sum[j] + num[i])
                    sum[i] = sum[j] + num[i];
            }
        }
    }
    long long max = 0;
    for(int i=0; i<n; i++)
        if (max < sum[i])
            max = sum[i];
    cout<< max;
}
