Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:
Input:
Stack: 3 2 1
Output: 3 2 1

Example 2:
Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2



void insertsorted(stack<int> &s, int num)
{
    if(s.empty() || (!s.empty()) && s.top() < num )
    {
        s.push(num);
        return;
    }
    
    int n = s.top(); 
    s.pop();
    
    insertsorted(s,num);
    s.push(n);
    
}


void SortedStack :: sort()
{
   //Your code here
   if(s.empty())
   {
       return;
   }
   
   int num = s.top();
   s.pop();
   
   sort();
   
   insertsorted(s, num);
}
