class Solution {
private:
    unordered_map<int,bool> memo;
    bool dp(string s,vector<string>& wordDict,int i){
        if(i==s.length()){
            return true;
        }
        if(memo.count(i)) return memo[i];
        for(int j=i;j<s.length();j++){
            if(find(wordDict.begin(),wordDict.end(),s.substr(i,j-i+1))!=wordDict.end() && dp(s,wordDict,j+1)){
                memo[i]=true;
                return true;
            }
        }
        memo[i]=false;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return dp(s,wordDict,0);
    }
};
