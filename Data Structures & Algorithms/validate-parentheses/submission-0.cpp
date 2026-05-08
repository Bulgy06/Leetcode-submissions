class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c=='{' || c=='(' || c=='['){
                myStack.push(c);
            }
            else if(c=='}' || c==')' || c==']'){
                if(myStack.empty()) return false;
                switch(c){
                    case '}':
                        if(myStack.top()!='{') return false;
                        else myStack.pop();
                        break;
                    case ')':
                        if(myStack.top()!='(') return false;
                        else myStack.pop();
                        break;
                    case ']':
                        if(myStack.top()!='[') return false;
                        else myStack.pop();
                        break;
                }
            }
        }
        return myStack.empty();
    }
};
