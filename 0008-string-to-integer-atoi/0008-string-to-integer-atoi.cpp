class Solution {
public:
    int myAtoi(string s) {
        int num = 0, i = 0, sign = 1; // +ve maan ke chalte hain

        // Step 1: leading white spaces skip karo
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Step 2: sign determine karo (+ ya -)
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '+') ? 1 : -1;
            ++i;
        }

        // Step 3: digits padho jab tak digit milte rahein
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Overflow check: yaha pe bug tha!
            // Galat tha: (INT_MAX/10 && s[i] > '7')  -> yeh hamesha true (constant hai)
            // Sahi hai: num already INT_MAX/10 ke BARABAR ho, tabhi last digit check karo
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7)) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }

            num = num * 10 + digit; // digit ko number mein jodo
            ++i;
        }

        return num * sign;
    }
};