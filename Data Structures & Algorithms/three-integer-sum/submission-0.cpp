class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> ans;
        
        for(int i = 0; i < nums.size(); i++){

            unordered_set<int> seen;
            for(int j = i+1; j < nums.size(); j++){

                    if(seen.count(-(nums[i] + nums[j]))){
                        vector<int> triplet = {nums[i], nums[j], -(nums[j] + nums[i])};
                        sort(triplet.begin(), triplet.end());
                        ans.insert(triplet);
                    }

                    seen.insert(nums[j]);
                    
            }
        }

        
        vector<vector<int>> ansRefined;
        for(auto it: ans){
            ansRefined.push_back(it);
        }
        return ansRefined;
    }
};
