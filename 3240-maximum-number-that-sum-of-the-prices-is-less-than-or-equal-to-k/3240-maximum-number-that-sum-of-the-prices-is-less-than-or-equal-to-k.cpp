class Solution {
public:
    long long total_price(long long n, int x) {
        long long count = 0;

        for (int i = x - 1; i < 60; i += x) {
            uint64_t total = (uint64_t)n + 1;
            uint64_t full = total / (1ULL << (i + 1));
            uint64_t rem = total % (1ULL << (i + 1));

            count += full * (1ULL << i);
            count += std::max(0LL, (long long)(rem - (1ULL << i)));
        }

        return count;
    }

    long long findMaximumNumber(long long k, int x) {
        long long low = 0, high = 1e15, ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2; // avoid overflow here too
            if (total_price(mid, x) <= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
