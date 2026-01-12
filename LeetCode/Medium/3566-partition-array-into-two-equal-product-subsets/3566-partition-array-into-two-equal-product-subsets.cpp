class Solution {
public:
    using i128 = __int128;

    vector<int> nums;
    int len;
    i128 x;

    bool solve(int i, i128 curr, int taken) {
        if (curr > x) return false;
        if (curr == x) return taken > 0 && taken < len;
        if (i == len) return false;

        return solve(i + 1, curr, taken) || solve(i + 1, curr * nums[i], taken + 1);
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        this->nums = nums;
        len = nums.size();
        x = target;

        i128 product = 1;
        for (int n : nums) product *= n;

        if (product != (i128)target * target) return false;

        return solve(0, 1, 0);
    }
};