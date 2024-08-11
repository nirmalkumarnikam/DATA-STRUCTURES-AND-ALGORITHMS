Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers.


Example 1:
Input:
N = 6
Arr[] = {6, 8, 4, 5, 2, 3}
Output: 604
Explanation: The minimum sum is formed 
by numbers 358 and 246.

Example 2:
Input:
N = 5
Arr[] = {5, 3, 0, 7, 4}
Output: 82
Explanation: The minimum sum is 
formed by numbers 35 and 047.


class Solution{   
public:
    string solve(int arr[], int n) {
    
        sort(arr,arr+n);    // 2 3 4 5 6 8
        string s1,s2;
        string ans;
        int i=n-1,j=n-2,carry=0;
        while(i>=0 or j>=0)
        {
            int sum=carry;
            if(i>=0)
                sum += arr[i];
            if(j>=0)
                sum += arr[j];
            carry = sum/10;
            if(sum)
                ans.push_back(sum%10+'0');  //The character '0' has an ASCII value of 48
            i-=2;                           //it will convert integer to char
            j-=2;
        }
        //after addition carry is remain
        if(carry)
        ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans==""?"0":ans;
  }
};

