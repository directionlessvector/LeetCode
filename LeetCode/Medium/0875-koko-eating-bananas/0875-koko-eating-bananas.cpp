class Solution {
public:
    bool check(int mid, int h, vector<int>& piles) {
        long long sum = 0LL;
        for (int x : piles) {
            sum += (x + mid - 1) / mid;
            if (sum > h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, h, piles)) {
                ans = mid;
                r = mid - 1;
            } 
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};