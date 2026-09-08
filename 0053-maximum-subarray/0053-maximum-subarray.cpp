class Solution {
public:
    int maxSumArrayHelper(vector<int>& v, int start, int end){
        if(start == end){
            return v[start];
        }
        int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
        int mid =  start + ((end-start)>>1); // agar hum chate hai ki pehle - operation perform ho  bad me divede wa;a to  bracket bhoatimportant hai  uske liye 

        int maxLeftSum = maxSumArrayHelper(v, start, mid);
        int maxRightSum = maxSumArrayHelper(v, mid + 1, end);

        //max cross Border sum.
        int leftBorderSum = 0, rightBorderSum = 0;
        for(int i=mid; i>= start; i--){
           // yaha  pe left side ka maximum nikal  rahe hai 
            leftBorderSum += v[i];
            if(leftBorderSum > maxLeftBorderSum) maxLeftBorderSum = leftBorderSum;
        }

        for(int i=mid+1; i <= end; i++){
           // yaha  pe right side ka maximum nikal  rahe hai 
            rightBorderSum += v[i];
            if(rightBorderSum > maxRightBorderSum) maxRightBorderSum = rightBorderSum;
        }
        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum ;
        return max(maxLeftSum,max(maxRightSum,crossBorderSum));
        }
    int maxSubArray(vector<int>& nums) {
      return maxSumArrayHelper(nums, 0, nums.size()-1);
    }
};