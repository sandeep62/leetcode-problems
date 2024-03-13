class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        for(int i = 0;i < s.length();i++){
            if(s[i] == '#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans1 = "",ans2 = "";
        while(!st.empty()){
            ans1 += st.top();
            st.pop();
        }
        stack<char>st2;
        for(int i = 0;i < t.length();i++){
            if(t[i] == '#'){
                if(!st2.empty()){
                    st2.pop();
                }
            }
            else{
                st2.push(t[i]);
            }
        }
        while(!st2.empty()){
            ans2 += st2.top();
            st2.pop();
        }
        //cout << ans1 << " " << ans2 << endl;
        if(ans1 == ans2)return true;
        return false;
    }
};