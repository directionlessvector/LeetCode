class Solution {
public:
    vector<vector<int>> dp;

    int solve(int l, int r, vector<int>& nums) {
        if (l + 1 >= r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        for (int i = l + 1; i < r; i++) {
            int cost =  nums[l] * nums[i] * nums[r] + 
                        solve(l, i, nums)+
                        solve(i, r, nums);
            ans = max(ans, cost);
        }
        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        dp.assign(n + 2, vector<int>(n + 2, -1));
        return solve(0, n + 1, nums);
    }
};
