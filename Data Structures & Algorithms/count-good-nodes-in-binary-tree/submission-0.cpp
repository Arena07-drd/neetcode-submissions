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
    int goodNodes(TreeNode* root) {
        
        return dfsCount(root, INT_MIN);
    }

    int dfsCount(TreeNode* root, int maxVal){

        if (!root){
            return 0;
        }

        int good = 0;

        if (root->val >= maxVal){
            good = 1;
            maxVal = root->val;
        }

        return good + dfsCount(root->left, maxVal) + dfsCount(root->right, maxVal);
    }
};
