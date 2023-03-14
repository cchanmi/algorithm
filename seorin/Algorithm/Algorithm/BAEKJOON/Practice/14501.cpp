#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int t[17], p[17], revenue[17] = {0};
    
    cin>>n;
    for(int i=1; i<=n;i++)
        cin>> t[i] >> p[i];
    
    for(int i=1; i<=n+1; i++) {
        for(int j=1; j<i; j++)
            if (j+t[j]-1 < i)
                revenue[i] = max( revenue[i], revenue[j] + p[j]);
        revenue[i] = max(revenue[i], revenue[i-1]);
    }
    cout<< revenue[n+1];
}
