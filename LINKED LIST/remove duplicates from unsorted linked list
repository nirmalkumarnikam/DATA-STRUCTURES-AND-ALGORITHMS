class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_map<int, bool>visited;
        Node*temp=head;
        
        Node*prev=head;
        
        while(temp!=NULL ){
            
            
            if(!visited[temp->data]){
                visited[temp->data]=true;
                prev=temp;
                temp=temp->next;
            }else{
                prev->next=temp->next;
                temp->next = NULL;
                delete temp;
                temp=prev->next;
            }
            
            
        }
        return head;
    }
};
