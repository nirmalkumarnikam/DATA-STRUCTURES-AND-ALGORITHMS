/*
Q) Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Input: nums = [4,1,2,1,2]
Output: 4

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        map<int , int> check; //initialize map

        // +1 to check when ever the num is found
        for(int i=0; i<nums.size(); i++){  
            check[nums[i]]++;
        }

        // iterate over check and if value is 1... thats our ans...
        for(auto it:check){
            if(it.second == 1) return it.first;
        }

        return -1;   //just in case everything is double
    }
};

// TC = O(n log(n))    n for iterating and log n for inserting in map
// SC = O(n)           worst case for map




//using XOR Best solution

/*The XOR operation has the property that 𝑎⊕𝑎=0, a⊕a=0 and 𝑎⊕0 = 𝑎 a⊕0=a. 
Therefore, XOR-ing all numbers together will cancel out the numbers that appear twice, 
leaving only the number that appears once.*/

// TC = O(n)
// SC = O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int result = 0;
        for(int i=0; i< nums.size(); i++){
            result ^=nums[i];
        }

        return result;
    }
};