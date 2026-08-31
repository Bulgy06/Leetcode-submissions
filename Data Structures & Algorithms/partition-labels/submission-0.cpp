class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> partitions;
        unordered_map<char,int> last;
        for(int i=0;i<s.length();i++){
            last[s[i]]=i;
        }
        int end=0;
        int start=0;
        for(int j=0;j<s.length();j++){
            end=max(end,last[s[j]]);
            if(j==end){
                partitions.push_back(end-start+1);
                start=j+1;
            }
        }
        return partitions;
    }
};
