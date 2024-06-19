// here we found out zeros in matrix
// then we set rows and col as -1 using set minus one function
// come back to initial function we replaced -1 with 0.

// with this approach we will not be able to deal with  matrix containg -1

// time comp = n^3

// class Solution {
// public:

//     void setMinusOne(int row, int col, vector<vector<int>>& matrix){
//         for(int i = 0; i<matrix[0].size(); i++){
//             if(matrix[row][i]!=0)
//                 matrix[row][i]=-1;
//         }
//         for(int i = 0; i<matrix.size(); i++){
//             if(matrix[i][col]!=0)
//                 matrix[i][col]=-1;
//         }
//     }

//     void findZero(vector<vector<int>>& matrix){
//         for(int i = 0; i<matrix.size(); i++){
//             for(int j = 0; j<matrix[0].size(); j++){
//                 if(matrix[i][j]==0){
//                     setMinusOne(i, j, matrix);
//                 }
//             }
//         }
//     }

//     void setZeroes(vector<vector<int>>& matrix) {
//         // find zero
//         findZero(matrix);

//         // replace -1 with 0
//         for(int i = 0; i<matrix.size(); i++){
//             for(int j = 0; j<matrix[0].size(); j++){
//                 if(matrix[i][j]==-1){
//                     matrix[i][j]=0;
//                 }
//             }
//         }
//     }
// };



//time comp = O(n^2)
//space comp = O(m+n)
// class Solution {
// public:

//      //make 2 arrays, row array and col array
//      //whenever we find a '0' element we will mark its index as 1 in row and col array
        
//      //then using this arrays we will setZeros in matrix


//     void setZeroes(vector<vector<int>>& matrix) {
//         vector<int>row(matrix.size(),0);
//         vector<int>col(matrix[0].size(),0);

//         for(int i = 0; i<matrix.size(); i++){
//             for(int j = 0; j<matrix[0].size(); j++){
//                 if(matrix[i][j]==0){
//                     row[i]=1;
//                     col[j]=1;
//                 }
//             }
//         }

//         for(int i = 0; i<matrix.size(); i++){
//             for(int j = 0; j<matrix[0].size(); j++){
//                 if(row[i] || col[j]){
//                     matrix[i][j]=0;
//                 }
//             }
//         }
        
//     }
// };







// time comp = O(n^2)
// space comp = O(1)

// same as previous approach 
// but instead of making new array we will use first row and first col of initial matrix

// what is first row and first column contain zeros... 
//     therefore we are using 'firstrowzero' and 'firstcolzero' so that later we will make 
//     these rows and cols zero.


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // vector<int>row(matrix.size(),0);   -->matrix[..][0];
        // vector<int>col(matrix[0].size(),0);-->matrix[0][..]];

        
        //check if first row has zero or not
        int firstrowzero = 0;
        for(int i = 0; i< matrix[0].size(); i++){
            if(matrix[0][i]==0) firstrowzero=1;
        }
        int firstcolzero = 0;
        for(int i = 0; i< matrix.size(); i++){
            if(matrix[i][0]==0) firstcolzero=1;
        }
        
        
        for(int i = 1; i<matrix.size(); i++){
            for(int j = 1; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i = 1; i<matrix.size(); i++){
            for(int j = 1; j<matrix[0].size(); j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        if(firstrowzero){
            for(int i = 0; i< matrix[0].size(); i++){
                    matrix[0][i]=0;
            }
        }
        if(firstcolzero){
            for(int i = 0; i< matrix.size(); i++){
                    matrix[i][0]=0;
            }
        }
        
    }
};




