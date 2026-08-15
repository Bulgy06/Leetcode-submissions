class Solution {
public:
    int tribonacci(int n) {
        if(n==0|| n==1) return n;
        if(n==2) return 1;
        vector<int> mem(n+1,0);
        mem[0]=0;
        mem[1]=1;
        mem[2]=1;
        for(int i=3;i<=n;i++){
            mem[i]=mem[i-1]+mem[i-2]+mem[i-3];
        }
        return mem[n];
    }
};