class Solution {
public:
    // this problem can be reduced to counting subset with a given difference which can be further reduced to counting subset sum
    
    // target sum--> counting subset with given sum (ie. target here)-->counting subset sum 
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int mod=1e9+7;
        int n=nums.size();
        int array_sum=0;
        for(auto n:nums)
            array_sum+=n;
        // cout<<array_sum;

        
        int sum=((target+array_sum)/2)%mod;
        
        if(array_sum < target or (array_sum + target)%2 != 0 or sum<0)
        return 0;
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1));
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]=(dp[i-1][j-nums[i-1]] + dp[i-1][j])%mod;
                }
                else
                {
                    dp[i][j]=(dp[i-1][j])%mod;
                }
            }
        }
        
        return dp[n][sum]%mod;
    }
};