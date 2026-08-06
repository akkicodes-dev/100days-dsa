class Solution {
public:
    // Helper: kisi bhi number ke saare digits ka product nikalta hai
    int digitProduct(int num) {
        int product = 1;
        while (num > 0) {
            int digit = num % 10;
            product = product * digit;
            num = num / 10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        int candidate = n;

        // jab tak candidate ka digit product 't' se divisible NAHI hai,
        // aage badhte raho
        while (digitProduct(candidate) % t != 0) {
            candidate++;
        }

        return candidate;
    }
};