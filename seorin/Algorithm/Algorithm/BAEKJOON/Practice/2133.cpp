#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n%2==1) {
        cout << 0 << endl;
        return 0;
    }
    long first[n+1], second[n+1], third[n+1];
    first[2] = 1;
    second[2]= 1;
    third[2] = 1;
    for(int i=4; i<=n; i += 2) {
        first[i] = first[i-2] + second[i-2] + third[i-2];
        second[i] = first[i-2] + 2*second[i-2] + third[i-2];
        third[i] = first[i-2] + second[i-2] + 2*third[i-2];
    }
    cout << first[n] + second[n] + third[n] << "\n";
}
