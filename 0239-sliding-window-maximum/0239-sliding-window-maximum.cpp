
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;
//         deque<int> dq;

//         for (int i = 0; i < nums.size(); i++) {

//             // Removal: window ke bahar wala index remove karo
//             if (!dq.empty() && dq.front() <= i - k) {
//                 dq.pop_front();
//             }

//             // Removal: chhote elements ke indices remove karo
//             while (!dq.empty() && nums[dq.back()] <= nums[i]) {
//                 dq.pop_back();
//             }

//             // Addition: current index add karo
//             dq.push_back(i);

//             // Answer save karo
//             if (i >= k - 1) {
//                 ans.push_back(nums[dq.front()]);
//             }
//         }

//         return ans;
//     }
// };





class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;


        //process 1st Window
        //ye addtion  wala  step hai 1st me kaaa
        for(int index =0; index < k; index++){
            //mhuje har element ke index ko  storekarna hii h
            //isme koi shak nhi hai 
            //current  lement ke index ko ignore karne kaa mere pass koi logic hi nhai hai
            //thata why store karna hi padegaa
            //but
            // ekso store karne se pehle koi iske left side me chota elment
            //already  insert ho chukaa hai  to, toh mhuje vo sab remove karne padenge 
            //vo element cannot be the  answer cannot be in the front as the  
            //current element is larger

            //addtion
            while(!dq.empty() && nums[dq.back()] < nums[index]){
                dq.pop_back();
            }

            dq.push_back(index);
        }
         //answer
         int element = nums[dq.front()];
         ans.push_back(element);


        //Remaining Window
        for(int index =k; index < nums.size(); index++){
            //removal 
            if(!dq.empty() && dq.front() <= index - k){
                dq.pop_front();
            }
              //addtion
            while(!dq.empty() && nums[dq.back()] <= nums[index]){
                dq.pop_back();
            }
            dq.push_back(index);


            //anwser
            int element = nums[dq.front()];
            ans.push_back(element);

        }
        return ans;
    }
};

