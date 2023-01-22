#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){
    queue<char> bracketWord;
    stack<char> reverseWord;
    string word;
    getline(cin, word);
    for(int i=0; i<word.size(); i++) {
        if(word[i] == '<') {
            while (word[i] != '>') {
                bracketWord.push(word[i]);
                i++;
            }
            bracketWord.push(word[i]);
            while (!bracketWord.empty()) {
                cout<<bracketWord.front();
                bracketWord.pop();
            }
        } else {
            while (word[i] != ' ' && word[i] != '<' && i<word.size()) {
                reverseWord.push(word[i]);
                i++;
            }
            while (!reverseWord.empty()) {
                cout<<reverseWord.top();
                reverseWord.pop();
            }
            if( word[i] == ' ')
                cout << word[i];
            else
                i--;
        }
    }
}
