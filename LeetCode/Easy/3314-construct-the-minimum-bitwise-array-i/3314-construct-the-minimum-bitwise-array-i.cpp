class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int &x : nums) {
            if (x & 1) {
                int t = ((x + 1) & ~x) >> 1;
                ans.push_back(x & ~t);
            } 
            else
                ans.push_back(-1);
        }
        
        return ans;
    }
};