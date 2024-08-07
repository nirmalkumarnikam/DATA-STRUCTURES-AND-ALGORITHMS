#include <vector>
#include <stack>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while (node != NULL || !st.empty()) {
            // Reach the leftmost node of the current node
            while (node != NULL) {
                st.push(node);
                node = node->left;
            }

            // Current node is NULL, pop the node from the stack and process it
            node = st.top();
            st.pop();

            inorder.push_back(node->val);

            // Visit the right subtree of the current node
            node = node->right;
        }

        return inorder;
    }
};
