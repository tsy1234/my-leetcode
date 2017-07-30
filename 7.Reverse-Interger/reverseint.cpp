#include <iostream>
#include <climits>

using namespace std;

class ReverseInt {
    public:
        static int reverse(int x) {
            long long res = 0;
            while (x) {
                res = res * 10 + x % 10;
                x = x / 10;
            }
            return (res < INT_MIN || res > INT_MAX) ? 0 :res;
        }
};

int main() {
    cout << INT_MAX << endl;
    cout << ReverseInt::reverse(-2153) << endl;
}