#include <iostream>
#include <stack>

using namespace std;

int main() {
    string task;
    stack<char> stick;
    getline(cin, task);
    int stickNum=0;
    for(int i=0; i<task.size();i++) {
        if (task[i]=='(') {
            stick.push(task[i]);
        } else {
            if(task[i-1] == '(') {
                stick.pop();
                stickNum += stick.size();
            } else {
                stick.pop();
                stickNum++;
            }
        }
    }
    cout<< stickNum;
}
