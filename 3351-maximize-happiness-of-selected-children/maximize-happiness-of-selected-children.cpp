class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long ans=0;
        int c=0;
        for(int i=0;i<happiness.size();i++)
        {
            ans+=max(0,happiness[i]-c);
            c++;
            if(c>=k){
                break;
            }
        }
        return ans;
    }
};