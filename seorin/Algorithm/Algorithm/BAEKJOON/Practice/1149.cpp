#include <iostream>
#include <queue>

using namespace std;


int main(){
    int n;
    cin>> n;
    int curR, curG, curB;
    long r = 0, g = 0, b = 0;
    for(int i=0;i<n; i++) {
        cin >> curR >> curG >> curB;
        curR += min(g, b);
        curG += min(r, b);
        curB += min(r, g);
        r = curR;
        g = curG;
        b = curB;
    }
    long minSum;
    if (r <= g && r <= b)
        minSum = r;
    else if ( g <= r && g <= b)
        minSum = g;
    else
        minSum = b;
    cout<<minSum<<"\n";
}
