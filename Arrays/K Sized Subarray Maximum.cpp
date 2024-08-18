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










// tc = O(n)+O(n) =>traverse + we will remove atmost n element
class Solution
{
  public:
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int>q;
        vector<int>ans;
        
        for(int i = 0; i<n; i++){
            
            //keeping it inbound
            while(!q.empty() && q.front()<= i-k)q.pop_front();
            
            // Remove elements from the back that are smaller than the current element
            while(!q.empty() && arr[q.back()]<arr[i]){
                q.pop_back();
            }
            q.push_back(i);
            
            if(i>=k-1)ans.push_back(arr[q.front()]);
        }
        return ans;
    }
    
};
