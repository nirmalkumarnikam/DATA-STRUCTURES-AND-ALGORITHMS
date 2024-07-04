
// TC: O(n)
// SC: O(n)
class Solution{
public:
    void Reverse(stack<int> &St){
        vector<int>ans;
        while(!St.empty()){
            ans.push_back(St.top());
            St.pop();
        }
        
        int num = ans.size();
        int n = 0;
        while(n<num){
            St.push(ans[n]);
            n++;
        }
    }
};


// TC: O(n)
// SC: O(n)
class Solution{
public:
    void Reverse(stack<int> &St){
        stack<int>newst;
        
        while(!St.empty()){
            newst.push(St.top());
            St.pop();
        }
        
        St = newst;
    }
};


/*
Algo: 
Reverse: (remove top element and insert it at bottom of stack)

If the stack is empty, do nothing (base case).
Remove the top element.
Recursively call Reverse to reverse the rest of the stack.
Insert the removed element at the bottom of the reversed stack using insertAtBottom.

insertAtBottom:
If the stack is empty, push the element ele.
Otherwise, remove the top element and recursively call insertAtBottom to place ele at the bottom.
After the recursive call, push the removed element back onto the stack, ensuring that ele remains at the bottom.


TC: 2^n
SC: 1
*/




class Solution {
public:

    // Function to insert an element at the bottom of a stack
    void insertAtBottom(stack<int> &st, int ele) {
        // Base case: If the stack is empty, push the element onto the stack
        if(st.empty()) {
            st.push(ele);
            return;
        }
        
        // Otherwise, remove the top element and recursively call insertAtBottom
        int removeElement = st.top();
        st.pop();
        insertAtBottom(st, ele);
        
        // After the recursive call, push the removed element back onto the stack
        st.push(removeElement);
    }

    // Function to reverse a stack
    void Reverse(stack<int> &st) {
        // Base case: If the stack is empty, do nothing
        if(st.empty()) {
            return;
        }
        
        // Remove the top element of the stack
        int element = st.top();
        st.pop();
        
        // Recursively call Reverse to reverse the remaining stack
        Reverse(st);
        
        // Insert the removed element at the bottom of the reversed stack
        insertAtBottom(st, element);
    }
};
