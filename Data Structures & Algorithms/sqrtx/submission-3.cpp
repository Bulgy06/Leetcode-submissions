class Solution {
public:
    int mySqrt(int x) {
        int l=1;
        int r=x;
        int res=0;
        if(x==0||x==1) return x;
        while(l<=r){
            int m=l+(r-l)/2;
            if((long long)m*m==x) return m;
            else if((long long)m*m<x){
                l=m+1;
                res=max(m,res);
            }
            else{
                r=m-1;
            }
        }
        return res;
    }
};