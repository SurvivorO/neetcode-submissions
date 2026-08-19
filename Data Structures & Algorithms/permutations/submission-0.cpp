class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), false);
        vector<int> temp;

        helper(nums, visited, temp, ans);

        return ans;
    }

    void helper(
        const vector<int>& nums,
        vector<bool>& visited,
        vector<int>& temp,
        vector<vector<int>>& ans
    ){

        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){

            if(visited[i]) continue;

            visited[i] = true;

            temp.push_back(nums[i]);
            helper(nums, visited, temp, ans);
            temp.pop_back();

            visited[i] = false;
        }

        return;
    }
};
