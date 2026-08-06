class Solution {
public:
    // ============================================================
    // canJump(nums)
    // MATLAB: "Kya index 0 se shuru karke last index tak pahunch 
    //          sakte hain?" (har index pe nums[i] tak jump allowed hai)
    //
    // APPROACH: GREEDY (recursion/DP ki zaroorat nahi is problem mein!)
    // INSIGHT: Humein har possible path track karne ki zaroorat nahi.
    //          Bas itna kaafi hai — "ab tak sabse door kaunsa index 
    //          reach kar sakte hain" (maxReach). Agar current index 
    //          us maxReach ke andar hai, toh wahan pahuchna guaranteed 
    //          possible hai (chahe wo kisi bhi combination of jumps se ho)
    // ============================================================
    bool canJump(vector<int>& nums) {
        
        // maxReach = "ab tak ka sabse door index jahan tak pahunch sakte hain"
        // Shuru mein hum index 0 pe khade hain, toh maxReach = 0 
        // (bina kuch kiye bhi index 0 toh "reachable" hai hi)
        int maxReach = 0;
        
        int n = nums.size();

        // Array ko LEFT SE RIGHT, EK BAAR traverse karo (O(n), no recursion)
        for (int i = 0; i < n; i++) {

            // ---------- CHECK: Kya current index 'i' reachable hai? ----------
            // Agar 'i' hamare 'maxReach' se AAGE nikal gaya hai, matlab 
            // hum yahan tak pahunch hi nahi sakte kisi bhi combination 
            // of jumps se — STUCK ho gaye kahin pehle
            // (jaise agar maxReach = 3 tha but ab i = 4 pe hain, 
            //  matlab koi bhi purana jump humein 4 tak laa hi nahi paya)
            if (i > maxReach) {
                return false;   // is index unreachable → seedha fail
            }

            // ---------- UPDATE: maxReach ko badhao (agar possible ho) ----------
            // Current index 'i' se hum 'nums[i]' tak jump kar sakte hain,
            // matlab yahan se hum index (i + nums[i]) tak pahunch sakte hain
            // Agar ye purane maxReach se zyada door hai, toh maxReach update karo
            // (max() isliye taaki maxReach kabhi GHATE nahi, sirf badhe ya same rahe)
            maxReach = max(maxReach, i + nums[i]);

            // ---------- OPTIONAL EARLY EXIT (chahe toh add kar sakte ho) ----------
            // Agar maxReach already last index (n-1) ko cross/touch kar chuka hai,
            // toh loop poora chalane ki zaroorat nahi, turant true return kar sakte ho
            // if (maxReach >= n - 1) return true;
        }

        // Loop poora complete ho gaya bina kahin stuck hue → 
        // matlab har index reachable tha, including last index
        return true;
    }
};

// ============================================================
// 🧠 REVISION CHEAT SHEET:
// ============================================================
// PATTERN NAME: Greedy — "Max Reach Tracking"
//
// KAB USE KARE YE PATTERN: 
//   Jab problem sirf reachability (true/false) puche, aur "kahan 
//   tak pahunch sakte ho" jaisa concept ho — recursion/DP se pehle 
//   greedy socho: "kya ek single variable track karke kaam chal sakta hai?"
//
// KEY VARIABLE: maxReach — "sabse door jahan ab tak pahunch sakte hain"
//
// CORE LOGIC (2 lines):
//   if (i > maxReach) return false;         // stuck ho gaye
//   maxReach = max(maxReach, i + nums[i]);   // reach update karo
//
// WHY GREEDY WORKS HERE: 
//   Humein YE nahi jaanna ki EXACTLY kaunse jumps le kar end tak 
//   pahunche — bas itna jaanna hai ki possible hai ya nahi. Isliye 
//   "maximum reach" track karna kaafi hai, har path explore karne 
//   ki zaroorat nahi (isi wajah se O(2^n) recursion → O(n) greedy 
//   mein convert ho gaya)
//
// TIME COMPLEXITY: O(n) — single pass
// SPACE COMPLEXITY: O(1) — koi extra array/dp table nahi chahiye
//
// RELATED PROBLEMS (same greedy family):
//   Jump Game II (minimum jumps chahiye — thoda alag greedy)
//   Jump Game III (yahan values negative bhi ho sakti, DP/BFS chahiye)
//   Gas Station problem (similar "greedy reach" flavor)
// ============================================================