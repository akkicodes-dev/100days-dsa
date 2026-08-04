// class Solution {
// public:
//    void solve(vector<vector<int>>& mat, int & target,int sum, int row, int & mini){
//         if(row == mat.size()){
//            mini =min(mini , abs(target - sum));
//            return;
//         }
//         int ans = INT_MAX; //3 call particularly minimize karna hai to esiliye int_max le liyaaa 
//         for(int col=0; col <mat[row].size(); col++){
//           solve(mat, target, sum + mat[row] [col], row + 1, mini);
//             //ans = min(ans, reAns ); // it is inbuilt function in c++
//         }
//         //return ans;
//     }

//     int minimizeTheDifference(vector<vector<int>>& mat, int target) {
//         int sum = 0 ,row =0, mini = INT_MAX;
//         solve(mat,target,sum,row,mini);
//         return mini;
//     }
// };


class Solution {
public:
    int target; // class member bana diya, taaki solve() mein baar baar pass na karna pade

    // solve(row, sum) = "row se lekar last row tak best choices karke,
    //                    minimum |target - finalSum| kya milega"
    int solve(vector<vector<int>>& mat, int row, int sum, 
              vector<vector<int>>& dp) {

        // BASE CASE: saari rows process ho chuki hain
        // ab jo 'sum' bana hai, wahi final sum hai — uska answer nikaal ke return kar
        if (row == mat.size()) {
            return abs(target - sum);
        }

        // MEMOIZATION CHECK: 
        // agar (row, sum) state pehle solve ho chuki hai, dobara mat karo — seedha return
        if (dp[row][sum] != -1) {
            return dp[row][sum];
        }

        int best = INT_MAX;

        // is row ke har column (choice) ko try karo
        for (int col = 0; col < mat[row].size(); col++) {
            int result = solve(mat, row + 1, sum + mat[row][col], dp);
            best = min(best, result); // sabse chhota difference wala best hai
        }

        // is state ka answer dp table mein SAVE karo (future reuse ke liye)
        // aur wahi answer return bhi karo
        return dp[row][sum] = best;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        this->target = target; // member variable set kiya

        int m = mat.size();
        int maxSum = 70 * m; // worst case: har row se max element (70) le liya

        // dp[row][sum] = us state ka pehle se calculate kiya hua answer (-1 = not computed)
        vector<vector<int>> dp(m, vector<int>(maxSum + 1, -1));

        // shuru row=0 se, sum=0 se karo
        return solve(mat, 0, 0, dp);
    }
};