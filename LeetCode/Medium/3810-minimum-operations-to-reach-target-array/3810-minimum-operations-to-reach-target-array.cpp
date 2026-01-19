class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& t) {
        int n = a.size();
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            if (t[i] != a[i])
                mp[a[i]]++;
        }

        return mp.size();
    }
};