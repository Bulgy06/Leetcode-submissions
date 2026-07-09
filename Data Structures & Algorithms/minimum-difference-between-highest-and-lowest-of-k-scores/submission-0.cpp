class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int smallest=0;
        int largest=k-1;
        int res=INT_MAX;
        while(largest<nums.size()){
            res=min(nums[largest]-nums[smallest],res);
            smallest++;
            largest++;
        }
        return res;
    }
};