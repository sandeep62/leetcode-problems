class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second>1)
            {
                ans=x.first;
            }
        }
        return ans;
        
    }
};