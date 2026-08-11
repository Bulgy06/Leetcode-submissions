class Solution {
private:
    vector<string> res;
    void backtracking(string curString,int n,int open,int close){
        if(curString.length()==2*n){
            if(open==close)res.push_back(curString);
            return;
        }

        if(open<n){
            curString+="(";
            backtracking(curString,n,open+1,close);
            curString.pop_back();
        }

        if(close<open){
            curString+=")";
            backtracking(curString,n,open,close+1);
            curString.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        backtracking("",n,0,0);
        return res;
    }
};
