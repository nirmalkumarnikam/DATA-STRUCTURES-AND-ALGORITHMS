 //iterative approach
    struct Node* reverseList(struct Node *head)
    {
        Node* temp = NULL;
        Node* prev = NULL;
        
        while(head != NULL){
            temp = head->next;
            head->next=prev;
            prev = head;
            head = temp;
            
        }
        
        return prev;
    }
    

//recursive approach
    
    struct Node* reverse(struct Node*prev,struct Node* curr){
        if(curr != NULL){
            Node* temp = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
            
            return reverse(prev, curr);
        }
        else
        {
            return prev;
        }
    }
    
    struct Node* reverseList(struct Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        
        return reverse(prev, curr);
    }
