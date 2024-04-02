class Solution {
public:
    bool isIsomorphic(string s, string t) {
         unordered_map<char, char> mp, mp2;
         int n=s.length();
        for (int i=0; i<n; i++) {
            if (mp[s[i]] && mp[s[i]]!=t[i]) return false;
            if (mp2[t[i]] && mp2[t[i]]!=s[i]) return false;
            mp[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }
};