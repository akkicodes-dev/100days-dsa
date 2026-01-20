class Solution {
public:
    string decodeMessage(string key, string message) {
        
        unordered_map<char, char> mp;
        char curr = 'a';  // first mapping letter

        // Build mapping from key
        for (char ch : key) {
            if (ch == ' ') continue;          // ignore spaces
            if (mp.count(ch) == 0) {          // first time letter appears
                mp[ch] = curr;                // map to current alphabet letter
                curr++;                       // move to next letter
            }
        }

        // Decode the message
        string ans = "";
        for (char ch : message) {
            if (ch == ' ') ans += ' ';        // keep spaces
            else ans += mp[ch];               // substitute using mapping
        }

        return ans;
    }
};
