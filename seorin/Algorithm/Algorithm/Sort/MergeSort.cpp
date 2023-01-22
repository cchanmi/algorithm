// 아래 코드 꼭 보기
#include <iostream>
using namespace std;

const long MAX_SIZE = 1000000;
int sorted[MAX_SIZE];


void sort(int num[], long start, long end){
    int gar;
    if(end-start < 2 ){
        if(num[start] > num[end]){
            gar = num[start];
            num[start] = num[end];
            num[end] = gar;
        }
        return;
    }
    long middle = (start + end) /2;
    sort(num, start, middle);
    sort(num, middle+1, end);
    long left = start, right = middle+1;
    
    for(long i=start; i<= end; i++){
        if((num[left] < num[right] && left < middle+1) || right > end){
            sorted[i] = num[left];
            left++;
        }else{
            sorted[i] = num[right];
            right++;
        }
    }
    for(long i=start; i<= end; i++){
        num[i] = sorted[i];
    }
}

int main(){
    long n;
    cin >> n;
    int num[n];
    
    for(int i = 0 ; i<n; i++){
        cin>> num[i];
    }
    sort(num, 0, n-1);

    for(int i = 0 ; i<n; i++){
        cout <<num[i] << "\n";
    }
}
