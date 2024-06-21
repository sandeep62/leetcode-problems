class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int zeroSum = 0;  // Sum of satisfied customers when the owner is not grumpy
        int WindowSum = 0;  // Sum of customers that can be satisfied during the grumpy period within the window
        int maxWindowSum = 0;  // Maximum sum of additional satisfied customers

        for (int i = 0; i < n; ++i) {
            // Calculate zeroSum for customers when the owner is not grumpy
            if (grumpy[i] == 0) {
                zeroSum += customers[i];
            } else if (i < minutes) {
                // Calculate initial WindowSum for the first 'minutes' window
                WindowSum += customers[i];
            }

            // Adjust the WindowSum for the sliding window
            if (i >= minutes) {
                // Add the current customer if they are in the grumpy period
                if (grumpy[i] == 1) {
                    WindowSum += customers[i];
                }
                // Subtract the customer who is sliding out of the window if they were in the grumpy period
                if (grumpy[i - minutes] == 1) {
                    WindowSum -= customers[i - minutes];
                }
            }

            // Update the maximum WindowSum
            maxWindowSum = max(maxWindowSum, WindowSum);
        }

        // Return the total sum of satisfied customers
        return zeroSum + maxWindowSum;
    }
};
