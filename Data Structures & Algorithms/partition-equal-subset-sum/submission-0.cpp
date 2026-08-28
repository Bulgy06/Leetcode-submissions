class Solution {
private:
    vector<vector<int>> memo;
    bool dp(vector<int> &nums, int i,int curSum, int target){
        if(curSum==target) return true;
        if(i==nums.size() || curSum>target) return false;

        if(memo[i][curSum]!=-1) return memo[i][curSum];
        
        memo[i][curSum]=dp(nums,i+1,curSum+nums[i],target)||dp(nums,i+1,curSum,target);
        return memo[i][curSum];

    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        int target=sum/2;
        memo= vector<vector<int>>(nums.size(),vector<int>(target+1,-1));
        return dp(nums,0,0,target);
    }
};
