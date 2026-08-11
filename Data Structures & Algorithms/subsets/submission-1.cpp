class Solution {
private:
    vector<vector<int>> res;
    void backtrack(vector<int> &subset,vector<int> &nums,int i){
        res.push_back(subset);
        for(int j=i;j<nums.size();j++){
            subset.push_back(nums[j]);
            backtrack(subset,nums,j+1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        backtrack(subset,nums,0);
        return res;
    }
};
