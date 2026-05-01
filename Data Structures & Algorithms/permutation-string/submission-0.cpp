class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int window_size=s1.length();
        vector<int> s1_ftable(26,0);
        for(int i=0;i<s1.length();i++) s1_ftable[s1[i]-'a']++;
        int left=0;
        int right=0;
        vector<int> s2_ftable(26,0);
        while(right<s2.length()){
            s2_ftable[s2[right]-'a']++;
            if(right-left+1>window_size){
                s2_ftable[s2[left]-'a']--;
                left++;
            }
            if(s2_ftable==s1_ftable) return true;
            right++;
        }
        return false;
    }
};