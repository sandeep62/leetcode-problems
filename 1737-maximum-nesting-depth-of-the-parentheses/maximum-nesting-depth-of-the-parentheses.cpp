class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int ans=0;
        stack<char>s1;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                count++;
                s1.push(s[i]);
            }
            else if(s[i]==')')
            {
                count--;
                s1.pop();
            }
            ans=max(ans,count);

        }
        return ans;

        
    }
};