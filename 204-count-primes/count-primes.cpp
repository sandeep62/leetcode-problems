class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        
        int ans = 0;
        vector<bool> isprime(n, true);
        isprime[0] = isprime[1] = false; // 0 and 1 are not prime numbers

        for (int i = 2; i < n; i++) {
            if (isprime[i]) {
                ans++;
                 if (i > sqrt(n)) continue; 
                for (int j = i * i; j < n; j += i) {
                    isprime[j] = false;
                }
            }
        }
        return ans;
    }
};
