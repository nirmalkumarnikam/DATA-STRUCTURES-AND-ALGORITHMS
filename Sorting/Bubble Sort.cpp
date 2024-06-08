Bubble Sort:-
    we will compare betn 1 & 2nd element and swap them if 1>2
    this way we will do n iteration and all the elements will be sorted.

    Example: arr = 10   1   7   6   14   9
                    i
    
    Round 1:  10   1   7   6   14   9
               i  i+1
               ^   ^
                swap
              
              1   10   7   6   14   9
                   i  i+1
                   ^   ^
                    swap
              
              1   7   10   6   14   9
                       i  i+1
                       ^   ^
                        swap
              
              1   7   6   10   14   9
                           i  i+1
                           ^   ^
                            No-swap
              
              1   7   6   10   14   9
                                i  i+1
                                ^   ^
                                 swap
                                 
               1   7   6   10   9  | 14  <- Sorted
               
               First iteration done
                               
    
    Round 2:   1   7   6   10   9 
               i  i+1
               ^   ^
                No-swap
              
               1   7   6   10   9 
                   i  i+1
                   ^   ^
                    swap
              
               1   6   7   10   9
                       i  i+1
                       ^   ^
                        No-swap
              
               1   6   7   10   9
                           i  i+1
                           ^   ^
                            swap
              
               1   6   7   9  |10  14  <- Sorted
                                
                                 
               Second iteration done
                               

    Round 3:   1   6   7   9 
               i  i+1
               ^   ^
                No-swap
              
               1   6   7   9 
                   i  i+1
                   ^   ^
                    No-swap
              
               1   6   7   9 
                       i  i+1
                       ^   ^
                        No-swap
              
               1   6   7  | 9  10  14  <- Sorted
                                
                                 
               Third iteration done

    Round 4:   1   6   7
               i  i+1
               ^   ^
                No-swap
              
               1   6   7
                   i  i+1
                   ^   ^
                    No-swap
                       
               1   6  | 7   9  10  14  <- Sorted
                                
                                 
               Third iteration done


    Round 5:   1   6
               i  i+1
               ^   ^
                No-swap
              
               1 |  6   7   9  10  14  <- Sorted
                                
               Forth iteration done

               Last element will be already sorted.
               Therefore total round N-1.
