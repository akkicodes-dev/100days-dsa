class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) return 0;
        if (n < 1000000) return n - 999;
        if (n < 1000000000LL) return 999000 + (n - 1000000LL + 1) * 2;
        if (n < 1000000000000LL) return 1998999000LL + (n - 1000000000LL + 1) * 3;
        if (n < 1000000000000000LL) return 2998998999000LL + (n - 1000000000000LL + 1) * 4;
        // n == 1000000000000000 (max limit, 16-digit number, needs special handling)
        return 3998998998999000LL + 5;
    }
};