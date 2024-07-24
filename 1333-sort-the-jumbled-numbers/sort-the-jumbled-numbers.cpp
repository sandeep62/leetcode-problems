class Solution {
public:

    int  getmappednum(int num,vector<int>&mapping)
    {
        if(num<10)
        {
            return mapping[num];
        }
        int mappednum=0;
        int place=1;
        while(num)
        {
            int lastdigit=num%10;
            int mappednumber=mapping[lastdigit];
            mappednum+=mappednumber*place;
            place=place*10;
            num/=10;
        }
        return  mappednum;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>mapitem;
        for(int i=0;i<n;i++)
        {
            int mappednum=getmappednum(nums[i],mapping);
            mapitem.push_back({mappednum,i});

        }
        sort(begin(mapitem),end(mapitem));
        vector<int>result;
        for(auto &p:mapitem)
        {
            int original_index=p.second;
            result.push_back(nums[original_index]);
        }
        return result;
    }
};