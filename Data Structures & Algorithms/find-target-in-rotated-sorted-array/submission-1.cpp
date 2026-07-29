class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target) return mid;

            //left is sorted range 
            if(nums[mid] > nums[right]){
                //target is in sorted range
                if(nums[left] <= target && nums[mid] > target){
                    right = mid - 1;
                    continue;
                }else{
                    //target is in unsorted range

                    left = mid + 1;
                    continue;
                }
            }else{
                //right is sorted range
                if(nums[mid] < target && nums[right] >= target){
                    //target is in sorted range
                    left = mid + 1;
                    continue;
                }else{
                    //target is in unsorted range
                    right = mid - 1;
                    continue;
                }
            }
        }

        return -1;
    }
};
