class Solution {
private:
    vector<string> res;
    void backtracking(string &digits, vector<string> &choices,string s,int i){
        if(i==digits.length()){
            res.push_back(s);
            return;
        }
        if(i>=digits.length()) return;

        int digit=digits[i]-'0';
        int len=choices[digit-2].length();
        for(int j=0;j<len;j++){
            s.push_back(choices[digit-2][j]);
            backtracking(digits,choices,s,i+1);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="") return res;
        vector<string> choices={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        backtracking(digits,choices,"",0);
        return res;
    }
};
