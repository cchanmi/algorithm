#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 10000

int t;
int start, dest;
queue<int> iQueue;
queue<string> sQueue;
set<int> numSet;
int d[4];
bool visited[MAX];

int calDSLRNum(int i, int num) {
    int result = 0;
    if (i==0) {
        result = (2*num)%10000;
    } else if (i==1) {
        num -= 1;
        if (num < 0) num = 9999;
        result = num;
    } else if (i==2) {
        result = num*10%10000+num/1000;
    } else if (i==3) {
        result = num/10 + num%10*1000;
    }
    return result;
}

char calDSLRString(int i) {
    if (i==0) return 'D';
    else if (i==1) return 'S';
    else if (i==2) return 'L';
    else return 'R';
}

string dslr() {
    int count = 10000;
    while (count--) {
        int preNum = iQueue.front();
        string preString = sQueue.front();
        iQueue.pop();
        sQueue.pop();
        for(int i=0; i<4; i++) {
            int curNum = calDSLRNum(i, preNum);
            if (visited[curNum]) continue;
            if(curNum == dest) return preString + calDSLRString(i);
            iQueue.push(curNum);
            sQueue.push(preString + calDSLRString(i));
            visited[curNum] = true;
        }
    }
    return "";
}

int main() {
    FAST;
    cin >> t;
    while (t--) {
        memset(visited, false, sizeof(visited));
        while (!iQueue.empty()) iQueue.pop();
        while (!sQueue.empty()) sQueue.pop();
        cin >> start >> dest;
        iQueue.push(start);
        sQueue.push("");
        visited[start] = true;
        cout << dslr() << "\n";
    }
}
