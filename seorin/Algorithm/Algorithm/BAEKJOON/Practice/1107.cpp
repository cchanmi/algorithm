#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int wrong[10];
int m;

// 해당 채널이 리모컨으로 눌리는지 알려주는 함수
bool isRightNum(long num) {
    do {
        for(int i=0; i<m; i++)
            if (wrong[i] == num%10)
                return false;
        num /= 10;
    } while(num != 0);
    return true;
}

int main() {
    long n;
    long num;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin>>wrong[i];
    }
    long ans = abs(n - 100);
    long bigNum = n, smallNum = n;
    while(1) {
        if(bigNum > 1000001)
            break;
        if (isRightNum(bigNum))
            break;
        bigNum++;
    }
    while(1) {
        if(smallNum < 0) {
            smallNum = 1000001;
            break;
        }
        if (isRightNum(smallNum))
            break;
        smallNum--;
    }
    int digit = 1;
    num = bigNum/10;
    while(num != 0) {
        num /= 10;
        digit++;
    }
    bigNum = abs(bigNum - n) + digit;

    digit = 1;
    num = smallNum/10;
    while(num != 0) {
        num /= 10;
        digit++;
    }
    smallNum = abs(smallNum - n) + digit;
    
    ans = min(ans, bigNum);
    ans = min(ans, smallNum);
    cout<<ans<<"\n";
    
}
