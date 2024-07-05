You are given a string S of size N that represents the prefix form of a valid mathematical expression. Convert it to its infix form.

Example 1:
Input: 
*-A/BC-/AKL
Output: 
((A-(B/C))*((A/K)-L))
Explanation: 
The above output is its valid infix form.
Your Task:

Complete the function string preToInfix(string pre_exp), which takes a prefix string as input and return its infix form.

Expected Time Complexity: O(N).

Expected Auxiliary Space: O(N).

Constraints:

3<=|S|<=104






class Solution {
  public:
    // Helper function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert prefix expression to infix expression
string preToInfix(string pre_exp) {
    // Stack to hold intermediate results
    stack<string> st;

    // Reverse the prefix expression to start processing from right to left
    reverse(pre_exp.begin(), pre_exp.end());

    // Process each character in the reversed prefix expression
    for (char& ch : pre_exp) {
        if (!isOperator(ch)) {
            // If the character is an operand, push it to the stack
            st.push(string(1, ch));
        } else {
            // If the character is an operator, pop two operands from the stack
            string operand1 = st.top(); st.pop();
            string operand2 = st.top(); st.pop();
            // Create the infix expression by combining the operands with the operator
            string new_expr = "(" + operand1 + ch + operand2 + ")";
            // Push the resulting expression back to the stack
            st.push(new_expr);
        }
    }

    // The final element in the stack is the complete infix expression
    return st.top();
}
};
