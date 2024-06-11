
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



CODE:

class Solution
{
    void merge(int arr[], int l, int m, int r)
    {
        int n1 = m-l+1;
        int n2 = r-m;
        
        //creating a temp arrays
        int L[n1], R[n2];
        
        //copy the values in these arrays
        for(int i = 0; i<n1; i++)
            L[i]=arr[l+i];
        
        for(int j = 0; j<n2; j++)
            R[j]=arr[m+1+j];
        
        
         /* Merge the temp arrays back into arr[l..r]*/
        int i = 0, j = 0, k = l;
        
        while( i<n1 && j < n2)
        {
            if(L[i]<=R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        
        /* Copy the remaining elements*/
        while(i<n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        
        while(j<n2)
        {
            arr[k]=R[j];
            j++;
            k++;
        }
        
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        
        if(l < r)
        {
            int m = l+(r-l)/2;
            
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            
            merge(arr, l, m,r);    
        }
    }
};
