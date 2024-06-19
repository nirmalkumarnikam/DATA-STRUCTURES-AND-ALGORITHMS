

//brute force
// time comp = O(n)
// space comp = O(1);
// class Solution{
// public:
// 	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
// 	    // code here
// 	    int maxIndex=-1;
// 	    int maxCount = -1;
	    
	    
// 	    for(int i = 0; i<n; i++){
            
//             int currCount = -1;
            
//             for(int j = 0; j<m; j++)
//             {
//                 if(arr[i][j]==1)
//                 {
//                   currCount++;
//                 }
                
//             }
                
//             if(currCount>maxCount)
//             {
//                 maxCount = currCount;
//                 maxIndex = i;
//             }
//         }
//         return maxIndex;
// 	}
// };







//here we will use the sorted nature of array

class Solution{
public:
    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        int r = 0;              // keeps track of row; starts at first row             
        int c = m-1;            // keeps track of column; starts at last column
        int max_row_index=-1;   // keeps track of result row index
        
        // starting from top right corner
        // go left if you encounter 1
        // do down if you encounter 0
        while(r<n && c>=0)
        {
            if(arr[r][c]==1)
            {
                max_row_index = r;
                c--;
            }
            else
                r++;
        }
        return max_row_index;
    }
};
	

