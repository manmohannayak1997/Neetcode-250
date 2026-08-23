/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool containsOne(TreeNode* root) {

        if (root == nullptr)
            return false;

        bool leftHasOne = containsOne(root->left);
        bool rightHasOne = containsOne(root->right);

        if (!leftHasOne)
            root->left = nullptr;

        if (!rightHasOne)
            root->right = nullptr;

        return root->val == 1 ||
               leftHasOne ||
               rightHasOne;
    }

    TreeNode* pruneTree(TreeNode* root) {

        if (containsOne(root))
            return root;

        return nullptr;
    }
};