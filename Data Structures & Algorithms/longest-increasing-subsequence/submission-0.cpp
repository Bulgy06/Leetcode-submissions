class Solution {
private:
    vector<vector<int>> memo;
    int dp(vector<int> &nums,int i, int j,int n){
        if(i==nums.size()) return 0;

        if(memo[i][j+1]!=-1) return memo[i][j+1];

        if(j==-1 || nums[i]>nums[j]){
            memo[i][j+1]=max(1+dp(nums,i+1,i,n),dp(nums,i+1,j,n));
        }
        else{
            memo[i][j+1]=dp(nums,i+1,j,n);
        }
        return memo[i][j+1];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memo=vector<vector<int>>(nums.size(),vector<int>(nums.size(),-1));
        int prev_chosen=-1;
        int res=0;
        return dp(nums,0,prev_chosen,nums.size());
    }
};
