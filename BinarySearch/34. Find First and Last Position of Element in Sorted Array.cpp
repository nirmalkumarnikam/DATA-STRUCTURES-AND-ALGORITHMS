//brute force
//O(n) Linear search
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int first= -1, last=-1;
//         int n = nums.size();
//         for(int i = 0; i< n; i++){
//             if(nums[i] == target)
//             {
//                 if(first == -1) first = i;
                
//                 last = i;
//             }
//         }

//         vector<int>ans{first, last};
//         return ans;
//     }
// };






//using Binary Search
// O(log n)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0; 
        int end = nums.size()-1;

        int firstOcc = -1;

        //this loop will find first occurance
        while(start <= end)
        {
            int mid = start + (end-start)/2;

            if(nums[mid]==target)
            {
                firstOcc = mid;      //mid is one of the candidate 
                end = mid-1;         //but we will find more to the left
            }
            else if(nums[mid] < target)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }


        start = 0; 
        end = nums.size()-1;
        int lastOcc = -1;

        while(start <= end)
        {
            int mid = start+ (end-start)/2;

            if(nums[mid]==target)
            {
                lastOcc = mid;          //mid is one of the candidate 
                start = mid+1;          //but we will find more to the right
            }
            else if(nums[mid] < target)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }

        vector<int>ans{firstOcc, lastOcc};
        return ans;
    }
};



