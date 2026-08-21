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
            if(i > index && candidates[i] ==candidates[i-1] ){
                continue;
            }
            v.push_back(candidates[i]);
            combinationSum_Helper(candidates, target-candidates[i],v, ans, i+1);//i+1 ka logic hi bhoat important hota hai  esme wo  kya karta hai pichle wale element ko leta hi nahi hai agge ke letaa hai jeese 
            v.pop_back();//hum yaha pe back trace kr rahe hai
        }
    }
  
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
          vector<vector<int>>ans;
        vector<int>v; // ye currrent vector hai matlab humne elements kya kya bana ke rakhe hau 
        combinationSum_Helper(candidates, target,v, ans, 0);//ye kyu bana rahe hai hum kyuki  hame ek index chaiye 
          // push ans into  the set
    //  set<vector<int>> st;
    //   for(auto e:ans){
    //    st.insert(e);
    //  }
    //   ans.clear();

    //  for(auto e:st){
    //     ans.push_back(e);//only unique vectors
    //  }
        return ans;

    }
};