class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> mem(n,0);
        mem[0]=cost[0];
        mem[1]=cost[1];
        for(int i=2;i<cost.size();i++){
            mem[i]=min(cost[i]+mem[i-1],cost[i]+mem[i-2]);
        }
        return min(mem[n-1],mem[n-2]);
    }
};
