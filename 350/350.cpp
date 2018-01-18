class Solution {
public:
    // brutal method
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
           sort(nums1.begin(), nums1.end());
           sort(nums2.begin(), nums2.end());
           int len1 = nums1.size(), len2 = nums2.size(), i = 0 , j = 0;
           vector<int> res;

           while (i < len1 && j < len2) {
                if (nums1[i] == nums2[j]) {
                    res.push_back(nums1[i]);
                    i++;
                    j++;
                } else {
                    if (nums1[i] < nums2[j]) {
                        i++;
                    } else {
                        j++;
                    }
                }
           }
           return res;
    }
    // better
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for (int i = i;i < nums1.size();i++) dict[nums1[i]]++;
        for (int i = 0;i < nums2.size();i++) {
            if (--dict[nums2[i]] >= 0) res.push_back(nums2[i]);
        }
        return res;
    }
};