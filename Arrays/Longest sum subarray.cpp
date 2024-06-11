/*
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        //..........BRUTE FORCE...............
                    // TC = n^3
                    // SC = O(1)
        
          Run a nested loop . 
          Outer loop will contain variable i from 0 to n-1.
          Second loop will contains variable j from i to n-1.
          Run a third loop from i to j and find the sum . 
          If sum is K , then update answer , ans = max ( ans, j-i+1).
                    
        
        int ans = 0;
        
        for(int i =0; i< n; i++ ){
           for(int j = i; j<n; j++){
               int sum =0;
               for(int p = i; p<=j; p++){
                   sum += a[p]; 
               }
               if(sum == k)
               {
                   ans = max(ans, j-i+1);
               }
           } 
        }
        
        return ans;
    } 

};

*/

class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // unordered_map 'um' implemented  
        // as hash table 
        unordered_map<int,int>mapp;
        
        int sum = 0, maxlen = 0;
        
        // traverse the given array
        for(int i = 0; i<n; i++){
            
            //accumulate sum
            sum += a[i];
            
            // when subarray starts from index '0' 
            if(sum == k)maxlen = i+1;
            
            // make an entry for 'sum' if it is 
            // not present in 'um' 
            if(mapp.find(sum)== mapp.end()){
                mapp[sum]=i;
            }
            
            // check if 'sum-k' is present in 'um' 
            // or not 
            if(mapp.find(sum-k) != mapp.end()){
                
                // update maxLength
                if(maxlen < (i-mapp[sum-k]))
                    maxlen = i-mapp[sum-k];
            }
        }
        return maxlen;
    } 
};




