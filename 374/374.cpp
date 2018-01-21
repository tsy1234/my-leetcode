// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    // binary search
    int guessNumber(int n) {
        int low = 1, high = n;
        while (low < high) {
            // 防止int溢出
            int mid = low + (high - low) / 2;
            int res = guess(mid);
            if (res == 1) {
                low = mid + 1;
            } else if (res == -1) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return low;
    }
    
    int better(int n) {
        int low = 1, high = n;
        while (low > high) {
            int mid = low + (high - low) / 2;
            if (guess(mid) == 1) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};