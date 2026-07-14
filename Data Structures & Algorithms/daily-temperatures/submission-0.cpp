class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> result;

        for(int i = 0; i < temperatures.size(); i++){
            int currTemp = temperatures[i];
            bool foundWarmDay = false;
            for(int j = i+1; j < temperatures.size(); j++){
                int futureTemp = temperatures[j];
                if(futureTemp > currTemp){
                    foundWarmDay = true;
                    result.push_back(j - i);
                    break;
                }
                
            }
            if(!foundWarmDay) result.push_back(0);
        }

        return result;
    }
};
