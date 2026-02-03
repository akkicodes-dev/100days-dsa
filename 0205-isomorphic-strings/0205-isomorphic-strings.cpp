// class Solution {
// public:
//     bool isIsomorphic(const string& s, const string& t) {
//         int hash[256] = {0}; //mapping of each char of language' s to Language 't'
//         bool isTCharsMapped[256]={0}; // stores if t [i] char already mapped wwith s[i].

//         for(int i=0; i<s.size(); i++){
//            if(hash[s[i]] == 0 && isTCharsMapped[t[i]] == 0){
//                 hash[s[i]] = t[i];
//                 isTCharsMapped[t[i]] = true;
//            }
//         }
//         for(int i=0; i< s.size(); i++){
//             if(char(hash[s[i]]) != t[i]){
//                 return false;
//             }
//         }
//         return true;
         
//     }
// };

class Solution {
public:
    bool isIsomorphic(const string& s, const string& t) {
        int hash[256]; 
        bool isTCharsMapped[256] = {0};

        // Initialize hash with -1 (so 0 value bhi valid map ban sake)
        for(int i = 0; i < 256; i++){
            hash[i] = -1;
        }

        for(int i = 0; i < s.size(); i++){
            char c1 = s[i];
            char c2 = t[i];

            // If not mapped and t[i] also not used → create mapping
            if(hash[c1] == -1 && isTCharsMapped[c2] == false){
                hash[c1] = c2;
                isTCharsMapped[c2] = true;
            }
        }

        // Validate mapping
        for(int i = 0; i < s.size(); i++){
            if(char(hash[s[i]]) != t[i]){
                return false;
            }
        }
        return true;
    }
};
