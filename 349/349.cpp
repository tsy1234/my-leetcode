class Solution {
public:
    // 我的暴力方法～～
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1 = shuffle(nums1);
        int len2 = shuffle(nums2);
        int i = 0, j = 0;
        vector<int> res;
        while (i < len1 && j < len2) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            } else {
                if (nums1[i] > nums2[j]) {
                    j++;
                } else {
                    i++;
                }
            }
        }
        return res;
    }
    // 将数组排序并去除重复值，返回去除后数组的长度
    int shuffle(vector<int>& arr) {
        if (arr.size() == 0) return 0;
        sort(arr.begin(), arr.end());
        int len = arr.size(), i;
        for (i = 1;i < len;i++) {
            if (arr[i] == arr[i - 1]) {
                for (int j = i;j < len - 1;j++) {
                    arr[j] = arr[j + 1]; 
                }
                i--;
                len--;
            }
        }
        return i;
    }
    // 使用unordered_set的count方法来检查是否含有一样的值
    vector<int> better(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> res;
        int len = nums2.size();
        for (int i = 0;i < len;i++) {
            int val = nums2[i];
            if (set.count(val)) {
                res.push_back(val);
                set.erase(val);
            }
        }
        return res;
    }
};