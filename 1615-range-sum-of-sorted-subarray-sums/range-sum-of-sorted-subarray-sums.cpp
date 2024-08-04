class Solution {
public:
    int Mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int ans=0;
        vector<int>temp;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                temp.push_back(sum);
            }
        }
        //since temp is 0 based indexing so use left-1 and right-1 
        sort(temp.begin(),temp.end());
        for(int i=left-1;i<=right-1;i++)
        {
            ans=(ans+temp[i])%Mod;

        }

        return ans;




        
    }
};