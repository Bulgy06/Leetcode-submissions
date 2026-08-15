class Solution {
private:
    vector<vector<string>> res;
    void backtracking(string s,int i, vector<string> &cur){
        if(i==s.length()){
            res.push_back(cur);
            return;
        }
        for(int j=i;j<s.length();j++){
            string w=s.substr(i,j-i+1);
            if(palindrome(w)){
                cur.push_back(w);
                backtracking(s,j+1,cur);
                cur.pop_back();
            }
        }
    }

    bool palindrome(string s){
        int l=0;
        int r=s.length()-1;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        backtracking(s,0,cur);
        return res;
    }
};