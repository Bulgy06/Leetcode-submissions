class Solution {
private:
    vector<vector<int>> res;
    void backtracking(vector<int> &subset,vector<int> &nums,int i){
        res.push_back(subset);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            subset.push_back(nums[j]);
            backtracking(subset,nums,j+1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subset;
        backtracking(subset,nums,0);
        return res;
    }
};
