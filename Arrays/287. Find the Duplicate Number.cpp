class Solution {
public:

    int findDuplicate(vector<int>& nums) {

        //based on floyeds algorithm in linked list
        //rat lena achhe se

        if (nums.size() > 1)
	{
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
	return -1;
    }

    // space comp O(n)
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<bool>visited(n+1,false);
    //     for(int i=0; i<n; i++){
    //         if(visited[nums[i]]){
    //             return nums[i];
    //         }else{
    //             visited[nums[i]]=true;
    //         }
    //     }
    //     return -1;
    // }
};