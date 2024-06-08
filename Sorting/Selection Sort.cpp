/*


Selection Sort:-
    we find smallest element and shift it to left most possible index.

    Example: arr = 64  25  12  22  11
                    i

            Round 1: 64  25  12  22  11        (swap i and smallest)
                      i              ^smallest 

                      11  25  12  22  64   

            Round 2: 11  25  12  22  64        (swap i and smallest)
                          i  ^smallest 

                      11  12  25  22  64
                                
             Round 3: 11  12  25  22  64        (swap i and smallest)
                               i  ^smallest 

                      11  12  22  25  64
             
             Round 4: 11  12  22  25  64        (swap i and smallest)
                                   i  
                                   ^smallest 
                      11  12  22  25  64
            
            Round 5: No need as last element will be already sorted.

                     therefore total round N-1.


Space Complexity = O(1)
Time Complexity = O(n^2)  


*/

// also see the working of swap function too.

void swap(int &a, int &b){
        int temp = a;
        a=b;
        b=temp;
    }
    
//select the smallest element and swap with left possible index.    
void insert(int arr[], int n)
{
    // we will iterate till n-1 element as last element is already sorted
    for(int i =0; i<n-1; i++){       
        int minIndex = i;              // we will assume ith index as smallest
        
        for(int j = i+1; j<n; j++){    
            if(arr[j]<arr[minIndex]){  //find smallest in array
                minIndex = j;
            }
        }
        
        swap(arr[minIndex], arr[i]);   //swap the left unsorted (i) and smallest element
    }

    // till the loop ends all the elements will be sorted.
}