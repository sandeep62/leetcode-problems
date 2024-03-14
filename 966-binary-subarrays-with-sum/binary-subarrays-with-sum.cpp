class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0,prefixsum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(auto el:nums)
        {
            prefixsum+=el;
            if(mp.find(prefixsum-goal)!=mp.end())
            {
                ans+=mp[prefixsum-goal];
            }
            mp[prefixsum]++;
        }
        return ans;
        }
};