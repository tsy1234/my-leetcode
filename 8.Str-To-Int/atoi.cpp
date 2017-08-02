#include <iostream>
#include <climits>
using namespace std;

int atoi(const char *str) {
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    cout << str[i] << endl;
    if (str[i] == '-' || str[i] == '+') {
        cout << (str[i++] == '-') << endl;
        sign = 1 - 2 * (str[i++] == '-'); 
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

