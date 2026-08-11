class Solution {
private:
    vector<vector<int>> res;
    void backtracking(int i,vector<int> &subset,vector<int> &nums,int target){
        if(target==0){ 
            res.push_back(subset);
            return;
        }
        if(target<0|| i>=nums.size()) return;
        subset.push_back(nums[i]);
        backtracking(i,subset,nums,target-nums[i]);
        subset.pop_back();
        backtracking(i+1,subset,nums,target);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        backtracking(0,subset,nums,target);
        return res;
    }
};
