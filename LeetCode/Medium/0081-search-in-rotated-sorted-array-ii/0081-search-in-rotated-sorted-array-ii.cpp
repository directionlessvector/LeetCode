class Solution {
public:
    bool search(vector<int>& a, int t) {
        int n = a.size();
        int l = 0, h = n - 1;

        while (l < h) {
            int mid = l + ((h - l) >> 1);

            if (a[mid] == t)
                return true;
            
            while (a[mid] == a[l]) l++;
            while (a[mid] == a[h]) h--;

            if (a[mid] <= a[l]) {
                if (a[l] <= t && t < a[mid]) 
                    h = mid - 1;
                else 
                    l = mid + 1;
            }

            else {
                if (a[mid] < t && t < a[h])
                    l = mid + 1;
                else 
                    h = mid - 1;
            }
        }

        return false; 
    }
};