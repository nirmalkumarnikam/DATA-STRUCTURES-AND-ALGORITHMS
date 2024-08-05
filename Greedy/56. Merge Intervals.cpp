Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


// Optimal
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
