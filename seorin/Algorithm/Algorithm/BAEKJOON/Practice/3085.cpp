#include <iostream>
#include <algorithm>

using namespace std;

int n;
char candy[52][52];

int eatCandy(int i, int j) {
    int ans = 1;
    int eat=1;
    for(int k=1; k<=n; k++)
        if(candy[i][k-1] == candy[i][k]) {
            eat++;
            ans = max(eat, ans);
        }
        else eat=1;
    for(int k=1; k<=n; k++)
        if(candy[k-1][j] == candy[k][j]) {
            eat++;
            ans = max(eat, ans);
        }
        else eat=1;
    return ans;
}

int main() {
    int ans=1;
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> candy[i][j];
    
    for(int i=1; i<=n; i++) {
        for(int j=1;j<=n;j++) {
            swap(candy[i][j], candy[i-1][j]);
            ans = max(ans, eatCandy(i, j));
            swap(candy[i][j], candy[i-1][j]);
            swap(candy[i][j], candy[i+1][j]);
            ans = max(ans, eatCandy(i, j));
            swap(candy[i][j], candy[i+1][j]);
            swap(candy[i][j], candy[i][j-1]);
            ans = max(ans, eatCandy(i, j));
            swap(candy[i][j], candy[i][j-1]);
            swap(candy[i][j], candy[i][j+1]);
            ans = max(ans, eatCandy(i, j));
            swap(candy[i][j], candy[i][j+1]);
        }
    }
    cout<<ans<<"\n";
}
