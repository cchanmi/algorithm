#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> startTeam, linkTeam;
int n, s[20][20];
bool isStartMember[20] = {false};
int ans = 10000000;

int teamGap() {
    int startState = 0, linkState = 0;
    bool isLinkMember;
    linkTeam.clear();
    for(int i=0; i<n; i++) {
        isLinkMember = true;
        for(int j=0; j<startTeam.size(); j++)
            if (i==startTeam[j]) isLinkMember = false;
        if(isLinkMember) linkTeam.push_back(i);
    }
    
    for(int i=0; i<n; i++) {
        if(isStartMember[i]) {
            for(int j=0; j<startTeam.size(); j++)
                startState += s[i][startTeam[j]];
        } else {
            for(int j=0; j<linkTeam.size(); j++)
                linkState += s[i][linkTeam[j]];
        }
    }
    return abs(startState-linkState);
}

void makeTeam(int startMemberNum, int depth, int leastNum) {
    if (startMemberNum == depth) {
//        for(int i=0; i<startTeam.size(); i++)
//            cout << startTeam[i] << " ";
//        cout << "\n";
        ans = min(ans, teamGap());
    } else {
        for(int i= leastNum; i<n; i++) {
            if (isStartMember[i]) continue;
            startTeam.push_back(i);
            isStartMember[i] = true;
            makeTeam(startMemberNum, depth+1, i);
            startTeam.pop_back();
            isStartMember[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> s[i][j];
    
    for(int i=1; i<=n/2; i++)
        makeTeam(i, 0, 0);
    cout << ans << "\n";
}
