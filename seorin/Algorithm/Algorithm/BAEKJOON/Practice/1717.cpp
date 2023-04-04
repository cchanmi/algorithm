#include <iostream>
#include <algorithm>

using namespace std;

int set[1000001];

int getParent(int num) {
    if (num == set[num]) return num;
    set[num] = getParent(set[num]);
    return set[num];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    int oper, a, b, temp;
    cin >> n >> t;
    for(int i=0; i<=n; i++) set[i] = i;
    while (t--) {
        cin >> oper >> a >> b;
        if (oper == 0) {
            b = getParent(b);
            a = getParent(a);
            if(a<b) set[b] = a;
            else set[a] = b;
        } else {
            a = getParent(a);
            b = getParent(b);
            if (a==b) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
