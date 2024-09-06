/*
what is balanced tree: difference between height of left part and part should be <= 1 at each node.

Algo:
1)we will travel each node and calculate height 
2) we will maintain bool ans for each traversal 
3) if difference between height of left tree and right tree is <=1 ans is true, else false;
4) then we will check for next left and right tree.

*/


class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    int height(Node* root){
        if(root == NULL){
            return 0;
        }
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return max(lh,rh)+1;
    }
    
    bool isBalanced(Node *root)
    {
        if(root == NULL)return 1;
        
        bool ans = abs(height(root->left)-height(root->right))<=1;
        
        return ans && isBalanced(root->left) && isBalanced(root->right);
    }
};