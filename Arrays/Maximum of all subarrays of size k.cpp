
//brute force

// class Solution
// {
//   public:
//     //Function to find maximum of each subarray of size k.
//     vector <int> max_of_subarrays(int *arr, int n, int k)
//     {
//         // your code here
//         vector<int>ans;
//         for(int i = 0; i<=n-k; i++){
//             int maxi = INT_MIN;
//             for(int j = i; j<i+k; j++){
//                 maxi=max(maxi, arr[j]);
//             }
//                 ans.push_back(maxi);
//         }
//         return ans;
//     }
// };





//........................bro ye approach smj nahi aya... bas copy kiya hai.....................................


class Solution
{
  public:
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector <int> res;
        deque<int> q;
        
        int i = 0;
        
        //iterating over first k elements or first window of array.
        for(i = 0;i<k;i++)
        {
            //for every element, the previously smaller elements 
            //are useless so removing them from deque.
            while((!q.empty()) && (arr[i] >= arr[q.back()]))
                q.pop_back();
            
            //adding new element at back of deque.   
            q.push_back(i);
            
        }
        
        //iterating over the rest of the elements.
        for(;i<n;i++)
        {
            //the element at the front of the deque is the largest 
            //element of previous window, so adding it to the list.
            res.push_back (arr[q.front()]);
            
            //removing the elements which are out of this window.
            while((!q.empty()) && (q.front() <= i-k))
            q.pop_front();
            
            //removing all elements smaller than the element being  
            //added currently (removing useless elements).
            while((!q.empty()) && (arr[i] >= arr[q.back()])) 
            q.pop_back();
            
            //adding new element at back of deque. 
            q.push_back(i);
            
        }
        
        //the element at the front of the deque is the largest 
        //element of last window, so adding it to the list.
        res.push_back (arr[q.front()]);
        q.pop_front();
        
        //returning the list.
        return res;
    }
};