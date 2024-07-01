Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]



class Solution {
public:
    // Function to generate all combinations of well-formed parentheses
    vector<string> generateParenthesis(int n) {
        vector<string> ans; // Vector to store all valid combinations
        string str = ""; // Temporary string to build each combination
        helper(ans, n, 0, 0, str); // Call the helper function to generate combinations
        return ans; // Return the vector containing all valid combinations
    }

    // Helper function to generate combinations using recursion
    void helper(vector<string>& ans, int n, int open, int close, string str) {
        // Base case: if the length of the current string equals n*2, it's a valid combination
        if (str.size() == n * 2) {
            ans.push_back(str); // Add the valid combination to the result vector
            return; // Exit the current recursive call
        }

        // If the number of open parentheses is less than n, we can add an open parenthesis
        if (open < n) {
            helper(ans, n, open + 1, close, str + "("); // Recur with an additional open parenthesis
        }

        // If the number of close parentheses is less than the number of open parentheses, we can add a close parenthesis
        if (close < open) {
            helper(ans, n, open, close + 1, str + ")"); // Recur with an additional close parenthesis
        }
    }
};
