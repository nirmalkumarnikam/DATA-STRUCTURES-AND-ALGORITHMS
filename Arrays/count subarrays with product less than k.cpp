

//BRUTE FORCE
//tle at test case 1120
//algo:
    // 2 for loops will hepl you to go throught eacg subarray possible.
    // multiply it and check if prod is less than k
    // if yes then count++
    // else prod > k then break loop as there is no use of processing further.



// class Solution{
//   public:
//     long long countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
//         long long count=0;
//         for(int i =0; i<n; i++){
//             long long prod = 1;
            
//             for(int j=i; j<n;j++){
//                 prod = prod*a[j];
//                 if(prod<k)
//                 {
//                     count++;
//                 }
//                 else if(prod>k)
//                 {
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };






// sliding window approach
// time comp = O(n)
// algo:
//     in for loop
//         we will multiply end element to prod;
//         if prod >= k we will divide the prod by element at index start till prod <k (while loop)
//         in this window formed between start and end index: no of suarrays in them will have prod < k
//             No of subarray between start and end = 1+(end-start)
//      move to next end element and repeate steps again

class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
        int start = 0, end =0;
        long long prod =1, ans=0;
        for(end = 0; end<n; end++){
            prod *= a[end];
            
            while(prod >= k && start < end)
            {
                prod /= a[start];
                start++;
            }
            
            if(prod < k){
                ans += 1+(end-start);
            }
        }
      
        return ans;

    }
};
