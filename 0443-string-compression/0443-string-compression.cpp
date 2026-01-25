class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;

        for (int i = 0; i < n; i++) {
            char ch = chars[i];
            int count = 0;

            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            // BUG FIX 1:
            // You wrote "==" which compares instead of assigning.
            // It should be "=" to store the character.
            if (count == 1) {
                chars[idx++] = ch;  // <-- FIXED
            } else {
                chars[idx++] = ch;
                string str = to_string(count);

                for (char dig : str) {
                    chars[idx++] = dig;
                }
            }

            i--;  // balancing the for-loop increment
        }

        chars.resize(idx);
        return idx;
    }
};
