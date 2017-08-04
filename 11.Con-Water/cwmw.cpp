#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int l = 0;
    int r = height.size() - 1;
    int water = 0;
    while (l < r) {
        int side = min(height[l], height[r]);
        water = max(water, side * (r - l));
        if (height[l] <= height[r]) {
            l = l + 1;
        } else {
            r = r - 1;
        }
    }
    return water;
}

int main() {
    int arr[] = {2, 1, 3};
    vector<int> a(arr, arr + 3);
    cout << maxArea(a) << endl;
    return 0;
}