class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int cnt = 0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i] %2 == 0 && cnt == 0 && nums[i]<=threshold){
                cnt++;
            }
            else if(cnt>0){
                if(nums[i]%2 == 0 && nums[i-1] %2 != 0 && nums[i]<=threshold){
                    cnt++;
                }
                else if(nums[i]%2!=0 && nums[i-1] %2 == 0 && nums[i]<=threshold){
                    cnt++;
                }
                else{
                    maxi = max(maxi,cnt);
                    if(nums[i]%2 == 0 && nums[i]<=threshold){
                        cnt = 1;
                    }
                    else{
                        cnt = 0;
                    }
                }
            }
        }
        maxi = max(maxi,cnt);
        return maxi;
    }
};