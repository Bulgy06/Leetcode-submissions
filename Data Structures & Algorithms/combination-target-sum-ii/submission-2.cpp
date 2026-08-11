class Solution {
private:
    vector<vector<int>> res;
    void backtracking(int i,vector<int> &subset,vector<int> &nums,int target){
        if(target==0){ 
            res.push_back(subset);
            return;
        }
        if(target<0|| i>=nums.size()) return;
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]){
                continue;
            }
            subset.push_back(nums[j]);
            backtracking(j+1,subset,nums,target-nums[j]);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        sort(candidates.begin(),candidates.end());
        backtracking(0,subset,candidates,target);
        return res;
    }
};
