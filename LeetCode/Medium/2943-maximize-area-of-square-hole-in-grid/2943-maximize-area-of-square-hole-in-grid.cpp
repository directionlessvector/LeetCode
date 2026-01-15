class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        // check for max gap horizontally
        int gaph = 1, temp = 1;
        for (int i = 1; i < h.size(); i++) {
            if (h[i] == h[i-1] + 1)
                temp++; 
            else 
                temp = 1;
            gaph = max(gaph, temp);
        }

        // check for max gap vertically
        int gapv = 1;
        temp = 1;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] == v[i-1] + 1) 
                temp++;
            else 
                temp = 1;
            gapv = max(gapv, temp);
        }

        int side = min(gaph, gapv) + 1;
        return side * side;
    }
};