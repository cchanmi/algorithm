#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    double e, s, m;
    cin>> e >> s >> m;
    int i = 0;
    while(1) {
        double j = (15*i+e-s) / 28;
        double k = (15*i+e-m) / 19;
        if(j - (int)j == 0)
            if((k - (int)k == 0))
                break;
        i++;
    }
    cout<< 15*i + e <<"\n";
}
