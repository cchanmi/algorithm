#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;
int salePer[7];

#define MAX_SALE_PER 40
#define MIN_SALE_PER 10

int minSalePer = 40, maxSalePer = 0;


void input(vector<vector<int>> &users, vector<int> &emoticons) {
    for  (int i=0; i<emoticons.size(); i++)
        salePer[i] = MIN_SALE_PER;
    return;
}

vector<int> getResult(
    vector<vector<int>> &users, 
    vector<int> &emoticons) {
    int userCount = 0, buyAmount = 0;
    for (int i=0; i<users.size(); i++) {
        int buyMoneyAmount = 0;
        for (int j=0; j<emoticons.size(); j++) {
            if (users[i][0] <= salePer[j])
                buyMoneyAmount += emoticons[j] * (100 - salePer[j]) / 100;
        }
        if (users[i][1] <= buyMoneyAmount) {
            for (int k=0; k<emoticons.size(); k++) {
                cout  << "salePer  [" << k << "]  :  "<< salePer[k] << "\n";
            }
            cout << "buyMoneyAmount : " << buyMoneyAmount << "\n";
            userCount++;
        } else  {
            for (int k=0; k<emoticons.size(); k++) {
                cout  << "salePer  [" << k << "]  :  "<< salePer[k] << "\n";
            }
            cout << "buyMoneyAmount : " << buyMoneyAmount << "\n\n";
            buyAmount += buyMoneyAmount;
        }
    }
    cout <<  "userCount : " << userCount << "\n";
    cout <<  "buyAmount : " << buyAmount << "\n";

    cout << "\n\n";
    vector<int> answer;
    answer.push_back(userCount);
    answer.push_back(buyAmount);   
    return answer;
}

void dfs(
    int minIndex,
    vector<vector<int>> &users, 
    vector<int> &emoticons,
    vector<int> &answer
    ) {
    vector<int> findAnswer = getResult(users, emoticons);
    if (answer[0] < findAnswer[0]) {
        answer[0] = findAnswer[0];
        answer[1] = findAnswer[1];
    } else if (answer[0] == findAnswer[0]) {
        answer[1] = max(answer[1], findAnswer[1]);
    }
    
    
    for(int i=minIndex; i< emoticons.size(); i++) {
        if (salePer[i]<MAX_SALE_PER) {
            salePer[i] += 10;
            dfs(i, users, emoticons, answer);
            salePer[i] -= 10;
        }
    }
    return;
}

vector<int> solution(
    vector<vector<int>> users, 
    vector<int> emoticons
    ) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    input(users, emoticons);
    dfs(0, users, emoticons, answer);
    return answer;
}

int main () {
    vector<vector<int>> users;
    vector<int> emoticons;
    vector<int> userInfo;
    /**
     * 1 
    */

    userInfo.push_back(40);
    userInfo.push_back(10000);
    users.push_back(userInfo);
    userInfo.clear();

    userInfo.push_back(25);
    userInfo.push_back(10000);
    users.push_back(userInfo);
    userInfo.clear();

    emoticons.push_back(7000);
    emoticons.push_back(9000);



   /**
    * 2
   */
  /*
    userInfo.push_back(40);
    userInfo.push_back(2900);
    users.push_back(userInfo);
    userInfo.clear();

    userInfo.push_back(23);
    userInfo.push_back(10000);
    users.push_back(userInfo);
    userInfo.clear();

    userInfo.push_back(11);
    userInfo.push_back(5200);
    users.push_back(userInfo);
    userInfo.clear();

    userInfo.push_back(5);
    userInfo.push_back(5900);
    users.push_back(userInfo);
    userInfo.clear();


    userInfo.push_back(27);
    userInfo.push_back(9200);
    users.push_back(userInfo);
    userInfo.clear();

    userInfo.push_back(40);
    userInfo.push_back(3100);
    users.push_back(userInfo);
    userInfo.clear();

    userInfo.push_back(32);
    userInfo.push_back(6900);
    users.push_back(userInfo);
    userInfo.clear();




    emoticons.push_back(1300);
    emoticons.push_back(1500);
    emoticons.push_back(1600);
    emoticons.push_back(4900);
    */
    
    vector<int> answer = solution(users, emoticons);
    for (int i=0; i<answer.size(); i++) {
        cout << answer[i] << "  ";
    }
    cout << "\n";
}