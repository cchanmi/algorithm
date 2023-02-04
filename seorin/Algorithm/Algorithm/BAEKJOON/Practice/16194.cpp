#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int card[n+1];
    card[0] = 0;
    for(int i=1; i<n+1; i++)
        cin>>card[i];
    int min;
    for(int i=1; i<=n; i++) {
        min = card[i];
        for(int j=0; j<=i/2; j++) {
            if (min > card[j] + card[i-j])
                min = card[j] + card[i-j];
        }
        card[i] = min;
    }
    cout<<card[n];
}
