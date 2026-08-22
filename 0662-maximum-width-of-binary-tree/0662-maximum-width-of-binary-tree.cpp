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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,1});//{root, idx}
         int maxWidth = 0;
        while(!q.empty()){
            int size = q.size();
            auto leftMost = q.front().second;// yehi  queue  ka leftMost index Hoga 
            auto rightMost = q.back().second;
           maxWidth = max(maxWidth, (int)(rightMost - leftMost +1));
            for(int i=0; i<size; i++){
                auto front = q.front();
                q.pop();
                auto current = front.first;
                auto idx = front.second - leftMost; // ✅ sirf yeh ek change: overflow bachane ke liye normalize kiya
                if(current->left)q.push({current->left, 2*idx});
                if(current->right)q.push({current->right, 2*idx+1}); 

            }
        }
        return maxWidth;
    }
};