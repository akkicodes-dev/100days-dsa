/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    // Global counter -> total cameras jitni bhi lagengi tree mein
    int cameras = 0;

    int minCameraCover(TreeNode* root) {
        // Agar root khud hi -1 (uncovered) return kare, matlab
        // usko cover karne ke liye ek camera root pe lagani hi padegi
        if (helper(root) == -1) {
            cameras++;
        }
        return cameras;
    }

private:
    // Har node 3 states mein se ek return karega:
    //  -1 -> is node ko camera chahiye (abhi tak uncovered hai)
    //   0 -> is node covered hai (kisi child ya khud pe camera hai) but iske paas khud camera nahi
    //   1 -> is node pe khud camera lagi hui hai
    int helper(TreeNode* root) {

        // Base case: null node covered maana jaata hai, LEKIN camera wala nahi
        // (isliye 0 return hoga, na ki 1 — yehi wo bug tha)
        if (root == nullptr) return 0;

        // Pehle apne left aur right subtree ka status pata karo
        int lchild = helper(root->left);
        int rchild = helper(root->right);

        // Agar koi bhi child uncovered (-1) hai, toh parent (current node)
        // pe camera lagani padegi taaki wo uncovered child cover ho jaaye
        if (lchild == -1 || rchild == -1) {
            cameras++;          // ek camera yaha lagai
            return 1;           // ab yeh node khud camera wala hai
        }

        // Agar dono child mein se koi bhi camera wala (1) hai,
        // toh current node automatically covered ho jaata hai
        if (lchild == 1 || rchild == 1) {
            return 0;            // covered hai, but khud camera nahi
        }

        // Agar dono child "covered" (0) hain but camera wale nahi,
        // toh current node khud abhi tak uncovered hai — parent ko bata do
        return -1;
    }
};