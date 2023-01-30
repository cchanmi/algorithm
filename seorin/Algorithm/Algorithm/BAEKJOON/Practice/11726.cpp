#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int squareNum[n+1];
    squareNum[0] = 1;
    squareNum[1] = 1;
    for(int i=2; i<=n; i++)
        squareNum[i] = (squareNum[i-2] + squareNum[i-1]) % 10007;
    cout<<squareNum[n];
}
