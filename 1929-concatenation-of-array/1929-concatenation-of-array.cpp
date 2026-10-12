class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans = nums;                           // copy of nums
        ans.insert(ans.end(), nums.begin(), nums.end());  // append nums again
        return ans;
    }
};