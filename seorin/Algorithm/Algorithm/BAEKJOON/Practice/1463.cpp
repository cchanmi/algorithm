#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int number[n+1];
    number[0] = 0;
    number[1] = 0;
    number[2] = 1;
    number[3] = 1;
    int num1, num2, num3;
    for(int i=4; i<=n; i++) {
        num1 = i;
        num2 = i;
        num3 = i;
        if (i % 3 == 0) num1 = number[i/3] + 1;
        if (i % 2 == 0) num2 = number[i/2] + 1;
        num3 = number[i-1] + 1;
        
        if(num1 <= num2 && num1 <= num3) number[i] = num1;
        else if(num2 <= num1 && num2 <= num3) number[i] = num2;
        else number[i] = num3;
    }
    cout<< number[n];
}
