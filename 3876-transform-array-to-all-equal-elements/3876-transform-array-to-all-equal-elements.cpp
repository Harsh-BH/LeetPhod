#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Returns true if we can make all elements equal within k operations.
    bool canMakeEqual(vector<int>& nums, int k) {
        int ops1 = minFlips(nums,  1, k);
        int ops2 = minFlips(nums, -1, k);
        return min(ops1, ops2) <= k;
    }

private:
  
    int minFlips(vector<int> arr, int target, int k) {
        int ops = 0;
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] != target) {
                arr[i]     = -arr[i];
                arr[i + 1] = -arr[i + 1];
                if (++ops > k) return k + 1;  
            }
        }
        return (arr[n - 1] == target) ? ops : k + 1;
    }
};
