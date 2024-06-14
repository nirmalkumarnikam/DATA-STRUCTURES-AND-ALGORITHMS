
//BRUTE FORCE
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        //last element in vector can be found out by 'ans.back()'
        
        vector<vector<int>> ans;
        int n = intervals.size();

        //push first vector for reference
        ans.push_back(intervals[0]);


        //Now iterate over all intervals
        for(int i = 1; i<n; i++){

            // as the array is sorted, we have managed case like this [[1,4],[0,0]] and [[1,4],[0,4]]
            // now at max 1 case will happen
            // 1)[[1,4],[1,5]] : here we will replace 4 with 5.
                // else we will push interval in vector.
            
            if(ans.back()[1] >= intervals[i][0])
            {
               ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;

    }
};