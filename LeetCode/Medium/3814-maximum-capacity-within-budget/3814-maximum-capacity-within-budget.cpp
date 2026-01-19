#define F first
#define S second

class Solution {
public:
    int maxCapacity(vector<int>& co, vector<int>& ca, int b) {
        int n = co.size();
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) a[i] = {co[i], ca[i]};
        sort(a.begin(), a.end());

        int ans = 0;

        // brute force
        // for (int i = 0; i < n; i++) {
        //     if (a[i].first < b) {
        //         int w = a[i].second;
        //         int c = a[i].first;
        //         ans = max(ans, w);
        //         for (int j = i + 1; (j < n) && ((c + a[j].first) < b); j++) {
        //             ans = max(ans, w + a[j].second);
        //         }
        //     }
        //     else 
        //         break;
        // }

        vector<int> pref(n);
        pref[0] = a[0].S;
        for (int i = 1; i < n; i++)
            pref[i] = max(pref[i - 1], a[i].S);

        for (int i = 0; i < n; i++) {
            if (a[i].F < b)
                ans = max(ans, a[i].S);

            int rem = b - a[i].F - 1;
            if (rem < 0) continue;

            int l = 0, r = i - 1, idx = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (a[m].F <= rem) {
                    idx = m;
                    l = m + 1;
                } 
                else {
                    r = m - 1;
                }
            }

            if (idx != -1)
                ans = max(ans, a[i].S + pref[idx]);
        }

        return ans;
    }
};