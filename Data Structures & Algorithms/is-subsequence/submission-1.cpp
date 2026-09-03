class Solution {
public:
    bool isSubsequence(string s, string t) {
        int track=0;
        for(int i=0;i<t.length();i++){
            if(s[track]==t[i]) track++;
        }
        return track==s.length()? true:false;
    }
};