class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>> memo(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++){
            memo[i][0]=i;
        }
        for(int j=0;j<n+1;j++){
            memo[0][j]=j;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(word1[i-1]==word2[j-1]) memo[i][j]=memo[i-1][j-1];
                else{
                    int inter=min(memo[i-1][j],memo[i][j-1]);
                    memo[i][j]=min(inter,memo[i-1][j-1]) +1;
                }
            }
        }
        return memo[m][n];
    }
};
