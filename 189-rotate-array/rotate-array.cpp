class Solution {
public:
    void reverse(vector<int>& nums, int low, int high) {
        while (low < high) {
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // In case k is greater than n
        reverse(nums, 0, n - 1);       // Reverse the entire array
        reverse(nums, 0, k - 1);       // Reverse the first k elements
        reverse(nums, k, n - 1);       // Reverse the remaining n-k elements
    }
};
