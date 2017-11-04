class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = true;
        for (int i = n - 1;i >= 0 && carry;i--) {
            carry = (++digits[i] %= 10) == 0;
        }
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};