class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";
        unordered_map<char,int> required_freq;
        for(char c:t) required_freq[c]++;
        unordered_map<char,int> window_freq;
        int left=0;
        int right=0;
        int total=required_freq.size();
        int satisfied=0;
        int begin=0;
        int minLen=INT_MAX;
        while(right<s.length()){

            if(required_freq.contains(s[right])){
                window_freq[s[right]]++;
                if(window_freq[s[right]]==required_freq[s[right]]){
                    satisfied++;
                }
            }

            while(satisfied==total){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    begin = left;
                }
                if(required_freq.contains(s[left])){
                    window_freq[s[left]]--;
                    if(window_freq[s[left]]<required_freq[s[left]]) satisfied--;
                }
                left++;
            }
            right++;
        }
        return minLen==INT_MAX? "":s.substr(begin,minLen);
    }
};
