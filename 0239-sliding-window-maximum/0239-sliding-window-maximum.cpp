
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {

            // Removal: window ke bahar wala index remove karo
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Removal: chhote elements ke indices remove karo
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Addition: current index add karo
            dq.push_back(i);

            // Answer save karo
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
