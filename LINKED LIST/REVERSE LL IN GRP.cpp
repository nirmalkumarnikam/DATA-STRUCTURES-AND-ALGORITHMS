class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
      
        if(head == NULL || head->next == NULL)return head; //base condition to recursive function
      
        node* temp = NULL;      //will point to next
        node* curr = head;      //will point to curr
        node* prev = NULL;      //will point to prev
        int count = 0;
        
        while(count<k && curr !=NULL){
            temp = curr->next;           
            curr->next=prev;
            prev = curr;
            curr = temp;
            count++;
        }
        
        head ->next = reverse(temp, k);
        
        return prev;
    }
};