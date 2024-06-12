
/*
Insertion Sort:-
    here we basically shift the elements towards right till we get elements at desired location

    Example: 
                arr =  10  1  7  4  8  2  11

                    take first element and consider it as sorted.
                    ie 10 is sorted.

        Round 1: 
                i = 1      1<10 -> left of 10

                right shift 10 by one time and paste 1 it i = 0.

                Now  1  10  7  4  8  2  11


        Round 2: 
                i = 2      1<10 -> left of 10
                           7>1  -> right of 1

                right shift 10 by one time and paste 7 it i = 1.

                Now  1  7  10  4  8  2  11


        Round 3: 
                i = 3      4<10 -> left of 10
                           4<7  -> left of 7
                           4>1  -> right of 1

                right shift 7 & 10 by one time and paste 4 it i = 1.

                Now  1  4  7  10   8  2  11
        
        
        Round 4: 
                i = 4      8<10 -> left of 10
                           8>7  -> right of 7

                right shift 10 by one time and paste 8 it i = 3.

                Now  1  4  7  8  10  2  11


        Round 5: 
                i = 5      2<10 -> left of 10
                           2<8  -> left of 8
                           2<7  -> left of 7
                           2<4  -> left of 4

                right shift all by one time and paste 2 at i = 1.

                Now  1  2  4  7  8  10  11
        
        
        Round 6: 
                i = 6      11>10  -> right of 10

                no shifting required... let it be as it is.

                Now  1  2  4  7  8  10  11


        Code Intution: 

            1. Start from the second element (i=1).
            2.  we will store that element in temp as it will be lost while shifting.
            3. Compare `temp` with elements on the left (starting from j=i-1).
            4. If `j >= 0` and `a[j] > temp`, shift `a[j]` to the right. (while loop)
            5. Insert `temp` at the correct position.

Space Complexity = O(1)
Time Complexity = O(n^2)  
*/

for(int i=1; i<n; i++){
    temp = a[i];
    j = i-1;
    while(j>=0 && a[j]>temp ){
        a[j+1] = a[j];
        j--;
    }
    a[j+1]=temp;
}