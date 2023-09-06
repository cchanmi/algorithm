#include <iostream>

#define MAX_N 2001
#define MAX_M 1000000

using namespace std;

int n, m;
int num[MAX_N];
int pel[MAX_N];

void input() {
    cin >> n;
    for (int i =1; i<=n;i++) {
        cin >> num[i];
    }
    pel[1] = 0;
    pel[n] = 0;
    for (int i =1; i<=n;i++) {
        int j=0;
        while (i-j>0 &&  i+j<=n) {
            if(num[i-j] == num[i+j]) {
                pel[i] = j;
                j++;
            } else break;
        }
    }
    cin >> m;
}

int solve(int a, int b) {
    if ( pel[(a+b)/2] >= b-(a+b)/2 ) {
        return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    input();
    int  a, b;
    while(m--) {
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }

}