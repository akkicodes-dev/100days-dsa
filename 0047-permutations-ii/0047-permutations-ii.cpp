class Solution {
public:
 void solve(vector<int>& nums, int i,vector<vector<int>> & ans ){
        //base case
        if(i >= nums.size()){ // one more important thing vector me length() nahi  hota size() hota hai  
            ans.push_back(nums);
            return;
        }

        //1 case slove karte hai
        unordered_map<int, bool>visited;
        for(int j =i; j < nums.size(); j++){
            if(visited.find(nums[j]) != visited.end()){
                continue;
            }
            visited[nums[j]]= true;
            swap(nums[i], nums[j]);
            solve(nums, i+1, ans);
           swap(nums[i],nums[j]);// Backtracking orginal me convert hogayega 
        }
        // dekh gpt yaha pe sort ans ko aur i ko lungaa i+1 ko chod ese me loop chalata jaungaa if thik hai yes or no  ans bata baki ka kuch bhi mat bata;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
       solve(nums, 0, ans);
      // push ans into  the set
    //   set<vector<int>> st;
    //   for(auto e:ans){
    //     st.insert(e);
    //   }
    //   ans.clear();

    //   for(auto e:st){
    //     ans.push_back(e);
    //   }
      return ans;
    } 
};