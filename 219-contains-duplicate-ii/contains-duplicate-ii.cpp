class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num_map; // Maps value to its latest index
        
        for (int i = 0; i < nums.size(); i++) {
            if (num_map.find(nums[i]) != num_map.end() && i - num_map[nums[i]] <= k) {
                return true;
            }
            num_map[nums[i]] = i; // Update the latest index of nums[i]
        }
        
        return false;
    }
};