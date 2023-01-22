#include <iostream>
using namespace std;

void selectionSort_main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i< n;i++)
        cin >> arr[i];
    
    int min, minIndex = 0;
    for(int i=0; i < n; i++){
        min = arr[i];
        minIndex = i;
        for(int j=i; j<n;j++)
            if(arr[j] < min ){
                min = arr[j];
                minIndex = j;
            }
        arr[minIndex] = arr[i];
        arr[i] = min;
        cout << min <<endl;
    }
}
