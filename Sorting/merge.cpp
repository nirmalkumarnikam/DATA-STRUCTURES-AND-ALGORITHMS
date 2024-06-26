#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>&arr, int i, int mid, int j){
    int arr1Index = i;
    int arr2Index = mid+1;

    vector<int>merged;

    while(arr1Index <= mid && arr2Index <= j){
        if(arr[arr1Index]<arr[arr2Index])
        {
            merged.push_back(arr[arr1Index]);
            arr1Index++;
        }
        else
        {
            merged.push_back(arr[arr2Index]);
            arr2Index++;
        }
    }

    while(arr1Index <= mid)
    {
        merged.push_back(arr[arr1Index]);
        arr1Index++;
    }
    while(arr2Index <= j)
    {
        merged.push_back(arr[arr2Index]);
        arr2Index++;
    }

    for(int k=0 ; k<merged.size() ; k++){
        arr[i]=merged[k];
        i++;
    }
}

void mergesort(vector<int>&arr, int i, int j){
    if(i>=j)return;
    int mid = (i+j)/2;

    mergesort(arr, i, mid);
    mergesort(arr,mid+1,j);
    // cout<<i+"   "+j;
    merge(arr,i, mid, j);
}

int main(){
    vector<int>arr{4,3,6,8,3,2,5,3,2,6,29,6,9,0};
    int n = arr.size();

    mergesort(arr, 0, n-1);

    for(int i = 0; i< n; i++){
        cout<< arr[i]<<"  ";
    }

    return 0;
}