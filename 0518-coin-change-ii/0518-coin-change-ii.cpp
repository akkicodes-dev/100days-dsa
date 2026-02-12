class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(amount + 1, 0));

        for(int i=0;i<n;i++)
        {
            dp[i][0] = 1;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j = 1; j<=amount;j++)
            {
                if(j-coins[i] >= 0 )
                    dp[i][j] += dp[i][j-coins[i]];

                dp[i][j] += dp[i+1][j];
            }
        }

        return dp[0][amount];
    }
};