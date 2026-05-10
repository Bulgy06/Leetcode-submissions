class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> myStack;
        for(int i=0;i<tokens.size();i++){
            string sym=tokens[i];
            if(sym=="+"|| sym=="-"|| sym=="/" || sym=="*"){
                int operand2=myStack.top();
                myStack.pop();
                int operand1=myStack.top();
                myStack.pop();
                if(sym=="+") myStack.push(operand1+operand2);
                else if(sym=="-") myStack.push(operand1-operand2);
                else if(sym=="*") myStack.push(operand1*operand2);
                else myStack.push(operand1/operand2);
            }
            else{
                myStack.push(stoi(sym));
            }

        }
        int res=myStack.top();
        myStack.pop();
        return res;
    }
};
