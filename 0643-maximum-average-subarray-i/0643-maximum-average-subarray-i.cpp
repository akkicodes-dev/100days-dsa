class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        // deque<int> dq;
       // vector<int> ans;

        // 1st window sathi
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
       int maxSum = sum;

       //start slsidng window
       int startIndex =0;
       int endindex = k;
       while(endindex < nums.size()){
        sum -=nums[startIndex]; // remove the previous element
        startIndex++;

        sum += nums[endindex];// add next element
        endindex++;

        maxSum = max(maxSum,sum);//Update the Sum
       }

       // return the avarage
       return (double) maxSum/ k;
    }
};