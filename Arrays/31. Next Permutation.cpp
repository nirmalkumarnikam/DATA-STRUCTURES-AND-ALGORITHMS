/*..........Best Approach.................*/
// class Solution {
// public:

//     void reverse(vector<int>& nums, int start_index){
//         int i = start_index;
//         int j = nums.size()-1;

//         while(i<j){
//             swap(nums[i],nums[j]);
//             i++;
//             j--;
//         }
//     }

//     void nextPermutation(vector<int>& nums) {
//         /*
//         Algo:
//             {2,1,5,4,3,0,0}
//             1)Find Break_Point from left:
//                     here Break_Point = 1, breaks the increasing order from right.
//             1.5) if no Break_Point then Revarse array and return array.
//             2)Find Next_Greater element of Break point from right:
//                     Next_Greater = 3
//             3)Swap(Break_Point, Next_Greater)   
//             4)reverse array from 'Break_Point + 1' till end of array
//             5)return array;
//          */

//         int Break_Point = -1;
//         int Next_Greater = -1;

//         //find Break_Point
//         for(int i=nums.size()-2; i>=0; i-- ){
//             if(nums[i]<nums[i+1]){
//                 Break_Point = i;
//                 break;
//             }
//         }

//         //if Break_Point DNE then reverse array
//         if(Break_Point == -1){
//             reverse(nums,0);
//             return ;
//         }

//         //find Next_Greater
//         for(int i=nums.size()-1; i>Break_Point; i-- ){
//             if(nums[i]>nums[Break_Point]){
//                 Next_Greater = i;
//                 break;
//             }
//         }

//         //Swap Break_Point and Next_Greater
//         swap(nums[Break_Point], nums[Next_Greater]);

//         // Now reverese array to the right of Break_Point
//         reverse(nums, Break_Point+1);
//     }
// };


// mentos approach
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        next_permutation(nums.begin(), nums.end());


    }
};