/*
Brute Force:
initiate a map<Node, bool>
check the value of each bool if visited or not, if visited return true
mark value of each Node as true when we go through it

Time complexity: O(n)
Space ComplexityL O(n)
*/

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        Node* temp = head;
        unordered_map<Node*, bool>visited;
        visited[temp]=true;;
        while(temp!=NULL){
            temp=temp->next;
            if(!visited[temp])
            {   
                visited[temp]=true;
            }else{
                return true;
            }
            
        }
        return false;
    }
};





/*
Optimal:
Floyd Algorithm
make two Nodes fast and slow.
fast will move two times and slow will move 1 time in single iteration
if a loop exists then fast and slow will meet in the future.
else fast will reach null and we return false.

Time complexity: O(n)
Space ComplexityL O(1)
*/

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        if(head->next == NULL)return false;
        
        Node* slow=head;
        Node* fast=head;
        
        while(fast->next!=NULL && fast!=NULL){
            
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            
            slow=slow->next;
            
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};





