class Solution {
public:

    int lcs(string word1,string word2,int n,int m)
    {
        int t[n+1][m+1];
        //initialisation of the dp matrix 

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 ||j==0)
                {
                    t[i][j]=0;

                }
            }
        }
        // filling the dp matrix
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    t[i][j]=t[i-1][j-1]+1;
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return ((n+m)-2*lcs(word1,word2,n,m));
        
    }
};