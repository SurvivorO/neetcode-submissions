class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i < strs.size(); i++){
            ans += strs[i];
            ans += "./.";
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            string delimiter = s.substr(i,3);
            if(delimiter.size() == 3 && delimiter == "./.") {
                ans.push_back(temp);
                temp = "";
                i += 2;
                continue;
            }
            temp.push_back(s[i]);
        }

        return ans;
    }
};
