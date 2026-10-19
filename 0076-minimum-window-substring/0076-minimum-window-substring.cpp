class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return "";

        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        int required = need.size();
        int formed = 0;

        unordered_map<char, int> window;

        int left = 0, right = 0;
        int minLen = INT_MAX, startIdx = 0;

        while (right < (int)s.size()) {
            char c = s[right];
            window[c]++;

            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};