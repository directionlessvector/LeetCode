class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n = nums.size();
        int sum = 0, st = 0;
        int ans = n + 1;

        for (int end = 0; end < n; end++) {
            sum += nums[end];
            while (sum >= t) {
                ans = min(ans, end - st + 1);
                sum -= nums[st];
                st++;
            }
        }

        if (ans != n + 1) return ans;
        return 0;
    }
};