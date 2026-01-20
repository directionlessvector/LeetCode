class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        
        vector<vector<int>> pr(m, vector<int>(n, 0)),pc(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pr[i][j] = a[i][j];
                pc[i][j] = a[i][j];
                if (j > 0) pr[i][j] += pr[i][j - 1];
                if (i > 0) pc[i][j] += pc[i - 1][j];
            }
        }
    
        int ans = 1;
        for (int k = 2; k <= min(m, n); k++) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    int t = pr[i][j + k - 1];
                    if (j > 0) t -= pr[i][j - 1];
                    
                    bool flag = true;
                    
                    for (int r = i; r < i + k && flag; r++) {
                        int rs = pr[r][j + k - 1];
                        if (j > 0) rs -= pr[r][j - 1];
                        if (rs != t)
                            flag = false;
                    }
                    
                    for (int c = j; c < j + k && flag; c++) {
                        int cs = pc[i + k - 1][c];
                        if (i > 0) cs -= pc[i - 1][c];
                        if (cs != t)
                            flag = false;
                    }
                    
                    int d1 = 0, d2 = 0;
                    for (int t = 0; t < k; t++) {
                        d1 += a[i + t][j + t];
                        d2 += a[i + t][j + k - 1 - t];
                    }

                    if (d1 != t || d2 != t) flag = false;
                    if (flag)
                        ans = max(ans, k);
                }
            }
        }
        
        return ans;
    }
};