class Solution {
private:
    int res;
    int dp(vector<int> &nums,int target,vector<int> &memo){
        if(target==0){
            return 1;
        }
        if(target<0) return 0;
        if(memo[target]!=-1) return memo[target];
        int total=0;
        for(int number:nums){
            total+=dp(nums,target-number,memo);
        }
        return memo[target]=total;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target+1,-1);
        return dp(nums,target,memo);
        
    }
};