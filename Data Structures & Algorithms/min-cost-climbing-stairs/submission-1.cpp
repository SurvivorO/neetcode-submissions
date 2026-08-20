class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> dp(cost.size(), -1);


        int min1 = helper(cost, 0, dp);
        int min2 = helper(cost, 1, dp);

        return min(min1, min2);
    }

    int helper(
        const vector<int>& cost,
        int stepsCovered,
        vector<int>& dp
    ){

        if(stepsCovered >= cost.size()){
            return 0;
        }

        if(dp[stepsCovered] != -1) return dp[stepsCovered];

        // take 1 step
        int step1 = cost[stepsCovered] + helper(cost, stepsCovered + 1, dp);

        // take 2 step
        int step2 = cost[stepsCovered] + helper(cost, stepsCovered + 2, dp);

        return dp[stepsCovered] = min(step1, step2);
    }
};
