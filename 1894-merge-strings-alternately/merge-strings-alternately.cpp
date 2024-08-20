class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int i=0;
        int j=0;
        string ans="";
        bool flag=true;
        while(i<word1.size() || j<word2.size()){

            if(i>=word1.size()){
                ans +=word2[j++];
            }
            else if(j>=word2.size()){
                ans +=word1[i++];
            }
            else{
                if(flag){
                    ans +=word1[i++];
                    flag=!flag;
                }
                else{
                    ans +=word2[j++];
                    flag=!flag;
                }

            }
        }
        return ans;
    }
};