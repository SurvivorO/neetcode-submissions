class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long fullProduct = 1;

        int containsZero = 0;

        for(auto num : nums){

            if(num == 0) {
                containsZero += 1;
                continue;
            }
            fullProduct *= num;
        }

        vector<int> ans;
        int n = nums.size();
        if(containsZero > 1) return vector<int>(n,0);
        for(auto num : nums){
            if(containsZero == 1){
                num == 0 ? ans.push_back(fullProduct) : ans.push_back(0);
            }else{
                ans.push_back(fullProduct/num);
            }
            
        }

        return ans;
    }
};
