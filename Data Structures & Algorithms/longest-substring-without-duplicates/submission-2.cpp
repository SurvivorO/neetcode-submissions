class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;

        unordered_map<char, int> freq;
        int maxLength = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){

            left =  max(left,freq[s[i]]);
            freq[s[i]] = i + 1;
            int currLength = i - left + 1;
            maxLength = max(currLength, maxLength);
        }

        return maxLength;
    }
};
