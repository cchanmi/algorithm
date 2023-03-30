#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

string p, str;
int t, n, dNum;
bool isReverse;
deque<int> x;

void input() {
    cin >> p >>n >> str;
    int num = -1;
    x.clear();
    for(auto o : str)
        if (isdigit(o)) {
            if(num == -1) num = 0;
            num *= 10;
            num += o - '0';
        } else {
            if(num != -1) x.push_back(num);
            num = -1;
        }
    dNum=0;
    for(auto o : p) if(o == 'D') dNum++;
}

int main() {
    cin>>t;
    while (t--) {
        input();
        if (dNum>x.size()) {
            cout << "error\n";
            continue;
        }
        isReverse = false;
        for(int i=0; i<p.size(); i++) {
            if(p[i] == 'R')
                isReverse = isReverse ? false : true;
            else
                if (!isReverse) x.pop_front();
                else x.pop_back();
        }
        if(!isReverse) {
            if(x.size() ==0) {
                cout<<"[]\n";
                continue;
            }
            cout << "[";
            for(int i=0; i<x.size()-1; i++) {
                cout << x[i];
                cout << ",";
            }
            cout<<x[x.size()-1];
            cout<<"]\n";
        } else {
            if(x.size() ==0) {
                cout<<"[]\n";
                continue;
            }
            cout << "[";
            for(int i=x.size()-1; i>0; i--) {
                cout << x[i];
                cout << ",";
            }
            cout<<x[0];
            cout<<"]\n";
        }
    }
}

