//Brute force
//time comp = n^2
//spacecomp = n^2

/* 
 i  j        i  j
(0, 0): 1 ->(0, 2)     see the pattern
(0, 1): 2 ->(1, 2)     i_new = j_old 
(0, 2): 3 ->(2, 2)     and j_new = (n-1) -i_old
                        therefore 'newMatrix[j][n-1-i] = matrix[i][j];'
(1, 0): 4 ->(0, 1) 
(1, 1): 5 ->(1, 1) 
(1, 2): 6 ->(2, 1)

(2, 0): 7 ->(0, 0) 
(2, 1): 8 ->(1, 0) 
(2, 2): 9 ->(2, 0) 


*/


//optimal
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>>newMatrix(n,vector<int>(m,0)); 

//         for(int i = 0; i<n; i++){
//             for(int j = 0; j<m ; j++){
//                 newMatrix[j][n-1-i] = matrix[i][j];
//             }
//         }

//         matrix = newMatrix;
//     }
// };




class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //transpoze 
        for(int i=0; i<matrix.size(); i++) //O(n)
        {                                  //        => O(n^2)
            for(int j=0; j<i; j++){        //O(n)
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        //col swaping
         for(int i=0; i<matrix.size(); i++)      //O(n)
        {                                        //        => O(n^2)
            for(int j=0; j<matrix.size()/2; j++){//O(n)
                swap(matrix[i][j],matrix[i][matrix.size()-j-1]);
            }
        }


    }
};
