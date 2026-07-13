class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size() == 1) return 0;
        
        //calculate maxLeft array
        vector<int> maxLeft(height.size(), 0);
        maxLeft[0] = height[0];
        for(int i = 1; i < height.size(); i++){
            maxLeft[i] = max(maxLeft[i-1], height[i]);
        }

        //calculate maxRight array
        vector<int> maxRight(height.size(), 0);
        maxRight[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; i--){
            maxRight[i] = max(maxRight[i+1], height[i]);
        }

        int capacity = 0;
        for(int i = 0; i < height.size(); i++){
        
            int highestLeft = maxLeft[i];
            int highestRight = maxRight[i];

            //calculate currnt col height - size
            int expectedCapacity = min(highestLeft, highestRight);
            int actualCapacity = expectedCapacity - height[i];
            if(actualCapacity < 0) actualCapacity = 0;

            capacity += actualCapacity;
        }

        return capacity;
        
    }
};
