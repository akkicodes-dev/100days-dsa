class Solution {
public:
    void solve(TreeNode* root, int target, int sum, vector<int> temp, vector<vector<int>>& ans) {
        if (root == NULL) {
            return;
        }

        // current node pe kya karta hu
        sum = sum + root->val;
        temp.push_back(root->val);

        // leaf node wala case
        if (root->left == NULL && root->right == NULL) {
            if (sum == target) {
                ans.push_back(temp);
            }
            return;
        }

        solve(root->left, target, sum, temp, ans);
        solve(root->right, target, sum, temp, ans);

        // optional hai (temp by value pass ho raha hai)
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> temp;
        vector<vector<int>> ans;
        solve(root, targetSum, sum, temp, ans);
        return ans;
    }
};