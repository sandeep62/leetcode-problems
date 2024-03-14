class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,prefixsum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(auto el:nums)
        {
            prefixsum+=el;
            if(mp.find(prefixsum-k)!=mp.end())
            {
                ans+=mp[prefixsum-k];
            }
            mp[prefixsum]++;
        }
        return ans;

        
    }
};