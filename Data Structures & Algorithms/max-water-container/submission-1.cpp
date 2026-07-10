class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int left = 0;
        int right = heights.size() - 1;

        int maxWater = 0;

        while (left < right){
            int currHeight = min(heights[left], heights[right]);
            int currWater = currHeight * (right - left);

            maxWater = max(maxWater, currWater);
            
            if(heights[left] < heights[right]) left += 1;
            else right -= 1;
        }

        return maxWater;
    }
};
