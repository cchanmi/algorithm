#include <iostream>
#include <algorithm>

using namespace std;


int l,c;
char word[15], password[15];
bool visitWord[15] = {false};

bool isRightPW(char word[]) {
    int consonant=0, vowel=0;
    for(int i=0; i<l; i++)
        if ( word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u') vowel++;
        else consonant++;
    if (consonant >= 2 && vowel >=1) return true;
    else return false;
}

void dfs(int depth, int leastWord) {
    if (depth == l) {
        if (isRightPW(password)) {
            for(int i=0; i<l; i++)
                cout<< password[i];
            cout << "\n";
        }
    } else {
        for(int i=leastWord; i<c; i++) {
            if( visitWord[i] == true) continue;
            // 추가하고 1을 올려주는 개념이니까   0부터 시작하면  하나 추가하면 ( 추가 됐다면 ) 1, 두 개 추가하면 2 이렇게 될 것임!
            password[depth] = word[i];
            visitWord[i] = true;
            dfs(depth+1, i+1);
            visitWord[i] = false;
        }
    }
}


int main() {
    cin >> l >> c;
    for(int i=0; i<c; i++)
        cin>>word[i];
    sort(word, word+c);
    dfs(0, 0);
}
