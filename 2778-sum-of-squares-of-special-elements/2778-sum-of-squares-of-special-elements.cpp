class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n  = nums.size();
        int sum =0;
        for(int i =0; i <= n-1;i++){
        if(n % (i+1) == 0){
          sum += nums[i] * nums[i];
        }

        }
        return sum;
    }
};