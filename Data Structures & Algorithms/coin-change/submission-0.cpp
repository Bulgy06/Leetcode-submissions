class Solution {
private:
    vector<int> memo;
    int dp(vector<int> &coins,int amount){
        if(amount==0) return 0;
        if(amount<0) return -1;
        if(memo[amount]!=-2) return memo[amount];
        int minCoins=INT_MAX;
        for(int coin: coins){
            int res=dp(coins,amount-coin);
            if(res!=-1){
                minCoins=min(minCoins,1+res);
            }
        }
        memo[amount]=(minCoins==INT_MAX)?-1:minCoins;
        return memo[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        memo.resize(amount+1,-2);
        return dp(coins,amount);
    }
};
