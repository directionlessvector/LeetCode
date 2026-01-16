class Solution {
public:
    bool search(vector<int>& a, int t) {
        int l = 0, h = a.size() - 1;

        while (l <= h) {
            int mid = l + ((h - l) >> 1);

            if (a[mid] == t) return true;

            if (a[l] == a[mid] && a[mid] == a[h]) {
                l++;
                h--;
            }
            
            else if (a[l] <= a[mid]) {
                if (a[l] <= t && t < a[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }

            else {
                if (a[mid] < t && t <= a[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return false;
    }
};