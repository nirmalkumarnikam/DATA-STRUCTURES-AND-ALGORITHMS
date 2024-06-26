/*
Merge Sort:
    based on divide and concour.


    Example: 
        Initial: 
                          {15, 5, 24, 8, 1, 3, 16, 10, 20}
                         /                                \
                {15, 5, 24, 8, 1}                        {3, 16, 10, 20}
                    /          \                         /              \
                {15, 5, 24}    {8, 1}                 {3, 16}         {10, 20}
                   /      \      /    \               /     \           /   \
                {15, 5}  {24}   {8} {1}               {3} {16}        {10} {20}
                 /   \     |     |   |                 |   |           |     |
                {15} {5}  {24}  {8} {1}              {3} {16}         {10} {20}
                 \    /    |     \   /                 \   /            \   /
                {5, 15}  {24}   {1, 8}                {3, 16}         {10, 20}
                   \      /       |                      |                |   
                {5, 15, 24}     {1, 8}                  {3, 16}       {10, 20}
                      \           /                         \            /
                    {1, 5, 8, 15, 24}                      {3, 10, 16, 20}
                             \                             /
                            {1, 3, 5, 8, 10, 15, 16, 20, 24}


Time Complexity: O(n log n)
Space Complexity:O(n)

*/

/*
Algo:
1)mergesort fun: divide karo
    recursively call mergesort 2 functions (l -> m) and (m+1 -> r)
    call merge function (l, m, r)
2)merge function:
    make 2 temp arr and fill values from (l -> m) and (m+1 -> r) in both
    using the 'merge two sorted array approach' merge them
*/  
    


// CODE:



#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>&arr, int i, int mid, int j){
    int arr1Index = i;
    int arr2Index = mid+1;

    //creating a temp arrays
    vector<int>merged;

    /* Merge the temp arrays back into arr[l..r]*/
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

    /* Copy the remaining elements*/
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