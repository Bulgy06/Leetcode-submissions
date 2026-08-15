class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n,0);
        vector<int> trusted(n,0);
        for(int i=0;i<trust.size();i++){
            trusts[trust[i][0]-1]++;
            trusted[trust[i][1]-1]++;
        }
        for(int j=0;j<n;j++){
            if(trusts[j]==0 && trusted[j]==n-1){
                return j+1;
            }
        }
        return -1;
    }
};