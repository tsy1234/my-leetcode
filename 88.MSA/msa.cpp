class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, cur = 0;
        while (i < m || j < n) {
            if (i < m && j < n) {
                int comp = nums1[cur] - nums2[j];
                if (comp <= 0) {
                    i++;
                } else {    
                    for (int k = m + n - 1;k > cur;k--) {
                        nums1[k] = nums1[k - 1];
                    }
                    nums1[cur] = nums2[j++];
                }
                cur++;
                continue;
            }
            if (i < m) i++;
            if (j < n) {
                nums1[cur++] = nums2[j++];
            }
        }
    }
    void better(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n -1, k = m + n - 1;
        // single loop
        // while (j >= 0) {
        //     nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        // }
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};