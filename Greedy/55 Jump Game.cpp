Jump Game
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

 /*
    algo:
    we will maintain Two variable MaxIndex and currentIndex.
    if the we can jump more than MaxIndex then we will update MaxIndex 
    else we will keep iterating and adding to current index

    at end of the loop if maxIndex exceeds array size we have passed jump game
    else we loose
    */

    bool canJump(vector<int>& nums) {
    int maxIndex = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (i > maxIndex) {
            return false; // If the current index is beyond the furthest reachable index, we can't move further
        }
        maxIndex = max(maxIndex, i + nums[i]);
        if (maxIndex >= nums.size() - 1) {
            return true; // If we can reach or go beyond the last index, return true
        }
    }

    return false; // If we exit the loop without reaching the last index, return false
}
