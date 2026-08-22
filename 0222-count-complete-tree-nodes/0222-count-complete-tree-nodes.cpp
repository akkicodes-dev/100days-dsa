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
    int findHeightLeft(TreeNode* root){
        int h =0;
        while(root){ // jab tak  apka root node hai  wo  null na hojaye
            h++;
            root = root->left;
        }
        return h;
    }
     int findHeightRight(TreeNode* root){
        int h =0;
        while(root){ // jab tak  apka root node hai  wo  null na hojaye
            h++;
            root = root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;

        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        if(lh == rh){
            //FCBT
            return(1<<lh)-1;// 2^h-1 kardiya hai
        }
        //lh != rh
        int countLeft = countNodes(root->left);
        int countRight = countNodes(root->right);
        return countLeft + countRight + 1;
    
    }
};