#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int num[n];
    int increase[n], decrease[n];
    for (int i=0; i<n; i++)
        cin>> num[i];
    increase[0] = 1;
    decrease[n-1] = 1;
    for(int i=1; i<n; i++) {
        increase[i] = 1;
        decrease[n-1-i] = 1;
        for(int j=0; j<i; j++) {
            if (num[j] < num[i])
                if (increase[j] > increase[i]-1)
                    increase[i] = increase[j]+1;
            if (num[n-1-j] < num[n-1-i])
                if (decrease[n-1-j] > decrease[n-1-i]-1)
                    decrease[n-1-i] = decrease[n-1-j]+1;
        }
    }
    int max = 0;
    for(int i=0; i<n; i++)
        if (max < increase[i] + decrease[i] - 1)
            max = increase[i] + decrease[i] - 1;
    
    cout<<max<<"\n";
}
