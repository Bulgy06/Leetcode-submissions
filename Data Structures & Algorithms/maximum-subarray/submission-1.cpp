class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int total=0;
        int maxsum=nums[0];
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            maxsum=max(maxsum,total);
            if(total<0){
                total=0;
            }
        }
        return maxsum;
    }
};
