#include <bits/stdc++.h>

using namespace std;

int solve(long long num) {
    int n = 0;
    queue<bool> node;
    long long temp;
    temp = pow(2, n);
    while (num > temp) {
        n++;
        temp = pow(2, n);
    }
    while (num < temp) {
        n--;
        temp = pow(2, n);
    }
    if (n%2 == 1)  {
        node.push(false);
    }
    while(n>=0) {
        if (temp <= num) {
            num -= temp;
            node.push(true);
        } else {
            node.push(false);
        }
        n--;
        temp = pow(2, n);
    }
    while (!node.empty()) {
        node.pop();
        if (node.empty()) break;
        if(!node.front()) {
            return false;
        }
        node.pop();
    }
    return true;
}

int main () {
    vector<long long> numbers;
    numbers.push_back(7);
    numbers.push_back(42);
    numbers.push_back(63);
    numbers.push_back(111);


    numbers.push_back(95);
    numbers.push_back(5);

    for(int  i=0; i< numbers.size(); i++) {
        cout << solve(numbers[i]) << "\n";
    }
}