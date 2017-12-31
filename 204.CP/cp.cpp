class Solution {
public:
    // time limit exceeded
    int countPrimes(int n) {
        int count = 0, i, j;
        for (i = 2;i < n;i++) {
            int upper = sqrt(i);
            for (j = 2;j <= upper;j++) {
                if (i % j == 0) break;
            }
            if (j > upper) count++;
        }
        return count;
    }
    
    int good(int n) {
        vector<bool> notPrime(n);
        int count = 0;
        for (int i = 2;i < n;i++) {
            if (notPrime[i] == false) {
                count++;
                for (int j = 2;i*j < n;j++) {
                    notPrime[i*j] = true;
                }
            }
        }
        return count;
    }
};