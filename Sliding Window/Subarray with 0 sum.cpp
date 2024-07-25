Given an array of integers. Find if there is a subarray (of size at-least one) with 0 sum. You just need to return true/false depending upon whether there is a subarray present with 0-sum or not. Printing will be taken care by the driver code.

Example 1:
Input:
n = 5
arr = {4,2,-3,1,6}
Output: 
Yes
Explanation: 
2, -3, 1 is the subarray with sum 0.

Example 2:
Input:
n = 5
arr = {4,2,0,1,6}
Output: 
Yes
Explanation: 
0 is one of the element in the array so there exist a subarray with sum 0.
Your Task:
You only need to complete the function subArrayExists() that takes array and n as parameters and returns true or false.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 104
-105 <= a[i] <= 105




  
class Solution{
    public:
    
    // this que has lot of approach
    
    // // Approach 1:
    // // Brute Force:
    // // TC = O(n^3)
    bool subArrayExists(int arr[], int n)
    {
        for(int i=0; i<n; i++){
            for(int j = i; j<n; j++){
                int sum = 0;
                for(int k = i; k<=j; k++){
                    sum += arr[k];
                    if(sum == 0)return true;
                }
            }
        }
        return false;
    }
    
    
    
    
    // // Approach 2:
    // // Better:
    // // TC = O(n^2)
    bool subArrayExists(int arr[], int n)
    {
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j = i; j<n; j++){
                sum += arr[j];
                if(sum == 0)return true;
            }
        }
        return false;
    }
    
    
    
    
    // Approach 3:
    // Better: Prefix Sum (sliding window)
    // TC = O(n)
    
    // imp: Ordered Map: searching = O( log n )
    //                   Insertion = O( log n )
    //      Unordered Map: searching = O( 1 )
    //                     Insertion = O( 1 )
                        
                        
    bool subArrayExists(int arr[], int n)
    {
        vector<int>PrefixSum;
        unordered_map<int, int> mapp; //to find if currelement in PrefixSum is present before
        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            PrefixSum.push_back(sum);
            
            //if single element is zero
            if(sum == 0 || arr[i]==0)return true;
        }
        
        for(int i=0; i<n; i++){
            if(mapp.find(PrefixSum[i])!=mapp.end()){
                return true;    
            }
            mapp[PrefixSum[i]]++;
        }
        
        return false;
    }
};
