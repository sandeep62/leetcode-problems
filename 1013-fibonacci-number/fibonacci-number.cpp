class Solution {
    private:
    int memo[1000];
public:
    Solution(){
        for(int i=0;i<1000;i++)
        {
            memo[i]=-1;
        }
    };
    int fib(int n) {
        if(memo[n]==-1){
            int res;
            if(n==0 || n==1){
                res=n;
            }
            else{
                res=fib(n-1)+fib(n-2);
            }
            memo[n]=res;
        }
        return memo[n];
        
    }
};