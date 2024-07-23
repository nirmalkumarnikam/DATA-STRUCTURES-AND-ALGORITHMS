/*

Remove duplicate elements from sorted Array
Difficulty: EasyAccuracy: 38.18%Submissions: 237K+Points: 2
Given a sorted array arr. Return the size of the modified array which contains only distinct elements.
Note:
1. Don't use set or HashMap to solve the problem.
2. You must return the modified array size only where distinct elements are present and modify the original array such that all the distinct elements come at the beginning of the original array.

Examples :

Input: arr = [2, 2, 2, 2, 2]
Output: [2]
Explanation: After removing all the duplicates only one instance of 2 will remain i.e. [2] so modified array will contains 2 at first position and you should return 1 after modifying the array, the driver code will print the modified array elements.
Input: arr = [1, 2, 4]
Output: [1, 2, 4]
Explation:  As the array does not contain any duplicates so you should return 3.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ ai ≤ 106

*/




class Solution {
  public:
    int remove_duplicate(vector<int> &arr) {
        // Check if the array size is 1, if so return 1 as there's nothing to remove.
        if(arr.size() == 1) return 1;
        
        int i = 0, j = 1;
        
        // Iterate over the array with two pointers i and j.
        while(j < arr.size() && i < j) {
            // If the elements at i and j are the same, erase the element at j.
            if(arr[i] == arr[j]) {
                arr.erase(arr.begin() + j);
            } else {
                // If they are different, move both pointers forward.
                i++;
                j++;
            }
        }
        
        // Return the size of the array after removing duplicates.
        return arr.size();
    }
};


class Solution {
  public:
    int remove_duplicate(vector<int> &arr) {
        // The unique function shifts the unique elements to the beginning of the array
        // and returns an iterator to the end of the unique range.
        return unique(arr.begin(), arr.end()) - arr.begin();
    }
};

class Solution {
  public:
    int remove_duplicate(vector<int> &arr) {
        int i = 0;
        // Iterate over the array starting from the second element.
        for(int j = 1; j < arr.size(); j++) {
            // If the current element is not equal to the last unique element, increment i and update arr[i].
            if(arr[i] != arr[j]) {
                i++;
                arr[i] = arr[j];
            }
        }
        // Return the count of unique elements.
        return i + 1;
    }
};
