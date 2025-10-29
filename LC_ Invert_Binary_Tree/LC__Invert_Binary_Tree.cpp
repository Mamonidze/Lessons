
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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* current = root;
        if(f(current))
        {
            return root;
        }
        return current;
    }

    bool f (TreeNode* current)
    {
        if(current == nullptr)
        {
            return true;
        }
        TreeNode* temp = current->right;
        current->right = current->left;
        current->left = temp;
        return f(current->left) && f(current->right);
    }

};