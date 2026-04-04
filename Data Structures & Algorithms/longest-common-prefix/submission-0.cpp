class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int min=INT_MAX;
        int indx;
        for(int i=0;i<strs.size();i++){
            if(strs[i].length()<min){
                min=strs[i].length();
                indx=i;
            }
        }
        string shortest=strs[indx];
        for(int j=0;j<shortest.size();j++){
            char c=shortest[j];
            for(const string &s:strs){
                if(s[j]!=c){
                    return shortest.substr(0,j);
                }
            }

        }
        return shortest;

        
    }
};