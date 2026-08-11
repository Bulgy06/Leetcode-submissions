class Solution {
private:
    int res=0;
    int backtracking(vector<int> &nums,int i,int currentXor){
        res+=currentXor;
        for(int j=i;j<nums.size();j++){
            backtracking(nums,j+1,currentXor^nums[j]);
        }
        return res;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return backtracking(nums,0,0);
    }
};