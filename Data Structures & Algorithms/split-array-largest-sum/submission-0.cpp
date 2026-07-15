class Solution {
    bool canSplit(vector<int> &nums,int largest,int k){
        int subArrays=1;
        int curSum=0;
        for(int num:nums){
            curSum+=num;
            if(curSum>largest){
                curSum=num;
                subArrays++;
            }
        }
        return subArrays<=k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int res=r;
        while(l<=r){
            int mid=(r-l)/2 + l;
            if(canSplit(nums,mid,k)){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
};