// class Solution {
// public:
//     void solve(vector<int>& nums,int i,int &ans, int step){
//         if(i == nums.size() -1) {
//             ans = min(ans, step);
//             return ;
//             }// means me succesesfully poch gaya hua destionation return kardiya index maine 
//         if(i >=nums.size()) return; //array out of bounds hogvay hai
//        //if( nums[i] == 0 ) return false;// app stuck hogaye ho app agge nahi  jaa sakte hai

      
//         for(int jump = 1; jump <= nums[i]; jump++){
//            solve(nums, i+ jump,ans,step+1);
//         }
//         //return reAns;
//     }

//     int jump(vector<int>& nums) {
//         int ans = INT_MAX;
//         solve(nums,0,ans,0);
//         return ans;
//     }
// };


class Solution {
public:
    int jump(vector<int>& nums) {
        int near = 0, far = 0, jumps = 0;

        while (far < nums.size() - 1) {
            int farthest = 0;
            for (int i = near; i <= far; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            near = far + 1;
            far = farthest;
            jumps++;
        }

        return jumps;        
    }
};
