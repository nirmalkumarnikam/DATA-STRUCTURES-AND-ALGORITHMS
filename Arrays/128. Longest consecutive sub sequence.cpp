
//brute force
// time comp = n^2
// class Solution {
// public:

//     bool linearsearch(int x, vector<int>& nums){
//         for(int i = 0; i< nums.size(); i++)
//         {
//             if(nums[i]==x)return true;
//         }
//         return false;
//     }

//     int longestConsecutive(vector<int>& nums) {
        
//         //if arr is empty return 0.
//         if(nums.size()==0) return 0;
        
//         //select an element and find its next ele in array by linear search
//         //if found increase count and find next number
//         //repeate till next num is not found.
//         // store count in global ans and return that.

//         int ans= INT_MIN;
//         for(int i = 0; i<nums.size(); i++){
//             int cnt = 1;
//             int x  = nums[i];
//             while(linearsearch(x+1, nums))
//             {
//                 x = x+1;
//                 cnt++;
//             }
//             ans = max(ans, cnt);
//         }
//         return ans;
//     }
// };






//optimal using set
//time comp = O(3n)  filling the elements O(n)  
//                   + iterating the set (worst case O(n)) 
//                   + checking next element O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // if arr is empty return 0.
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1; 

        int count = 1, ans = 1;

        //insert in set
        unordered_set<int> st;

        for(int i =0; i< nums.size();i++){
            st.insert(nums[i]);
        }


        // check elements from set
        for(auto it: st)
        {
            // 'it' is element in set, if 'it-1' is not present in set which means 'it' is starting point of sequence
            
            // then in while loop we are checking if next element is present or not --while loop condition
            // if its present then count++ and will find next element   --while loop body

            // when we are not able to find next element we will store count in ans.


            if(st.find(it-1) == st.end())
            {
                count = 1;
                int x = it;

                while(st.find(x+1) != st.end())
                {
                    x +=1;
                    count++;
                }

                ans = max(ans, count);
            }
        }
        return ans;
        
    }
};



//better  than set one
//time comp = O(n)
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {

//         // if arr is empty return 0.
//         if(nums.size()==0) return 0;
//         if(nums.size()==1) return 1;
        
        

//         sort(nums.begin(), nums.end());

//         int lastsmaller = nums[0]; 

//         int count = 1, ans = 1;

//            // here we are going to iterate over sorted array...

//            // we will store 1st num in lastsmaller...
//            // as there will be duplicate numbers... if( current num == lastsmaller) do nothing
//            // else if( current num is 1 greater than lastsmaller ) count++, update lastsmaller, and update ans
//            // else( current number is way different than last smaller which means sequece is broken ) restart count...

//            // return ans;

//         for(int i =0; i<nums.size();i++)
//         {

//             if(nums[i]== lastsmaller)
//             {
//                 continue;
//             }
//             else if(nums[i]-1 == lastsmaller)
//             {
//                 count++;
//                 ans = max(ans,count);
//                 lastsmaller = nums[i];
//             }
//             else
//             {
//                 count  = 1;
//                 lastsmaller=nums[i];
//             }

//         }
//         return ans;
        
//     }
// };