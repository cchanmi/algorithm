#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool visitNum[10] = {false};
int k;
string a;
vector<long> numList;
vector<int> num;

bool compare(int a, char oper, int b) {
    switch (oper) {
        case '<':
            if(a<b) {
                return true;
            }
            break;
        case '>':
            if(a>b) {
                return true;
            }
            break;
        default: break;
    }
    return false;
}

void dfs(int depth) {
    if (depth == k+1) {
        long rightNum = 0;
        for(int i=0; i<num.size(); i++) {
            rightNum *= 10;
            rightNum += num[i];
        }
        numList.push_back(rightNum);
    } else {
        for(int i=0; i<10; i++) {
            if(visitNum[i]) continue;
            if(compare(num[depth-1], a[depth-1], i)) {
                visitNum[i] = true;
                num.push_back(i);
                dfs(depth+1);
                num.pop_back();
                visitNum[i] = false;
            }
        }
    }
}


int main() {
    cin >> k;
    cin.ignore();
    getline(cin, a);
    a.erase(remove(a.begin(), a.end(), ' '), a.end());
    for(int i=0; i<10; i++) {
        num.push_back(i);
        visitNum[i] = true;
        dfs(1);
        visitNum[i] = false;
        num.pop_back();
    }
    
    sort(numList.begin(), numList.end());
    cout.width(k+1);
    cout.fill('0');
    cout << numList[numList.size()-1] << "\n";
    cout.width(k+1);
    cout.fill('0');
    cout << numList[0] << "\n";
}
