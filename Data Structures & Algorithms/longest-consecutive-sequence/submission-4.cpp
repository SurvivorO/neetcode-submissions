class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;

        unordered_set<int> numsData;

        for(int i = 0; i < nums.size(); i++){
            numsData.insert(nums[i]);
        }
        
        int longest = 0;

        for(auto num : numsData){
            if(numsData.count(num-1)) continue;

            int counter = 1;
            while(numsData.count(num+1)){
                counter += 1;
                num = num + 1;
            }

            longest = max(counter, longest);
        }

        return longest;        
    }
};
