class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>freq;
        int  maxi= *max_element(nums.begin(),nums.end());
        int i=0,j=0;
        ll ans=0;
        while(j < n){
            freq[nums[j]]++;
            while(freq[maxi] >= k){
                ans += n-j;
                freq[nums[i]]--;
                i++;
            }
            j++;   
        }
        return ans;
    }
};