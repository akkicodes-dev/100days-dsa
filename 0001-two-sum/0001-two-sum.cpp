class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

            int n = nums.size();
            //lets find out pairs
            for(int i=0; i<n; i++){
                for(int j=i+1; j<n;j++){
                    int first = nums[i];
                    int second = nums[j];

                    int sum = first + second;

                    if(sum == target){
                        return {i,j};
                    }
                }
            }
            return {};
    }
};