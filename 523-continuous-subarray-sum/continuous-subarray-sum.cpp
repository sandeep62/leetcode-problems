class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;

        // To store (prefix sum % k) and its earliest index
        unordered_map<int, int> prefixSumModMap;
        // Initial condition: prefix sum 0 at index -1 to handle subarrays starting from index 0
        prefixSumModMap[0] = -1;

        int prefixSum = 0;
        for (int i = 0; i < n; ++i) {
            prefixSum += nums[i];
            int mod = (k == 0) ? prefixSum : prefixSum % k;

            // If mod was seen before, there is a subarray summing to multiple of k
            if (prefixSumModMap.find(mod) != prefixSumModMap.end()) {
                // Check if subarray length is at least 2
                if (i - prefixSumModMap[mod] > 1) {
                    return true;
                }
            } else {
                // Store the first occurrence of this mod
                prefixSumModMap[mod] = i;
            }
        }

        return false;
    }
};