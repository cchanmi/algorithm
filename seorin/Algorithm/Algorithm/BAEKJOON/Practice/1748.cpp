#include <iostream>

using namespace std;

int main() {
    long n;
    cin>> n;
    int ans=0, add = 1, div = 9;
    long check = 1;
    while(n >= check) {
        check *= 10;
        if(n >= check) {
            ans += div * add;
            div *= 10;
            add++;
        } else {
            ans += (n-check/10+1)*add;
        }
    }
    
    cout<<ans<<"\n";
}
