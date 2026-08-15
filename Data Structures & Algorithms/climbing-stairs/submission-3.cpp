class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2){
            return n;
        }
        vector<int> mem(n+1,0);
        mem[1]=1;
        mem[2]=2;
        for(int i=3;i<=n;i++){
            mem[i]=mem[i-1]+mem[i-2];
        }
        return mem[n];
    }
};
