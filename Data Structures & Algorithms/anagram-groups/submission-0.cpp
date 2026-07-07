class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<int,int> readIndices;
        for(int i = 0; i < strs.size(); i++){
            
            if(readIndices[i] == 1) continue;

            vector<string> ansList;
            ansList.push_back(strs[i]);
            for(int j = i+1; j < strs.size(); j++){
                if(checkAnagram(strs[i], strs[j]) == false) continue;

                readIndices[j] = 1;
                ansList.push_back(strs[j]);
                
            }

            ans.push_back(ansList);
        }

        return ans;
    }

    bool checkAnagram(string s, string t){
        if(s.size() != t.size()) return false;

        int charFreq[26] = {0};
        for(int i = 0; i < s.size(); i++){
            charFreq[s[i] - 'a'] += 1;
            charFreq[t[i] - 'a'] -= 1;
        }
        for(int i = 0; i < 26; i++){
            if(charFreq[i] > 0) return false;
        }
        return true;
    }
};
