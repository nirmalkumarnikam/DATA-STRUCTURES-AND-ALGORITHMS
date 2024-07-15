
/*
Recursive
TC= O(n)
SC= O(n)   worst case when skew binary tree is given
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1+max(lh,rh);
    }
};





/*
Level Order Traversal
TC= O(n)
SC= O(n)   worst case when complete binary tree is given
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int count = 0;
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == nullptr){
                count++;
                if(!q.empty()){
                    q.push(nullptr);
                }
            }else{
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        
        return count;
    }
};