#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin>>n;
    int num[n], ngf[n], appear[10000001] = {0};
    for(int i=0; i<n; i++) {
        cin>>num[i];
        appear[num[i]]++;
    }
    stack<int> oftenNum;
    
    oftenNum.push(num[n-1]);
    for(int i=n-1; i>=0; i--) {
        ngf[i] = -1;
        while (!oftenNum.empty()) {
            if(appear[num[i]] >= appear[oftenNum.top()])
                oftenNum.pop();
            else {
                ngf[i] = oftenNum.top();
                break;
            }
        }
        oftenNum.push(num[i]);
    }
    
    for(int i=0; i<n; i++) {
        cout<<ngf[i]<<" ";
    }
}
