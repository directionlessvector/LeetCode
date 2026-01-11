class Solution {
public:
    long long countPairs(vector<string>& w) {
        int n = w.size();
        int m = w[0].size();

        unordered_map<string, long long> mp;

        for (auto &s : w) {
            string curr = "";
            for (int i = 0; i < m - 1; i++) {
                int d = s[i + 1] - s[i];
                if (d < 0) d += 26;
                curr += to_string(d);
            }
            mp[curr]++;
        }

        long long ans = 0;
        for (auto &[_, cnt] : mp) {
            ans += ((cnt) * (cnt - 1)) >> 1;
        }

        return ans;
    }
};