class Solution {
    private:
    char findKthHelper(int k, long long length, char currentStart) {
        if (length == 1) {
            // When the length reduces to 1, we return the current character
            return currentStart;
        }
        
        long long mid = length / 2;
        
        if (k <= mid) {
            // If k is in the first half, continue with the same starting character
            return findKthHelper(k, mid, currentStart);
        } else {
            // If k is in the second half, reduce k and increment the character
            char nextChar = (currentStart == 'z') ? 'a' : currentStart + 1;
            return findKthHelper(k - mid, mid, nextChar);
        }
    }

public:
    char kthCharacter(int k) {
        // The current word starts as "a"
        char start = 'a';
        // Find the power of 2 length required to cover k
        long long length = 1;
        
        while (length < k) {
            length *= 2;
        }
        
        // Recursively reduce k
        return findKthHelper(k, length, start);
    }
};