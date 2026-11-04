/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int getheight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftDepth = getheight(root->left);
        int rightDepth = getheight(root->right);
        int ans = max(leftDepth, rightDepth) + 1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        // base case
        if (root == NULL) {
            // empty treee ko  balanced hi Maan Raha huu
            return true;
        }
        // current Node ans nikalnaa hai
        int leftHeight = getheight(root->left);
        int rightheight = getheight(root->right);

        int absolutDiff = abs(leftHeight - rightheight);
        if (absolutDiff > 1) {
            // not balanced
            return false;
        } else {
            // current node  to  pakka balanced hai
            // baki  recursion se solve karwalo
        }
        // LeftAns nikalnaa hai
        bool leftAns = isBalanced(root->left);
        // rightAns nilkalna hai
        bool rightAns = isBalanced(root->right);
        if (leftAns == true && rightAns == true) {
            return true;
        } else {
            return false;
        }
    }
};