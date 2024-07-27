//ek node ko uske sahi jagah par leke jana heapify fn ka kaam hai.
// TC: O(n)

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

int main(){
    int arr[6] = {-1, 34,34,65,3,66};
    int n = 5;
    cout<<"Given arr: ";
    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    for(int i = n/2; i>0; i--){
        heapify(arr, n, i);
    }

    cout<<"Heapified arr: ";
    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    return 0;
}

//     65
//  66    34 
// 3   34