#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int num[7];
void printNum(int depth) {
    if (depth == m) {
        for(int i=0; i<m; i++)
            cout <<num[i] << " ";
        cout<<"\n";
        return;
    } else {
        for(int i=1; i<=n; i++) {
            num[depth] = i;
            printNum(depth+1);
        }
    }
    return;
}
int main() {
    cin>> n >> m;
    printNum(0);
}
