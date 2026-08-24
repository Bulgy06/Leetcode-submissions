class Solution {
private:
    unordered_map<int,int> memo;
    int dp(string s,int i){
        if(i==s.length()) return 1;
        if(s[i]=='0') return 0;
        if(memo.count(i)) return memo[i];
        int ans=dp(s,i+1);
        if(i+1<s.length() && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))){
            ans+=dp(s,i+2);
        }
        return memo[i]=ans;
    }
public:
    int numDecodings(string s) {
        return dp(s,0);
    }
};
