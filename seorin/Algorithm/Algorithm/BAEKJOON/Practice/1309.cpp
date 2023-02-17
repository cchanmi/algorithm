#include <iostream>

using namespace std;

int main() {
    int n;
    cin>> n;
    long long left, right, gap;
    long long backLeft = 0, backRight = 0, backGap = 1;
    
    for(int i=0; i<n; i++) {
        left = backRight + backGap;
        right = backLeft + backGap;
        gap = backLeft + backRight + backGap;
        backLeft = left % 9901;
        backRight = right % 9901;
        backGap = gap % 9901;
    }
    
    cout<< (left + right + gap) % 9901 << "\n";
}
