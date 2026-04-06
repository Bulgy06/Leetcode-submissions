class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        if(n<3) return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left= i+1;
            int right=n-1;
            int target=-nums[i];
            while(left<right){
                int curSum=nums[left]+nums[right];
                if(curSum==target){
                    int leftVal=nums[left];
                    int rightVal=nums[right];
                    res.push_back({nums[i],leftVal,rightVal});
                    while(left<right && nums[left]==leftVal) left++;
                    while(left<right && nums[right]==rightVal) right--;
                }
                else if(curSum<target) left++;
                else right--;
            }
        }
        return res;
    }
};