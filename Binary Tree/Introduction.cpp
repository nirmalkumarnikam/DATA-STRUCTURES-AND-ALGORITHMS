#include <iostream>
#include<queue>
#include<stack>
using namespace std;


class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"ENTER DATA: ";
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"\n Enter the data to the left of "<<data<<" : ";
    root->left = buildTree(root->left);
    cout<<"\n Enter the data to the right of "<<data<<" : ";
    root->right = buildTree(root->right);

    return root;
}

void LevelOrderTraversal(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

    // queue: 1 NULL 3 5 NULL 7 11 17 NULL 

        node* temp = q.front();
        q.pop();

        if(temp == NULL){    //purana level complete hua
            cout<<endl;

            if(!q.empty()){//queue has some child node.
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }

}

void ReverseLevelOrderTraversal(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    stack<node*>st;
    while(!q.empty()){

    // queue: 1 NULL 3 5 NULL 7 11 17 NULL 

        node* temp = q.front();
        q.pop();

        if(temp == NULL){    //purana level complete hua
            cout<<endl;

            if(!q.empty()){//queue has some child node.
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
        st.push(temp);
    }

    while(!st.empty()){
        if(st.top()==NULL){
            cout<<endl;
        }else{
            cout<<st.top()->data<<" ";
        }
        st.pop();
    }
}

int main(){
    cout<<"hello tree"<<endl;
    node* root = NULL;
    // Binart Tree: 1 3 5 7 11 17
    //Enter data: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    cout<<"\nLevelOrderTraversal: "<<endl;
    LevelOrderTraversal(root);
    cout<<"\nReverceLevelOrderTraversal: "<<endl;
    ReverseLevelOrderTraversal(root);
    return 0;
}