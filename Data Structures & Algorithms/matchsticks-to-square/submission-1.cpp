class Solution {
private:
    int target;
    bool backtracking(vector<int> &m,int s1,int s2,int s3,int s4,int i){
        if(i==m.size()){
            if(s1==s2 && s2==s3 && s3==s4) return true;
            return false;
        }
        bool side1=false;
        if(s1+m[i]<=target) side1=backtracking(m,s1+m[i],s2,s3,s4,i+1);
        bool side2=false;
        if(s2+m[i]<=target) side2=backtracking(m,s1,s2+m[i],s3,s4,i+1);
        bool side3=false;
        if(s3+m[i]<=target) side3=backtracking(m,s1,s2,s3+m[i],s4,i+1);
        bool side4=false;
        if(s4+m[i]<=target) side4=backtracking(m,s1,s2,s3,s4+m[i],i+1);
        bool res=side1||side2||side3||side4;
        return res;
    }
public:
    bool makesquare(vector<int>& matchsticks){
        target=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(target%4!=0) return false;
        target=target/4;
        return backtracking(matchsticks,0,0,0,0,0);
    }
};