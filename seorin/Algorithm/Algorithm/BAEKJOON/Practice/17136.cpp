#include <iostream>
#include <algorithm>

using namespace std;

int ans = 30;
int colorPaper[5] = {0};
int paper[10][10] = {0};
bool isAllZero = true;

void checkPaper() {
    if(colorPaper[0]>5 || colorPaper[1]>5 ||colorPaper[2]>5 ||colorPaper[3]>5 ||colorPaper[4]>5) return;
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {   //하나씩 검사 시작
            if(paper[i][j] == 1) { // 만약 1이 발견되면
                for(int l=0; l<5; l++) {
                    bool isSmall = true;
                    if(i+l>9 || j+l>9) isSmall = false;
                    for(int n=0; n<=l; n++)
                        for(int m=0; m<=l; m++)
                            if(paper[i+n][j+m] == 0) isSmall = false;
                    if (isSmall) {  // l 사이즈가 가능하다면
                        colorPaper[l]++;   // l 색종이 추가하고, 해당 영역 색칠
                        for(int n=0; n<=l; n++)
                            for(int m=0; m<=l; m++)
                                paper[i+n][j+m] = 0;
                        checkPaper();
                        // 다음 케이스를 위해 복구해놓기
                        for(int n=0; n<=l; n++)
                            for(int m=0; m<=l; m++)
                                paper[i+n][j+m] = 1;
                        colorPaper[l]--;
                    } else return;
                }
            }
        }
    }
    int colorPaperNum = 0;
    for(int i=0; i<5; i++) {
        if ( colorPaper[i] > 5) colorPaperNum = 30;
        else colorPaperNum += colorPaper[i];
    }
    if (colorPaperNum == 0) return;
    ans = min(ans, colorPaperNum);
}

int main() {
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++) {
            cin >> paper[i][j];
            if ( paper[i][j] == 1 ) isAllZero = false;
        }
    if (isAllZero) {
        cout << 0;
        return 0;
    }
    checkPaper();
    if (ans > 25) ans = -1;
    cout << ans << "\n";
}
