class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int res=nums[1]-nums[0];
        int minval=nums[0];
        for(int i=1;i<n;i++)
        {

            res=max(res,nums[i]-minval);
            minval=min(minval,nums[i]);

        }
        if(res>0)
        {
             return res;

        }
        else{
            return -1;
        }
       
        
    }
};