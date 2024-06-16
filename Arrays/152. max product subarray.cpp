//brute force
//tle at 190/191
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//          long long prod = 1;
//          long long ans = INT_MIN;

//         for(int i =0; i < n; i++){
//             prod =1;
//             for(int j = i; j<n; j++){
//                 prod *= nums[j];
//                 ans = max(ans, prod);
//             }
//         }

//         return ans;   
//     }
// };










// time comp = O(n)
// we will iterate from LEFT to RIGHT and do suff multiplication
// we will iterate from RIGHT to LEFT and do pref multiplication
// we will keep storing max of these in ans.
// if zero occurs some where we will change suff or preff to 1.


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long int suff = 1, pref = 1;
        
        long long int n = nums.size();

        long long int ans = INT_MIN;

        for(int i = 0; i<nums.size(); i++){
            if(pref == 0)pref = 1;
            if(suff == 0)suff = 1;

            suff *= nums[i];
            pref *= nums[n-i-1];

            ans = max(ans, max(suff,pref));
            
        }

        return ans;
    }
};