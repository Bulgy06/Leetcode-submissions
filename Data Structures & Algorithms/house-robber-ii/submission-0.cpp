class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> nums1(nums.begin(),nums.end()-1);
        vector<int> nums2(nums.begin()+1,nums.end());
        if(nums.size()==1) return nums[0];
        if(nums.empty()) return 0;
        if(nums.size()==2) return max(nums[0],nums[1]);
        nums1[0]=nums[0];
        nums1[1]=max(nums[0],nums[1]);
        nums2[0]=nums[1];
        nums2[1]=max(nums[1],nums[2]);
        for(int i=2;i<nums.size()-1;i++){
            nums1[i]=max(nums1[i-1],nums[i]+nums1[i-2]);
        }
        for(int i=2;i<nums.size()-1;i++){
            nums2[i]=max(nums2[i-1],nums[i+1]+nums2[i-2]);
        }
        return max(*max_element(nums1.begin(),nums1.end()),*max_element(nums2.begin(),nums2.end()));
    }
};
