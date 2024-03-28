class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int i=0,j=0,ans=0;
        while(j<n)
        {
            mp[nums[j]]++;
            while(i<=j && mp[nums[j]]>k)
            {
                mp[nums[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
        

    }
};