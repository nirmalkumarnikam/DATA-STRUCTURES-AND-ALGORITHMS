Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span 
100 is greater than equal to 100 and there are no more elements behind it so the span is 1,
80 is greater than equal to 80 and smaller than 100 so the span is 1,
60 is greater than equal to 60 and smaller than 80 so the span is 1,
70 is greater than equal to 60,70 and smaller than 80 so the span is 2,
60 is greater than equal to 60 and smaller than 70 so the span is 1,
75 is greater than equal to 60,70,60,75 and smaller than 100 so the span is 4,
85 is greater than equal to 80,60,70,60,75,85 and smaller than 100 so the span is 6. 
Hence the output will be 1 1 1 2 1 4 6.



/*
Algo: 
we are iterating from last element 
and checking in remaining array that element less than it exist or not
if exist them count++ 
when we reach end of array add count to the ans;

TC: O(n^2)
SC: O(n)
*/
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
      vector<int>ans(n,1);
      for(int  i = n-1; i>=0; i--){
          int count = 1;
          for(int j = i-1; j>=0; j--){
              if(price[j]<=price[i])
              {
                  count++;
              }
              else
              {
                  break;
              }
          }
          ans[i] = count;
      }
      return ans;
    }
};




/*
Algo:

Initialize an empty stack st.
Initialize an empty vector ans.
For each day i from 0 to n-1:
    While st is not empty and price[st.top()] <= price[i]:
        Pop the top element from st.
    If st is empty:
    Append i + 1 to ans, as we are using 0 based indexing. (this means every element is smaller than cuurent element)
    Else:
    Append i - st.top() to ans. (this will gove no of elements between index i and st.top)
    Push i onto st.
Return ans.

TC: O(n)
    Each element is pushed and popped from the stack at most once. Therefore, the total number of operations involving the stack is 𝑂(𝑛).
    The for loop runs n times, and in each iteration, there may be some push and pop operations on the stack, but each element is pushed and popped only once in total.

SC: O(n)
*/

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<int>st;
       
       vector<int>ans;
       
       for(int i=0; i<n; i++){
           while(!st.empty() && price[st.top()] <= price [i]){
               st.pop();
           }
           
           if(st.empty()){
                ans.push_back(i+1);
           }
           else
           {
                ans.push_back(i-st.top());
           }
           st.push(i);
       }
       
       return ans;
    }
};
