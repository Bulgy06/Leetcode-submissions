class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=accumulate(nums.begin(),nums.end(),0);
        int expected=nums.size()*(nums.size()+1)/2;
        return expected-ans;
    }
};
