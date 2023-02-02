#include <iostream>

using namespace std;

int main() {
    int n, max;
    cin>>n;
    int card[n+1];
    card[0] = 0;
    for(int i=1; i<=n; i++)
        cin>>card[i];
    for(int i=1; i<=n;i++) {
        max = 0;
        for(int j=0; j<=i/2; j++)
            if(max < card[j] + card[i-j])
                max = card[j] + card[i-j];
        card[i] = max;
    }
    cout<< card[n];
}
