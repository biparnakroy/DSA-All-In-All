class Solution {
public:
    // Function to count how many numbers are in the range [prefix, prefix + 1)
    long long countNumbersInRange(long long prefix, long long n) {
        long long count = 0;
        long long cur = prefix;
        long long next = prefix + 1;

        while (cur <= n) {
            count += min(n + 1, next) - cur;
            cur *= 10;
            next *= 10;
        }

        return count;
    }

    int findKthNumber(int n, int k) {
        long long cur = 1; // Start with the smallest prefix, which is 1
        k--;               // We treat k as 0-based to simplify logic

        while (k > 0) {
            // Count how many numbers are between [cur, cur+1)
            long long count = countNumbersInRange(cur, n);

            if (count <= k) {
                // If k is larger than or equal to the count, it means the k-th
                // number is not in this subtree, so we skip this subtree and
                // move to the next prefix.
                cur++;
                k -= count;
            } else {
                // If k is smaller than the count, the k-th number is in this
                // subtree, so we go deeper (move to cur * 10).
                cur *= 10;
                k--; // We take one step deeper into the tree
            }
        }

        return cur;
    }
};