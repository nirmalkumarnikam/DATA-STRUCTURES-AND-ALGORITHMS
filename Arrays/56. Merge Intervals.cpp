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
            // now at max 2 case will happen
            // 1)[[1,4],[1,5]] : here we will replace 4 with 5.
                // else we will push interval in vector.
            // 2)[[1,4],[2,3]] : here we will keep 4 as it is
            
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




// Time Complexity: Sorting: O(n log n) + Merging: O(n) =  O(n log n)
// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());

        int i=1;
        if(arr.size()==1)return arr;
        while(i<=arr.size()-1){
            if(arr[i-1][1]>=arr[i][0]){
                arr[i-1][1]=max(arr[i-1][1],arr[i][1]);
                arr.erase(arr.begin()+i);
            }else{
                i++;
            }
        }

        return arr;

    }
};





