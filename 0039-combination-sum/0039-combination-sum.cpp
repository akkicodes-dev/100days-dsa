class Solution {
public:
    void  combinationSum_Helper(vector<int>& candidates, int target, vector<int> v,   vector<vector<int>>& ans, int index){
        //base case
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(target < 0){
            return;
        }

        for(int i=index; i<candidates.size();i++){
            v.push_back(candidates[i]);
            combinationSum_Helper(candidates, target-candidates[i],v, ans, i);
            v.pop_back();//hum yaha pe back trace kr rahe hai
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v; // ye currrent vector hai matlab humne elements kya kya bana ke rakhe hau 
        combinationSum_Helper(candidates, target,v, ans, 0);//ye kyu bana rahe hai hum kyuki  hame ek index chaiye 
        return ans;
    }
};