class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        int diff=0,countofopen=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                diff++,countofopen++;
                ans.push_back(s[i]);
            }
            else if(s[i]==')')
            {
                if(diff==0) continue;
                diff--;
                ans.push_back(s[i]);
            }
            else{
                ans.push_back(s[i]);
            }
        }
        string fans="";
        int times=countofopen-diff;
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]=='('){
                times--;
                if(times<0) continue;
            }
            fans.push_back(ans[i]);
        }

        return fans;
    }
};