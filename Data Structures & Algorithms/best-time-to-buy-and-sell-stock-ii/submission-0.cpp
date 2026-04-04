class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        for(int i=0;i<prices.size()-1;i++){
            int n=prices[i+1]-prices[i];
            if(n>0){
                maxprofit=maxprofit+n;
            }
        }
        return maxprofit;
        
    }
};