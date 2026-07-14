class Solution {
public:
    bool isValid(string s) {
        
        stack<char> openStack;

        for(int i = 0; i < s.size(); i++){
            char p = s[i];
            if(openStack.empty() && (p == ']' || p == ')' || p == '}')) return false;
            if(p == '(' || p == '[' || p == '{') openStack.push(p);
            else {
                char b = openStack.top();
                if((p == ']' && b != '[') || (p == ')' && b != '(') || (p == '}' && b != '{')) return false;
                openStack.pop();
            }
        }
        if(!openStack.empty()) return false;
        return true;
    }
};
