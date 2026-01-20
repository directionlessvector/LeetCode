class Solution {
public:
    bool isPalin(int i, int j, const string& s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(int i, int j, const string& s, vector<vector<int>>& dp) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (isPalin(i, j, s)) return dp[i][j] = 0;

        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            if (isPalin(i, k, s)) {
                int right = (dp[k+1][j] != -1) ? dp[k+1][j] : solve(k+1, j, s, dp);
                ans = min(ans, 1 + right);
            }
        }

        return dp[i][j] = ans;
    }

    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, s, dp);
    }
};