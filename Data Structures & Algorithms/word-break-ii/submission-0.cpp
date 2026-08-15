class Solution {
private:
    vector<string> res;
    unordered_set<string> wordset;
    void backtracking(string &s,int i,vector<string> &cur){
        if(i==s.length()){
            res.push_back(join(cur));
        }

        for(int j=i;j<s.length();j++){
            string w=s.substr(i,j-i+1);
            if(wordset.count(w)){
                cur.push_back(w);
                backtracking(s,j+1,cur);
                cur.pop_back();
            }
        }
    }

    string join(vector<string> &cur){
        string h="";
        for(int i=0;i<cur.size();i++){
            h+=cur[i]+" ";
        }
        h.pop_back();
        return h;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordset=unordered_set<string> (wordDict.begin(),wordDict.end());
        vector<string> cur;
        backtracking(s,0,cur);
        return res;
    }
};