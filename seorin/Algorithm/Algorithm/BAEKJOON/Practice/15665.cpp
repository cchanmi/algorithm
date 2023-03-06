#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m, n;
vector<int> num;
int seq[7];

void dfs(int depth) {
    if (depth >= m) {
        for(int i=0; i<m; i++)
            cout <<seq[i] << " ";
        cout<<"\n";
        return;
    } else {
        for(int i=0; i<num.size(); i++) {
            seq[depth] = num[i];
            dfs(depth+1);
        }
    }
    return;
}

int main() {
    cin>> n >> m;
    int number;
    for(int i=0; i<n; i++) {
        cin>> number;
        num.push_back(number);
        for(int j=0; j<num.size()-1; j++)
            if (number == num[j]) {
                num.pop_back();
                break;
            }
    }
    sort(num.begin(), num.end());
//    for(int i=0; i<num.size(); i++)
//        cout<<num[i]<<"\n";
    dfs(0);
}
