class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
        unordered_map<Node*, bool>visited;
       Node* temp=head;
       Node* prev=head;
       visited[temp]= true;
       while(temp!=NULL && temp->next != NULL){
           temp=temp->next;
           if(!visited[temp]){
               visited[temp]=true;
           }else{
               return temp->data;
           }
           prev=temp;
       }
       
       return -1;
       
    }
};
