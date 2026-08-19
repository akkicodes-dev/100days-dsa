class Solution {
public:
    void solve(vector<int>& nums, int i,vector<vector<int>> & ans ){
        //base case
        if(i >= nums.size()){ // one more important thing vector me length() nahi  hota size() hota hai  
            ans.push_back(nums);
            return;
        }

        //1 case slove karte hai
        for(int j =i; j < nums.size(); j++){
            swap(nums[i], nums[j]);
            solve(nums, i+1, ans);
            swap(nums[i],nums[j]);// Backtracking orginal me convert hogayega 
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       solve(nums, 0, ans);
       return ans;
    }
};