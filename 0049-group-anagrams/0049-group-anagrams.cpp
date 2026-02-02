// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(const vector<string>& strs) {
//         map<string,vector<string>>mp;

//         for(auto str: strs){
//             string s = str;
//             sort(s.begin(), s.end());
//             mp[s].push_back(str);
//         }
//         vector<vector<string>> ans;
//         for(auto it =mp.begin(); it!=mp.end(); it++){
//             ans.push_back(it -> second);
//         }
//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// };


// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(const vector<string>& strs) {

//         // Map to store sorted string as key and all its anagrams as values
//         map<string, vector<string>> mp;

//         // Loop through every string and group them by sorted key
//         for (auto str : strs) {
//             string s = str;               // make a copy
//             sort(s.begin(), s.end());     // sorted string becomes the key
//             mp[s].push_back(str);         // push original string into the group
//         }

//         vector<vector<string>> ans;

//         // Extract all groups from the map into ans
//         for (auto it = mp.begin(); it != mp.end(); it++) {
//             ans.push_back(it->second);
//         }

//         // 🔥 VERY IMPORTANT: Sort inside each group so expected output matches
//         for (auto &v : ans) {
//             sort(v.begin(), v.end());
//         }

//         // Sort the groups themselves
//         sort(ans.begin(), ans.end());

//         return ans;
//     }
// };



class Solution {
public:
    
    std::array<int,256>hash(string s){
        std::array<int,256>hash={0};

        for(int i=0; i<s.size();i++){
            hash[s[i]]++;
        }
        return hash;
    }

    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        map<std::array<int,256>,vector<string>>mp;

        for(auto str: strs){
            
            mp[hash(str)].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it =mp.begin(); it!=mp.end(); it++){
            ans.push_back(it -> second);
        }

        for (auto &v : ans) {
                         sort(v.begin(), v.end());
     }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

