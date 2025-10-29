
  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return f(root, root->val);
    }
    bool f(TreeNode* node, int value)
    {
        if (node == nullptr)
        {
            return true;
        }
        if(node->val != value)
        {
            return false;
        }
        return f(node->left, value) && f(node->right, value);
    }
};