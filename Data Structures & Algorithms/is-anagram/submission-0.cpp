class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int freqArr[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            freqArr[s[i] - 'a'] += 1;
            freqArr[t[i] - 'a'] -= 1;
        }

        for(int i = 0; i < 26; i++){
            if(freqArr[i] > 0) return false;
        }

        return true;
    }
};
