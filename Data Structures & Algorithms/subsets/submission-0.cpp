class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        pickNotPick(nums, ans, temp, 0);

        return ans;
    }

    void pickNotPick(
        const vector<int>& nums,
        vector<vector<int>>& ans,
        vector<int>& temp,
        int idx
    ){
        if(idx >= nums.size()){
            ans.push_back(temp);
            return;
        }

        pickNotPick(nums, ans, temp, idx+1);

        temp.push_back(nums[idx]);
        pickNotPick(nums, ans, temp, idx+1);
        temp.pop_back();
    }
};
