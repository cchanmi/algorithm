#include <iostream>

using namespace std;

int main() {
    string str;
    int small, big, num, blank;
    while (getline(cin, str)) {
        small = 0;
        big = 0;
        num = 0;
        blank = 0;
        for(int j=0; j<str.size(); j++) {
            if(str[j] >= 'a' && str[j] <= 'z') small++;
            else if(str[j] >= 'A' && str[j] <= 'Z') big++;
            else if (str[j] >='0' && str[j] <= '9') num++;
            else if(str[j] == ' ') blank++;
        }
        cout<< small << " " << big << " " << num << " " << blank << "\n";
    }
}
