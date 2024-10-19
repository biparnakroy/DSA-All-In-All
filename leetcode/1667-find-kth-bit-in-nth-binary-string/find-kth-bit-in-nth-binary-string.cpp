class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) {
            return '0'; // Base case: S_1 = "0"
        }

        int len = (1 << n) - 1; // Length of S_n is 2^n - 1
        int mid = len / 2 + 1;  // Middle position

        if (k == mid) {
            return '1'; // Middle bit is always '1'
        } else if (k < mid) {
            // If k is in the first part (S_(n-1))
            return findKthBit(n - 1, k);
        } else {
            // If k is in the second part, invert the corresponding bit in
            // S_(n-1)
            int mirroredK = len - k + 1;
            char mirroredBit = findKthBit(n - 1, mirroredK);
            return mirroredBit == '0' ? '1' : '0'; // Invert the bit
        }
    }
};