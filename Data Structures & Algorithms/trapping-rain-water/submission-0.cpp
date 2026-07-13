class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size() == 1) return 0;
        
        int capacity = 0;
        for(int i = 0; i < height.size(); i++){
            //get tallest left
            int left = i-1;
            int maxLeft = 0;
            while(left >= 0){
                maxLeft = max(height[left], maxLeft);
                left -= 1;
            }

            //get tallest right
            int right = i+1;
            int maxRight = 0;
            while(right < height.size()){
                maxRight = max(height[right], maxRight);
                right += 1;
            }

            //calculate currnt col height - size
            int expectedCapacity = min(maxLeft, maxRight);
            int actualCapacity = expectedCapacity - height[i];
            if(actualCapacity < 0) actualCapacity = 0;

            capacity += actualCapacity;
        }

        return capacity;
        
    }
};
