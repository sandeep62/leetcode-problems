class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long ans=0,latestocc=-1;
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                latestocc=i-1;
            }
            ans+=i-latestocc;
        }
        return ans;

        
    }
};