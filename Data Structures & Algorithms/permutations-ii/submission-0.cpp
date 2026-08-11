class Solution {
private:
    vector<vector<int>> res;
    void backtracking(vector<int> &subset,vector<int> &nums,vector<int> &pick){
        if(subset.size()==nums.size()){
            res.push_back(subset);
            return;
        }

        for(int j=0;j<nums.size();j++){
            if(pick[j]==1 || (j>0 && nums[j]==nums[j-1] && !pick[j-1])) continue;
            subset.push_back(nums[j]);
            pick[j]=1;
            backtracking(subset,nums,pick);
            subset.pop_back();
            pick[j]=0;
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subset;
        vector<int> pick;
        pick.reserve(nums.size());
        backtracking(subset,nums,pick);
        return res;
    }
};