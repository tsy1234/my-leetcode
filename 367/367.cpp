class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};

// 这个方式当num = 2147483647时， temp会溢出，于是一直小于num
// int i = 1, temp = 1;
// while (temp < num) {
//     i += 2;
//     temp += i;
// }
// return temp == num;