class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string>v;
        int n=arr.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;

        }

        for(auto &x:arr)
        {
            if(mp[x]==1)
            {
                v.push_back(x);
            }
        }
        if(k>v.size())
        {
            return "";
        }

        return v[k-1];
    }
};