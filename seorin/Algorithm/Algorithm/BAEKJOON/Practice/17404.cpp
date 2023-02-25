#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;
    int rgb[1000][3];
    long charge[1000][3] = {0}; // !!
    for(int i=0; i<n; i++)
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    long minCharge = 1000000;
    
    for(int j=0; j<3; j++) {
        
        for(int k=0; k<3; k++) {
            charge[0][k] = 1000000;
            if(k==j) charge[0][k] = rgb[0][k];
        }
        for(int i=1; i<n; i++) {
            charge[i][0] = rgb[i][0] + min(charge[i-1][1], charge[i-1][2]);
            charge[i][1] = rgb[i][1] + min(charge[i-1][0], charge[i-1][2]);
            charge[i][2] = rgb[i][2] + min(charge[i-1][0], charge[i-1][1]);
        }
        for(int k=0; k<3; k++) {
            if(k==j) continue;
            if(charge[n-1][k] < minCharge)
                minCharge = charge[n-1][k];
        }
    }
    cout<< minCharge;
}
