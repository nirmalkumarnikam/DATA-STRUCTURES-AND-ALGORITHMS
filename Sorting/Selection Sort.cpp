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



*/











#include <iostream>
using namespace std;



int main(){
    return 0;
}