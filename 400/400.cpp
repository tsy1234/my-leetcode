class Solution {
public:
    // INT_MAX  2147483647
    // my error code spen one and half hour
    int findNthDigit(int n) {
        float width[10], base = 9;
        width[0] = 0;
        // 不需要存入数组，只需要用一次
        for (int i = 1;i < 10;i++) {
            width[i] = base * i;
            cout << "i: " << i << width[i] << endl;
            base *= 10;
        }

        int num = n, j = 0;
        while (num > width[j]) {
            num -= width[j];
            j++;
        }
        int integer;
        if (j == 1) {
            integer = width[j - 1] + num / j;
        } else {
            integer = width[j - 1] / (j - 1) + num / j;   
        }
        int  re = num % j;
        cout << "num j re" << num << " " << j << " " << re << endl;
        integer += (re == 0 ? 0 : 1);
        cout << integer << endl;
        if (re == 0) {
            return integer % 10;
        } else {
            int res;
            for (int i = 0;i < j - re + 1;i++) {
                res = integer % 10;
                integer /= 10;
            }
            return res;
        }
    }

    int better(int n) {
        int d = 1;
        long acc = 9;
        int i = 1;
        
        while(n > d*acc){
            // 减去多一位的数的所有单词总量
            n -= (d++) * acc;
            // 增加下限
            i += acc;
            acc *= 10;
        }
        // (n - 1) / d 。。。。。
        return to_string(i + (n - 1) / d)[(n - 1) % d] - '0';
    }
};