Given an unsorted array arr of size n that contains only non negative integers, find a sub-array (continuous elements) that has sum equal to s. You mainly need to return the left and right indexes(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right. If no such subarray exists return an array consisting of element -1.

Examples:

Input: arr[] = [1,2,3,7,5], n = 5, s = 12
Output: 2 4
Explanation: The sum of elements from 2nd to 4th position is 12.
Input: arr[] = [1,2,3,4,5,6,7,8,9,10], n = 10, s = 15,
Output: 1 5
Explanation: The sum of elements from 1st to 5th position is 15.
Input: arr[] = [7,2,1], n = 3, s = 2
Output: 2 2
Explanation: The sum of elements from 2nd to 2nd position is 2.
Input: arr[] = [5,3,4], n = 3, s = 2
Output: -1
Explanation: There is no subarray with sum 2
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:

0 <= arr[i] <= 109
1 <= n <= 105
0 <= s <= 109




class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        if (s == 0) {
            // Check for a single zero element in the array
            for (int i = 0; i < n; ++i) {
                if (arr[i] == 0) {
                    return {i + 1, i + 1}; // Return 1-based index of the zero element
                }
            }
            return {-1}; // If no zero is found, return {-1}
        }

        int l = 0, r = 0; // Initialize left and right bounds of the sliding window
        long long sum = 0; // Initialize the sum of the current sub-array

        // Iterate through the array using the right bound
        while (r < n) {
            sum += arr[r]; // Add the current element to the sum

            // Check if the current sum matches the target sum
            if (sum == s) {
                return {l + 1, r + 1}; // Return 1-based indices of the sub-array
            }

            // If the current sum exceeds the target sum, adjust the left bound
            while (sum > s && l <= r) {
                sum -= arr[l]; // Subtract the element at the left bound from the sum
                l++; // Move the left bound to the right

                // Check again if the adjusted sum matches the target sum
                if (sum == s) {
                    return {l + 1, r + 1}; // Return 1-based indices of the sub-array
                }
            }

            r++; // Move the right bound to the right
        }

        // If no sub-array is found, return {-1}
        return {-1};
    }
};

