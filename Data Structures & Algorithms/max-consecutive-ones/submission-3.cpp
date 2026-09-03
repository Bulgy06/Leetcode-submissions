class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int l=0;
        int r=0;
        int ans=0;
        while(l<=r && r<nums.size()){
            if(nums[r]==1){
                ans=max(ans,r-l+1);
                r++;
            }
            else{
                while(r<nums.size() && nums[r]==0){
                    r++;
                }
                l=r;
            }
        }
        return ans;
    }
};