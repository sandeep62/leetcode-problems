class Solution {
public:
    string removeKdigits(string num, int k) {
       int n=num.size();
       stack<char>s;
       for(auto c:num)
       {
        while(!s.empty() && s.top()>c && k>0)
        {
            s.pop();
            k--;
        }
        s.push(c);
       } 
        while(k>0 && !s.empty())
        {
            s.pop();
            k--;
        }
        string ans="";
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        int endingindex=0;
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(ans[i]!='0')
            {
                endingindex=i;
                break;
            }
        }
        ans=ans.substr(0,endingindex+1);
        reverse(ans.begin(),ans.end());
        if(ans==""){
            ans="0";
        }
        return ans;


    }
};