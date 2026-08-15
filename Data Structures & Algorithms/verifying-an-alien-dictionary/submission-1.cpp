class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> rank;
        vector<int> ranks(words.size(),0);
        for(int i=0;i<order.length();i++){
            rank[order[i]]=i;
        }
        bool different=false;
        for(int j=0;j<words.size()-1;j++){
            for(int k=0;k<min(words[j].length(),words[j+1].length());k++){
                if(rank[words[j][k]]<rank[words[j+1][k]]){
                    different=true;
                    break;
                }
                if(rank[words[j][k]]>rank[words[j+1][k]]){
                    return false;
                }
            }
            if(!different && (words[j].length()>words[j+1].length())) return false;
        }
        return true;
        
    }
};