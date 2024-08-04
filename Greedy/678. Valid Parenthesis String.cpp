Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true
  
Example 3:
Input: s = "(*))"
Output: true



// class Solution {
// public:

//     // recursively check each parenthesis.
//     // when * is there check for each parenthesis
       // TLE at test case 7
    //    TC = 3^N
    //    SC = N


//     bool helper(string s, int count, int index){
//         if(index >= s.size() && count == 0){
//             return true;
//         }
//         if(index >= s.size() && count != 0){
//             return false;
//         }
//         if(count < 0) return false;


//         if(s[index]=='('){
//             return helper(s, count+1, index+1);
//         }else if(s[index]==')'){
//             return helper(s, count-1, index+1);
//         }else{
//             return (helper(s, count-1, index+1)
//                     || helper(s, count+1, index+1)
//                     || helper(s, count, index+1));
//         }
//     }

//     bool checkValidString(string s) {
//         int count = 0, index = 0;
//         bool ans = helper(s, count, index);
//         return ans;
//     }
// };



//other way is DP

class Solution {
public:

    bool checkValidString(string s) {
       
    }
};
