class Solution {
public:

    int solve(vector<int>& nums, int index, vector<int>& dp) {

        // Base Case:
        // Agar saare houses dekh liye to lootne ke liye kuch nahi bacha.
        if(index >= nums.size()) {
            return 0;
        }

        // Optimization (Memoization):
        // Agar is index ka answer pehle se calculate hai,
        // to recursion dobara chalane ki zaroorat nahi.
        if(dp[index] != -1) {
            return dp[index];
        }

        // Choice 1: Current house loot lo.
        // Fir next adjacent house nahi loot sakte,
        // isliye index + 2 par jump karenge.
        int includeAns = nums[index] + solve(nums, index + 2, dp);

        // Choice 2: Current house skip kar do.
        // Fir next house consider kar sakte hain.
        int excludeAns = solve(nums, index + 1, dp);

        // Dono choices me se maximum profit choose karo.
        int finalAns = max(includeAns, excludeAns);

        // IMPORTANT:
        // Yehi optimization hai.
        // Is index ka answer store kar diya.
        // Next time same index aaya to direct use karenge.
        dp[index] = finalAns;

        return dp[index];
    }

    int rob(vector<int>& nums) {

        // DP array:
        // dp[i] = maximum loot possible starting from index i
        vector<int> dp(nums.size(), -1);

        return solve(nums, 0, dp);
    }
};