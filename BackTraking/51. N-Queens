class Solution {
public:
    // Function to convert the current state of the board to a vector of strings and add it to the answer list
    void addstring(vector<vector<string>>&ans, vector<vector<string>>&check, int n){
        vector<string> temp;
        // Loop through each row
        for(int i = 0; i < n; i++){
            string str = "";
            // Concatenate the elements of the row into a single string
            for(int j = 0; j < n; j++){
                str += check[i][j];
            }
            // Add the concatenated string to the temp vector
            temp.push_back(str);
        }
        // Add the temp vector to the answer list
        ans.push_back(temp);
    }

    // Function to check if it is safe to place a queen at the given row and column
    bool isSafe(int row, int col, vector<vector<string>>&check, int n){
        int y = col;
        int x = row;

        // Check the row on the left side
        while(y >= 0){
            if(check[x][y] == "Q"){
                return false;
            }
            y--;
        }

        y = col;
        x = row;

        // Check the upper diagonal on the left side
        while(y >= 0 && x >= 0){
            if(check[x][y] == "Q"){
                return false;
            }
            y--;
            x--;
        }

        y = col;
        x = row;

        // Check the lower diagonal on the left side
        while(y >= 0 && x < n){
            if(check[x][y] == "Q"){
                return false;
            }
            y--;
            x++;
        }
        return true;
    }

    // Function to solve the N-Queens problem using backtracking
    void solve(vector<vector<string>>&ans, int n, vector<vector<string>>&check, int col){
        // If all queens are placed
        if(col == n){
            addstring(ans, check, n);
            return;
        }

        // Consider this column and try placing the queen in all rows one by one
        for(int i = 0; i < n; i++){
            // Check if it's safe to place the queen at check[i][col]
            if(isSafe(i, col, check, n)){
                // Place the queen
                check[i][col] = "Q";
                // Recur to place rest of the queens
                solve(ans, n, check, col + 1);
                // Backtrack and remove the queen
                check[i][col] = ".";
            }
        }
    }

    // Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        // Handle the special case where n is 1
        if(n == 1){
            vector<vector<string>> result; // Declare the 2D vector

            for (int i = 0; i < n; ++i) {
                vector<string> temp; // Create a temporary vector
                temp.push_back("Q"); // Add the string "Q" to the temporary vector
                result.push_back(temp); // Add the temporary vector to the 2D vector
            }
            return result;
        }

        vector<vector<string>> ans; // Declare the 2D vector to store the answer
        vector<vector<string>> check(n, vector<string>(n, ".")); // Initialize the board with '.'
        int col = 0; // Start with the first column
        solve(ans, n, check, col); // Call the solve function

        return ans; // Return the answer
    }
};
