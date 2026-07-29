class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxM = piles[0];

        for (int i = 0; i < piles.size(); i++) {
            maxM = max(piles[i], maxM);
        }

        int left = 1;
        int right = maxM;

        int minAns = maxM;
        while(left <= right){
            int mid = left + (right - left)/2;

            if(canEatAll(piles, h, mid)){
                right = mid - 1;
                minAns = mid;
            } 
            else left = mid + 1;
        }

        return minAns;
        
    }

    bool canEatAll(vector<int>& piles, int h, int speed){
        int count = 0;
        for(int i = 0; i < piles.size(); i++){
            count += (piles[i] + speed - 1)/speed;
            if(count > h) return false;
        }

        if(count > h) return false;
        return true;
    }
};
