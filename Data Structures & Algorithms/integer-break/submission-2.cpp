class Solution {
private:
    vector<int> dp;
public:
    int integerBreak(int n) {
        dp.resize(n+1,0);
        if(n<=3) return n-1;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                dp[i]=max(j*dp[i-j],dp[i]);
            }
        }
        return dp[n];
    }
};