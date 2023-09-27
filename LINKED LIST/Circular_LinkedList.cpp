#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node( int d ){
        this -> data = d;
        this -> next = NULL;
    }

    ~Node(){
        int value= this -> data;
        if (this-> next != NULL){
            delete next;
            next = NULL;
        }
        cout<<" memmory is freed  for node with data "<< value << endl;
    }

};

void insertNode(Node* &tail, int element, int d){
    //we are assumong that ement is present in list
    
    //empty list,,,
    if(tail==NULL){
        Node* newNode= new Node(d);
        tail= newNode;
        tail->next=newNode;
    }
    else{
        Node* temp = new Node(d);
        Node* curr = tail;
        while(curr -> data != element){
            curr= curr->next;
        }

        //now we have reched to the desired node
        temp -> next = curr -> next;
        curr -> next = temp;
    }

}

void print( Node* &tail){
    Node* temp = tail;

    //if list is empty
    if(tail == NULL){
        cout<<"List is Empty "<<endl;
        return;
    }

    do
    {
        cout<<tail -> data <<" ";
        tail = tail -> next; 
    } while (tail != temp);
    cout<<endl;
}

void deleteNode(Node* &tail, int value){
    //if the list is empty
    if(tail == NULL){
        cout<<"List is empty , please check again"<<endl;
        return;
    }
    else{
        //non empty list
        
        //assuming the list contains atleast one element

        Node* prev = tail;
        Node* curr = prev -> next;
        
        while(curr->data != value){
            prev = curr;
            curr = curr -> next;
        }



        prev -> next = curr -> next;
        
        // 1 Node Linked List
        if(tail==curr){
            tail==prev;
        }

        // >=2 Node Linked List
        if( tail == curr ){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

int main(){

    Node* tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 88);
    print(tail);
    insertNode(tail, 88, 99);
    print(tail);
    insertNode(tail, 3, 77);
    print(tail);
    
    deleteNode(tail, 3);
    print(tail);    

    return 0;
}