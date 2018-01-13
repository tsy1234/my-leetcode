class Solution {
public:
    int addDigits(int num) {
        while (num / 10 != 0) {
            int temp = 0;
            while (num / 10 != 0) {
                temp += num % 10;
                num /= 10;
            }
            temp += num;
            num = temp;
        }
        return num;
    }
    // digit root
    int better(int num) {
        return 1 + (num - 1) % 9;
    }
};