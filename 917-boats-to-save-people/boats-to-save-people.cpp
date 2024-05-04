class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size()-1;
        int ans=0;
        int i=0;
        while(i<=n)
        {
            if(people[i]+people[n]<= limit )
            {
                ans++;
                n--;
                i++;
            }
            else
            {
                ans++;
                n--;

            }

        }
        return ans;
        
    }
};