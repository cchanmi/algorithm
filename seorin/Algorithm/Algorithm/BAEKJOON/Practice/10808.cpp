#include <iostream>

using namespace std;

int main() {
    int alpha[26] = {0};
    string word;
    getline(cin, word);
    for(int i=0; i<word.size(); i++)
        alpha[word[i] - 'a']++;
    for(int i=0; i<26; i++)
        cout<< alpha[i] << " ";
}
