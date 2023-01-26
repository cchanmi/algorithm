#include <iostream>
#include <stack>

using namespace std;

int main() {
    string notation;
    getline(cin, notation);
    notation = '(' + notation + ')';
    
    stack<char> oper;
    string postfixNotation;
    for(int i=0; i<notation.size();i++) {
        char word = notation[i];
        if(word == '+' || word == '-') {
            while (oper.top() != '(') {
                postfixNotation.push_back(oper.top());
                oper.pop();
            }
            oper.push(word);
        } else if (word == '*' || word == '/') {
            while (oper.top() != '(' && oper.top() != '+' && oper.top() != '-') {
                postfixNotation.push_back(oper.top());
                oper.pop();
            }
            oper.push(word);
        } else if (word == '(') {
            oper.push(word);
        } else if (word == ')') {
            while (oper.top() != '(') {
                postfixNotation.push_back(oper.top());
                oper.pop();
            }
            oper.pop();
        } else {
            postfixNotation.push_back(word);
        }
    }
    cout<<postfixNotation<<"\n";
}
