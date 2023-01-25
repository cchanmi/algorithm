#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin>> n;
    int num[n], nge[n];
    for(int i=0; i<n; i++)
        cin >> num[i];
    stack<int> bigNum;
    bigNum.push(num[n-1]);
    for(int i=n-1; i>=0; i--) {
        if(num[i] >= bigNum.top()) {
            while (!bigNum.empty()) {
                if (num[i] >= bigNum.top())
                    bigNum.pop();
                else
                    break;
            }
            
            if (bigNum.empty())
                nge[i] = -1;
            else
                nge[i] = bigNum.top();
            bigNum.push(num[i]);
        } else {
            nge[i] = bigNum.top();
            bigNum.push(num[i]);
        }
    }
    for(int i=0; i<n; i++) {
        cout<< nge[i] << " ";
    }
}
