/*
Quick Sort:-
    1)choose any one element as Pivot Element
    2)ele less than pivot will go left of pivot and ele greater than pivot will go right of pivot.
    3)repeat step 1 & 2 for the remaining partitions. 

    Example:  arr = 7   6   10   5   9   2   1   15   7

                    7   6   10   5   9   2   1   15   7
                    ^
                  Pivot

    1st iteration:  7   6   10   5   9   2   1   15   7
                    s                                 e

                    7   6   10   5   9   2   1   15   7
                             s                        e
                                    Swap(s,e)
                    
                    7   6   7   5   9   2   1   15   10
                                    s       e
                                    Swap(s,e)
                    
        IMP         7   6   7   5   1   2   9   15   10
                                        e   s
                                    now  s > e => Swap(0, e)

                    2   6   7   5   1   7   9   15   10
                                        ^
                                        e = {partition}

                    Now array is separated in two parts... 
                    recursively apply same function for both parts.

Time Complexity: Worst case: O(n^2)
                 avg case: O(n logn)
*/



// Code:

int Partition(vector<int>A, int lb, int ub){

    int pivot = A[start];
    int start = lb;
    int end = ub;
    
    
    while(start < end)
    {
        //this loop will iterate till element grater than pivot
        while(A[start]<=pivot)
        {
            start++;
        }

        //this loop will iterate till element less than pivot
        while(A[end]>pivot)
        {
            end--;
        }

        //swap them
        if(start<end)
        {
            swap(A[start], A[end]);
        }
    }
    // after this loop situatition will be like this
    // 7   6   7   5   1   2   9   15   10
    //                     e   s


    //bring partition element to its right place
    swap(A[up], A[end]);

    return end; //return index of partition
}

void QuickSort(vector<int>A, int lb, int ub){
    if(lb<ub)
    {
        //loc is where we have made partition
        int loc = Partition(A, ub, lb);
        QuickSort(A, lb, loc-1);         //call for left side
        QuickSort(A, loc+1, ub);         //call for right side
    }
}





                                          
                                 


