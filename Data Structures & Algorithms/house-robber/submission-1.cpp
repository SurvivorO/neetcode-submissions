class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size(), -1);

        int ans = helper(0, nums, dp);

        return ans;
    }

    int helper(
        int idx,
        const vector<int>& nums,
        vector<int>& dp
    ){
        if(idx >= nums.size()){
            return 0;
        }

        if(dp[idx] != -1) return dp[idx];

        int rob = nums[idx] + helper(idx + 2, nums, dp);
        int notRob = helper(idx + 1, nums, dp);

        return dp[idx] = max(rob, notRob);
    }
    
};
