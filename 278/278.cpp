// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    // brutal Time limit exceed
    int firstBadVersion(int n) {
        for (int i = 1;i <= n;i++) {
            if (isBadVersion(i)) return i;
        }
    }
    // end = mid 因为此时mid可能就是第一个错误，如果end = mid - 1 则出错
    int binarySearch(int n) {
        int start = 1, end = n, middle;
        while (start < end) {
            middle = start + (end - start) / 2;
            if (isBadVersion(middle)) {
                end = middle;
            } else {
                start = middle + 1;
            }
        }
        return start;
    }
};