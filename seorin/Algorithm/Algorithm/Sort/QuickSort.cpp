#include <iostream>
using namespace std;

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void quickSort(int arr[], int left, int right){
    if(left >= right) return;
    int middle = (left + right)/2;
    swap(arr, left, middle);
    int i = left, j = right, pivot = arr[left];
    while(i < j){
        while (i<j && arr[j]>pivot) j--;
        while (i<j && arr[i]<= pivot) i++;
        swap(arr, i, j);
    }
    swap(arr, left, i);
    
    quickSort(arr, left, i-1);
    quickSort(arr, i+1, right);
}

void quickSort_main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i< n;i++)
        cin >> arr[i];
    
    quickSort(arr, 0, n-1);
    
    for(int i=0; i< n;i++)
        cout<<arr[i] << endl;
}
