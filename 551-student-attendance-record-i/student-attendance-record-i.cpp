class Solution {
public:
    bool checkRecord(string s) {
        int n = s.length();
        int a = 0; // Count of 'A'
        int lCount = 0; // Consecutive 'L' count

        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                a++;
                if (a >= 2) {
                    return false; // More than one 'A'
                }
            }
            if (s[i] == 'L') {
                lCount++;
                if (lCount >= 3) {
                    return false; // Three or more consecutive 'L's
                }
            } else {
                lCount = 0; // Reset the consecutive 'L' counter if the current character is not 'L'
            }
        }
        
        return true; // If no rules are broken, return true
    }
};
