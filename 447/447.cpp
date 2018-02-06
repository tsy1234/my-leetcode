class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int len = points.size(), res = 0;
        for (int i = 0;i < len;i++) {
            unordered_map<int, int> map;
            for (int j = 0;j < len;j++) {
                if (i == j) continue;
                int xDis = points[i].first - points[j].first;
                int yDis = points[i].second - points[j].second;
                int distance = xDis * xDis + yDis * yDis;
                map[distance]++;
            }
            for (auto p : map) {
                if (p.second > 1) {
                    res += p.second * (p.second - 1);
                }
            }
        }   
        return res;
    }
};