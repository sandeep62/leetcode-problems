class Solution {
public:
    int Startatone(int n, int k) {
        if (n == 1) {
            return 0; // For zero-indexing, the last person is at index 0.
        } else {
            return (Startatone(n - 1, k) + k) % n;
        }
    }

    int findTheWinner(int n, int k) {
        return Startatone(n, k) + 1; // Convert zero-indexing to one-indexing.
    }
};
