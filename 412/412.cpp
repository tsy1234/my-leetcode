class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1;i <= n;i++) {
            string str;
            if (i % 3 == 0 || i % 5 == 0) {
                if (i % 3 == 0 && i % 5 == 0) {
                    str = "FizzBuzz";
                } else {
                    str = (i % 3 == 0 ? "Fizz" : "Buzz");
                }
            } else {
                str = to_string(i);
            }
            res.push_back(str);
        }
        return res;
    }

    vector<string> better(int n) {
        vector<string> res;
        for (int i = 1;i <= n;i++) {
            string str = "";
            if (i % 3 == 0) str += "Fizz";
            if (i % 5 == 0) str += "Buzz";
            if (str.size() == 0) str += to_string(i);
            res.push_back(str);
        }
        return res;
    }
};