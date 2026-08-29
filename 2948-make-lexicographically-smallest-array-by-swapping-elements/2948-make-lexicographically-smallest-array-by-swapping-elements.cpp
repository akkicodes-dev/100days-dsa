#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<deque<int>> groups;          // list of queues
        unordered_map<int,int> numToGroup;  // nums[i] -> groups index

        for (int n : sortedNums) {
            if (groups.empty() || abs(n - groups.back().back()) > limit) {
                groups.push_back(deque<int>());
            }
            groups.back().push_back(n);
            numToGroup[n] = groups.size() - 1;
        }

        vector<int> res;
        for (int n : nums) {
            int j = numToGroup[n];
            res.push_back(groups[j].front());
            groups[j].pop_front();
        }
        return res;
    }
};