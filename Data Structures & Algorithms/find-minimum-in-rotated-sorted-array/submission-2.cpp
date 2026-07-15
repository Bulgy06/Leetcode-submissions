class Solution {
public:
    int findMin(vector<int>& nums) {
        int minimum=nums[0];
        int l=0;
        int r=nums.size()-1;
        int result;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>=minimum){
                l=mid+1;
            }
            else{
                r=mid-1;
                minimum=nums[mid];
            }

        }
        return minimum;
    }
};