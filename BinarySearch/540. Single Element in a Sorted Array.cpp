class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];

        // here we are cheking couple, if found we move 2 places ahead

        for(int i =0; i<n; i++)
        {
            if(nums[i]==nums[i+1]){
                i++;
            }else
            {
                return nums[i];
            }
        }

        return -1;
    }
};




class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        //if arr is of size 1
        if(n == 1)return nums[0];

        // if first element is single
        if(nums[0]!=nums[1]) return nums[0];
        // if last ele is single
        if(nums[n-1]!= nums[n-2]) return nums[n-1];

        //now we will search in array exept first and last element
        int start = 1;
        int end = n-2;

        while(start <= end)
        {
            int mid = start + (end-start)/2;
            
            // if element is nor similar to nearbay element... its our ans
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }

            // if couple is (even, odd) our ans lies right of mid
            if((nums[mid] == nums[mid+1] && mid%2 == 0) 
                    || (nums[mid-1]==nums[mid] && (mid-1)%2 == 0))
            {
                start = mid+1;
            }
            // if couple is (odd,even) our ans lies left of mid
            else
            {
                end = mid -1;
            }
        }

        return -1;
    }
};





class Solution {
public:

/*
    1)remove edge cases
            if there is only one element... thats our ans
            check corner elements

         0  1  2  3  4  5  6  7  8
    2)   1  1  2  2  3  4  4  8  8
               i  j     k  l
        
        if couple is in left of single ele its index are {even, odd} == i j
        if couple is in right of single ele its index are {odd, even} == k l
*/

    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==1)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-2]!=nums[n-1])return nums[n-1];

        int start = 1,end = n-1;

        while(start<=end){
            int mid = start + (end-start)/2;

            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }else if( nums[mid]==nums[mid-1] ){
                if((mid-1)%2 == 0){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }else{
                if((mid)%2 == 0){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }


        return -1;
    }
};



