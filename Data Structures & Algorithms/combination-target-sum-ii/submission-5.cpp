class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(candidates.begin(), candidates.end());
        combine(candidates, ans, temp, 0, target);
        return ans;
    }

    void combine(
        const vector<int>& candidates,
        vector<vector<int>>& ans,
        vector<int>& temp,
        int idx, 
        int target
    ){

        if(target == 0){
            ans.push_back(temp);
            return;
        } 
        if(idx == candidates.size()) return;

        for(int i = idx; i < candidates.size(); i++){

            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) continue;

            temp.push_back(candidates[i]);
            combine(candidates, ans, temp, i+1, target - candidates[i]);
            temp.pop_back();
        }

        return;
    }
};
