#include <iostream>
#include <algorithm>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = i*2;
    int right = i*2+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        swap(arr[size], arr[1]);
        size--;

        heapify(arr,size, 1);
    }
}

int main(){
    int arr[6] = {-1, 66, 34, 65, 3, 34};
    int n = 5;
    heapSort(arr, n);

    cout<<"HeapSorted arr: ";
    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}