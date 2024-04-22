#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    static int openLock(vector<string>& deadends, const string& target) {
        bitset<10000> seen=0;// 0000~9999
        for(string& s: deadends){
            seen[stoi(s)]=1;
        }
        if (seen[0]) return -1;//edge case
        queue<pair<short, short>> q;
        q.emplace(0, 0);
        seen[0]=1;
        short z=stoi(target);
        short dec[4]={1, 10, 100,1000};
        while(!q.empty()){
            auto [turn, s]=q.front(); q.pop();
        //    cout<<turn<<":"<<s<<endl;
            if (s==z) return turn;
            short digit, t=s;
            for(short d=0; d<4; d++){// 8 ways of turning
                digit=t%10, t/=10;
                for(short i: {-1, 1}){
                    short dnext=(digit+i+10)%10;
                    short x=s+(dnext-digit)*dec[d];
                    if (!seen[x]) {
                        q.emplace(turn+1, x);
                        seen[x]=1;
                    }
                }
            }
        }
        return -1;
    }
};
