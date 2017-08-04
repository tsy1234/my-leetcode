#include <iostream>
#include <climits>
using namespace std;

int atoi(const char *str) {
    int sign = 1, base = 0, i = 0;
    // 去除前面的空格
    while (str[i] == ' ') { i++; }

    if (str[i] == '-' || str[i] == '+') {
        sign = 1 - 2 * (str[i++] == '-'); .// good 判断了符号并且将指针指向下一个字母
    }

    while (str[i] >= '0' && str[i] <= '9') {
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}

int main() {
    char s[] = "23-12"; 
    cout << atoi(s) << endl;
    return 0;
}

