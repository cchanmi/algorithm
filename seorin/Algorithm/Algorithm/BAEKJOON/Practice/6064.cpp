#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    int m, n, x, y;
    cin >> t;
    int resultA, resultB, a, b;
    for(int i=0; i<t; i++) {
        cin >> m >> n >> x >> y;
        a = 0;
        b = 0;
        resultA = m*a + x;
        resultB = n*b + y;
        while (resultA != resultB) {
            if (resultA > resultB) {
                b++;
                resultB = n*b + y;
            }
            else {
                a++;
                resultA = m*a + x;
            }
            if(resultA> m*n && resultB > m*n) {
                resultA = -1;
                break;
            }
        }
        cout<<resultA << "\n";
    }
}

