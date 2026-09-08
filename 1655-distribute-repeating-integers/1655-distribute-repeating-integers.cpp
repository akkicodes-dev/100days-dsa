class Solution {
public:
    bool canDistributeHelper(vector<int>& counts, vector<int>&quantity, int ithCustomer){
        //base condtion
        if(ithCustomer == quantity.size()){
            return  true;
        }
        for(int i= 0; i< counts.size(); ++i){
            if(counts[i] >= quantity[ithCustomer]){
                counts[i] -=  quantity[ithCustomer];
                if(canDistributeHelper(counts, quantity, ithCustomer +1)){
                    return true;
                }
               counts[i] +=  quantity[ithCustomer];//backtracing
            }
        }
        return false;
    }
  
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> countmap;
        for(auto num : nums ){
            countmap[num]++;
        }
        vector<int>counts;
        for(auto it: countmap){
            counts.push_back(it.second);
            sort(quantity.rbegin(), quantity.rend());// sort kardega decreasing order  me 
        }
        return canDistributeHelper(counts, quantity, 0);
    }        
};