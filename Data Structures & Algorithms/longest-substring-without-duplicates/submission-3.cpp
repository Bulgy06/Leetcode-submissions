class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mp;
        int maxi=0;
        int left=0;
        int right=0;
        while(right<s.length()){
            if(!mp.count(s[right])){
                mp.insert(s[right]);
                maxi=max(maxi,right-left+1);
                right++;
            }
            else{
                mp.erase(s[left]);
                left++;

            }
        }
        return maxi;
    }
};
