/*
Algo:
1)Perform normal swapping on left and right child of root.
2)go ahead ie go left go right
3)Base Condition: if root is NULL return;
*/

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        if(root == NULL){
            return;
        }
        
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirror(root->left);
        mirror(root->right);
    }
};
