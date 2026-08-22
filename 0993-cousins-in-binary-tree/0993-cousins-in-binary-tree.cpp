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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,nullptr});
        while(!q.empty())
       { 
        
        bool foundX = false,foundY = false;
        TreeNode *parentX = nullptr,*parentY = nullptr;
        int size = q.size();
        int i = 0;
        while(i<size)
        {
            TreeNode *node = q.front().first;
            TreeNode *parent = q.front().second;
            q.pop();
            if(node->val == x){
                foundX = true;
                parentX = parent;
            }
             if(node->val == y){
                foundY = true;
                parentY = parent;
            }
             if(node->left){
                q.push({node->left,node});
            }
             if(node->right){
                q.push({node->right,node});
            }
            i++;
        }
    if(foundX && foundY)
        return (parentX != parentY); 
    if(foundX || foundY)
        return false;

       }
    return false;
          
    }
};