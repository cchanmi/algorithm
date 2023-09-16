#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100001

int a, p;
stack<int> squence;
set<int> numSet;

int calNum(int num) {
    int result = 0;
    while (num != 0) {
        result += pow((num%10), p);
        num/=10;
    }
    return result;
}

int main() {
    FAST;
    cin >> a >> p;
    squence.push(a);
    numSet.insert(a);
    a = calNum(a);
    
    while (numSet.find(a) == numSet.end() && a != squence.top()) {
        squence.push(a);
        numSet.insert(a);
        a = calNum(a);
    }
    
    
    while (squence.top()!=a && squence.size()>=0) {
        squence.pop();
    }
    
    if (squence.top() == a)
        squence.pop();
    cout << squence.size() << "\n";
}

