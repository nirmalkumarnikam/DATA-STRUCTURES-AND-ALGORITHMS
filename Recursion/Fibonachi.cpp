/*
class Solution {
  public:
  
    int fib(int n,vector<int> &ans){
        if(n==0)return 0;           // problem with this code is lot for redudant entries are created
        if(n==1)return 1;           // and we cannot avoid these redudancies from getting into array.
        
        int num = fib(n-1, ans)+fib(n-2, ans);
        
        ans.push_back(num);                    
        return num;
    }
  
    vector<int> Series(int n) {
        // Code here
        vector<int> ans{0,1};
        
        int num = fib(n,ans);
        
        return ans;
    }
};
*/

/*
class Solution {
  public:
  
    int fib(int n){
        if(n==0)return 0;           
        if(n==1)return 1;          
        
        int num = fib(n-1)+fib(n-2);
 
        return num;
    }
  
    vector<int> Series(int n) {
        // Code here
        vector<int> ans;
        for(int i = 0; i<=n; i++){    // so here we are finding fibonacchi value at each index
            int num = fib(i);         // and appending it to the vector.
            ans.push_back(num);       // this approach will give tle
        }
        return ans;
    }
};
*/


//best approaach here is  using for loop
class Solution {
  public:
    vector<int> Series(int n) {
        vector<int> ans;
        ans.push_back(0);
        if (n == 0) return ans; // Return empty for n=0
        ans.push_back(1);
        if (n == 1) return ans; // Return [0] for n=1
        ans.push_back(1);
        if (n == 2) return ans; // Return [0,1] for n=1
        for(int i = 3; i <=n; i++) {    
            int num = ans[i-1] + ans[i-2];
            ans.push_back(num);
        }
        return ans;
    }
};