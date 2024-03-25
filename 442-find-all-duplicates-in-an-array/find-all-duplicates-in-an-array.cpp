class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second>1)
            {
                ans.push_back(x.first);
            }
            else{
                continue;
            }
        }
        return ans;
        
    }
};