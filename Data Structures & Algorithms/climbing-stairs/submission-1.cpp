class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        vector<int> dp(n+1, -1);
        int ans = helper(n, dp);
        return ans;

    }

    int helper(int n, vector<int>& dp){

        
        if(n <= 0){
            return 0;
        }
        if(n == 1) return 1;
        if(n == 2) return 2;

        if(dp[n] != -1) return dp[n];

        int pick1 = helper(n-1, dp);
        int pick2 = helper(n-2, dp);

        return dp[n] = pick1 + pick2;

        
    }
};
