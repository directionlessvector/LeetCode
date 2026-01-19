class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& c, int r) {
        int q = -1;
        vector<int> ans = {-1, -1};

        for (auto &i : towers) {
            int x = i[0];
            int y = i[1];
            int curr = i[2];
            int dist = abs(x - c[0]) + abs(y - c[1]);
            if (curr > q && dist <= r) {
                ans = {x, y};
                q = curr;
            }
            else if (curr == q) {
                if (x < ans[0] || (x == ans[0] && y < ans[1])) {
                    ans = {x, y};
                }
            }
        }

        return ans;
    }
};