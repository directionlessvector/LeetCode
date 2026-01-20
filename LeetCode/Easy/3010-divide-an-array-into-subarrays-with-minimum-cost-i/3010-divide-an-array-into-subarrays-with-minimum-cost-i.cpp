class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = 0;
        ans += nums[0];

        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 1; i < nums.size(); i++)
            pq.push(nums[i]);
        
        ans += pq.top();
        pq.pop();

        ans += pq.top();
        pq.pop();

        return ans;
    }
};