class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> operands;
        for(int i = 0; i < tokens.size(); i++){
            string c = tokens[i];
            if(isOperator(c)){
                int op2 = operands.top();
                operands.pop();
                int op1 = operands.top();
                operands.pop();
                if(c == "+") op1 = op1 + op2;
                else if(c == "-") op1 = op1 - op2;
                else if(c == "*") op1 = op1 * op2;
                else if(c == "/") op1 = op1 / op2;

                operands.push(op1);
            }else{
                operands.push(stoi(c));
            }
        }

        return operands.top();
    }

    bool isOperator(string c){
        if(c == "+" || c == "-" || c == "*" || c == "/") return true;
        return false;
    }
};
