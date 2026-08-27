class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxArray(nums.size(),INT_MIN);
        vector<int> minArray(nums.size(),INT_MAX);
        maxArray[0]=nums[0];
        minArray[0]=nums[0];
        int global=nums[0];
        for(int i=1;i<nums.size();i++){
            minArray[i]=min(nums[i],min(minArray[i-1]*nums[i],maxArray[i-1]*nums[i]));
            maxArray[i]=max(nums[i],max(maxArray[i-1]*nums[i],minArray[i-1]*nums[i]));
            global=max(global,max(minArray[i],maxArray[i]));
        }
        return global;
    }
};
