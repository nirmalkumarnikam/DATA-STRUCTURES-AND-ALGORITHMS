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

void buildFromLevelOrderTraversal(node* &root){
    int data;
    cout<<"Enter Root Data: ";
    cin>>data;

    root = new node(data);

    queue<node*> q;

    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the Data to the left of "<<temp->data<<" ";
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            node* leftNode = new node(leftData);
            temp->left = leftNode;
            q.push(leftNode);
        }



        cout<<"Enter the Data to the right of "<<temp->data<<" ";
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            node* rightNode = new node(rightData);
            temp->right = rightNode;
            q.push(rightNode);
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


void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<" "<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL){
        return;
    }

    cout<<" "<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<" "<<root->data<<" ";
}



int main(){
    cout<<"hello tree"<<endl;
    node* root = NULL;
    // Binart Tree: 1 3 5 7 11 17
    //Enter data: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root = buildTree(root);
    buildFromLevelOrderTraversal(root);
    cout<<"\nLevelOrderTraversal: "<<endl;
    LevelOrderTraversal(root);
    cout<<"\nReverceLevelOrderTraversal: "<<endl;
    ReverseLevelOrderTraversal(root);

    cout<<"\nInorder Traversal:";
    inorder(root);
    cout<<"\nPreOrder Traversal:";
    preorder(root);
    cout<<"\nPostorder Traversal:";
    postorder(root);


    return 0;
}