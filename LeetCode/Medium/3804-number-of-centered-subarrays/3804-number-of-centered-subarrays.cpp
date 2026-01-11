class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int l = 0; l < n; l++) {
            long long sum = 0;
            unordered_set<long long> st;
            for (int r = l; r < n; r++) {
                sum += nums[r];
                st.insert(nums[r]);
                if (st.count(sum)) ans++;
            }
        }

        return ans;
    }
};