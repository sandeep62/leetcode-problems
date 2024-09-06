class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        if(n<3)
        {
            return false;
        }
        int sum=0;
        for(int i=1;i<n;i++)
        {
            sum=nums[i]+nums[i-1];
            if(st.find(sum)!=st.end())
            {
                return true;
            }
            st.insert(sum);

        }
        return false;
    }
};