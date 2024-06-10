class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // make a vector to store non duplicate values
        vector<int> ans;
        ans.push_back(nums[0]);
        int ansNum = 0;
        
        for(int i =1; i< nums.size(); i++){
            
            //push unique value in ans
            if(ans[ansNum]!=nums[i]){
                ans.push_back(nums[i]);
                ansNum++;
            }
        }

        //put values of num in ans.
        nums = ans;
        return ans.size();
    }
};