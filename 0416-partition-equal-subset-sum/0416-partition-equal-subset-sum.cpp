// class Solution {
// public:
//     bool solve(vector<int>&nums, int target, int i){
//         if(target < 0 || i == nums.size()) return false;
//         if(target == 0)return true;

//         bool inc = solve(nums,target - nums[i],i + 1);//mhuje agle wale operation ke liye  i bada hona chiye particular jo  hai uske liye nahiii 2 ka 2 hi  3 agle wale me chiaye

//         bool exc = solve(nums,target,i + 1);

//         return inc || exc;
//     }

//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(),0);
//         if(sum % 2 != 0)return false;//eska matlab odd sum arhaaa hai hum divde nahi kr sakte 

//         int target = sum >>1; // it means sum divided by 2 shift operator
//         return solve(nums,target,0);

//     }
// };






class Solution {
public:
    // ============================================================
    // solve(nums, target, i, dp)
    // MATLAB: "Index i se lekar end tak ke elements mein se, 
    //          kya hum exactly 'target' sum bana sakte hain?"
    // Return: true agar possible hai, false agar nahi
    // ============================================================
    bool solve(vector<int>& nums, int target, int i, 
               vector<vector<int>>& dp) {

        // ---------- BASE CASES ----------
        // Case 1: target negative ho gaya → matlab humne itna zyada 
        //         add kar diya ki target cross ho gaya → GALAT PATH
        // Case 2: array khatam ho gaya (i == size) lekin target 
        //         abhi bhi 0 nahi hua → is path se target banana 
        //         POSSIBLE NAHI hai
        // NOTE: ye check pehle isliye hai kyunki agar target<0 hai 
        //       toh index bhi range se bahar ja sakta hai kabhi kabhi, 
        //       safety ke liye pehle check karo
        if (target < 0 || i == nums.size()) return false;

        // Case 3: target exactly 0 ban gaya → matlab humne jitne bhi 
        //         elements "include" kiye unka sum = original target 
        //         → YE EXACT MATCH HAI → true return karo turant
        //         (baaki elements ka use hi nahi karna, already ho gaya kaam)
        if (target == 0) return true;

        // ---------- MEMOIZATION CHECK ----------
        // State = (i, target) → agar ye combination pehle kabhi 
        // solve ho chuka hai (kisi aur recursion path se), toh 
        // dobara calculate mat karo — seedha purana saved answer utha lo
        // dp[i][target] == -1 matlab "abhi tak calculate NAHI hua"
        // dp[i][target] == 0  matlab "pehle calculate hua tha, answer FALSE tha"
        // dp[i][target] == 1  matlab "pehle calculate hua tha, answer TRUE tha"
        if (dp[i][target] != -1) return dp[i][target];

        // ---------- RECURSIVE CASE ----------
        // Har index pe DO choices hain current element ke liye:

        // CHOICE 1 (INCLUDE): is element (nums[i]) ko apne subset mein 
        // shamil karo → toh target ab itna kam ho jayega (kyunki 
        // itna sum toh humne already "cover" kar liya is element se)
        // agli call mein i+1 pe jao (agla element dekhne)
        bool inc = solve(nums, target - nums[i], i + 1, dp);

        // CHOICE 2 (EXCLUDE): is element ko chhod do, use mat lo
        // target waisa ka waisa rahega (kyunki kuch add nahi kiya)
        // agli call mein i+1 pe jao
        bool exc = solve(nums, target, i + 1, dp);

        // Agar DONO mein se KOI BHI ek raasta se target ban jaye, 
        // toh overall answer TRUE hai (isiliye OR use kiya, AND nahi)
        bool result = inc || exc;

        // ---------- MEMO STORE ----------
        // Is state (i, target) ka answer table mein SAVE karo, taaki 
        // agar future mein koi aur path isi (i, target) pe wapas aaye 
        // toh usko dobara calculate na karna pade — seedha yahan se utha le
        // NOTE: dp array 'int' type ka hai (bool nahi), isliye 
        //       true/false ko 1/0 mein convert karke store kar rahe hain
        dp[i][target] = result ? 1 : 0;

        return result;
    }

    // ============================================================
    // canPartition(nums)
    // MATLAB: "Kya is array ko DO EQUAL SUM waale parts mein todna 
    //          possible hai?"
    // Trick: agar total sum ko 2 equal parts mein todna hai, toh 
    //        bas ek subset dhundo jiska sum = total_sum / 2 ho.
    //        Agar wo mil gaya, baaki elements automatically doosra 
    //        half ban jayenge (kyunki total fix hai)
    // ============================================================
    bool canPartition(vector<int>& nums) {
        
        // Poore array ka total sum nikal lo
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // ---------- EARLY REJECTION ----------
        // Agar total sum hi ODD hai, toh use 2 EQUAL (integer) parts 
        // mein todna MATHEMATICALLY IMPOSSIBLE hai 
        // (kyunki odd/2 fraction ban jayega, integer nahi)
        // → Seedha false return kardo, recursion shuru karne ki 
        //   zaroorat hi nahi (bina wajah time waste)
        if (sum % 2 != 0) return false;

        // Target = half sum → hume bas itna sum wala EK subset chahiye
        // (>> 1 matlab right shift by 1 = divide by 2, same cheez hai 
        //  sum/2 likhne se, thoda fast operation hota hai)
        int target = sum >> 1;

        // ---------- DP TABLE SETUP ----------
        // dp[i][t] = "index i se aage, target t banana possible hai kya"
        // 
        // ROW dimension = nums.size() 
        //     → kyunki 'i' ki range hai 0 se (nums.size()-1) tak
        //
        // COLUMN dimension = (sum/2 + 1)
        //     → kyunki 'target' ki range hai 0 se sum/2 tak
        //     → +1 isliye kyunki 0 bhi ek valid index/value hai 
        //       (agar max value 5 hai toh 0,1,2,3,4,5 → total 6 slots chahiye)
        //
        // Initial value = -1 
        //     → matlab "is state ka answer abhi calculate NAHI hua hai"
        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));

        // Recursion shuru karo: index 0 se, poora 'target' banane ki koshish karo
        return solve(nums, target, 0, dp);
    }
};

// ============================================================
// 🧠 REVISION CHEAT SHEET (2 min mein poora yaad aa jaye):
// ============================================================
// PATTERN NAME: 0/1 Knapsack (Subset Sum variant)
//
// STATE: (i, target) — "kaunse index pe hoon, kitna target baaki hai"
//
// CHOICE: har index pe → INCLUDE karu ya EXCLUDE karu (2 options)
//
// BASE CASES:
//   target < 0        → false (overshoot ho gaya)
//   i == size          → false (elements khatam, target abhi bhi baaki)
//   target == 0        → true  (target ban gaya, kaam done)
//
// COMBINE: inc || exc  (dono mein se ek bhi chale toh TRUE)
//
// TIME COMPLEXITY: 
//   Bina DP: O(2^n)        — exponential, TLE
//   DP ke saath: O(n × sum/2) — polynomial, FAST
//
// TRICK CONNECT KARNE KE LIYE: 
//   "Equal partition" = "half sum wala subset dhundo" 
//   → ye HAMESHA subset-sum problem mein convert ho jaata hai
// ============================================================