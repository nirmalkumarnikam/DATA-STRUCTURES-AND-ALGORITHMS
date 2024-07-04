Given an array arr[ ] of n elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Examples
Input: arr[] = [1 3 2 4], n = 4
Output: 3 4 4 -1
Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.

Input: arr[] [6 8 0 1 3], n = 5
Output: 8 -1 1 3 -1
Explanation: The next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger element on right and hence -1.





class Solution{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> res(n, -1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    res[i]=arr[j];
                    break;
                }
            }
        }
        return res;
    }
};






// TC: O(N^2)
// SC: O(1)
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n) {
    // Iterate over each element in the array
    for (int i = 0; i < n; i++) {
        // Flag to check if a larger element is found
        bool present = false;
        // Check the elements to the right of the current element
        for (int j = i + 1; j < n; j++) {
            // If a larger element is found
            if (arr[i] < arr[j]) {
                // Update the current element with the next larger element
                arr[i] = arr[j];
                // Set the flag to true indicating a larger element is found
                present = true;
                // Exit the inner loop as we found the next larger element
                break;
            }
        }
        // If no larger element was found
        if (!present) {
            // Assign -1 to the current element
            arr[i] = -1;
        }
    }
    // Return the modified array with next larger elements
    return arr;
}

};


// TC: O(n)
// SC: O(n)
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n) {
    // Stack to keep track of next greater elements
    stack<int> st;

    // Traverse the array from the end to the beginning
    for (int i = n-1; i >= 0; i--) {
        // If the stack is empty, there is no greater element to the right
        if (st.empty()) {
            // Push the current element to the stack
            st.push(arr[i]);
            // Assign -1 to the current element as there is no greater element
            arr[i] = -1;
        } else {
            // Pop elements from the stack that are less than or equal to the current element
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            // If stack is empty after popping, there is no greater element to the right
            if (st.empty()) {
                // Push the current element to the stack
                st.push(arr[i]);
                // Assign -1 to the current element as there is no greater element
                arr[i] = -1;
            } else {
                // If stack is not empty, the top element is the next greater element
                int ele = arr[i]; // Store the current element
                arr[i] = st.top(); // Update the current element with the next greater element
                st.push(ele); // Push the stored element back to the stack
            }
        }
    }
    // Return the modified array with next greater elements
    return arr;
}

};
