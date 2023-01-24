#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin>> n;
    string notation;
    int num[n];
    cin.ignore();
    getline(cin, notation);
    for(int i=0; i<n; i++)
        cin >> num[i];
    stack<double> result;
    for(int i=0; i<notation.size(); i++) {
        char oper = notation[i];
        if (oper == '+' || oper == '-' || oper == '*' || oper == '/') {
            double secondNum = result.top();
            result.pop();
            double firstNum = result.top();
            result.pop();
            if ( oper == '+') {
                result.push(firstNum + secondNum);
            } else if (oper == '-') {
                result.push(firstNum - secondNum);
            } else if (oper == '*') {
                result.push(firstNum*secondNum);
            } else if (oper == '/') {
                result.push(firstNum/secondNum);
            }
        } else {
            result.push(num[oper-'A']);
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout<<result.top()<<"\n";
}
