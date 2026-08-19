class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> ans;

        combineRepeat(nums, temp, ans, 0, target);

        return ans;
    }

    void combineRepeat(
        const vector<int>& nums,
        vector<int>& temp,
        vector<vector<int>>& ans,
        int idx,
        int target
    ){
        if(target == 0) ans.push_back(temp);
        if(idx == nums.size()) return;

        for(int i = idx; i < nums.size(); i++){
            if(nums[i] > target) continue;

            temp.push_back(nums[i]);
            combineRepeat(nums, temp, ans, i, target - nums[i]);
            temp.pop_back();
        }
    }
};
